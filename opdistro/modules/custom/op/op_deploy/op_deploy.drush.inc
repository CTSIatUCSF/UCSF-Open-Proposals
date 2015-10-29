<?php

/**
 * @file
 *   Drush commands for OP feature deployment.
 */

/**
 * Implementation of hook_drush_command().
 *
 * @return
 *   An associative array describing your command(s).
 */
function op_deploy_drush_command() {
  $items = array();

  // The 'op-create-terms' command
  $items['op-create-terms'] = array(
    'description' => "Create taxonomy terms for an OP forum feature if they do not already exist.",
    'arguments' => array(
      'feature_name' => 'The name of the OP forum feature.',
    ),
    'examples' => array(
      'drush op-create-terms op_generic' => 'Create terms for the "op_generic" forum feature if none exist.',
    ),
  );

  // The 'op-export-terms' command
  $items['op-export-terms'] = array(
    'description' => "Export taxonomy terms for an OP forum feature.",
    'arguments' => array(
      'feature_name' => 'The name of the OP forum feature.',
    ),
    'examples' => array(
      'drush op-export-terms op_generic' => 'Export terms for the "op_generic" forum feature.',
    ),
  );

  return $items;
}



/**
 * Implementation of hook_drush_help().
 *
 * @param
 *   A string with the help section (prepend with 'drush:')
 *
 * @return
 *   A string with the help text for your command.
 */
function op_deploy_drush_help($section) {
  switch ($section) {
    case 'drush:op-create-terms':
      return dt("This command will create a set of taxonomy terms for a feature module, if none exist and if the set has been defined by the feature module.");
    case 'drush:op-export-terms':
      return dt("This command will export a set of taxonomy terms for a feature module.");
  }
}

/**
 * Create terms command callback. 
 *
 * @see drush_invoke()
 * @see drush.api.php
 */
function drush_op_deploy_op_create_terms($feature_name='') {

  if (empty($feature_name)) {
    return drush_set_error(dt('Feature name not supplied'));
  }
  if (!module_exists($feature_name)) {
    return drush_set_error(dt('Feature module ' . $feature_name .' not enabled'));
  }
  op_deploy_load_op_terms($feature_name);
}

/**
 * Export terms command callback. 
 *
 * @see drush_invoke()
 * @see drush.api.php
 */
function drush_op_deploy_op_export_terms($feature_name='') {

  if (empty($feature_name)) {
    return drush_set_error(dt('Feature name not supplied'));
  }
  if (!module_exists($feature_name)) {
    return drush_set_error(dt('Feature module ' . $feature_name .' not enabled'));
  }
  op_deploy_export_op_terms($feature_name);
}
