<?php
/**
 * @file
 * op_global.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function op_global_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'op_global_default';
  $context->description = 'site wide context (can be disabled by other contexts)';
  $context->tag = 'defaults';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-open_proposals_lp_logo' => array(
          'module' => 'boxes',
          'delta' => 'open_proposals_lp_logo',
          'region' => 'brand',
          'weight' => '-10',
        ),
        'search-form' => array(
          'module' => 'search',
          'delta' => 'form',
          'region' => 'main_menu',
          'weight' => '-87',
        ),
        'boxes-open_proposals_lp_navbar' => array(
          'module' => 'boxes',
          'delta' => 'open_proposals_lp_navbar',
          'region' => 'main_menu',
          'weight' => '-86',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('defaults');
  t('site wide context (can be disabled by other contexts)');
  $export['op_global_default'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'op_sitewide_ucsf';
  $context->description = 'UCSF Open Proposals blocks and such';
  $context->tag = 'defaults';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
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
        'boxes-poweredby' => array(
          'module' => 'boxes',
          'delta' => 'poweredby',
          'region' => 'top_links',
          'weight' => '0',
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
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('UCSF Open Proposals blocks and such');
  t('defaults');
  $export['op_sitewide_ucsf'] = $context;

  return $export;
}
