<?php
/**
 * @file
 * op_filters.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function op_filters_filter_default_formats() {
  $formats = array();

  // Exported format: Filtered HTML.
  $formats['filtered_html'] = array(
    'format' => 'filtered_html',
    'name' => 'Filtered HTML',
    'cache' => 1,
    'status' => 1,
    'weight' => -9,
    'filters' => array(
      'filter_url' => array(
        'weight' => -10,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'filter_html' => array(
        'weight' => -9,
        'status' => 1,
        'settings' => array(
          'allowed_html' => '<a> <em> <strong> <cite> <code> <ul> <ol> <li> <dl> <dt> <dd>',
          'filter_html_help' => 1,
          'filter_html_nofollow' => 0,
        ),
      ),
      'filter_autop' => array(
        'weight' => -8,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => -6,
        'status' => 1,
        'settings' => array(),
      ),
      'pathologic' => array(
        'weight' => -5,
        'status' => 1,
        'settings' => array(
          'local_paths' => 'http://dev.open-proposals.ucsf.edu/
http://open-proposals.ucsf.edu/
/',
          'protocol_style' => 'full',
        ),
      ),
    ),
  );

  // Exported format: Full HTML.
  $formats['full_html'] = array(
    'format' => 'full_html',
    'name' => 'Full HTML',
    'cache' => 0,
    'status' => 1,
    'weight' => -8,
    'filters' => array(
      'filter_url' => array(
        'weight' => -48,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'filter_htmlcorrector' => array(
        'weight' => -47,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_tokens' => array(
        'weight' => -46,
        'status' => 1,
        'settings' => array(),
      ),
      'pathologic' => array(
        'weight' => -45,
        'status' => 1,
        'settings' => array(
          'local_paths' => 'http://dev.open-proposals.ucsf.edu/
http://open-proposals.ucsf.edu/
/',
          'protocol_style' => 'full',
        ),
      ),
    ),
  );

  // Exported format: PHP code.
  $formats['php_code'] = array(
    'format' => 'php_code',
    'name' => 'PHP code',
    'cache' => 0,
    'status' => 1,
    'weight' => -7,
    'filters' => array(
      'php_code' => array(
        'weight' => -49,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_tokens' => array(
        'weight' => -45,
        'status' => 1,
        'settings' => array(),
      ),
      'pathologic' => array(
        'weight' => -44,
        'status' => 1,
        'settings' => array(
          'local_paths' => 'http://dev.open-proposals.ucsf.edu/
http://open-proposals.ucsf.edu/
/',
          'protocol_style' => 'full',
        ),
      ),
    ),
  );

  // Exported format: Plain text.
  $formats['plain_text'] = array(
    'format' => 'plain_text',
    'name' => 'Plain text',
    'cache' => 1,
    'status' => 1,
    'weight' => -6,
    'filters' => array(
      'filter_html_escape' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_url' => array(
        'weight' => 1,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'filter_autop' => array(
        'weight' => 2,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  // Exported format: User WYSIWYG.
  $formats['user_wysiwyg'] = array(
    'format' => 'user_wysiwyg',
    'name' => 'User WYSIWYG',
    'cache' => 1,
    'status' => 1,
    'weight' => -10,
    'filters' => array(
      'filter_url' => array(
        'weight' => -10,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'filter_htmlcorrector' => array(
        'weight' => -8,
        'status' => 1,
        'settings' => array(),
      ),
      'pathologic' => array(
        'weight' => -6,
        'status' => 1,
        'settings' => array(
          'local_paths' => 'http://dev.open-proposals.ucsf.edu/
http://open-proposals.ucsf.edu/
/',
          'protocol_style' => 'full',
        ),
      ),
    ),
  );

  return $formats;
}
