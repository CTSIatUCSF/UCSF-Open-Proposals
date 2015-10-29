<?php
/**
 * @file
 * opg_core.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function opg_core_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:opg_default_group:add user'
  $permissions['node:opg_default_group:add user'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:administer group'
  $permissions['node:opg_default_group:administer group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:administer taxonomy'
  $permissions['node:opg_default_group:administer taxonomy'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_default_group:approve and deny subscription'
  $permissions['node:opg_default_group:approve and deny subscription'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:create opg_admin_post content'
  $permissions['node:opg_default_group:create opg_admin_post content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_default_group:create opg_group content'
  $permissions['node:opg_default_group:create opg_group content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_default_group:create page content'
  $permissions['node:opg_default_group:create page content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_default_group:delete any opg_admin_post content'
  $permissions['node:opg_default_group:delete any opg_admin_post content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_default_group:delete any opg_group content'
  $permissions['node:opg_default_group:delete any opg_group content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_default_group:delete any page content'
  $permissions['node:opg_default_group:delete any page content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_default_group:delete own opg_admin_post content'
  $permissions['node:opg_default_group:delete own opg_admin_post content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_default_group:delete own opg_group content'
  $permissions['node:opg_default_group:delete own opg_group content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_default_group:delete own page content'
  $permissions['node:opg_default_group:delete own page content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_default_group:delete terms'
  $permissions['node:opg_default_group:delete terms'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_default_group:edit terms'
  $permissions['node:opg_default_group:edit terms'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_default_group:manage members'
  $permissions['node:opg_default_group:manage members'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:manage permissions'
  $permissions['node:opg_default_group:manage permissions'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:manage roles'
  $permissions['node:opg_default_group:manage roles'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:subscribe'
  $permissions['node:opg_default_group:subscribe'] = array(
    'roles' => array(
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:subscribe without approval'
  $permissions['node:opg_default_group:subscribe without approval'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_default_group:unsubscribe'
  $permissions['node:opg_default_group:unsubscribe'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:update any opg_admin_post content'
  $permissions['node:opg_default_group:update any opg_admin_post content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_default_group:update any opg_group content'
  $permissions['node:opg_default_group:update any opg_group content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_default_group:update any page content'
  $permissions['node:opg_default_group:update any page content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_default_group:update body field'
  $permissions['node:opg_default_group:update body field'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:update field_first_name field'
  $permissions['node:opg_default_group:update field_first_name field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:update field_last_name field'
  $permissions['node:opg_default_group:update field_last_name field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:update field_opg_about field'
  $permissions['node:opg_default_group:update field_opg_about field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:update field_opg_addbtn_anon field'
  $permissions['node:opg_default_group:update field_opg_addbtn_anon field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:update field_opg_addbtn_auth field'
  $permissions['node:opg_default_group:update field_opg_addbtn_auth field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:update field_opg_admin_navblock field'
  $permissions['node:opg_default_group:update field_opg_admin_navblock field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:update field_opg_ap_send field'
  $permissions['node:opg_default_group:update field_opg_ap_send field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:update field_opg_details_link field'
  $permissions['node:opg_default_group:update field_opg_details_link field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:update field_opg_form_intro field'
  $permissions['node:opg_default_group:update field_opg_form_intro field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:update field_opg_group_admin_navblock field'
  $permissions['node:opg_default_group:update field_opg_group_admin_navblock field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:update field_opg_group_status field'
  $permissions['node:opg_default_group:update field_opg_group_status field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:update field_opg_groupword field'
  $permissions['node:opg_default_group:update field_opg_groupword field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_default_group:update field_opg_login_type field'
  $permissions['node:opg_default_group:update field_opg_login_type field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:update field_opg_logo field'
  $permissions['node:opg_default_group:update field_opg_logo field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:update field_opg_logo_image field'
  $permissions['node:opg_default_group:update field_opg_logo_image field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:update field_opg_mgr_email field'
  $permissions['node:opg_default_group:update field_opg_mgr_email field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:update field_opg_mgr_name field'
  $permissions['node:opg_default_group:update field_opg_mgr_name field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:update field_opg_mgr_phone field'
  $permissions['node:opg_default_group:update field_opg_mgr_phone field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:update field_opg_mgr_photo field'
  $permissions['node:opg_default_group:update field_opg_mgr_photo field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:update field_opg_multifile field'
  $permissions['node:opg_default_group:update field_opg_multifile field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:update field_opg_navbar field'
  $permissions['node:opg_default_group:update field_opg_navbar field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:update field_opg_navblock field'
  $permissions['node:opg_default_group:update field_opg_navblock field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:update field_opg_noanoncom field'
  $permissions['node:opg_default_group:update field_opg_noanoncom field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:update field_opg_noun field'
  $permissions['node:opg_default_group:update field_opg_noun field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:update field_opg_novote_comment field'
  $permissions['node:opg_default_group:update field_opg_novote_comment field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:update field_opg_novote_node field'
  $permissions['node:opg_default_group:update field_opg_novote_node field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:update field_opg_phases field'
  $permissions['node:opg_default_group:update field_opg_phases field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:update field_opg_post_type field'
  $permissions['node:opg_default_group:update field_opg_post_type field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:update field_opg_postlogin field'
  $permissions['node:opg_default_group:update field_opg_postlogin field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:update field_opg_postwords field'
  $permissions['node:opg_default_group:update field_opg_postwords field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:update field_opg_poweredby field'
  $permissions['node:opg_default_group:update field_opg_poweredby field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:update field_opg_primary_author field'
  $permissions['node:opg_default_group:update field_opg_primary_author field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:update field_opg_revision_tab field'
  $permissions['node:opg_default_group:update field_opg_revision_tab field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:update field_opg_right_header field'
  $permissions['node:opg_default_group:update field_opg_right_header field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:update field_opg_singlefile field'
  $permissions['node:opg_default_group:update field_opg_singlefile field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:update field_opg_sponsor field'
  $permissions['node:opg_default_group:update field_opg_sponsor field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:update field_opg_start_date field'
  $permissions['node:opg_default_group:update field_opg_start_date field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:update field_opg_status field'
  $permissions['node:opg_default_group:update field_opg_status field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:update field_opg_status_voc field'
  $permissions['node:opg_default_group:update field_opg_status_voc field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:update field_opg_sublogin field'
  $permissions['node:opg_default_group:update field_opg_sublogin field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:update field_opg_submission_templates field'
  $permissions['node:opg_default_group:update field_opg_submission_templates field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:update field_opg_subtitle field'
  $permissions['node:opg_default_group:update field_opg_subtitle field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:update field_opg_taxo_blocks field'
  $permissions['node:opg_default_group:update field_opg_taxo_blocks field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_default_group:update field_opg_teaser_comments field'
  $permissions['node:opg_default_group:update field_opg_teaser_comments field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_default_group:update field_org field'
  $permissions['node:opg_default_group:update field_org field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:update field_register_as_other field'
  $permissions['node:opg_default_group:update field_register_as_other field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:update field_title field'
  $permissions['node:opg_default_group:update field_title field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:update group'
  $permissions['node:opg_default_group:update group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:update group_access field'
  $permissions['node:opg_default_group:update group_access field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:update group_content_access field'
  $permissions['node:opg_default_group:update group_content_access field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:update group_group field'
  $permissions['node:opg_default_group:update group_group field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:update og_group_ref field'
  $permissions['node:opg_default_group:update og_group_ref field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:update og_roles_permissions field'
  $permissions['node:opg_default_group:update og_roles_permissions field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:update og_user_node field'
  $permissions['node:opg_default_group:update og_user_node field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:update og_vocabulary field'
  $permissions['node:opg_default_group:update og_vocabulary field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:update own opg_admin_post content'
  $permissions['node:opg_default_group:update own opg_admin_post content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_default_group:update own opg_group content'
  $permissions['node:opg_default_group:update own opg_group content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_default_group:update own page content'
  $permissions['node:opg_default_group:update own page content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_default_group:update upload field'
  $permissions['node:opg_default_group:update upload field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_default_group:view body field'
  $permissions['node:opg_default_group:view body field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:view field_first_name field'
  $permissions['node:opg_default_group:view field_first_name field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:view field_last_name field'
  $permissions['node:opg_default_group:view field_last_name field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:view field_opg_about field'
  $permissions['node:opg_default_group:view field_opg_about field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:view field_opg_addbtn_anon field'
  $permissions['node:opg_default_group:view field_opg_addbtn_anon field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:view field_opg_addbtn_auth field'
  $permissions['node:opg_default_group:view field_opg_addbtn_auth field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:view field_opg_admin_navblock field'
  $permissions['node:opg_default_group:view field_opg_admin_navblock field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:view field_opg_ap_send field'
  $permissions['node:opg_default_group:view field_opg_ap_send field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:view field_opg_details_link field'
  $permissions['node:opg_default_group:view field_opg_details_link field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:view field_opg_form_intro field'
  $permissions['node:opg_default_group:view field_opg_form_intro field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:view field_opg_group_admin_navblock field'
  $permissions['node:opg_default_group:view field_opg_group_admin_navblock field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:view field_opg_group_status field'
  $permissions['node:opg_default_group:view field_opg_group_status field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:view field_opg_groupword field'
  $permissions['node:opg_default_group:view field_opg_groupword field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_default_group:view field_opg_login_type field'
  $permissions['node:opg_default_group:view field_opg_login_type field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:view field_opg_logo field'
  $permissions['node:opg_default_group:view field_opg_logo field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:view field_opg_logo_image field'
  $permissions['node:opg_default_group:view field_opg_logo_image field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:view field_opg_mgr_email field'
  $permissions['node:opg_default_group:view field_opg_mgr_email field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:view field_opg_mgr_name field'
  $permissions['node:opg_default_group:view field_opg_mgr_name field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:view field_opg_mgr_phone field'
  $permissions['node:opg_default_group:view field_opg_mgr_phone field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:view field_opg_mgr_photo field'
  $permissions['node:opg_default_group:view field_opg_mgr_photo field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:view field_opg_multifile field'
  $permissions['node:opg_default_group:view field_opg_multifile field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:view field_opg_navbar field'
  $permissions['node:opg_default_group:view field_opg_navbar field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:view field_opg_navblock field'
  $permissions['node:opg_default_group:view field_opg_navblock field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:view field_opg_noanoncom field'
  $permissions['node:opg_default_group:view field_opg_noanoncom field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:view field_opg_noun field'
  $permissions['node:opg_default_group:view field_opg_noun field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:view field_opg_novote_comment field'
  $permissions['node:opg_default_group:view field_opg_novote_comment field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:view field_opg_novote_node field'
  $permissions['node:opg_default_group:view field_opg_novote_node field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:view field_opg_phases field'
  $permissions['node:opg_default_group:view field_opg_phases field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:view field_opg_post_type field'
  $permissions['node:opg_default_group:view field_opg_post_type field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:view field_opg_postlogin field'
  $permissions['node:opg_default_group:view field_opg_postlogin field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:view field_opg_postwords field'
  $permissions['node:opg_default_group:view field_opg_postwords field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:view field_opg_poweredby field'
  $permissions['node:opg_default_group:view field_opg_poweredby field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:view field_opg_primary_author field'
  $permissions['node:opg_default_group:view field_opg_primary_author field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:view field_opg_revision_tab field'
  $permissions['node:opg_default_group:view field_opg_revision_tab field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:view field_opg_right_header field'
  $permissions['node:opg_default_group:view field_opg_right_header field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:view field_opg_singlefile field'
  $permissions['node:opg_default_group:view field_opg_singlefile field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:view field_opg_sponsor field'
  $permissions['node:opg_default_group:view field_opg_sponsor field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:view field_opg_start_date field'
  $permissions['node:opg_default_group:view field_opg_start_date field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:view field_opg_status field'
  $permissions['node:opg_default_group:view field_opg_status field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:view field_opg_status_voc field'
  $permissions['node:opg_default_group:view field_opg_status_voc field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:view field_opg_sublogin field'
  $permissions['node:opg_default_group:view field_opg_sublogin field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:view field_opg_submission_templates field'
  $permissions['node:opg_default_group:view field_opg_submission_templates field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:view field_opg_subtitle field'
  $permissions['node:opg_default_group:view field_opg_subtitle field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:view field_opg_taxo_blocks field'
  $permissions['node:opg_default_group:view field_opg_taxo_blocks field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_default_group:view field_opg_teaser_comments field'
  $permissions['node:opg_default_group:view field_opg_teaser_comments field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_default_group:view field_org field'
  $permissions['node:opg_default_group:view field_org field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:view field_register_as_other field'
  $permissions['node:opg_default_group:view field_register_as_other field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:view field_title field'
  $permissions['node:opg_default_group:view field_title field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:view group_access field'
  $permissions['node:opg_default_group:view group_access field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:view group_content_access field'
  $permissions['node:opg_default_group:view group_content_access field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:view group_group field'
  $permissions['node:opg_default_group:view group_group field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:view og_group_ref field'
  $permissions['node:opg_default_group:view og_group_ref field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:view og_roles_permissions field'
  $permissions['node:opg_default_group:view og_roles_permissions field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:view og_user_node field'
  $permissions['node:opg_default_group:view og_user_node field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:view og_vocabulary field'
  $permissions['node:opg_default_group:view og_vocabulary field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_default_group:view upload field'
  $permissions['node:opg_default_group:view upload field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_group:add user'
  $permissions['node:opg_group:add user'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_group:administer group'
  $permissions['node:opg_group:administer group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_group:administer taxonomy'
  $permissions['node:opg_group:administer taxonomy'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_group:approve and deny subscription'
  $permissions['node:opg_group:approve and deny subscription'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_group:create opg_admin_post content'
  $permissions['node:opg_group:create opg_admin_post content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_group:create opg_group content'
  $permissions['node:opg_group:create opg_group content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_group:create page content'
  $permissions['node:opg_group:create page content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_group:delete any opg_admin_post content'
  $permissions['node:opg_group:delete any opg_admin_post content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_group:delete any opg_group content'
  $permissions['node:opg_group:delete any opg_group content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_group:delete any page content'
  $permissions['node:opg_group:delete any page content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_group:delete own opg_admin_post content'
  $permissions['node:opg_group:delete own opg_admin_post content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_group:delete own opg_group content'
  $permissions['node:opg_group:delete own opg_group content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_group:delete own page content'
  $permissions['node:opg_group:delete own page content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_group:delete terms'
  $permissions['node:opg_group:delete terms'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_group:edit terms'
  $permissions['node:opg_group:edit terms'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_group:manage members'
  $permissions['node:opg_group:manage members'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_group:manage permissions'
  $permissions['node:opg_group:manage permissions'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_group:manage roles'
  $permissions['node:opg_group:manage roles'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_group:subscribe'
  $permissions['node:opg_group:subscribe'] = array(
    'roles' => array(
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_group:subscribe without approval'
  $permissions['node:opg_group:subscribe without approval'] = array(
    'roles' => array(
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_group:unsubscribe'
  $permissions['node:opg_group:unsubscribe'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:opg_group:update any opg_admin_post content'
  $permissions['node:opg_group:update any opg_admin_post content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_group:update any opg_group content'
  $permissions['node:opg_group:update any opg_group content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_group:update any page content'
  $permissions['node:opg_group:update any page content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_group:update body field'
  $permissions['node:opg_group:update body field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_group:update field_first_name field'
  $permissions['node:opg_group:update field_first_name field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_group:update field_last_name field'
  $permissions['node:opg_group:update field_last_name field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_group:update field_opg_about field'
  $permissions['node:opg_group:update field_opg_about field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_group:update field_opg_addbtn_anon field'
  $permissions['node:opg_group:update field_opg_addbtn_anon field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_group:update field_opg_addbtn_auth field'
  $permissions['node:opg_group:update field_opg_addbtn_auth field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_group:update field_opg_admin_navblock field'
  $permissions['node:opg_group:update field_opg_admin_navblock field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_group:update field_opg_ap_send field'
  $permissions['node:opg_group:update field_opg_ap_send field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_group:update field_opg_details_link field'
  $permissions['node:opg_group:update field_opg_details_link field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_group:update field_opg_form_intro field'
  $permissions['node:opg_group:update field_opg_form_intro field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_group:update field_opg_group_admin_navblock field'
  $permissions['node:opg_group:update field_opg_group_admin_navblock field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_group:update field_opg_group_status field'
  $permissions['node:opg_group:update field_opg_group_status field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_group:update field_opg_groupword field'
  $permissions['node:opg_group:update field_opg_groupword field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_group:update field_opg_login_type field'
  $permissions['node:opg_group:update field_opg_login_type field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_group:update field_opg_logo field'
  $permissions['node:opg_group:update field_opg_logo field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_group:update field_opg_logo_image field'
  $permissions['node:opg_group:update field_opg_logo_image field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_group:update field_opg_mgr_email field'
  $permissions['node:opg_group:update field_opg_mgr_email field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_group:update field_opg_mgr_name field'
  $permissions['node:opg_group:update field_opg_mgr_name field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_group:update field_opg_mgr_phone field'
  $permissions['node:opg_group:update field_opg_mgr_phone field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_group:update field_opg_mgr_photo field'
  $permissions['node:opg_group:update field_opg_mgr_photo field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_group:update field_opg_multifile field'
  $permissions['node:opg_group:update field_opg_multifile field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_group:update field_opg_navbar field'
  $permissions['node:opg_group:update field_opg_navbar field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_group:update field_opg_navblock field'
  $permissions['node:opg_group:update field_opg_navblock field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_group:update field_opg_noanoncom field'
  $permissions['node:opg_group:update field_opg_noanoncom field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_group:update field_opg_noun field'
  $permissions['node:opg_group:update field_opg_noun field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_group:update field_opg_novote_comment field'
  $permissions['node:opg_group:update field_opg_novote_comment field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_group:update field_opg_novote_node field'
  $permissions['node:opg_group:update field_opg_novote_node field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_group:update field_opg_phases field'
  $permissions['node:opg_group:update field_opg_phases field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_group:update field_opg_post_type field'
  $permissions['node:opg_group:update field_opg_post_type field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_group:update field_opg_postlogin field'
  $permissions['node:opg_group:update field_opg_postlogin field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_group:update field_opg_postwords field'
  $permissions['node:opg_group:update field_opg_postwords field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_group:update field_opg_poweredby field'
  $permissions['node:opg_group:update field_opg_poweredby field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_group:update field_opg_primary_author field'
  $permissions['node:opg_group:update field_opg_primary_author field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_group:update field_opg_revision_tab field'
  $permissions['node:opg_group:update field_opg_revision_tab field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_group:update field_opg_right_header field'
  $permissions['node:opg_group:update field_opg_right_header field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_group:update field_opg_singlefile field'
  $permissions['node:opg_group:update field_opg_singlefile field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_group:update field_opg_sponsor field'
  $permissions['node:opg_group:update field_opg_sponsor field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_group:update field_opg_start_date field'
  $permissions['node:opg_group:update field_opg_start_date field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_group:update field_opg_status field'
  $permissions['node:opg_group:update field_opg_status field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_group:update field_opg_status_voc field'
  $permissions['node:opg_group:update field_opg_status_voc field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_group:update field_opg_sublogin field'
  $permissions['node:opg_group:update field_opg_sublogin field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_group:update field_opg_submission_templates field'
  $permissions['node:opg_group:update field_opg_submission_templates field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_group:update field_opg_subtitle field'
  $permissions['node:opg_group:update field_opg_subtitle field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_group:update field_opg_taxo_blocks field'
  $permissions['node:opg_group:update field_opg_taxo_blocks field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_group:update field_opg_teaser_comments field'
  $permissions['node:opg_group:update field_opg_teaser_comments field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_group:update field_org field'
  $permissions['node:opg_group:update field_org field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_group:update field_register_as_other field'
  $permissions['node:opg_group:update field_register_as_other field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_group:update field_title field'
  $permissions['node:opg_group:update field_title field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_group:update group'
  $permissions['node:opg_group:update group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_group:update group_access field'
  $permissions['node:opg_group:update group_access field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_group:update group_content_access field'
  $permissions['node:opg_group:update group_content_access field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_group:update group_group field'
  $permissions['node:opg_group:update group_group field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_group:update og_group_ref field'
  $permissions['node:opg_group:update og_group_ref field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_group:update og_roles_permissions field'
  $permissions['node:opg_group:update og_roles_permissions field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_group:update og_user_node field'
  $permissions['node:opg_group:update og_user_node field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_group:update og_vocabulary field'
  $permissions['node:opg_group:update og_vocabulary field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_group:update own opg_admin_post content'
  $permissions['node:opg_group:update own opg_admin_post content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_group:update own opg_group content'
  $permissions['node:opg_group:update own opg_group content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_group:update own page content'
  $permissions['node:opg_group:update own page content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_group:update upload field'
  $permissions['node:opg_group:update upload field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_group:view body field'
  $permissions['node:opg_group:view body field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_group:view field_first_name field'
  $permissions['node:opg_group:view field_first_name field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_group:view field_last_name field'
  $permissions['node:opg_group:view field_last_name field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_group:view field_opg_about field'
  $permissions['node:opg_group:view field_opg_about field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_group:view field_opg_addbtn_anon field'
  $permissions['node:opg_group:view field_opg_addbtn_anon field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_group:view field_opg_addbtn_auth field'
  $permissions['node:opg_group:view field_opg_addbtn_auth field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_group:view field_opg_admin_navblock field'
  $permissions['node:opg_group:view field_opg_admin_navblock field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_group:view field_opg_ap_send field'
  $permissions['node:opg_group:view field_opg_ap_send field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_group:view field_opg_details_link field'
  $permissions['node:opg_group:view field_opg_details_link field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_group:view field_opg_form_intro field'
  $permissions['node:opg_group:view field_opg_form_intro field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_group:view field_opg_group_admin_navblock field'
  $permissions['node:opg_group:view field_opg_group_admin_navblock field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_group:view field_opg_group_status field'
  $permissions['node:opg_group:view field_opg_group_status field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_group:view field_opg_groupword field'
  $permissions['node:opg_group:view field_opg_groupword field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_group:view field_opg_login_type field'
  $permissions['node:opg_group:view field_opg_login_type field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_group:view field_opg_logo field'
  $permissions['node:opg_group:view field_opg_logo field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_group:view field_opg_logo_image field'
  $permissions['node:opg_group:view field_opg_logo_image field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_group:view field_opg_mgr_email field'
  $permissions['node:opg_group:view field_opg_mgr_email field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_group:view field_opg_mgr_name field'
  $permissions['node:opg_group:view field_opg_mgr_name field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_group:view field_opg_mgr_phone field'
  $permissions['node:opg_group:view field_opg_mgr_phone field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_group:view field_opg_mgr_photo field'
  $permissions['node:opg_group:view field_opg_mgr_photo field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_group:view field_opg_multifile field'
  $permissions['node:opg_group:view field_opg_multifile field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_group:view field_opg_navbar field'
  $permissions['node:opg_group:view field_opg_navbar field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_group:view field_opg_navblock field'
  $permissions['node:opg_group:view field_opg_navblock field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_group:view field_opg_noanoncom field'
  $permissions['node:opg_group:view field_opg_noanoncom field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_group:view field_opg_noun field'
  $permissions['node:opg_group:view field_opg_noun field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_group:view field_opg_novote_comment field'
  $permissions['node:opg_group:view field_opg_novote_comment field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_group:view field_opg_novote_node field'
  $permissions['node:opg_group:view field_opg_novote_node field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_group:view field_opg_phases field'
  $permissions['node:opg_group:view field_opg_phases field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_group:view field_opg_post_type field'
  $permissions['node:opg_group:view field_opg_post_type field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_group:view field_opg_postlogin field'
  $permissions['node:opg_group:view field_opg_postlogin field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_group:view field_opg_postwords field'
  $permissions['node:opg_group:view field_opg_postwords field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_group:view field_opg_poweredby field'
  $permissions['node:opg_group:view field_opg_poweredby field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_group:view field_opg_primary_author field'
  $permissions['node:opg_group:view field_opg_primary_author field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_group:view field_opg_revision_tab field'
  $permissions['node:opg_group:view field_opg_revision_tab field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_group:view field_opg_right_header field'
  $permissions['node:opg_group:view field_opg_right_header field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_group:view field_opg_singlefile field'
  $permissions['node:opg_group:view field_opg_singlefile field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_group:view field_opg_sponsor field'
  $permissions['node:opg_group:view field_opg_sponsor field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_group:view field_opg_start_date field'
  $permissions['node:opg_group:view field_opg_start_date field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_group:view field_opg_status field'
  $permissions['node:opg_group:view field_opg_status field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_group:view field_opg_status_voc field'
  $permissions['node:opg_group:view field_opg_status_voc field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_group:view field_opg_sublogin field'
  $permissions['node:opg_group:view field_opg_sublogin field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_group:view field_opg_submission_templates field'
  $permissions['node:opg_group:view field_opg_submission_templates field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_group:view field_opg_subtitle field'
  $permissions['node:opg_group:view field_opg_subtitle field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_group:view field_opg_taxo_blocks field'
  $permissions['node:opg_group:view field_opg_taxo_blocks field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_group:view field_opg_teaser_comments field'
  $permissions['node:opg_group:view field_opg_teaser_comments field'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:opg_group:view field_org field'
  $permissions['node:opg_group:view field_org field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_group:view field_register_as_other field'
  $permissions['node:opg_group:view field_register_as_other field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_group:view field_title field'
  $permissions['node:opg_group:view field_title field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_group:view group_access field'
  $permissions['node:opg_group:view group_access field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_group:view group_content_access field'
  $permissions['node:opg_group:view group_content_access field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_group:view group_group field'
  $permissions['node:opg_group:view group_group field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_group:view og_group_ref field'
  $permissions['node:opg_group:view og_group_ref field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_group:view og_roles_permissions field'
  $permissions['node:opg_group:view og_roles_permissions field'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:opg_group:view og_user_node field'
  $permissions['node:opg_group:view og_user_node field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_group:view og_vocabulary field'
  $permissions['node:opg_group:view og_vocabulary field'] = array(
    'roles' => array(
      'member' => 'member',
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:opg_group:view upload field'
  $permissions['node:opg_group:view upload field'] = array(
    'roles' => array(),
  );

  return $permissions;
}
