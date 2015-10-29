<?php
/**
 * @file
 * op_global.features.beautytips_custom_styles.inc
 */

/**
 * Implements hook_beautytips_custom_styles().
 */
function op_global_beautytips_custom_styles() {

  $items = array();

  $items = array(
    'op_global|MXxwcm9maWxlcw' => array(
      'name' => 'profiles',
      'fill' => '#506480',
      'stroke_width' => 0,
      'stroke_style' => '',
      'width' => '8.8em',
      'padding' => '5px',
      'corner_radius' => 6,
      'spike_girth' => 10,
      'spike_length' => 5,
      'shadow' => 'no_shadow',
      'shadow_blur' => '',
      'shadow_color' => '',
      'css_class' => 'profiles-bt',
      'css_color' => '#FFF',
      'css_font_family' => 'tahoma, arial, sans serif',
      'css_font_weight' => 'bold',
      'css_font_size' => '0.9em',
      'machine_name' => 'op_global|MXxwcm9maWxlcw',
    ),
    'op_global|Mnxsb2dpbg' => array(
      'name' => 'login',
      'fill' => '#FBCCA7',
      'stroke_width' => 0,
      'stroke_style' => '',
      'width' => '12.1em',
      'padding' => '8px',
      'corner_radius' => 8,
      'spike_girth' => 10,
      'spike_length' => 10,
      'shadow' => 'no_shadow',
      'shadow_blur' => 0,
      'shadow_color' => 0,
      'css_class' => '',
      'css_color' => '#494949',
      'css_font_family' => 'tahoma, arial, sans serif',
      'css_font_weight' => 'normal',
      'css_font_size' => '15px',
      'machine_name' => 'op_global|Mnxsb2dpbg',
    ),
  );

  return $items;
}
