<?php
/**
 * @file
 * opg_combo.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function opg_combo_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create opg_combo_group content'.
  $permissions['create opg_combo_group content'] = array(
    'name' => 'create opg_combo_group content',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any opg_combo_group content'.
  $permissions['delete any opg_combo_group content'] = array(
    'name' => 'delete any opg_combo_group content',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own opg_combo_group content'.
  $permissions['delete own opg_combo_group content'] = array(
    'name' => 'delete own opg_combo_group content',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any opg_combo_group content'.
  $permissions['edit any opg_combo_group content'] = array(
    'name' => 'edit any opg_combo_group content',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own opg_combo_group content'.
  $permissions['edit own opg_combo_group content'] = array(
    'name' => 'edit own opg_combo_group content',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'node',
  );

  return $permissions;
}
