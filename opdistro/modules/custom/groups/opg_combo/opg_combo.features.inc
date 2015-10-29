<?php
/**
 * @file
 * opg_combo.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function opg_combo_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function opg_combo_node_info() {
  $items = array(
    'opg_combo_group' => array(
      'name' => t('OPG Combo Group'),
      'base' => 'node_content',
      'description' => t('A group representing an opportunity with multiple phases, each of which is itself a forum group.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
