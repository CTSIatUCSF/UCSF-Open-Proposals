<?php
/**
 * @file
 * opg_generic.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function opg_generic_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create opg_generic content'.
  $permissions['create opg_generic content'] = array(
    'name' => 'create opg_generic content',
    'roles' => array(
      'admin' => 'admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any opg_generic content'.
  $permissions['delete any opg_generic content'] = array(
    'name' => 'delete any opg_generic content',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own opg_generic content'.
  $permissions['delete own opg_generic content'] = array(
    'name' => 'delete own opg_generic content',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any opg_generic content'.
  $permissions['edit any opg_generic content'] = array(
    'name' => 'edit any opg_generic content',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own opg_generic content'.
  $permissions['edit own opg_generic content'] = array(
    'name' => 'edit own opg_generic content',
    'roles' => array(
      'admin' => 'admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  return $permissions;
}
