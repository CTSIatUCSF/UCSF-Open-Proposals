<?php
/**
 * @file
 * opg_core.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function opg_core_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_about|node|opg_group|form';
  $field_group->group_name = 'group_about';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'opg_group';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'About Page',
    'weight' => '8',
    'children' => array(
      0 => 'field_opg_about',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'About Page',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_about|node|opg_group|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_form_intro|node|opg_group|form';
  $field_group->group_name = 'group_form_intro';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'opg_group';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Submission Form',
    'weight' => '7',
    'children' => array(
      0 => 'field_opg_form_intro',
      1 => 'field_opg_noun',
      2 => 'field_opg_postwords',
      3 => 'field_opg_submission_templates',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Submission Form',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-form-intro field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_form_intro|node|opg_group|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_header_tab|node|opg_group|form';
  $field_group->group_name = 'group_header_tab';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'opg_group';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Header',
    'weight' => '9',
    'children' => array(
      0 => 'field_opg_logo',
      1 => 'field_opg_logo_image',
      2 => 'field_opg_navbar',
      3 => 'field_opg_poweredby',
      4 => 'field_opg_right_header',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Header',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_header_tab|node|opg_group|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_misc_tab|node|opg_group|form';
  $field_group->group_name = 'group_misc_tab';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'opg_group';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Miscellaneous',
    'weight' => '11',
    'children' => array(
      0 => 'field_opg_postlogin',
      1 => 'field_opg_sublogin',
      2 => 'field_opg_groupword',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Miscellaneous',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_misc_tab|node|opg_group|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_opg_mgr|node|opg_group|form';
  $field_group->group_name = 'group_opg_mgr';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'opg_group';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Opportunity Manager',
    'weight' => '10',
    'children' => array(
      0 => 'field_opg_mgr_email',
      1 => 'field_opg_mgr_name',
      2 => 'field_opg_mgr_phone',
      3 => 'field_opg_mgr_photo',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Opportunity Manager',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-opg-mgr field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_opg_mgr|node|opg_group|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_opg_og_settings|node|opg_group|form';
  $field_group->group_name = 'group_opg_og_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'opg_group';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'OG Settings',
    'weight' => '13',
    'children' => array(
      0 => 'group_access',
      1 => 'group_group',
      2 => 'og_group_ref',
      3 => 'og_roles_permissions',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-opg-og-settings field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_opg_og_settings|node|opg_group|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_opg_settings|node|opg_group|form';
  $field_group->group_name = 'group_opg_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'opg_group';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'OPG Settings',
    'weight' => '12',
    'children' => array(
      0 => 'field_opg_login_type',
      1 => 'field_opg_noanoncom',
      2 => 'field_opg_novote_comment',
      3 => 'field_opg_novote_node',
      4 => 'field_opg_post_type',
      5 => 'field_opg_revision_tab',
      6 => 'field_opg_status_voc',
      7 => 'field_opg_teaser_comments',
      8 => 'field_opg_taxo_blocks',
      9 => 'path',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_opg_settings|node|opg_group|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_phases|node|opg_group|form';
  $field_group->group_name = 'group_phases';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'opg_group';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Home Page Intro',
    'weight' => '5',
    'children' => array(
      0 => 'body',
      1 => 'field_opg_details_link',
      2 => 'field_opg_phases',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Home Page Intro',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-phases field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_phases|node|opg_group|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_textblock_tab|node|opg_group|form';
  $field_group->group_name = 'group_textblock_tab';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'opg_group';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Text Blocks',
    'weight' => '6',
    'children' => array(
      0 => 'field_opg_addbtn_anon',
      1 => 'field_opg_addbtn_auth',
      2 => 'field_opg_admin_navblock',
      3 => 'field_opg_group_admin_navblock',
      4 => 'field_opg_navblock',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Text Blocks',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_textblock_tab|node|opg_group|form'] = $field_group;

  return $export;
}
