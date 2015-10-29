<?php
/**
 * @file
 * opg_core.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function opg_core_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer group'.
  $permissions['administer group'] = array(
    'name' => 'administer group',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'og',
  );

  // Exported permission: 'create field_opg_addbtn_anon'.
  $permissions['create field_opg_addbtn_anon'] = array(
    'name' => 'create field_opg_addbtn_anon',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_opg_addbtn_auth'.
  $permissions['create field_opg_addbtn_auth'] = array(
    'name' => 'create field_opg_addbtn_auth',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_opg_admin_navblock'.
  $permissions['create field_opg_admin_navblock'] = array(
    'name' => 'create field_opg_admin_navblock',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_opg_details_link'.
  $permissions['create field_opg_details_link'] = array(
    'name' => 'create field_opg_details_link',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_opg_group_admin_navblock'.
  $permissions['create field_opg_group_admin_navblock'] = array(
    'name' => 'create field_opg_group_admin_navblock',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_opg_logo'.
  $permissions['create field_opg_logo'] = array(
    'name' => 'create field_opg_logo',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_opg_logo_image'.
  $permissions['create field_opg_logo_image'] = array(
    'name' => 'create field_opg_logo_image',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_opg_navbar'.
  $permissions['create field_opg_navbar'] = array(
    'name' => 'create field_opg_navbar',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_opg_navblock'.
  $permissions['create field_opg_navblock'] = array(
    'name' => 'create field_opg_navblock',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_opg_post_type'.
  $permissions['create field_opg_post_type'] = array(
    'name' => 'create field_opg_post_type',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_opg_postlogin'.
  $permissions['create field_opg_postlogin'] = array(
    'name' => 'create field_opg_postlogin',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_opg_poweredby'.
  $permissions['create field_opg_poweredby'] = array(
    'name' => 'create field_opg_poweredby',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_opg_right_header'.
  $permissions['create field_opg_right_header'] = array(
    'name' => 'create field_opg_right_header',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_opg_status_voc'.
  $permissions['create field_opg_status_voc'] = array(
    'name' => 'create field_opg_status_voc',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_opg_sublogin'.
  $permissions['create field_opg_sublogin'] = array(
    'name' => 'create field_opg_sublogin',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create opg_admin_post content'.
  $permissions['create opg_admin_post content'] = array(
    'name' => 'create opg_admin_post content',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create opg_default_group content'.
  $permissions['create opg_default_group content'] = array(
    'name' => 'create opg_default_group content',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create opg_group content'.
  $permissions['create opg_group content'] = array(
    'name' => 'create opg_group content',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any opg_admin_post content'.
  $permissions['delete any opg_admin_post content'] = array(
    'name' => 'delete any opg_admin_post content',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any opg_default_group content'.
  $permissions['delete any opg_default_group content'] = array(
    'name' => 'delete any opg_default_group content',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any opg_group content'.
  $permissions['delete any opg_group content'] = array(
    'name' => 'delete any opg_group content',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own opg_admin_post content'.
  $permissions['delete own opg_admin_post content'] = array(
    'name' => 'delete own opg_admin_post content',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own opg_default_group content'.
  $permissions['delete own opg_default_group content'] = array(
    'name' => 'delete own opg_default_group content',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own opg_group content'.
  $permissions['delete own opg_group content'] = array(
    'name' => 'delete own opg_group content',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in opg_group_status'.
  $permissions['delete terms in opg_group_status'] = array(
    'name' => 'delete terms in opg_group_status',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in opg_sponsor'.
  $permissions['delete terms in opg_sponsor'] = array(
    'name' => 'delete terms in opg_sponsor',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in opg_status'.
  $permissions['delete terms in opg_status'] = array(
    'name' => 'delete terms in opg_status',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit any opg_admin_post content'.
  $permissions['edit any opg_admin_post content'] = array(
    'name' => 'edit any opg_admin_post content',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any opg_default_group content'.
  $permissions['edit any opg_default_group content'] = array(
    'name' => 'edit any opg_default_group content',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any opg_group content'.
  $permissions['edit any opg_group content'] = array(
    'name' => 'edit any opg_group content',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit field_opg_addbtn_anon'.
  $permissions['edit field_opg_addbtn_anon'] = array(
    'name' => 'edit field_opg_addbtn_anon',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_opg_addbtn_auth'.
  $permissions['edit field_opg_addbtn_auth'] = array(
    'name' => 'edit field_opg_addbtn_auth',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_opg_admin_navblock'.
  $permissions['edit field_opg_admin_navblock'] = array(
    'name' => 'edit field_opg_admin_navblock',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_opg_details_link'.
  $permissions['edit field_opg_details_link'] = array(
    'name' => 'edit field_opg_details_link',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_opg_group_admin_navblock'.
  $permissions['edit field_opg_group_admin_navblock'] = array(
    'name' => 'edit field_opg_group_admin_navblock',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_opg_logo'.
  $permissions['edit field_opg_logo'] = array(
    'name' => 'edit field_opg_logo',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_opg_logo_image'.
  $permissions['edit field_opg_logo_image'] = array(
    'name' => 'edit field_opg_logo_image',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_opg_navbar'.
  $permissions['edit field_opg_navbar'] = array(
    'name' => 'edit field_opg_navbar',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_opg_navblock'.
  $permissions['edit field_opg_navblock'] = array(
    'name' => 'edit field_opg_navblock',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_opg_post_type'.
  $permissions['edit field_opg_post_type'] = array(
    'name' => 'edit field_opg_post_type',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_opg_postlogin'.
  $permissions['edit field_opg_postlogin'] = array(
    'name' => 'edit field_opg_postlogin',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_opg_poweredby'.
  $permissions['edit field_opg_poweredby'] = array(
    'name' => 'edit field_opg_poweredby',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_opg_right_header'.
  $permissions['edit field_opg_right_header'] = array(
    'name' => 'edit field_opg_right_header',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_opg_status_voc'.
  $permissions['edit field_opg_status_voc'] = array(
    'name' => 'edit field_opg_status_voc',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_opg_sublogin'.
  $permissions['edit field_opg_sublogin'] = array(
    'name' => 'edit field_opg_sublogin',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_opg_addbtn_anon'.
  $permissions['edit own field_opg_addbtn_anon'] = array(
    'name' => 'edit own field_opg_addbtn_anon',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_opg_addbtn_auth'.
  $permissions['edit own field_opg_addbtn_auth'] = array(
    'name' => 'edit own field_opg_addbtn_auth',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_opg_admin_navblock'.
  $permissions['edit own field_opg_admin_navblock'] = array(
    'name' => 'edit own field_opg_admin_navblock',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_opg_details_link'.
  $permissions['edit own field_opg_details_link'] = array(
    'name' => 'edit own field_opg_details_link',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_opg_group_admin_navblock'.
  $permissions['edit own field_opg_group_admin_navblock'] = array(
    'name' => 'edit own field_opg_group_admin_navblock',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_opg_logo'.
  $permissions['edit own field_opg_logo'] = array(
    'name' => 'edit own field_opg_logo',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_opg_logo_image'.
  $permissions['edit own field_opg_logo_image'] = array(
    'name' => 'edit own field_opg_logo_image',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_opg_navbar'.
  $permissions['edit own field_opg_navbar'] = array(
    'name' => 'edit own field_opg_navbar',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_opg_navblock'.
  $permissions['edit own field_opg_navblock'] = array(
    'name' => 'edit own field_opg_navblock',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_opg_post_type'.
  $permissions['edit own field_opg_post_type'] = array(
    'name' => 'edit own field_opg_post_type',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_opg_postlogin'.
  $permissions['edit own field_opg_postlogin'] = array(
    'name' => 'edit own field_opg_postlogin',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_opg_poweredby'.
  $permissions['edit own field_opg_poweredby'] = array(
    'name' => 'edit own field_opg_poweredby',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_opg_right_header'.
  $permissions['edit own field_opg_right_header'] = array(
    'name' => 'edit own field_opg_right_header',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_opg_status_voc'.
  $permissions['edit own field_opg_status_voc'] = array(
    'name' => 'edit own field_opg_status_voc',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_opg_sublogin'.
  $permissions['edit own field_opg_sublogin'] = array(
    'name' => 'edit own field_opg_sublogin',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own opg_admin_post content'.
  $permissions['edit own opg_admin_post content'] = array(
    'name' => 'edit own opg_admin_post content',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own opg_default_group content'.
  $permissions['edit own opg_default_group content'] = array(
    'name' => 'edit own opg_default_group content',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own opg_group content'.
  $permissions['edit own opg_group content'] = array(
    'name' => 'edit own opg_group content',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in opg_group_status'.
  $permissions['edit terms in opg_group_status'] = array(
    'name' => 'edit terms in opg_group_status',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in opg_sponsor'.
  $permissions['edit terms in opg_sponsor'] = array(
    'name' => 'edit terms in opg_sponsor',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in opg_status'.
  $permissions['edit terms in opg_status'] = array(
    'name' => 'edit terms in opg_status',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'subscribe to groups'.
  $permissions['subscribe to groups'] = array(
    'name' => 'subscribe to groups',
    'roles' => array(
      'admin' => 'admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'subscriptions',
  );

  // Exported permission: 'view field_opg_addbtn_anon'.
  $permissions['view field_opg_addbtn_anon'] = array(
    'name' => 'view field_opg_addbtn_anon',
    'roles' => array(
      'admin' => 'admin',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_opg_addbtn_auth'.
  $permissions['view field_opg_addbtn_auth'] = array(
    'name' => 'view field_opg_addbtn_auth',
    'roles' => array(
      'admin' => 'admin',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_opg_admin_navblock'.
  $permissions['view field_opg_admin_navblock'] = array(
    'name' => 'view field_opg_admin_navblock',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_opg_details_link'.
  $permissions['view field_opg_details_link'] = array(
    'name' => 'view field_opg_details_link',
    'roles' => array(
      'admin' => 'admin',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_opg_group_admin_navblock'.
  $permissions['view field_opg_group_admin_navblock'] = array(
    'name' => 'view field_opg_group_admin_navblock',
    'roles' => array(
      'admin' => 'admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_opg_logo'.
  $permissions['view field_opg_logo'] = array(
    'name' => 'view field_opg_logo',
    'roles' => array(
      'admin' => 'admin',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_opg_logo_image'.
  $permissions['view field_opg_logo_image'] = array(
    'name' => 'view field_opg_logo_image',
    'roles' => array(
      'admin' => 'admin',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_opg_navbar'.
  $permissions['view field_opg_navbar'] = array(
    'name' => 'view field_opg_navbar',
    'roles' => array(
      'admin' => 'admin',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_opg_navblock'.
  $permissions['view field_opg_navblock'] = array(
    'name' => 'view field_opg_navblock',
    'roles' => array(
      'admin' => 'admin',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_opg_post_type'.
  $permissions['view field_opg_post_type'] = array(
    'name' => 'view field_opg_post_type',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_opg_postlogin'.
  $permissions['view field_opg_postlogin'] = array(
    'name' => 'view field_opg_postlogin',
    'roles' => array(
      'admin' => 'admin',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_opg_poweredby'.
  $permissions['view field_opg_poweredby'] = array(
    'name' => 'view field_opg_poweredby',
    'roles' => array(
      'admin' => 'admin',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_opg_right_header'.
  $permissions['view field_opg_right_header'] = array(
    'name' => 'view field_opg_right_header',
    'roles' => array(
      'admin' => 'admin',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_opg_status_voc'.
  $permissions['view field_opg_status_voc'] = array(
    'name' => 'view field_opg_status_voc',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_opg_sublogin'.
  $permissions['view field_opg_sublogin'] = array(
    'name' => 'view field_opg_sublogin',
    'roles' => array(
      'admin' => 'admin',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_opg_addbtn_anon'.
  $permissions['view own field_opg_addbtn_anon'] = array(
    'name' => 'view own field_opg_addbtn_anon',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_opg_addbtn_auth'.
  $permissions['view own field_opg_addbtn_auth'] = array(
    'name' => 'view own field_opg_addbtn_auth',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_opg_admin_navblock'.
  $permissions['view own field_opg_admin_navblock'] = array(
    'name' => 'view own field_opg_admin_navblock',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_opg_details_link'.
  $permissions['view own field_opg_details_link'] = array(
    'name' => 'view own field_opg_details_link',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_opg_group_admin_navblock'.
  $permissions['view own field_opg_group_admin_navblock'] = array(
    'name' => 'view own field_opg_group_admin_navblock',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_opg_logo'.
  $permissions['view own field_opg_logo'] = array(
    'name' => 'view own field_opg_logo',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_opg_logo_image'.
  $permissions['view own field_opg_logo_image'] = array(
    'name' => 'view own field_opg_logo_image',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_opg_navbar'.
  $permissions['view own field_opg_navbar'] = array(
    'name' => 'view own field_opg_navbar',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_opg_navblock'.
  $permissions['view own field_opg_navblock'] = array(
    'name' => 'view own field_opg_navblock',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_opg_post_type'.
  $permissions['view own field_opg_post_type'] = array(
    'name' => 'view own field_opg_post_type',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_opg_postlogin'.
  $permissions['view own field_opg_postlogin'] = array(
    'name' => 'view own field_opg_postlogin',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_opg_poweredby'.
  $permissions['view own field_opg_poweredby'] = array(
    'name' => 'view own field_opg_poweredby',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_opg_right_header'.
  $permissions['view own field_opg_right_header'] = array(
    'name' => 'view own field_opg_right_header',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_opg_status_voc'.
  $permissions['view own field_opg_status_voc'] = array(
    'name' => 'view own field_opg_status_voc',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_opg_sublogin'.
  $permissions['view own field_opg_sublogin'] = array(
    'name' => 'view own field_opg_sublogin',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
