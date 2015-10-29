<?php

/**
 * Implements hook_views_data().
 */
function opg_core_views_data() {
  $data['opg_core']['table']['group'] = t('OPG');
  $data['opg_core']['table']['join'] = array(
    // Exist in all views.
    '#global' => array(),
  );
 
  $data['opg_core']['opg_current_uid'] = array(
    'title' => t('OPG: current UID'),
    'help' => t('Open Proposal Groups custom field returns the current user ID.'),
    'field' => array(
      'handler' => 'views_handler_opg_current_uid',
    ),
  );
 
  return $data;
}

