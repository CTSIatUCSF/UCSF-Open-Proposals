<?php
/**
 * @file
 * op_global.features.beautytips_custom_tips.inc
 */

/**
 * Implements hook_beautytips_custom_tips().
 */
function op_global_beautytips_custom_tips() {

  $items = array();

  $items = array(
    'op_global|M3xhLnByb2ZpbGUtdGlw' => array(
      'element' => 'a.profile-tip',
      'content_type' => 'attribute',
      'content' => 'title',
      'disable_link' => 0,
      'trigger_on' => 'hover',
      'trigger_off' => 'mouseout',
      'style' => 'profiles',
      'shrink' => 0,
      'positions' => 'right,bottom,left,top',
      'animation_on' => '',
      'animation_off' => '',
      'visibility' => 0,
      'pages' => 'admin/*',
      'enabled' => 1,
      'machine_name' => 'op_global|M3xhLnByb2ZpbGUtdGlw',
    ),
    'op_global|MXxzcGFuLmNsaWNrdGlw' => array(
      'element' => 'span.clicktip',
      'content_type' => 'attribute',
      'content' => 'title',
      'disable_link' => 0,
      'trigger_on' => 'click',
      'trigger_off' => 'dblclick',
      'style' => 'hulu',
      'shrink' => 1,
      'positions' => '',
      'animation_on' => 'fadeIn',
      'animation_off' => 'fadeOut',
      'visibility' => 1,
      'pages' => 'tooltip',
      'enabled' => 1,
      'machine_name' => 'op_global|MXxzcGFuLmNsaWNrdGlw',
    ),
    'op_global|NHxhLmhvdmVydGlw' => array(
      'element' => 'a.hovertip',
      'content_type' => 'attribute',
      'content' => 'title',
      'disable_link' => 0,
      'trigger_on' => 'hover',
      'trigger_off' => 'mouseout',
      'style' => 'hulu',
      'shrink' => 1,
      'positions' => '',
      'animation_on' => '',
      'animation_off' => '',
      'visibility' => 0,
      'pages' => '',
      'enabled' => 1,
      'machine_name' => 'op_global|NHxhLmhvdmVydGlw',
    ),
    'op_global|NXwuY2xpY2t0ZXh0LXJpZ2h0' => array(
      'element' => '.clicktext-right',
      'content_type' => 'js',
      'content' => '$(this).next(\'.clicktextlong\').html()',
      'disable_link' => 0,
      'trigger_on' => 'click',
      'trigger_off' => 'click',
      'style' => 'login',
      'shrink' => 1,
      'positions' => 'right,top,bottom,left',
      'animation_on' => '',
      'animation_off' => '',
      'visibility' => 0,
      'pages' => '',
      'enabled' => 1,
      'machine_name' => 'op_global|NXwuY2xpY2t0ZXh0LXJpZ2h0',
    ),
    'op_global|NXxzcGFuLmNsaWNrdGV4dA' => array(
      'element' => '.clicktext',
      'content_type' => 'js',
      'content' => '$(this).next(\'.clicktextlong\').html()',
      'disable_link' => 0,
      'trigger_on' => 'click',
      'trigger_off' => 'click',
      'style' => 'login',
      'shrink' => 1,
      'positions' => 'top,bottom,left,right',
      'animation_on' => '',
      'animation_off' => '',
      'visibility' => 0,
      'pages' => '',
      'enabled' => 1,
      'machine_name' => 'op_global|NXxzcGFuLmNsaWNrdGV4dA',
    ),
  );

  return $items;
}
