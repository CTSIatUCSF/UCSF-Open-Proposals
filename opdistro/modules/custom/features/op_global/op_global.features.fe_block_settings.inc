<?php
/**
 * @file
 * op_global.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function op_global_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['boxes-ctsi_acknowledgement'] = array(
    'cache' => -2,
    'custom' => 0,
    'delta' => 'ctsi_acknowledgement',
    'module' => 'boxes',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'opbamboo' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'opbamboo',
        'weight' => 115,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['boxes-ctsi_tagline_banner'] = array(
    'cache' => -2,
    'custom' => 0,
    'delta' => 'ctsi_tagline_banner',
    'module' => 'boxes',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'opbamboo' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'opbamboo',
        'weight' => 76,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['boxes-op_admin_info'] = array(
    'cache' => -2,
    'custom' => 0,
    'delta' => 'op_admin_info',
    'module' => 'boxes',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(
      'admin' => 3,
    ),
    'themes' => array(
      'opbamboo' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'opbamboo',
        'weight' => 145,
      ),
    ),
    'title' => 'About This Site',
    'visibility' => 0,
  );

  $export['boxes-op_global_footer_ctsi'] = array(
    'cache' => -2,
    'custom' => 0,
    'delta' => 'op_global_footer_ctsi',
    'module' => 'boxes',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'opbamboo' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'opbamboo',
        'weight' => 153,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['boxes-op_global_node_create'] = array(
    'cache' => -2,
    'custom' => 0,
    'delta' => 'op_global_node_create',
    'module' => 'boxes',
    'node_types' => array(),
    'pages' => '*/create',
    'roles' => array(),
    'themes' => array(
      'opbamboo' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'opbamboo',
        'weight' => 147,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['boxes-op_global_right_header'] = array(
    'cache' => -2,
    'custom' => 0,
    'delta' => 'op_global_right_header',
    'module' => 'boxes',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'opbamboo' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'opbamboo',
        'weight' => 156,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['boxes-op_global_vote_login'] = array(
    'cache' => -2,
    'custom' => 0,
    'delta' => 'op_global_vote_login',
    'module' => 'boxes',
    'node_types' => array(),
    'pages' => '*/login-to-vote',
    'roles' => array(),
    'themes' => array(
      'opbamboo' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'opbamboo',
        'weight' => 148,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['boxes-open_proposals_lp_logo'] = array(
    'cache' => -2,
    'custom' => 0,
    'delta' => 'open_proposals_lp_logo',
    'module' => 'boxes',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'opbamboo' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'opbamboo',
        'weight' => 152,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['boxes-open_proposals_lp_navbar'] = array(
    'cache' => -2,
    'custom' => 0,
    'delta' => 'open_proposals_lp_navbar',
    'module' => 'boxes',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'opbamboo' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'opbamboo',
        'weight' => 155,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['boxes-poweredby'] = array(
    'cache' => -2,
    'custom' => 0,
    'delta' => 'poweredby',
    'module' => 'boxes',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'opbamboo' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'opbamboo',
        'weight' => 123,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['boxes-ucsf_copyright'] = array(
    'cache' => -2,
    'custom' => 0,
    'delta' => 'ucsf_copyright',
    'module' => 'boxes',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'opbamboo' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'opbamboo',
        'weight' => 224,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['boxes-ucsf_top_banner'] = array(
    'cache' => -2,
    'custom' => 0,
    'delta' => 'ucsf_top_banner',
    'module' => 'boxes',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'opbamboo' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'opbamboo',
        'weight' => 435,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-help'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'help',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'opbamboo' => array(
        'region' => 'help',
        'status' => 1,
        'theme' => 'opbamboo',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-main'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'main',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'opbamboo' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'opbamboo',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-main-menu'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'main-menu',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'opbamboo' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'opbamboo',
        'weight' => 141,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-management'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'management',
    'module' => 'system',
    'node_types' => array(),
    'pages' => 'navigation',
    'roles' => array(),
    'themes' => array(
      'opbamboo' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'opbamboo',
        'weight' => 142,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['system-navigation'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'navigation',
    'module' => 'system',
    'node_types' => array(),
    'pages' => 'navigation',
    'roles' => array(),
    'themes' => array(
      'opbamboo' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'opbamboo',
        'weight' => 144,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['system-powered-by'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'powered-by',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'opbamboo' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'opbamboo',
        'weight' => 169,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-user-menu'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'user-menu',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'opbamboo' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'opbamboo',
        'weight' => 226,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['tagadelic_taxonomy-tagadelic_taxonomy'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'tagadelic_taxonomy',
    'module' => 'tagadelic_taxonomy',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'opbamboo' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'opbamboo',
        'weight' => 197,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['user-login'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'login',
    'module' => 'user',
    'node_types' => array(),
    'pages' => 'navigation',
    'roles' => array(),
    'themes' => array(
      'opbamboo' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'opbamboo',
        'weight' => 225,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['user-new'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'new',
    'module' => 'user',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'opbamboo' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'opbamboo',
        'weight' => 429,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['user-online'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'online',
    'module' => 'user',
    'node_types' => array(),
    'pages' => 'admin/people',
    'roles' => array(),
    'themes' => array(
      'opbamboo' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'opbamboo',
        'weight' => 430,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  return $export;
}
