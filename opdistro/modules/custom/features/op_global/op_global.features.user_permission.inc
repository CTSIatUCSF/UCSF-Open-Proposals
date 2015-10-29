<?php
/**
 * @file
 * op_global.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function op_global_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'use Javascript for custom beautytip display'.
  $permissions['use Javascript for custom beautytip display'] = array(
    'name' => 'use Javascript for custom beautytip display',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'beautytips_manager',
  );

  return $permissions;
}
