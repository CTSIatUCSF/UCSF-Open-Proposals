<?php
/**
 * @file
 * opg_core.box.inc
 */

/**
 * Implements hook_default_box().
 */
function opg_core_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'opg_group_adminmember_nav';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'OPG > group admin pages > Nav links';
  $box->options = array(
    'body' => array(
      'value' => '<div class="tabs-wrapper">
<ul class="tabs primary clearfix">
<li><a href="[current-opg:path]">View</a></li>
<li><a href="/node/[current-opg:gid]/edit">Edit</a></li>
<li><a href="/node/[current-opg:gid]/group">Group</a></li>
<li><a href="/node/[current-opg:gid]/revisions">Revisions</a></li>
</ul></div>
',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['opg_group_adminmember_nav'] = $box;

  return $export;
}
