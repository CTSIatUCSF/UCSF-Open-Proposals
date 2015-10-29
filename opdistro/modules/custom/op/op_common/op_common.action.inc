<?php

/**
 * Implements hook_action_info().
 *
 * Defines custom actions for use with Views Bulk Operations views.
 */
function op_common_action_info() {

  $actions = array();

  $actions['op_common_update_node_status_action'] = array(
    'type' => 'node',
    'label' => 'OP: Update the status of the selected proposals',
    'configurable' => true,
    'triggers' => array(
      'any' => true,
    ),
    'behavior' => array('changes_property'),
  );

  $actions['op_common_update_node_comment_action'] = array(
    'type' => 'node',
    'label' => 'OP: Update the comment setting of the selected proposals',
    'configurable' => true,
    'triggers' => array(
      'any' => true,
    ),
    'behavior' => array('changes_property'),
  );

  $actions['op_common_update_node_rate_expiration_action'] = array(
    'type' => 'node',
    'label' => 'OP: Update the closing date for voting on the selected proposals',
    'configurable' => true,
    'triggers' => array(
      'any' => true,
    ),
    'behavior' => array('changes_property'),
  );

  return $actions;
}

/**
 * Configuration form for update Status taxonomy action.
 *
 * @see op_common_update_node_status_action()
 */
function op_common_update_node_status_action_form($context) {
  global $user;
  // dpm($context, __FUNCTION__);

  $form = array();

  if (isset($context['view']->filter['type']->value[0])) {
    $type = $context['view']->filter['type']->value[0];
  }
  else {
    $msg = "No content type filter value available from view {$context['view']->name}";
    drupal_set_message($msg, 'error');
    watchdog('op_common', $msg, null, WATCHDOG_ERROR);
  }

  $machine_name = null;

  foreach ($context['view']->relationship as $rname => $rdata) {
    if ($rdata->options['label'] == 'status' and isset($rdata->options['vocabularies'])) {
      $machine_name = array_shift(array_filter($rdata->options['vocabularies']));
      break;
    }
  }
  if (empty($machine_name)) {
    $msg = "No status vocabulary machine name available from view {$context['view']->name}";
    drupal_set_message($msg, 'error');
    watchdog('op_common', $msg, null, WATCHDOG_ERROR);
  }

  if ($type and $machine_name) {
    foreach (field_info_instances('node', $type) as $fname => $fdata) {
      if (!empty($fdata['display']['default']['module']) and $fdata['display']['default']['module'] == 'taxonomy') {
        $field_info = field_info_field($fname);
        if (!empty($field_info['settings']['allowed_values'])) {
          foreach ($field_info['settings']['allowed_values'] as $avdata) {
            if (isset($avdata['vocabulary']) and $avdata['vocabulary'] == $machine_name) {
              $form['field'] = array(
                '#type' => 'value',
                '#value' => $fname,
              );
              $form['fieldinfo'] = array(
                '#type' => 'markup',
                '#value' => 'Updating ' . $fname . ' - ' . $fdata['label'],
              );
              break;
            }
          }
        }
      }
    }
  }

  if ($vocabulary = taxonomy_vocabulary_machine_name_load($machine_name)) {
    $tree = taxonomy_get_tree($vocabulary->vid);
    $tids = array();
    foreach ($tree as $term) {
      $tids[$term->tid] = $term->name;
    }
    $form['tid'] = array(
      '#type' => 'select',
      '#title' => t('New !voc value', array('!voc' => $vocabulary->name)),
      '#options' => $tids,
    );

    // i don't think we need this, but leave it in case
    if (false) {
      $form['skip_tids'] = array(
        '#type' => 'checkboxes',
        '#title' => t('Do not change these values'),
        '#options' => $tids,
      );
    }
  }

  return $form;

}

/**
 * Validation function for update Status taxonomy action form.
 *
 * @see op_common_update_node_status_action_form()
 */
function op_common_update_node_status_action_validate($form, $form_state) {
  // dpm(__FUNCTION__);
  // dpm(array('form'=>$form, 'form_state'=>$form_state));

  if (empty($form_state['values']['field'])) {
    form_set_error('field', t('no field name found'));
  }
  if (empty($form_state['values']['tid'])) {
    form_set_error('taxonomy', t('choose a new term'));
  }
}

/**
 * Submit function for update Status taxonomy action form.
 *
 * @see op_common_update_node_status_action_form()
 */
function op_common_update_node_status_action_submit($form, $form_state) {
  $params = array();
  foreach ($form_state['values'] as $k => $v) {
    $params[$k] = $v;
  }
  return $params;
}

/**
 * Action function.
 *
 * Update the Status taxonomy value of a node.
 * The specific taxonomy should be identified by the context.
 */
function op_common_update_node_status_action(&$node, $context) {
  // in this case, $object is the $node
  // dpm(array('object'=>$node, 'context'=>$context), __FUNCTION__);

  if (empty($context['field'])) {
    $msg = t('No field name defined');
    drupal_set_message($msg, 'error');
    watchdog('op_common', $msg, null, WATCHDOG_ERROR);
    return;
  }
  $field = $context['field'];

  if (empty($context['tid'])) {
    $msg = t('No taxonomy term defined');
    drupal_set_message($msg, 'error');
    watchdog('op_common', $msg, null, WATCHDOG_ERROR);
    return;
  }

  $new_tid = $context['tid'];
  $new_term = taxonomy_term_load($new_tid);
  $vocabulary = taxonomy_vocabulary_load($new_term->vid);
  $tree = taxonomy_get_tree($vocabulary->vid);
  $terms = array();
  foreach ($tree as $term) {
    $terms[$term->tid] = $term;
  }

  $skip_tids = isset($row['skip_tids']) ? $row['skip_tids'] : array();

  $log = null;

  if (empty($node->{$field}[$node->language][0]['tid'])) {
    $log = t(
      'set %field (%voc) to !newtid:%newname'
      , array(
        '%field' => $field,
        '%voc' => $vocabulary->name,
        '!newtid' => $new_tid,
        '%newname' => $new_term->name,
      )
    );
    $node->{$field}[$node->language][0]['tid'] = $new_tid;
  }
  else {
    $old_tid = $node->{$field}[$node->language][0]['tid'];
    if (isset($terms[$old_tid])) {
      $old_term = $terms[$old_tid];
    }
    else {
      dpm($terms, "No entry found in terms for {$old_tid}");
    }
    if ($old_tid == $new_tid) {
      // already got one, it's verra nice
      drupal_set_message(t('already set correctly %voc term !oldtid:%oldname on !nid (%title)', array('%voc' => $vocabulary->name, '!oldtid' => $old_tid, '%oldname' => $old_term->name, '!nid' => $node->nid, '%title' => $node->title)), 'status');
    }
    elseif (isset($skip_tids[$old_tid])) {
      drupal_set_message(t('skipping %voc term !oldtid:%oldname on !nid (%title)', array('%voc' => $vocabulary->name, '!oldtid' => $old_tid, '%oldname' => $old_term->name, '!nid' => $node->nid, '%title' => $node->title)), 'status');
    }
    else {
      $log = t(
        'change %field (%voc) from !oldtid:%oldname to !newtid:%newname'
        , array(
          '%field' => $field,
          '%voc' => $vocabulary->name,
          '!oldtid' => $old_tid,
          '%oldname' => $old_term->name,
          '!newtid' => $new_tid,
          '%newname' => $new_term->name,
        )
      );
      $node->{$field}[$node->language][0]['tid'] = $new_tid;
    }
  }

  if ($log) {
    drupal_set_message(t('Update node !nid (%title) !log', array('!nid' => $node->nid, '%title' => $node->title, '!log' => $log)), 'status');
    $node->log = $log;
    $node->revision = true;
    // do not send notifications
    subscriptions_content_suppress_notifications(TRUE);
    $node->subscriptions_notify = FALSE;
  }
}

/**
 * Configuration form for update node comment status action.
 *
 * @see op_common_update_node_comment_action()
 */
function op_common_update_node_comment_action_form($context) {
  global $user;

  // Drupal 6  Drupal 7  Value
  // COMMENT_NODE_DISABLED   COMMENT_NODE_HIDDEN   0
  // COMMENT_NODE_READ_ONLY  COMMENT_NODE_CLOSED   1
  // COMMENT_NODE_READ_WRITE   COMMENT_NODE_OPEN   2

  $default = COMMENT_NODE_OPEN;

  if (isset($context['view']->filter['type']->value[0])) {
    $type = $context['view']->filter['type']->value[0];
    $default = variable_get('comment_' . $type, $default);
  }
  else {
    drupal_set_message("No content type filter value available from view {$context['view']->name}", 'error');
  }

  $default = (int) $default;

  $form['comment'] = array(
    '#type' => 'radios',
    '#title' => 'Comment setting',
    '#default_value' => $default,
    '#options' => array(t('Hidden'), t('Closed'), t('Open')),
  );

  return $form;

}

/**
 * Validate configuration form for update node comment status action.
 *
 * @see op_common_update_node_comment_action_form()
 */
function op_common_update_node_comment_action_validate($form, $form_state) {

  if (!isset($form_state['values']['comment'])) {
    form_set_error('comment', t('Choose a comment status'));
  }
  else {
    $comment = $form_state['values']['comment'];
    if (!is_numeric($comment)) {
      form_set_error('comment', t('Non-numeric comment status %comment', array('%comment' => $comment)));
    }
    $comment = (int) $comment;
    if (!in_array($comment, array(0, 1, 2))) {
      form_set_error('comment', t('Invalid comment status %comment', array('%comment' => $comment)));
    }
  }
}

/**
 * Process submitted configuration form for update node comment status action.
 *
 * @see op_common_update_node_comment_action_form()
 */
function op_common_update_node_comment_action_submit($form, $form_state) {
  $params = array();
  foreach ($form_state['values'] as $k => $v) {
    $params[$k] = $v;
  }
  return $params;
}

/**
 * Action function.
 *
 * Update the comment status of a node.
 */
function op_common_update_node_comment_action(&$node, $context) {
  // dpm(array('object'=>$node, 'context'=>$context), __FUNCTION__);

  if (!isset($context['comment'])) {
    $msg = t('No comment status values defined');
    drupal_set_message($msg, 'error');
    watchdog('op_common', $msg, null, WATCHDOG_ERROR);
    return;
  }
  $new_comment_status = (int)$context['comment'];
  $options = array(t('Hidden'), t('Closed'), t('Open'));
  $log = null;
  if ($node->comment != $new_comment_status) {
    $log = t(
      'change comment setting from %oldcn (!oldcv) to %newcn (!newcv)'
      , array(
        '%oldcn' => $options[$node->comment],
        '!oldcv' => $node->comment,
        '%newcn' => $options[$new_comment_status],
        '!newcv' => $new_comment_status,
      )
    );
    $node->comment = $new_comment_status;
  }
  else {
    drupal_set_message(t('No change to node !nid (%title)', array('!nid' => $node->nid, '%title' => $node->title)), 'status');
  }

  if ($log) {
    drupal_set_message(t('Update node !nid (%title) !log', array('!nid' => $node->nid, '%title' => $node->title, '!log' => $log)), 'status');
    $node->revision = true;
    $node->log = $log;
    // do not send notifications
    subscriptions_content_suppress_notifications(TRUE);
    $node->subscriptions_notify = FALSE;
  }
}

/**
 * Configuration form for update node rate_expiration action.
 *
 * @see op_common_update_node_rate_expiration_action()
 */
function op_common_update_node_rate_expiration_action_form($context) {

  $form['rate_expiration'] = array(
    '#type' => 'textfield',
    '#title' => t('Voting closing date'),
    '#default_value' => '',
    '#description' => t('Enter a valid date string. No strict format required. You can enter a past date to immediately close voting on the selected content.'),
  );

  return $form;

}

/**
 * Validate configuration form for update node rate_expiration action.
 *
 * @see op_common_update_node_rate_expiration_action_form()
 */
function op_common_update_node_rate_expiration_action_validate($form, $form_state) {

  if (empty($form_state['values']['rate_expiration'])) {
    form_set_error('rate_expiration', t('Choose a closing date'));
  }
  else {
    $rate_expiration = $form_state['values']['rate_expiration'];
    if (!strtotime($rate_expiration)) {
      form_set_error('rate_expiration', t('Invalid closing date %rate_expiration', array('%rate_expiration' => $rate_expiration)));
    }
  }
}

/**
 * Process submitted configuration form for update node rate_expiration status action.
 *
 * @see op_common_update_node_rate_expiration_action_form()
 */
function op_common_update_node_rate_expiration_action_submit($form, $form_state) {
  $params = array();
  foreach ($form_state['values'] as $k => $v) {
    $params[$k] = $v;
  }
  return $params;
}

/**
 * Action function.
 *
 * Update the rate_expiration status of a node.
 */
function op_common_update_node_rate_expiration_action(&$node, $context) {
  // dpm(array('object'=>$node, 'context'=>$context), __FUNCTION__);

  $log = '';
  if (!empty($context['rate_expiration'])) {
    $rate_expiration = $context['rate_expiration'];
    // we don't CARE about timezones, Mr. Rate. oy.
    if ($ts = strtotime($rate_expiration . ' UTC')) {
      $widgets = rate_get_active_widgets('node', $node->type, 'full');
      foreach ($widgets as $widget_id => $widget) {
        $begin = 'rate_expiration_' . $widget->name . '_begin';
        $end = 'rate_expiration_' . $widget->name . '_end';
        $endts = max($ts, $node->created);
        $node->{$begin} = date('r', $node->created);
        $node->{$end} = date('r', $endts);
        $log .= t(
        'change !widget voting closing date to %expdt (!expts)'
        , array(
          '!widget' => $widget->name,
          '%expdt' => $node->{$end},
          '!expts' => $endts,
        )
      );
      }
      rate_expiration_node_update($node);
    }
  }

  if ($log) {
    drupal_set_message(t('Update node !nid (%title) !log', array('!nid' => $node->nid, '%title' => $node->title, '!log' => $log)), 'status');
    $node->revision = true;
    $node->log = $log;
    // do not send notifications
    subscriptions_content_suppress_notifications(TRUE);
    $node->subscriptions_notify = FALSE;
  }
  else {
    drupal_set_message(t('No change to node !nid (%title)', array('!nid' => $node->nid, '%title' => $node->title)), 'status');
  }
}
