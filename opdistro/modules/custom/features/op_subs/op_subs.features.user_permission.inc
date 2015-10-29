<?php
/**
 * @file
 * op_subs.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function op_subs_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer user subscriptions'.
  $permissions['administer user subscriptions'] = array(
    'name' => 'administer user subscriptions',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'subscriptions',
  );

  // Exported permission: 'bulk-administer user subscriptions'.
  $permissions['bulk-administer user subscriptions'] = array(
    'name' => 'bulk-administer user subscriptions',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'subscriptions',
  );

  // Exported permission: 'subscribe to all content types'.
  $permissions['subscribe to all content types'] = array(
    'name' => 'subscribe to all content types',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'subscriptions',
  );

  // Exported permission: 'subscribe to content'.
  $permissions['subscribe to content'] = array(
    'name' => 'subscribe to content',
    'roles' => array(
      'admin' => 'admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'subscriptions',
  );

  // Exported permission: 'subscribe to content types'.
  $permissions['subscribe to content types'] = array(
    'name' => 'subscribe to content types',
    'roles' => array(
      'admin' => 'admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'subscriptions',
  );

  // Exported permission: 'suspend own subscriptions'.
  $permissions['suspend own subscriptions'] = array(
    'name' => 'suspend own subscriptions',
    'roles' => array(
      'admin' => 'admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'subscriptions',
  );

  return $permissions;
}
