<?php
/**
 * @file
 * op_subs.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function op_subs_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['boxes-op_subs_anon_node'] = array(
    'cache' => -2,
    'custom' => 0,
    'delta' => 'op_subs_anon_node',
    'module' => 'boxes',
    'node_types' => array(),
    'pages' => 'goto/subscribe/add/node/*',
    'roles' => array(
      'admin' => 3,
      'anonymous user' => 1,
    ),
    'themes' => array(
      'opbamboo' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'opbamboo',
        'weight' => 150,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['boxes-op_subs_anon_type'] = array(
    'cache' => -2,
    'custom' => 0,
    'delta' => 'op_subs_anon_type',
    'module' => 'boxes',
    'node_types' => array(),
    'pages' => 'goto/subscribe/add/type/*',
    'roles' => array(
      'admin' => 3,
      'anonymous user' => 1,
    ),
    'themes' => array(
      'opbamboo' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'opbamboo',
        'weight' => 149,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['boxes-op_subs_auth'] = array(
    'cache' => -2,
    'custom' => 0,
    'delta' => 'op_subs_auth',
    'module' => 'boxes',
    'node_types' => array(),
    'pages' => 'subscriptions/add/*',
    'roles' => array(),
    'themes' => array(
      'opbamboo' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'opbamboo',
        'weight' => 151,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  return $export;
}
