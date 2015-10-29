<?php
/**
 * @file
 * opg_generic.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function opg_generic_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:opg_default_group:create opg_generic content'
  $permissions['node:opg_default_group:create opg_generic content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_default_group:delete any opg_generic content'
  $permissions['node:opg_default_group:delete any opg_generic content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_default_group:delete own opg_generic content'
  $permissions['node:opg_default_group:delete own opg_generic content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_default_group:update any opg_generic content'
  $permissions['node:opg_default_group:update any opg_generic content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_default_group:update own opg_generic content'
  $permissions['node:opg_default_group:update own opg_generic content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_group:create opg_generic content'
  $permissions['node:opg_group:create opg_generic content'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_group:delete any opg_generic content'
  $permissions['node:opg_group:delete any opg_generic content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_group:delete own opg_generic content'
  $permissions['node:opg_group:delete own opg_generic content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_group:update any opg_generic content'
  $permissions['node:opg_group:update any opg_generic content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_group:update own opg_generic content'
  $permissions['node:opg_group:update own opg_generic content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  return $permissions;
}
