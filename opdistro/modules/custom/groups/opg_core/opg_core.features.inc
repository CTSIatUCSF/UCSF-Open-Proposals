<?php
/**
 * @file
 * opg_core.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function opg_core_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "boxes" && $api == "box") {
    return array("version" => "1");
  }
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function opg_core_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function opg_core_node_info() {
  $items = array(
    'opg_admin_post' => array(
      'name' => t('Announcement'),
      'base' => 'node_content',
      'description' => t('Basically just a flavor of Page, used for special announcement posts in OG based forums.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'opg_default_group' => array(
      'name' => t('OPG Default Group'),
      'base' => 'node_content',
      'description' => t('Universal groups that all registered users are made members of by default.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'opg_group' => array(
      'name' => t('OPG Group'),
      'base' => 'node_content',
      'description' => t('The main content type for Organic Groups based forums.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('<p class="description explanation">Recommended maximum lengths - Title: 55 characters / Subtitle: 75 characters</p>'),
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
