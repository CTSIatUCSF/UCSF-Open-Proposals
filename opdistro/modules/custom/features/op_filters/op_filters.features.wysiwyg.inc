<?php
/**
 * @file
 * op_filters.features.wysiwyg.inc
 */

/**
 * Implements hook_wysiwyg_default_profiles().
 */
function op_filters_wysiwyg_default_profiles() {
  $profiles = array();

  // Exported profile: user_wysiwyg
  $profiles['user_wysiwyg'] = array(
    'format' => 'user_wysiwyg',
    'editor' => 'tinymce',
    'settings' => array(
      'default' => 1,
      'user_choose' => 0,
      'show_toggle' => 0,
      'add_to_summaries' => 1,
      'theme' => 'advanced',
      'language' => 'en',
      'buttons' => array(
        'default' => array(
          'bold' => 1,
          'italic' => 1,
          'bullist' => 1,
          'numlist' => 1,
          'undo' => 1,
          'link' => 1,
          'unlink' => 1,
          'image' => 1,
          'formatselect' => 1,
          'removeformat' => 1,
        ),
        'paste' => array(
          'pastetext' => 1,
        ),
        'imce' => array(
          'imce' => 1,
        ),
      ),
      'theme_advanced_toolbar_location' => 'top',
      'theme_advanced_toolbar_align' => 'left',
      'theme_advanced_statusbar_location' => 'bottom',
      'theme_advanced_resizing' => 1,
      'verify_html' => 1,
      'preformatted' => 0,
      'convert_fonts_to_spans' => 1,
      'remove_linebreaks' => 0,
      'apply_source_formatting' => 0,
      'css_setting' => 'self',
      'css_path' => '%t/css/editor.css',
      'theme_advanced_styles' => '',
      'theme_advanced_blockformats' => 'p,h2,h3',
      'advanced__active_tab' => 'edit-basic',
      'paste_auto_cleanup_on_paste' => 1,
    ),
    'rdf_mapping' => array(),
  );

  return $profiles;
}
