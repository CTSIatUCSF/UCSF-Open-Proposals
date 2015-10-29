<?php

/**
 * @file
 * Custom tokens for Open Proposals.
 */

/**
 * Implements hook_token_info().
 *
 * @ingroup opg_core
 */
function opg_core_token_info() {
  $info = array();

  $info['types']['current-opg'] = array(
    'name' => t('Curent Open Proposal Group'),
    'description' => t('Tokens related to the currently active Open Proposal Group'),
    'type' => 'opg',
  );

  $info['types']['opg'] = array(
    'name' => t('Open Proposal Group'),
    'description' => t('Tokens related to an Open Proposal Group'),
    'needs_data' => 'opg',
  );
  $info['tokens']['opg']['create-text'] = array(
    'name' => t('Open Proposal Group node creation text'),
    'description' => t('The language prompting for logins to create a node of an Open Proposal Group'),
  );
  $info['tokens']['opg']['noun'] = array(
    'name' => t('Open Proposal Group word for node'),
    'description' => t('The word to use for a node of an Open Proposal Group - eg "proposal"'),
  );
  $info['tokens']['opg']['nouns'] = array(
    'name' => t('Open Proposal Group plural word for nodes'),
    'description' => t('The plural word to use for nodes of an Open Proposal Group - eg "proposals"'),
  );
  $info['tokens']['opg']['groupword'] = array(
    'name' => t('Open Proposal Group word for the group'),
    'description' => t('The word to use for an Open Proposal Group - eg "opportunity"'),
  );
  $info['tokens']['opg']['groupwords'] = array(
    'name' => t('Open Proposal Group plural word for groups'),
    'description' => t('The plural word to use for an Open Proposal Group - eg "opportunities"'),
  );
  $info['tokens']['opg']['login'] = array(
    'name' => t('Open Proposal Group login tokens'),
    'description' => t('The login tokens for an Open Proposal Group'),
    'type' => 'opg-login',
  );
  $info['tokens']['opg']['counts'] = array(
    'name' => t('Open Proposal Group statistics'),
    'description' => t('Statistics for an Open Proposal Group'),
  );
  $info['tokens']['opg']['path'] = array(
    'name' => t('Open Proposal Group path'),
    'description' => t('Relative path for the home page of an Open Proposal Group'),
  );
  $info['tokens']['opg']['gid'] = array(
    'name' => t('Open Proposal Group ID'),
    'description' => t('Entity ID number of an Open Proposal Group'),
  );

  $info['types']['opg-login'] = array(
    'name' => t('Open Proposal Group login settings'),
    'description' => t('The login settings for an Open Proposal Group'),
    'needs-data' => 'opg_login',
  );
  $info['tokens']['opg-login']['type'] = array(
    'name' => t('Open Proposal Group login type'),
    'description' => t('The login type for an Open Proposal Group'),
  );
  $info['tokens']['opg-login']['text'] = array(
    'name' => t('Open Proposal Group login text'),
    'description' => t('The login text for an Open Proposal Group'),
  );
  $info['tokens']['opg-login']['links'] = array(
    'name' => t('Open Proposal Group login links'),
    'description' => t('The login links for an Open Proposal Group'),
  );
  $info['tokens']['opg-login']['drupal-login'] = array(
    'name' => t('Open Proposal Group Drupal login'),
    'description' => t('The Drupal login tokens for an Open Proposal Group, if enabled'),
    'type' => 'ctsi-login',
  );
  $info['tokens']['opg-login']['saml-login'] = array(
    'name' => t('Open Proposal Group SAML login'),
    'description' => t('The SAML login tokens for an Open Proposal Group, if enabled'),
    'type' => 'ctsi-login',
  );

  $info['tokens']['opg']['op-subs'] = array(
    'name' => t('Open Proposal Groups subscription tokens'),
    'description' => t('Tokens for subscriptions to the Open Proposal Group'),
    'type' => 'op-subs',
  );

  $info['tokens']['site']['opg_core_default_noun'] = array(
    'name' => t('Open Proposal Groups default word for a forum post'),
    'description' => t('The default mixed-case word for a forum post for this site - eg "Proposal"'),
  );

  $info['tokens']['site']['opg_core_default_groupword'] = array(
    'name' => t('Open Proposal Groups default word for a forum group'),
    'description' => t('The default mixed-case word for a forum group for this site - eg "Opportunity"'),
  );
  $info['tokens']['site']['current-opg'] = array(
    'name' => t('Curent Open Proposal Group'),
    'description' => t('Tokens related to the currently active Open Proposal Group'),
  );

  return $info;
}

/**
 * Implements hook_tokens().
 *
 * @ingroup opg_core
 */
function opg_core_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $replacements = array();
  $sanitize = !empty($options['sanitize']);

  // dpm(compact('type','tokens','data','options'), __FUNCTION__ . ' ' . $type);

  if ($type == 'current-opg') {
    if ($current_opg = opg_core_current_opg($data)) {
      $replacements += token_generate('opg', $tokens, array('opg' => $current_opg), $options);
    }
    else {
      dpm(compact('type','tokens','data','options','current_opg'), 'could not load current opg');
    }
  }
  if ($type == 'opg' and !empty($data['opg'])) {
    $opg = $data['opg'];

    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'gid':
          $replacements[$original] = $opg['gid'];
          break;
        case 'path':
          $replacements[$original] = $opg['path'];
          break;
        case 'create-text':
          $replacements[$original] = $opg['create_text'];
          break;
        case 'postwords':
          $replacements[$original] = $opg['postwords'];
          break;
        case 'post_type':
          $replacements[$original] = $opg['post_type'];
          break;
        case 'post_type_name':
          $replacements[$original] = $opg['post_type_name'];
          break;
        case 'groupword':
          $replacements[$original] = $opg['groupword'];
          break;
        case 'groupwords':
          $replacements[$original] = $opg['groupwords'];
          break;
        case 'groupword_article':
          $replacements[$original] = $opg['groupword_article'];
          break;
        case 'ucgroupword':
          $replacements[$original] = $opg['ucgroupword'];
          break;
        case 'ucgroupwords':
          $replacements[$original] = $opg['ucgroupwords'];
          break;
        case 'ucgroupword_article':
          $replacements[$original] = $opg['ucgroupword_article'];
          break;
        case 'lcgroupword':
          $replacements[$original] = $opg['lcgroupword'];
          break;
        case 'lcgroupwords':
          $replacements[$original] = $opg['lcgroupwords'];
          break;
        case 'lcgroupword_article':
          $replacements[$original] = $opg['lcgroupword_article'];
          break;
        case 'noun':
          $replacements[$original] = $opg['noun'];
          break;
        case 'nouns':
          $replacements[$original] = $opg['nouns'];
          break;
        case 'noun_article':
          $replacements[$original] = $opg['noun_article'];
          break;
        case 'ucnoun':
          $replacements[$original] = $opg['ucnoun'];
          break;
        case 'ucnouns':
          $replacements[$original] = $opg['ucnouns'];
          break;
        case 'ucnoun_article':
          $replacements[$original] = $opg['ucnoun_article'];
          break;
        case 'lcnoun':
          $replacements[$original] = $opg['lcnoun'];
          break;
        case 'lcnouns':
          $replacements[$original] = $opg['lcnouns'];
          break;
        case 'lcnoun_article':
          $replacements[$original] = $opg['lcnoun_article'];
          break;
        case 'login':
          $replacements[$original] = $opg['login_type'];
          break;
      }
    }

    // [opg:counts:X] dynamic tokens
    if ($count_tokens = token_find_with_prefix($tokens, 'counts')) {
      $counts = opg_core_report_counts($opg);
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

    // Chained token relationships.
    if ($opg_login_tokens = token_find_with_prefix($tokens, 'login')) {
      $replacements += token_generate('opg-login', $opg_login_tokens, array('opg' => $opg), $options);
    }
    if ($op_subs_tokens = token_find_with_prefix($tokens, 'op-subs')) {
      $data['sub_link'] = opg_core_group_sublink($opg['gid']);
      $replacements += token_generate('op-subs', $op_subs_tokens, $data, $options);
    }

  }
  if ($type == 'opg-login' and !empty($data['opg']['login'])) {
    $opg = $data['opg'];
    $opg_login = $opg['login'];

    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'type':
          $replacements[$original] = $opg_login->type;
          break;
        case 'text':
          $replacements[$original] = $sanitize ? filter_xss($opg_login->text) : $opg_login->text;
          break;
        case 'links':
          $replacements[$original] = $sanitize ? filter_xss($opg_login->links) : $opg_login->links;
          break;
        case 'drupal-login':
          if (!empty($opg_login->login_types['drupal']->url)) {
            $drupal_url = $opg_login->login_types['drupal']->url;
            $replacements[$original] = $sanitize ? filter_xss($drupal_url) : $drupal_url;
          }
          break;
        case 'saml-login':
          if (!empty($opg_login->login_types['saml']->url)) {
            $saml_url = $opg_login->login_types['saml']->url;
            $replacements[$original] = $sanitize ? filter_xss($saml_url) : $saml_url;
          }
          break;
      }
    }

    // [opg-login:textpath:X] dynamic tokens
    if ($textpath_tokens = token_find_with_prefix($tokens, 'textpath')) {
      foreach ($textpath_tokens as $name => $original) {
        // dpm($original, 'textpath - ' . $name);
        $opg['extra_path'] = trim($name, '/');
        $text = op_common_op_login_text($opg);
        $replacements[$original] = $sanitize ? filter_xss($text) : $text;
      }
    }

    // [opg-login:opgpath:X] dynamic tokens
    if ($opgpath_tokens = token_find_with_prefix($tokens, 'opgpath')) {
      foreach ($opgpath_tokens as $name => $original) {
        // dpm($original, 'opgpath - ' . $name);
        $opg['extra_path'] = trim($opg['path'], '/') . '/' . trim($name, '/');
        $text = op_common_op_login_text($opg);
        $replacements[$original] = $sanitize ? filter_xss($text) : $text;
      }
    }


    // Chained token relationships.
    if ($drupal_login_tokens = token_find_with_prefix($tokens, 'drupal-login') and !empty($opg_login->login_types['drupal'])) {
      $drupal_login = $opg_login->login_types['drupal'];
      $replacements += token_generate('ctsi-login', $drupal_login_tokens, array('ctsi_login_type' => $drupal_login), $options);
    }
    if ($saml_login_tokens = token_find_with_prefix($tokens, 'saml-login') and !empty($opg_login->login_types['saml'])) {
      $saml_login = $opg_login->login_types['saml'];
      $replacements += token_generate('ctsi-login', $saml_login_tokens, array('ctsi_login_type' => $saml_login), $options);
    }
  }

  if ($type == 'site') {
    $defaults = array();
    opg_core_get_noun($defaults);
    opg_core_get_groupword($defaults);

    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'default_groupword':
          $replacements[$original] = $defaults['groupword'];
          break;
        case 'default_lcgroupword':
          $replacements[$original] = $defaults['lcgroupword'];
          break;
        case 'default_ucgroupword':
          $replacements[$original] = $defaults['ucgroupword'];
          break;
        case 'default_noun':
          $replacements[$original] = $defaults['noun'];
          break;
        case 'default_lcnoun':
          $replacements[$original] = $defaults['lcnoun'];
          break;
        case 'default_ucnoun':
          $replacements[$original] = $defaults['ucnoun'];
          break;
      }
    }
    if ($current_opg_tokens = token_find_with_prefix($tokens, 'current-opg')) {
      if ($current_opg = opg_core_current_opg($data)) {
        $replacements += token_generate('opg', $current_opg_tokens, array('opg' => $current_opg), $options);
      }
    }
  }

  return $replacements;
}
