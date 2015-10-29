<?php
/**
 * @file
 * opg_core.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function opg_core_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_opg_admin_post';
  $strongarm->value = '1';
  $export['comment_anonymous_opg_admin_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_opg_default_group';
  $strongarm->value = '0';
  $export['comment_anonymous_opg_default_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_opg_group';
  $strongarm->value = '0';
  $export['comment_anonymous_opg_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_opg_admin_post';
  $strongarm->value = 1;
  $export['comment_default_mode_opg_admin_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_opg_default_group';
  $strongarm->value = 1;
  $export['comment_default_mode_opg_default_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_opg_group';
  $strongarm->value = 0;
  $export['comment_default_mode_opg_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_opg_admin_post';
  $strongarm->value = '50';
  $export['comment_default_per_page_opg_admin_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_opg_default_group';
  $strongarm->value = '10';
  $export['comment_default_per_page_opg_default_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_opg_group';
  $strongarm->value = '10';
  $export['comment_default_per_page_opg_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_opg_admin_post';
  $strongarm->value = 0;
  $export['comment_form_location_opg_admin_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_opg_default_group';
  $strongarm->value = 0;
  $export['comment_form_location_opg_default_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_opg_group';
  $strongarm->value = 0;
  $export['comment_form_location_opg_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_opg_admin_post';
  $strongarm->value = '2';
  $export['comment_opg_admin_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_opg_default_group';
  $strongarm->value = '0';
  $export['comment_opg_default_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_opg_group';
  $strongarm->value = '0';
  $export['comment_opg_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_opg_admin_post';
  $strongarm->value = '1';
  $export['comment_preview_opg_admin_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_opg_default_group';
  $strongarm->value = '0';
  $export['comment_preview_opg_default_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_opg_group';
  $strongarm->value = '0';
  $export['comment_preview_opg_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_opg_admin_post';
  $strongarm->value = 0;
  $export['comment_subject_field_opg_admin_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_opg_default_group';
  $strongarm->value = 0;
  $export['comment_subject_field_opg_default_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_opg_group';
  $strongarm->value = 0;
  $export['comment_subject_field_opg_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ctsi_allow_anonymous_comments_opg_admin_post';
  $strongarm->value = 0;
  $export['ctsi_allow_anonymous_comments_opg_admin_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ctsi_allow_anonymous_comments_opg_default_group';
  $strongarm->value = 0;
  $export['ctsi_allow_anonymous_comments_opg_default_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ctsi_allow_anonymous_comments_opg_group';
  $strongarm->value = 1;
  $export['ctsi_allow_anonymous_comments_opg_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ctsi_allow_drupal_logins_opg_admin_post';
  $strongarm->value = 1;
  $export['ctsi_allow_drupal_logins_opg_admin_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ctsi_allow_drupal_logins_opg_default_group';
  $strongarm->value = 1;
  $export['ctsi_allow_drupal_logins_opg_default_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ctsi_allow_drupal_logins_opg_group';
  $strongarm->value = 1;
  $export['ctsi_allow_drupal_logins_opg_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ctsi_login_type_opg_admin_post';
  $strongarm->value = 'all';
  $export['ctsi_login_type_opg_admin_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ctsi_login_type_opg_default_group';
  $strongarm->value = 'all';
  $export['ctsi_login_type_opg_default_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ctsi_login_type_opg_group';
  $strongarm->value = 'all';
  $export['ctsi_login_type_opg_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ctsi_revision_tab_opg_admin_post';
  $strongarm->value = 0;
  $export['ctsi_revision_tab_opg_admin_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ctsi_revision_tab_opg_default_group';
  $strongarm->value = 0;
  $export['ctsi_revision_tab_opg_default_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ctsi_revision_tab_opg_group';
  $strongarm->value = 0;
  $export['ctsi_revision_tab_opg_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_enable_revisions_page_node_opg_admin_post';
  $strongarm->value = 1;
  $export['diff_enable_revisions_page_node_opg_admin_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_enable_revisions_page_node_opg_group';
  $strongarm->value = 1;
  $export['diff_enable_revisions_page_node_opg_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_show_preview_changes_node_opg_admin_post';
  $strongarm->value = 1;
  $export['diff_show_preview_changes_node_opg_admin_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_show_preview_changes_node_opg_default_group';
  $strongarm->value = 1;
  $export['diff_show_preview_changes_node_opg_default_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_show_preview_changes_node_opg_group';
  $strongarm->value = 1;
  $export['diff_show_preview_changes_node_opg_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_view_mode_preview_node_opg_admin_post';
  $strongarm->value = 'full';
  $export['diff_view_mode_preview_node_opg_admin_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_view_mode_preview_node_opg_default_group';
  $strongarm->value = 'full';
  $export['diff_view_mode_preview_node_opg_default_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_view_mode_preview_node_opg_group';
  $strongarm->value = 'full';
  $export['diff_view_mode_preview_node_opg_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_comment__comment_node_opg_admin_post';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_comment__comment_node_opg_admin_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_comment__comment_node_opg_default_group';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_comment__comment_node_opg_default_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_comment__comment_node_opg_group';
  $strongarm->value = array(
    'view_modes' => array(
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'teaser' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_comment__comment_node_opg_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_field_collection_item__field_opg_phases';
  $strongarm->value = array(
    'view_modes' => array(
      'full' => array(
        'custom_settings' => TRUE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_field_collection_item__field_opg_phases'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__opg_admin_post';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '5',
        ),
        'redirect' => array(
          'weight' => '4',
        ),
      ),
      'display' => array(
        'subscriptions_ui' => array(
          'default' => array(
            'weight' => '100',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '100',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__opg_admin_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__opg_group';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'node_fields_block' => array(
        'custom_settings' => TRUE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '14',
        ),
        'redirect' => array(
          'weight' => '15',
        ),
      ),
      'display' => array(
        'subscriptions_ui' => array(
          'default' => array(
            'weight' => '3',
            'visible' => TRUE,
          ),
          'node_fields_block' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__opg_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_taxonomy_term__opg_group_status';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'path' => array(
          'weight' => '4',
        ),
        'redirect' => array(
          'weight' => '3',
        ),
        'name' => array(
          'weight' => '0',
        ),
        'description' => array(
          'weight' => '2',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_taxonomy_term__opg_group_status'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_opg_admin_post';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_opg_admin_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_opg_default_group';
  $strongarm->value = array();
  $export['menu_options_opg_default_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_opg_group';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_opg_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_opg_admin_post';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_opg_admin_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_opg_default_group';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_opg_default_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_opg_group';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_opg_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_opg_admin_post';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );
  $export['node_options_opg_admin_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_opg_default_group';
  $strongarm->value = array();
  $export['node_options_opg_default_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_opg_group';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );
  $export['node_options_opg_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_opg_admin_post';
  $strongarm->value = '1';
  $export['node_preview_opg_admin_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_opg_default_group';
  $strongarm->value = '1';
  $export['node_preview_opg_default_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_opg_group';
  $strongarm->value = '0';
  $export['node_preview_opg_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_opg_admin_post';
  $strongarm->value = 1;
  $export['node_submitted_opg_admin_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_opg_default_group';
  $strongarm->value = 0;
  $export['node_submitted_opg_default_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_opg_group';
  $strongarm->value = 0;
  $export['node_submitted_opg_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_context_negotiation_group_context';
  $strongarm->value = array(
    'url' => array(),
    'node' => array(),
    'comment' => array(),
    'opg_core' => array(),
  );
  $export['og_context_negotiation_group_context'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_context_providers_weight_group_context';
  $strongarm->value = array(
    'url' => '-5',
    'node' => '-4',
    'og_extras' => '0',
    'opg_core' => '0',
    'user-edit' => '0',
    'user-view' => '0',
    'comment' => '0',
  );
  $export['og_context_providers_weight_group_context'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_group_manager_default_rids_node_opg_group';
  $strongarm->value = array(
    3 => '3',
  );
  $export['og_group_manager_default_rids_node_opg_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'op_common_taxdef_opg_status';
  $strongarm->value = array(
    0 => 'Open',
  );
  $export['op_common_taxdef_opg_status'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'op_deploy_op_terms_opg_core';
  $strongarm->value = array(
    'opg_group_status' => array(
      'terms' => array(
        0 => array(
          'name' => 'Preview',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        1 => array(
          'name' => 'Active',
          'description' => '',
          'weight' => '1',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        2 => array(
          'name' => 'Inactive',
          'description' => '',
          'weight' => '2',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        3 => array(
          'name' => 'Archived',
          'description' => '',
          'weight' => '3',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
      ),
      'defaults' => array(),
    ),
    'opg_sponsor' => array(
      'terms' => array(
        0 => array(
          'name' => 'Center for Healthcare Value (CHV)',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        1 => array(
          'name' => 'CTSI',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        2 => array(
          'name' => 'Ed Innovations',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        3 => array(
          'name' => 'Medical Education',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        4 => array(
          'name' => 'Research Resource Program (RRP)',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        5 => array(
          'name' => 'School of Medicine',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
      ),
      'defaults' => array(),
    ),
    'opg_status' => array(
      'terms' => array(
        0 => array(
          'name' => 'Administrative',
          'description' => '',
          'weight' => '0',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        1 => array(
          'name' => 'Awarded',
          'description' => '',
          'weight' => '1',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        2 => array(
          'name' => 'In Review',
          'description' => '',
          'weight' => '2',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        3 => array(
          'name' => 'Open',
          'description' => '',
          'weight' => '3',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        4 => array(
          'name' => 'Review Complete',
          'description' => '',
          'weight' => '4',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
        5 => array(
          'name' => 'Withdrawn',
          'description' => '',
          'weight' => '5',
          'format' => 'user_wysiwyg',
          'depth' => 0,
          'parents' => array(
            0 => '0',
          ),
        ),
      ),
      'defaults' => array(
        0 => 'Open',
      ),
    ),
  );
  $export['op_deploy_op_terms_opg_core'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_opg_admin_post_pattern';
  $strongarm->value = 'announcements/[node:nid]';
  $export['pathauto_node_opg_admin_post_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_opg_default_group_pattern';
  $strongarm->value = '';
  $export['pathauto_node_opg_default_group_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_opg_group_pattern';
  $strongarm->value = '';
  $export['pathauto_node_opg_group_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_opg_group_status_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_opg_group_status_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_opg_sponsor_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_opg_sponsor_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_opg_status_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_opg_status_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'subscriptions_default_workflow_opg_admin_post';
  $strongarm->value = array(
    'c_new' => 'c_new',
    'c_unpub' => 'c_unpub',
    'c_pub' => 'c_pub',
  );
  $export['subscriptions_default_workflow_opg_admin_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'subscriptions_default_workflow_opg_default_group';
  $strongarm->value = array(
    'n_new' => 'n_new',
    'n_unpub' => 'n_unpub',
    'n_pub' => 'n_pub',
    'c_new' => 'c_new',
    'c_unpub' => 'c_unpub',
    'c_pub' => 'c_pub',
  );
  $export['subscriptions_default_workflow_opg_default_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'subscriptions_default_workflow_opg_group';
  $strongarm->value = array();
  $export['subscriptions_default_workflow_opg_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'subscriptions_workflow_opg_admin_post';
  $strongarm->value = array(
    0 => 'c_new',
    1 => 'c_unpub',
    2 => 'c_pub',
  );
  $export['subscriptions_workflow_opg_admin_post'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'subscriptions_workflow_opg_default_group';
  $strongarm->value = array(
    0 => 'n_new',
    1 => 'n_unpub',
    2 => 'n_pub',
    3 => 'c_new',
    4 => 'c_unpub',
    5 => 'c_pub',
  );
  $export['subscriptions_workflow_opg_default_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'subscriptions_workflow_opg_group';
  $strongarm->value = array();
  $export['subscriptions_workflow_opg_group'] = $strongarm;

  return $export;
}
