<?php
/**
 * @file
 * op_global.box.inc
 */

/**
 * Implements hook_default_box().
 */
function op_global_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'ctsi_acknowledgement';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Footer > CTSI Acknowledgment';
  $box->options = array(
    'body' => array(
      'value' => '<p>UCSF Open Proposals is managed by the UCSF
<a target="_blank" href="http://ctsi.ucsf.edu">Clinical and Translational Science Institute (CTSI)</a>, part of the Clinical and Translational Science Award program funded by the National Center for Advancing Translational Sciences (Grant Number UL1 TR000004) at the National Institutes of Health (NIH).</p>',
      'format' => 'full_html',
    ),
  );
  $export['ctsi_acknowledgement'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'ctsi_tagline_banner';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'CTSI Tagline (banner)';
  $box->options = array(
    'body' => array(
      'value' => '&nbsp;',
      'format' => 'filtered_html',
    ),
    'additional_classes' => '',
  );
  $export['ctsi_tagline_banner'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'op_admin_info';
  $box->plugin_key = 'simple';
  $box->title = 'About This Site';
  $box->description = 'OP Admin Site Info';
  $box->options = array(
    'body' => array(
      'value' => '<li>Server Name: <?php echo (empty($_SERVER[\'HTTP_HOST\']) ? \'HTTP_HOST undefined\' : $_SERVER[\'HTTP_HOST\']); ?>
<li>DB Name: <?php echo db_query(\'select database()\')->fetchField(); ?>',
      'format' => 'php_code',
    ),
    'additional_classes' => '',
  );
  $export['op_admin_info'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'op_global_footer_ctsi';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Open Proposals > Footer > CTSI Acknowledgment';
  $box->options = array(
    'body' => array(
      'value' => '<p style="padding-left: 20px">UCSF Open Proposals is managed by the UCSF
<a target="_blank" href="http://ctsi.ucsf.edu">Clinical and Translational Science Institute (CTSI)</a>
, part of the Clinical and Translational Science Award program funded by the National Center for Advancing Translational Sciences (Grant Number UL1 TR000004) at the National Institutes of Health (NIH).</p>',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['op_global_footer_ctsi'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'op_global_node_create';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'OP Global Node Create Login Box';
  $box->options = array(
    'body' => array(
      'value' => '[op:create-text]',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['op_global_node_create'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'op_global_right_header';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Open Proposals > Right header';
  $box->options = array(
    'body' => array(
      'value' => '<h3 id="optopright"><a href="/">UCSF Open Proposals</a></h3>',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['op_global_right_header'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'op_global_vote_login';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'OP Global Vote Login Box';
  $box->options = array(
    'body' => array(
      'value' => '<div class="consult-loginblock" style="width:660px;padding:20px 0">
<h3 style="text-align:center">Login is required to vote:
<span style="padding-left:20px">[op:login:text]</span>
</h3>
</div>

',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['op_global_vote_login'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'open_proposals_lp_logo';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Open Proposal Forum > Landing Page Logo';
  $box->options = array(
    'body' => array(
      'value' => '<div class="site-logo op-global"><h1><a href="/"><img src="/sites/open-proposals.ucsf.edu/files/images/OPlogo.png" alt="UCSF Open Proposals" /><br />
<span>Enabling proposal &amp; team development</span></a></h1></div>

<!--<div class="site-logo"><h1><a href="/">UCSF Open Proposals<br />
<span>Enabling proposal &amp; team development</span></a></h1></div>-->',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['open_proposals_lp_logo'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'open_proposals_lp_navbar';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Open Proposals > Landing Page navbar';
  $box->options = array(
    'body' => array(
      'value' => '<div id="menu-icon"></div>
<ul class="menu">
<li><a id="home" href="/">Home</a></li>
<li><a href="/contact" id="contact">Contact</a></li>
<ul>',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['open_proposals_lp_navbar'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'poweredby';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Global > Powered by CTSI';
  $box->options = array(
    'body' => array(
      'value' => '<p><img src="/files/images/ctsi16.png" alt="CTSI" style="vertical-align:-2px" /> <a href="http://ctsi.ucsf.edu">Powered by CTSI</a></p>',
      'format' => 'php_code',
    ),
    'additional_classes' => 'poweredby',
  );
  $export['poweredby'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'ucsf_copyright';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'UCSF copyright footer';
  $box->options = array(
    'body' => array(
      'value' => '<p style="margin-bottom: 0;">The University of California Copyright ©2015 The Regents of the University of California. <span class="nowrap">All Rights Reserved.</span></p>
<p>Services on this website are for the use of UCSF researchers, CTSI affiliates, industry and community members who wish to establish explicit ties to UCSF.</p>',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['ucsf_copyright'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'ucsf_top_banner';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'ucsf top banner';
  $box->options = array(
    'body' => array(
      'value' => '<div class="container ucsf">
<div class="sixteen columns">
<ul class="ucsfnav">
<li>
<a title="University of California San Francisco" href="http://www.ucsf.edu/" id="ucsf">University of California San Francisco</a>
</li>
</ul>
<ul class="ucsfnav ucsfnav-right no-phone no-phone-ls">
<li>
<a title="About UCSF" href="http://www.ucsf.edu/about">About UCSF</a>
</li>
<li>
<a title="Search UCSF" href="http://www.ucsf.edu/ucsf/search">Search UCSF</a>
</li>
<li>
<a title="UCSF Medical Center" href="http://www.ucsfhealth.org">UCSF Medical Center</a>
</li>
</ul>
</div>
</div>',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['ucsf_top_banner'] = $box;

  return $export;
}
