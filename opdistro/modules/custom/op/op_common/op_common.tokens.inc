<?php

/**
 * @file
 * Custom tokens for Open Proposals.
 */

/**
 * Implements hook_token_info().
 *
 * @ingroup op_common
 */
function op_common_token_info() {
  $info = array();

  $info['types']['op'] = array(
    'name' => t('Curent Open Proposal forum'),
    'description' => t('Tokens related to the currently active Open Proposal forum'),
    'type' => 'op-forum',
  );

  $info['types']['op-forum'] = array(
    'name' => t('Open Proposal forums'),
    'description' => t('Tokens related to an Open Proposal forum'),
    'needs_data' => 'op_forum',
  );
  $info['tokens']['op-forum']['context'] = array(
    'name' => t('Open Proposal context'),
    'description' => t('The primary context of an Open Proposal forum'),
    'type' => 'context',
  );
  $info['tokens']['op-forum']['content-type'] = array(
    'name' => t('Open Proposal content type'),
    'description' => t('The content type of an Open Proposal forum'),
    'type' => 'content-type',
  );
  $info['tokens']['op-forum']['create-text'] = array(
    'name' => t('Open Proposal node creation text'),
    'description' => t('The language prompting for logins to create a node of an Open Proposal forum'),
  );
  $info['tokens']['op-forum']['noun'] = array(
    'name' => t('Open Proposal word for node'),
    'description' => t('The word to use for a node of an Open Proposal forum - eg "proposal"'),
  );
  $info['tokens']['op-forum']['nouns'] = array(
    'name' => t('Open Proposal plural word for nodes'),
    'description' => t('The plural word to use for nodes of an Open Proposal forum - eg "proposals"'),
  );
  $info['tokens']['op-forum']['login'] = array(
    'name' => t('Open Proposal login tokens'),
    'description' => t('The login tokens for an Open Proposal forum'),
    'type' => 'op-login',
  );
  $info['tokens']['op-forum']['counts'] = array(
    'name' => t('Open Proposal forum statistics'),
    'description' => t('Statistics for an Open Proposal forum'),
  );

  $info['types']['op-login'] = array(
    'name' => t('Open Proposal login settings'),
    'description' => t('The login settings for an Open Proposal forum'),
    'needs-data' => 'op_login',
  );
  $info['tokens']['op-login']['type'] = array(
    'name' => t('Open Proposal login type'),
    'description' => t('The login type for an Open Proposal forum'),
  );
  $info['tokens']['op-login']['text'] = array(
    'name' => t('Open Proposal login text'),
    'description' => t('The login text for an Open Proposal forum'),
  );
  $info['tokens']['op-login']['links'] = array(
    'name' => t('Open Proposal login links'),
    'description' => t('The login links for an Open Proposal forum'),
  );
  $info['tokens']['op-login']['drupal-login'] = array(
    'name' => t('Open Proposal Drupal login'),
    'description' => t('The Drupal login tokens for an Open Proposal forum, if enabled'),
    'type' => 'ctsi-login',
  );
  $info['tokens']['op-login']['saml-login'] = array(
    'name' => t('Open Proposal SAML login'),
    'description' => t('The SAML login tokens for an Open Proposal forum, if enabled'),
    'type' => 'ctsi-login',
  );

  $info['tokens']['node']['op'] = array(
    'name' => t('Open Proposal tokens'),
    'description' => t('Open Proposal tokens for the node type'),
    'type' => 'op-forum',
  );
  $info['tokens']['content-type']['op'] = array(
    'name' => t('Open Proposal tokens'),
    'description' => t('Open Proposal tokens for the content type'),
    'type' => 'op-forum',
  );

  return $info;
}

/**
 * Implements hook_tokens().
 *
 * @ingroup op_common
 */
function op_common_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $replacements = array();
  $sanitize = !empty($options['sanitize']);

  if ($type == 'op') {
    if ($current_forum = op_common_current_forum($data)) {
      $replacements += token_generate('op-forum', $tokens, array('op_forum' => $current_forum), $options);
      // Chained token relationships.
      if ($forum_tokens = token_find_with_prefix($tokens, 'forum')) {
        $replacements += token_generate('op-forum', $forum_tokens, array('op_forum' => $current_forum), $options);
      }
    }
    else {
      dpm(compact('current_forum','type','tokens','data','options'), 'could not load current forum');
    }
  }
  if ($type == 'op-forum' and !empty($data['op_forum'])) {
    $op_forum = $data['op_forum'];

    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'context':
          $replacements[$original] = $sanitize ? filter_xss($op_forum->context->description) : $op_forum->context->description;
          break;
        case 'content-type':
          if ($node_type = node_type_load($op_forum->content_type)) {
            $replacements[$original] = $sanitize ? filter_xss($node_type->name) : $node_type->name;
          }
          else {
            $replacements[$original] = $op_forum->content_type;
          }
          break;
        case 'create-text':
          $replacements[$original] = $op_forum->create_text;
          break;
        case 'noun':
          $replacements[$original] = $op_forum->noun;
          break;
        case 'nouns':
          $replacements[$original] = empty($op_forum->nouns) ? ($op_forum->noun . 's') : $op_forum->nouns;
          break;
        case 'login':
          $replacements[$original] = $op_forum->login_type;
          break;
      }
    }

    // [op-forum:counts:X] dynamic tokens
    if ($count_tokens = token_find_with_prefix($tokens, 'counts')) {
      // dpm(compact('op_forum','count_tokens','type','tokens','data','options'), 'op count tokens');
      $module = $op_forum->name;
      $function = $module .= '_report_counts';
      if (function_exists($function)) {
        $counts = $function();
        // dpm($counts, $function);
        foreach ($count_tokens as $name => $original) {
          if ($pos = strpos($name, '-')) {
            $arg = str_replace('_', ' ', substr($name, $pos+1));
            $name = substr($name, 0, $pos);
          }
          else {
            $arg = null;
          }
          if ($arg) {
            if (isset($counts[$name][$arg])) {
              $replacements[$original] = $counts[$name][$arg];
            }
            else {
              dpm(compact('name','arg','counts'), 'no such name-arg count');
            }
          }
          else {
            if (isset($counts[$name])) {
              $replacements[$original] = $counts[$name];
            }
            else {
              dpm(compact('name','counts'), 'no such count');
            }
          }
        }
      }
    }

    // Chained token relationships.
    if ($context_tokens = token_find_with_prefix($tokens, 'context')) {
      $replacements += token_generate('context', $context_tokens, array('context' => $op_forum->context), $options);
    }
    if ($content_type_tokens = token_find_with_prefix($tokens, 'content-type')) {
      if ($node_type = node_type_load($op_forum->content_type)) {
        $replacements += token_generate('content-type', $content_type_tokens, array('node_type' => $node_type), $options);
      }
    }
    if ($op_login_tokens = token_find_with_prefix($tokens, 'login')) {
      $replacements += token_generate('op-login', $op_login_tokens, array('op_login' => $op_forum->login), $options);
    }

  }
  if ($type == 'op-login' and !empty($data['op_login'])) {
    $op_login = $data['op_login'];

    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'type':
          $replacements[$original] = $op_login->type;
          break;
        case 'text':
          $replacements[$original] = $sanitize ? filter_xss($op_login->text) : $op_login->text;
          break;
        case 'links':
          $replacements[$original] = $sanitize ? filter_xss($op_login->text) : $op_login->links;
          break;
        case 'drupal-login':
          if (!empty($op_login->login_types['drupal']->url)) {
            $drupal_url = $op_login->login_types['drupal']->url;
            $replacements[$original] = $sanitize ? filter_xss($drupal_url) : $drupal_url;
          }
          break;
        case 'saml-login':
          if (!empty($op_login->login_types['saml']->url)) {
            $saml_url = $op_login->login_types['saml']->url;
            $replacements[$original] = $sanitize ? filter_xss($saml_url) : $saml_url;
          }
          break;
      }
    }

    // Chained token relationships.
    if ($drupal_login_tokens = token_find_with_prefix($tokens, 'drupal-login') and !empty($op_login->login_types['drupal'])) {
      $drupal_login = $op_login->login_types['drupal'];
      $replacements += token_generate('ctsi-login', $drupal_login_tokens, array('ctsi_login_type' => $drupal_login), $options);
    }
    if ($saml_login_tokens = token_find_with_prefix($tokens, 'saml-login') and !empty($op_login->login_types['saml'])) {
      $saml_login = $op_login->login_types['saml'];
      $replacements += token_generate('ctsi-login', $saml_login_tokens, array('ctsi_login_type' => $saml_login), $options);
    }
  }
  if ($type == 'node' and !empty($data['node'])) {
    $node = $data['node'];
    if ($op_forum_tokens = token_find_with_prefix($tokens, 'op')) {
      if ($op_forum = op_common_op_forum_load($node->type)) {
        $replacements += token_generate('op-forum', $op_forum_tokens, array('op_forum' => $op_forum), $options);
      }
    }
  }
  if ($type == 'content-type' and !empty($data['node_type'])) {
    $node_type = $data['node_type'];
    if ($op_forum_tokens = token_find_with_prefix($tokens, 'op')) {
      if ($op_forum = op_common_op_forum_load($node_type->type)) {
        $replacements += token_generate('op-forum', $op_forum_tokens, array('op_forum' => $op_forum), $options);
      }
    }
  }

  return $replacements;
}
