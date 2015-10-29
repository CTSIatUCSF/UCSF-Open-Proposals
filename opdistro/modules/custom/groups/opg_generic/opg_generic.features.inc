<?php
/**
 * @file
 * opg_generic.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function opg_generic_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function opg_generic_node_info() {
  $items = array(
    'opg_generic' => array(
      'name' => t('OPG Generic'),
      'base' => 'node_content',
      'description' => t('GenericGroupForumTitle GenericGroupForumNouns'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
