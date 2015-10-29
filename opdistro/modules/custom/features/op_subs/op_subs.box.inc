<?php
/**
 * @file
 * op_subs.box.inc
 */

/**
 * Implements hook_default_box().
 */
function op_subs_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'op_subs_anon_node';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'OP Subs - Anonymous Node Subscription';
  $box->options = array(
    'body' => array(
      'value' => '<p>[op:login:text] to receive email updates on this [op:noun].</p>
<p><a href="[ctsi:destination]">Return to content</a>',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['op_subs_anon_node'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'op_subs_anon_type';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'OP Subs - Anonymous Content Type Subscription';
  $box->options = array(
    'body' => array(
      'value' => '<p>[op:login:text] to receive email updates on all [op:content-type:name] [op:nouns].</p>
<p><a href="[ctsi:destination]">Return to content</a></p>
',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['op_subs_anon_type'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'op_subs_auth';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'OP Subs - Subscription Form Intro';
  $box->options = array(
    'body' => array(
      'value' => '<p>Receive an email when content is revised or commented on.</p>
',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['op_subs_auth'] = $box;

  return $export;
}
