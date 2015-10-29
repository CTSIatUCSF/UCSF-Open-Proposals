<?php
/**
 * @file
 * opg_core.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function opg_core_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'opg_core';
  $context->description = 'Open Proposal Groups standard context';
  $context->tag = 'opg';
  $context->conditions = array(
    'context_og_condition_group_type' => array(
      'values' => array(
        'opg_group' => 'opg_group',
      ),
      'options' => array(
        'node_form' => 1,
      ),
    ),
    'node' => array(
      'values' => array(
        'opg_group' => 'opg_group',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'nodetype_path' => array(
      'values' => array(
        'opg_group' => 'opg_group',
      ),
    ),
    'views' => array(
      'values' => array(
        'opg_core' => 'opg_core',
        'opg_core_reports' => 'opg_core_reports',
      ),
    ),
  );
  $context->reactions = array(
    'theme' => array(
      'title' => '',
      'subtitle' => '',
    ),
    'theme_html' => array(
      'class' => 'opg_core-section',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Open Proposal Groups standard context');
  t('opg');
  $export['opg_core'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'opg_core_content';
  $context->description = 'A node or content view (vs report views)';
  $context->tag = 'opg';
  $context->conditions = array(
    'opg_core_condition_node_group' => array(
      'values' => array(
        '_any_' => '_any_',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'opg_core_condition_node_group_content' => array(
      'values' => array(
        '_any_' => '_any_',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'views' => array(
      'values' => array(
        'opg_core' => 'opg_core',
        'opg_core_fields:aboutpage' => 'opg_core_fields:aboutpage',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('A node or content view (vs report views)');
  t('opg');
  $export['opg_core_content'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'opg_core_exclude';
  $context->description = 'Content types that should not be included in other OPG contexts';
  $context->tag = 'opg';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'opg_admin_post' => 'opg_admin_post',
        'opg_group' => 'opg_group',
        'page' => 'page',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Content types that should not be included in other OPG contexts');
  t('opg');
  $export['opg_core_exclude'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'opg_core_header';
  $context->description = 'Open Proposal Groups standard header context';
  $context->tag = 'opg';
  $context->conditions = array(
    'context_all' => array(
      'values' => array(
        'opg_core' => 'opg_core',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-opg_core_fields-logo_block' => array(
          'module' => 'views',
          'delta' => 'opg_core_fields-logo_block',
          'region' => 'brand',
          'weight' => '0',
        ),
        'views-opg_core_fields-poweredby_block' => array(
          'module' => 'views',
          'delta' => 'opg_core_fields-poweredby_block',
          'region' => 'top_links',
          'weight' => '1',
        ),
        'views-opg_core_fields-r_header_block' => array(
          'module' => 'views',
          'delta' => 'opg_core_fields-r_header_block',
          'region' => 'top_links',
          'weight' => '0',
        ),
        'views-opg_core_fields-navbar_block' => array(
          'module' => 'views',
          'delta' => 'opg_core_fields-navbar_block',
          'region' => 'main_menu',
          'weight' => '0',
        ),
      ),
    ),
    'disable_context' => array(
      'disabled' => array(
        'op_global_default' => 'op_global_default',
      ),
    ),
    'theme' => array(
      'title' => '',
      'subtitle' => '',
    ),
    'theme_html' => array(
      'class' => '',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Open Proposal Groups standard header context');
  t('opg');
  $export['opg_core_header'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'opg_core_home';
  $context->description = 'OPG group node page context';
  $context->tag = 'opg';
  $context->conditions = array(
    'context_og_condition_group_type' => array(
      'values' => array(
        'opg_group' => 'opg_group',
      ),
      'options' => array(
        'node_form' => 0,
      ),
    ),
    'node' => array(
      'values' => array(
        'opg_group' => 'opg_group',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-opg_core-adminpost_block' => array(
          'module' => 'views',
          'delta' => 'opg_core-adminpost_block',
          'region' => 'content',
          'weight' => '10',
        ),
        'views-opg_core-recent_pageblock' => array(
          'module' => 'views',
          'delta' => 'opg_core-recent_pageblock',
          'region' => 'content',
          'weight' => '12',
        ),
      ),
    ),
    'theme' => array(
      'title' => '',
      'subtitle' => '',
    ),
    'theme_html' => array(
      'class' => '',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('OPG group node page context');
  t('opg');
  $export['opg_core_home'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'opg_core_nodeform';
  $context->description = 'Open Proposal Group standard group content node form context';
  $context->tag = 'opg';
  $context->conditions = array(
    'context' => array(
      'values' => array(
        '~opg_core_exclude' => '~opg_core_exclude',
      ),
    ),
    'context_og_condition_group_type' => array(
      'values' => array(
        'opg_group' => 'opg_group',
      ),
      'options' => array(
        'node_form' => 1,
      ),
    ),
    'opg_core_condition_node_group_content' => array(
      'values' => array(
        '_any_' => '_any_',
      ),
      'options' => array(
        'node_form' => '2',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-44ac31ba6fbf7cb31f8f141e4cbdf240' => array(
          'module' => 'views',
          'delta' => '44ac31ba6fbf7cb31f8f141e4cbdf240',
          'region' => 'content_after_title',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Open Proposal Group standard group content node form context');
  t('opg');
  $export['opg_core_nodeform'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'opg_core_reviewer';
  $context->description = 'Context set when user has reviewer-level OG group role';
  $context->tag = 'opg';
  $context->conditions = array(
    'context_all' => array(
      'values' => array(
        'opg_core' => 'opg_core',
        'opg_core_content' => 'opg_core_content',
      ),
    ),
    'context_og_condition_member_role' => array(
      'values' => array(
        3 => 3,
        7 => 7,
      ),
      'options' => array(
        'node_form' => 0,
      ),
    ),
  );
  $context->reactions = array(
    'theme_html' => array(
      'class' => 'reviewer-only',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Context set when user has reviewer-level OG group role');
  t('opg');
  $export['opg_core_reviewer'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'opg_core_sidebar';
  $context->description = 'Open Proposal Groups standard sidebar layout context';
  $context->tag = 'opg';
  $context->conditions = array(
    'context_all' => array(
      'values' => array(
        'opg_core' => 'opg_core',
        'opg_core_content' => 'opg_core_content',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-opg_core_fields-navblock_block' => array(
          'module' => 'views',
          'delta' => 'opg_core_fields-navblock_block',
          'region' => 'sidebar_first',
          'weight' => '0',
        ),
        'opg_core-opg_core_taxo_block' => array(
          'module' => 'opg_core',
          'delta' => 'opg_core_taxo_block',
          'region' => 'sidebar_first',
          'weight' => '1',
        ),
        'views-opg_core-my_block' => array(
          'module' => 'views',
          'delta' => 'opg_core-my_block',
          'region' => 'sidebar_first',
          'weight' => '2',
        ),
        'views-opg_core-comments_block' => array(
          'module' => 'views',
          'delta' => 'opg_core-comments_block',
          'region' => 'sidebar_first',
          'weight' => '3',
        ),
        'views-opg_core-recent_block' => array(
          'module' => 'views',
          'delta' => 'opg_core-recent_block',
          'region' => 'sidebar_first',
          'weight' => '4',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Open Proposal Groups standard sidebar layout context');
  t('opg');
  $export['opg_core_sidebar'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'opg_core_subanon';
  $context->description = 'Open Proposal Groups anonymous subscription request';
  $context->tag = 'opg';
  $context->conditions = array(
    'context_all' => array(
      'values' => array(
        'opg_core' => 'opg_core',
      ),
    ),
    'path' => array(
      'values' => array(
        'goto/subscribe/*/group/*' => 'goto/subscribe/*/group/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-opg_core_fields-sublogin_block' => array(
          'module' => 'views',
          'delta' => 'opg_core_fields-sublogin_block',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Open Proposal Groups anonymous subscription request');
  t('opg');
  $export['opg_core_subanon'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'opg_sitewide_ucsf';
  $context->description = 'UCSF Open Proposal Groups blocks and such';
  $context->tag = 'opg';
  $context->conditions = array(
    'context_all' => array(
      'values' => array(
        'opg_core' => 'opg_core',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-ucsf_top_banner' => array(
          'module' => 'boxes',
          'delta' => 'ucsf_top_banner',
          'region' => 'ucsf_links',
          'weight' => '-9',
        ),
        'system-help' => array(
          'module' => 'system',
          'delta' => 'help',
          'region' => 'help',
          'weight' => '-10',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-10',
        ),
        'boxes-ctsi_acknowledgement' => array(
          'module' => 'boxes',
          'delta' => 'ctsi_acknowledgement',
          'region' => 'acknowledgement',
          'weight' => '-10',
        ),
        'system-user-menu' => array(
          'module' => 'system',
          'delta' => 'user-menu',
          'region' => 'footer_first',
          'weight' => '-10',
        ),
        'boxes-ucsf_copyright' => array(
          'module' => 'boxes',
          'delta' => 'ucsf_copyright',
          'region' => 'footer_first',
          'weight' => '-9',
        ),
      ),
    ),
    'disable_context' => array(
      'disabled' => array(
        'op_sitewide_ucsf' => 'op_sitewide_ucsf',
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('UCSF Open Proposal Groups blocks and such');
  t('opg');
  $export['opg_sitewide_ucsf'] = $context;

  return $export;
}
