<?php
/**
 * @file
 * op_saml_settings.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function op_saml_settings_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
