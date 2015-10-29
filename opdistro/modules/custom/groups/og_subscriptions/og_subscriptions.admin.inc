<?php

/**
 * @file
 * Organic Groups Subscriptions module (admin functions).
 */


/**
 * Implements hook_form_alter().
 *
 * Adds the Group Settings part to SUBSCRIPTIONS_CONFIG_PATH.
 *
 * @param array $form
 * @param array $form_state
 *
 * @ingroup hooks
 * @ingroup form
 */
function _og_subscriptions_form_subscriptions_settings_form_alter(array &$form, array &$form_state) {
  $tr = 't';

  $form['groups'] = array(
    '#type' => 'fieldset',
    '#title' => t('Group settings'),
    '#collapsible' => TRUE,
    '#weight' => -8,
  );

  // Get a list of all groups
  $groups = og_get_all_group();
  $select[0] = '<' . t('none') . '>';
  foreach ($groups as $gid) {
    $node = node_load($gid);
    $select[$gid] = check_plain($node->title);
  }
  
  $form['groups']['subscriptions_group_autosubscribe'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Autosubscribe'),
    '#default_value' => variable_get('subscriptions_group_autosubscribe', 0),
    '#description'   => t('Should users automatically be subscribed to group content when they are added to the group?.'),
  );
  
  $form['groups']['subscriptions_group_autounsubscribe'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Auto-unsubscribe'),
    '#default_value' => variable_get('subscriptions_group_autounsubscribe', 1),
    '#description'   => t('Should users automatically be unsubscribed from group content when they are removed from a group?'),
  );

  // Set option for restricting groups
  $form['groups']['subscriptions_restricted_group'] = array(
    '#type'          => 'select',
    '#title'         => t('Restricted groups'),
    '#default_value' => variable_get('subscriptions_restricted_group', array()),
    '#options'       => $select,
    '#description'   => t('Select groups which should be listed on the %Subscriptions | %Categories page.', array('%Subscriptions' => t('Subscriptions'), '%Categories' => $tr('Categories'))),
    '#multiple'      => TRUE,
  );
  $form['groups']['subscriptions_omitted_group'] = array(
    '#type'          => 'select',
    '#title'         => t('Omitted groups'),
    '#default_value' => variable_get('subscriptions_omitted_group', array()),
    '#options'       => $select,
    '#description'   => t('Select groups which should be <strong>omitted</strong> from subscriptions listings; i.e. they will be removed from subscription listings.'),
    '#multiple'      => TRUE,
  );
}

/**
 * Build the Groups subscription form at user/UID/subscriptions/group.
 *
 * @param array $form
 * @param int $uid
 * @param array $groups
 *
 * @return array
 *
 * @ingroup form
 */
function _og_subscriptions_group_form(array $form, $uid, array $groups) {

  $query = db_select('node', 'n', array('fetch' => PDO::FETCH_ASSOC));
  $query->join('subscriptions', 's', (db_driver() != 'pgsql' ? 'n.nid = s.value' : 'CAST(t.gid AS VARCHAR) = s.value'));
  $result = $query
    ->fields('s', array('value', 'send_interval', 'author_uid', 'send_comments', 'send_updates'))
    ->fields('n', array('nid', 'title'))
    ->condition('s.module', 'node')
    ->condition('s.field', 'gid')
    ->condition('s.recipient_uid', $uid)
    ->addTag('node_access')
    ->orderBy('s.author_uid')
    ->execute();

  foreach ($result as $s) {
    $subscriptions[$s['value']][$s['author_uid']] = $s;
    $titles[$s['value']] = check_plain($s['title']);
  }

  $form[0] = array(
    '#theme' => 'subscriptions_form_table',
  );

  $defaults = array();
  foreach ($groups as $gid) {
    $gids_to_restrict = variable_get('subscriptions_restricted_group', array());
    if (in_array($gid, $gids_to_restrict) && !user_access('administer site configuration')) {
      continue;
    }
    if (!isset($titles[$gid])) {
      $group = node_load($gid);
      $titles[$gid] = check_plain($group->title);
    }
    if (!isset($subscriptions[$gid][-1])) {
      // author-less item is missing -- add it here:
      $subscriptions[$gid][-1] = array(
        'send_interval' => _subscriptions_get_setting('send_interval', $uid),
        'send_comments' => _subscriptions_get_setting('send_comments', $uid),
        'send_updates' => _subscriptions_get_setting('send_updates', $uid),
        'author_uid' => FALSE,
      );
    }
    foreach ($subscriptions[$gid] as $author_uid => $subscription) {
      subscriptions_form_helper($form[0], $defaults, $author_uid, $gid, $titles[$gid], $subscription);
    }
  }

  if (isset($form[0]['checkboxes'])) {
    $form[0]['defaults'] = array(
      '#type' => 'value',
      '#value' => $defaults,
    );
    subscriptions_form_column_filter($form[0], $uid);
  }
  else {
    $form = array(array('#markup' => t('You are not a member of any groups.')));
  }

  return $form;
}

