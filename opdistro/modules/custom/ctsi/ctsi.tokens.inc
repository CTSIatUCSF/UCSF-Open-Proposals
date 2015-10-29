<?php

/**
 * @file
 * Custom tokens for CTSI sites.
 */

/**
 * Implements hook_token_info().
 *
 * @ingroup ctsi
 */
function ctsi_token_info() {
  $info = array();

  // CTSI tokens
  $info['types']['ctsi'] = array(
    'name' => t('CTSI custom tokens'),
    'description' => t('Custom tokens used by CTSI'),
  );
  $info['tokens']['ctsi']['destination'] = array(
    'name' => t('Current destination'),
    'description' => t('The value of the "destination" parameter if it is set, or the current URL if not.'),
  );
  $info['tokens']['ctsi']['drupal-login'] = array(
    'name' => t('Drupal login'),
    'description' => t('CTSI custom Drupal login tokens'),
    'type' => 'ctsi-login',
  );
  $info['tokens']['ctsi']['saml-login'] = array(
    'name' => t('SAML login'),
    'description' => t('CTSI custom SAML login tokens'),
    'type' => 'ctsi-login',
  );

  // CTSI login type tokens
  $info['types']['ctsi-login'] = array(
    'name' => t('CTSI custom login tokens'),
    'description' => t('Tokens related to custom login types used by CTSI'),
    'needs-data' => 'ctsi_login_type',
  );
  $info['tokens']['ctsi-login']['type'] = array(
    'name' => t('CTSI custom login type'),
    'description' => t('Custom login type used by CTSI'),
  );
  $info['tokens']['ctsi-login']['url'] = array(
    'name' => t('CTSI custom login URL'),
    'description' => t('Custom login URL used by CTSI'),
  );
  $info['tokens']['ctsi-login']['link'] = array(
    'name' => t('CTSI custom login link'),
    'description' => t('Custom login link used by CTSI'),
  );

  return $info;
}

/**
 * Implements hook_tokens().
 *
 * @ingroup ctsi
 */
function ctsi_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $replacements = array();
  $sanitize = !empty($options['sanitize']);

  if ($type == 'ctsi') {
    foreach ($tokens as $name => $original) {
      switch ($name) {

        case 'destination':
          $destination = ctsi_destination();
          $replacements[$original] = $sanitize ? filter_xss($destination) : $destination;
          break;

        case 'drupal-login':
          $login = ctsi_login_type_load('drupal');
          $replacements[$original] = $sanitize ? filter_xss($login->url) : $login->url;
          break;
          
        case 'saml-login':
          $login = ctsi_login_type_load('saml');
          $replacements[$original] = $sanitize ? filter_xss($login->url) : $login->url;
          break;

      }
    }

    // Chained token relationships
    if ($drupal_tokens = token_find_with_prefix($tokens, 'drupal-login') and $drupal_login = ctsi_login_type_load('drupal')) {
      $replacements += token_generate('ctsi-login', $drupal_tokens, array('ctsi_login_type' => $drupal_login), $options);
    }
    if ($saml_tokens = token_find_with_prefix($tokens, 'saml-login') and $saml_login = ctsi_login_type_load('saml')) {
      $replacements += token_generate('ctsi-login', $saml_tokens, array('ctsi_login_type' => $saml_login), $options);
    }
  }

  if ($type == 'ctsi-login' and !empty($data['ctsi_login_type'])) {
    $ctsi_login_type = $data['ctsi_login_type'];
    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'type':
          $replacements[$original] = $ctsi_login_type->type;
          break;
        case 'url':
          $replacements[$original] = $sanitize ? filter_xss($ctsi_login_type->url) : $ctsi_login_type->url;
          break;
        case 'link':
          $replacements[$original] = $sanitize ? filter_xss($ctsi_login_type->link) : $ctsi_login_type->link;
          break;
      }
    }
  }

  return $replacements;
}

