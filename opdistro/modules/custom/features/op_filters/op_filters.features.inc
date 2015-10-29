<?php
/**
 * @file
 * op_filters.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function op_filters_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
