<?php
/**
 * @file
 * opg_core.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function opg_core_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['boxes-opg_group_adminmember_nav'] = array(
    'cache' => -2,
    'custom' => 0,
    'delta' => 'opg_group_adminmember_nav',
    'module' => 'boxes',
    'node_types' => array(),
    'pages' => 'group/node/*/admin/*',
    'roles' => array(),
    'themes' => array(
      'opbamboo' => array(
        'region' => 'content_after_title',
        'status' => 1,
        'theme' => 'opbamboo',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['opg_core-opg_core_taxo_block'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'opg_core_taxo_block',
    'module' => 'opg_core',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'opbamboo' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'opbamboo',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-opg_core-active_block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'opg_core-active_block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'opbamboo' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'opbamboo',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-opg_core-adminpost_block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'opg_core-adminpost_block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'opbamboo' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'opbamboo',
        'weight' => 8,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-opg_core-comments_block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'opg_core-comments_block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'opbamboo' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'opbamboo',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-opg_core-my_block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'opg_core-my_block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'opbamboo' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'opbamboo',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-opg_core-popular_block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'opg_core-popular_block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'opbamboo' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'opbamboo',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-opg_core-recent_block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'opg_core-recent_block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'opbamboo' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'opbamboo',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-opg_core-recent_pageblock'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'opg_core-recent_pageblock',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'opbamboo' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'opbamboo',
        'weight' => 10,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-opg_core_fields-body_block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'opg_core_fields-body_block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'opbamboo' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'opbamboo',
        'weight' => 6,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-opg_core_fields-logo_block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'opg_core_fields-logo_block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'opbamboo' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'opbamboo',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-opg_core_fields-navbar_block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'opg_core_fields-navbar_block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'opbamboo' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'opbamboo',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-opg_core_fields-navblock_block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'opg_core_fields-navblock_block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'opbamboo' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'opbamboo',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-opg_core_fields-poweredby_block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'opg_core_fields-poweredby_block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'opbamboo' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'opbamboo',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-opg_core_fields-r_header_block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'opg_core_fields-r_header_block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'opbamboo' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'opbamboo',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-opg_core_fields-sublogin_block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'opg_core_fields-sublogin_block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'opbamboo' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'opbamboo',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
