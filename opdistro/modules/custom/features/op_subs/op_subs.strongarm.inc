<?php
/**
 * @file
 * op_subs.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function op_subs_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'subscriptions_avoid_empty_subscribe_links';
  $strongarm->value = 1;
  $export['subscriptions_avoid_empty_subscribe_links'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'subscriptions_cron_percent';
  $strongarm->value = '50';
  $export['subscriptions_cron_percent'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'subscriptions_form_expanded';
  $strongarm->value = 0;
  $export['subscriptions_form_expanded'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'subscriptions_form_in_block';
  $strongarm->value = '1';
  $export['subscriptions_form_in_block'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'subscriptions_form_link_only';
  $strongarm->value = '0';
  $export['subscriptions_form_link_only'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'subscriptions_hide_overview_page';
  $strongarm->value = 0;
  $export['subscriptions_hide_overview_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'subscriptions_number_of_mails';
  $strongarm->value = '0';
  $export['subscriptions_number_of_mails'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'subscriptions_omitted_taxa';
  $strongarm->value = array();
  $export['subscriptions_omitted_taxa'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'subscriptions_preview_mode';
  $strongarm->value = 'text';
  $export['subscriptions_preview_mode'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'subscriptions_restricted_taxa';
  $strongarm->value = array();
  $export['subscriptions_restricted_taxa'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'subscriptions_send_intervals';
  $strongarm->value = array(
    1 => 'As soon as possible',
    86400 => 'Daily',
    604800 => 'Weekly',
  );
  $export['subscriptions_send_intervals'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'subscriptions_showmailkeys';
  $strongarm->value = 1;
  $export['subscriptions_showmailkeys'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'subscriptions_show_by_author_options';
  $strongarm->value = 0;
  $export['subscriptions_show_by_author_options'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'subscriptions_show_install_info';
  $strongarm->value = 0;
  $export['subscriptions_show_install_info'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'subscriptions_site_mail';
  $strongarm->value = 'open.proposal@ucsf.edu';
  $export['subscriptions_site_mail'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'subscriptions_site_mail_name';
  $strongarm->value = 'Open Proposals';
  $export['subscriptions_site_mail_name'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'subscriptions_watchall';
  $strongarm->value = 1;
  $export['subscriptions_watchall'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'subscriptions_watchgood';
  $strongarm->value = 1;
  $export['subscriptions_watchgood'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'subscriptions_watchstats';
  $strongarm->value = 1;
  $export['subscriptions_watchstats'] = $strongarm;

  return $export;
}
