<?php

/**
 * Implements hook_action_info().
 *
 * Defines custom actions for use with Views Bulk Operations views.
 */
function opg_core_action_info() {

  $actions = array();

  $actions['opg_core_update_node_status_action'] = array(
    'type' => 'node',
    'label' => 'OPG: Update the status of the selected items',
    'configurable' => true,
    'triggers' => array(
      'any' => true,
    ),
    'behavior' => array('changes_property'),
  );

  $actions['opg_core_update_node_comment_action'] = array(
    'type' => 'node',
    'label' => 'OPG: Update the comment setting of the selected items',
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
 * @see opg_core_update_node_status_action()
 */
function opg_core_update_node_status_action_form($context) {
  global $user;
  // dpm($context, __FUNCTION__);

  $form = array();

  if ($group = _opg_core_action_load_group($context)) {
    $wrapper = entity_metadata_wrapper('node', $group['entity']);
  }
  else {
    return $form;
  }

  if (isset($wrapper->field_opg_status_voc)) {
    $vid = $wrapper->field_opg_status_voc->raw();
  }
  if (empty($vid)) {
    _opg_core_action_report("No status vocabulary ID available from group #{$gid} for view {$context['view']->name}");
    return $form;
  }

  if ($vocabulary = taxonomy_vocabulary_load($vid)) {
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
  else {
    _opg_core_action_report("Invalid status vocabulary ID {$vid} from group #{$gid} for view {$context['view']->name}");
  }

  return $form;

}

/**
 * Validation function for update Status taxonomy action form.
 *
 * @see opg_core_update_node_status_action_form()
 */
function opg_core_update_node_status_action_validate($form, $form_state) {
  // dpm(__FUNCTION__);
  // dpm(array('form'=>$form, 'form_state'=>$form_state));

  if (empty($form_state['values']['tid'])) {
    form_set_error('taxonomy', t('choose a new term'));
  }
}

/**
 * Submit function for update Status taxonomy action form.
 *
 * @see opg_core_update_node_status_action_form()
 */
function opg_core_update_node_status_action_submit($form, $form_state) {
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
function opg_core_update_node_status_action(&$node, $context) {

  if (empty($context['tid'])) {
    _opg_core_action_report('No taxonomy term defined');
    return;
  }
  $wrapper = entity_metadata_wrapper('node', $node);
  if (!isset($wrapper->field_opg_status)) {
    _opg_core_action_report('Core OPG status field not defined');
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

  $old_tid = $wrapper->field_opg_status->raw();
  if (empty($old_tid)) {
    $log = t(
      'set status (%voc) to !newtid:%newname'
      , array(
        '%voc' => $vocabulary->name,
        '!newtid' => $new_tid,
        '%newname' => $new_term->name,
      )
    );
    $wrapper->field_opg_status->set($new_tid);
  }
  else {
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
        'change status (%voc) from !oldtid:%oldname to !newtid:%newname'
        , array(
          '%voc' => $vocabulary->name,
          '!oldtid' => $old_tid,
          '%oldname' => $old_term->name,
          '!newtid' => $new_tid,
          '%newname' => $new_term->name,
        )
      );
      $wrapper->field_opg_status->set($new_tid);
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
 * @see opg_core_update_node_comment_action()
 */
function opg_core_update_node_comment_action_form($context) {
  global $user;

  $form = array();

  // Drupal 6  Drupal 7  Value
  // COMMENT_NODE_DISABLED   COMMENT_NODE_HIDDEN   0
  // COMMENT_NODE_READ_ONLY  COMMENT_NODE_CLOSED   1
  // COMMENT_NODE_READ_WRITE   COMMENT_NODE_OPEN   2

  $default = COMMENT_NODE_OPEN;

  // honestly we don't need to fail if this fails
  if ($group = _opg_core_action_load_group($context)) {
    $wrapper = entity_metadata_wrapper('node', $group['entity']);
    if (isset($wrapper->field_opg_post_type) and $post_type = $wrapper->field_opg_post_type->raw()) {
      $default = variable_get('comment_' . $post_type, $default);
    }
  }

  $default = (int) $default;

  $form['comment'] = array(
    '#type' => 'radios',
    '#title' => 'Comment setting',
    '#default_value' => $default,
    '#options' => array(
      COMMENT_NODE_HIDDEN => t('Hidden'),
      COMMENT_NODE_CLOSED => t('Closed'),
      COMMENT_NODE_OPEN => t('Open'),
    ),
  );

  return $form;

}

/**
 * Validate configuration form for update node comment status action.
 *
 * @see opg_core_update_node_comment_action_form()
 */
function opg_core_update_node_comment_action_validate($form, $form_state) {

  if (!isset($form_state['values']['comment'])) {
    form_set_error('comment', t('Choose a comment status'));
  }
  else {
    $comment = $form_state['values']['comment'];
    if (!is_numeric($comment)) {
      form_set_error('comment', t('Non-numeric comment status %comment', array('%comment' => $comment)));
    }
    $comment = (int) $comment;
    if (!in_array($comment, array(COMMENT_NODE_HIDDEN, COMMENT_NODE_CLOSED, COMMENT_NODE_OPEN))) {
      form_set_error('comment', t('Invalid comment status %comment', array('%comment' => $comment)));
    }
  }
}

/**
 * Process submitted configuration form for update node comment status action.
 *
 * @see opg_core_update_node_comment_action_form()
 */
function opg_core_update_node_comment_action_submit($form, $form_state) {
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
function opg_core_update_node_comment_action(&$node, $context) {
  // dpm(array('object'=>$node, 'context'=>$context), __FUNCTION__);

  if (!isset($context['comment'])) {
    _opg_core_action_report('No comment status values defined');
    return;
  }
  $new_comment_status = (int)$context['comment'];
  $options = array(
    COMMENT_NODE_HIDDEN => t('Hidden'),
    COMMENT_NODE_CLOSED => t('Closed'),
    COMMENT_NODE_OPEN => t('Open'),
  );
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
 * Display an error and log it with watchdog()
 */
function _opg_core_action_report($msg, $status=WATCHDOG_ERROR) {
  $levels = array(
    WATCHDOG_EMERGENCY => 'error',
    WATCHDOG_ALERT => 'error',
    WATCHDOG_CRITICAL => 'error',
    WATCHDOG_ERROR => 'error',
    WATCHDOG_WARNING => 'warning',
    WATCHDOG_NOTICE => 'warning',
    WATCHDOG_INFO => 'status',
    WATCHDOG_DEBUG => 'status',
  );
  if (!isset($levels[$status])) $status = WATCHDOG_ERROR;
  drupal_set_message($msg, $levels[$status]);
  watchdog('opg_core', $msg, null, $status);
}

/**
 * Load Organic Group info from context
 */
function _opg_core_action_load_group($context) {
  $group = FALSE;

  if (empty($context['view'])) {
    _opg_core_action_report('No view available from context');
    return $group;
  }

  if (empty($context['view']->args[0])) {
    _opg_core_action_report('No group ID argument available from view ' . $context['view']->name);
    return $group;
  }

  $gid = $context['view']->args[0];
  if ($group_node = node_load($gid)) {
    if (og_is_group('node', $group_node)) {
      $group = array('group_type' => 'node', 'gid' => $gid, 'entity' => $group_node);
    }
    else {
      _opg_core_action_report("Invalid group ID argument {$gid} from view {$context['view']->name} - node is not an OG group");
    }
  }
  else {
    // dpm(compact('context','gid','group_node'), __FUNCTION__ . ' wtf?');
    _opg_core_action_report("Unable to load node {$gid} from arguments to view {$context['view']->name}");
  }

  return $group;

}
