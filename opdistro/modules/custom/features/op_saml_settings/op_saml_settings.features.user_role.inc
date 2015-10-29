<?php
/**
 * @file
 * op_saml_settings.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function op_saml_settings_user_default_roles() {
  $roles = array();

  // Exported role: SAML.
  $roles['SAML'] = array(
    'name' => 'SAML',
    'weight' => 5,
  );

  return $roles;
}
