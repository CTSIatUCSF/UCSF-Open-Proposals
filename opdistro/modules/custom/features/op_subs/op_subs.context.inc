<?php
/**
 * @file
 * op_subs.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function op_subs_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'op_subs';
  $context->description = 'React to subscription requests';
  $context->tag = 'defaults';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'goto/subscribe/*' => 'goto/subscribe/*',
        'subscriptions/add/*' => 'subscriptions/add/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-op_subs_anon_type' => array(
          'module' => 'boxes',
          'delta' => 'op_subs_anon_type',
          'region' => 'content_after_title',
          'weight' => '-10',
        ),
        'boxes-op_subs_auth' => array(
          'module' => 'boxes',
          'delta' => 'op_subs_auth',
          'region' => 'content_after_title',
          'weight' => '-9',
        ),
        'boxes-op_subs_anon_node' => array(
          'module' => 'boxes',
          'delta' => 'op_subs_anon_node',
          'region' => 'content_after_title',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('React to subscription requests');
  t('defaults');
  $export['op_subs'] = $context;

  return $export;
}
