<?php
/**
 * @file
 * op_permits.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function op_permits_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
