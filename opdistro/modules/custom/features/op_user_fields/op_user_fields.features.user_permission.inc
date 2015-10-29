<?php
/**
 * @file
 * op_user_fields.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function op_user_fields_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'delete terms in departments'.
  $permissions['delete terms in departments'] = array(
    'name' => 'delete terms in departments',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in schools'.
  $permissions['delete terms in schools'] = array(
    'name' => 'delete terms in schools',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in departments'.
  $permissions['edit terms in departments'] = array(
    'name' => 'edit terms in departments',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in schools'.
  $permissions['edit terms in schools'] = array(
    'name' => 'edit terms in schools',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'taxonomy',
  );

  return $permissions;
}
