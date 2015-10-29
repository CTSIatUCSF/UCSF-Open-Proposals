<?php
/**
 * @file
 * op_permits.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function op_permits_user_default_roles() {
  $roles = array();

  // Exported role: OP Manager.
  $roles['OP Manager'] = array(
    'name' => 'OP Manager',
    'weight' => 4,
  );

  // Exported role: admin.
  $roles['admin'] = array(
    'name' => 'admin',
    'weight' => 0,
  );

  // Exported role: test.
  $roles['test'] = array(
    'name' => 'test',
    'weight' => 6,
  );

  return $roles;
}
