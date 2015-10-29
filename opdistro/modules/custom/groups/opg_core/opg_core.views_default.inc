<?php
/**
 * @file
 * opg_core.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function opg_core_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'opg_comments';
  $view->description = 'Recent comments on a node - for embedded display';
  $view->tag = 'default';
  $view->base_table = 'comment';
  $view->human_name = 'opg_comments';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access comments';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'comment';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  /* Relationship: Comment: Content */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'comment';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['required'] = TRUE;
  /* Field: Comment: Title */
  $handler->display->display_options['fields']['subject']['id'] = 'subject';
  $handler->display->display_options['fields']['subject']['table'] = 'comment';
  $handler->display->display_options['fields']['subject']['field'] = 'subject';
  $handler->display->display_options['fields']['subject']['label'] = '';
  $handler->display->display_options['fields']['subject']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['subject']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Comment: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'comment';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Comment: Approved */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'comment';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status_node']['id'] = 'status_node';
  $handler->display->display_options['filters']['status_node']['table'] = 'node';
  $handler->display->display_options['filters']['status_node']['field'] = 'status';
  $handler->display->display_options['filters']['status_node']['relationship'] = 'nid';
  $handler->display->display_options['filters']['status_node']['value'] = 1;
  $handler->display->display_options['filters']['status_node']['group'] = 1;
  $handler->display->display_options['filters']['status_node']['expose']['operator'] = FALSE;
  $export['opg_comments'] = $view;

  $view = new view();
  $view->name = 'opg_core';
  $view->description = 'Open Proposals Groups core view';
  $view->tag = 'opg';
  $view->base_table = 'node';
  $view->human_name = 'opg_core';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Recent Proposals';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = '<h2 id="posts">Proposals (@total total)</h2>
<div id="proposalCount">Displaying @start - @end</div>';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'pager';
  $handler->display->display_options['header']['area']['content'] = '<?php print theme(\'pager\') ?>';
  $handler->display->display_options['header']['area']['format'] = 'php_code';
  /* Relationship: OG membership: OG membership from Node */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: OG membership: Group ID */
  $handler->display->display_options['arguments']['gid']['id'] = 'gid';
  $handler->display->display_options['arguments']['gid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['gid']['field'] = 'gid';
  $handler->display->display_options['arguments']['gid']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['arguments']['gid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['gid']['default_argument_type'] = 'og_context';
  $handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['gid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['gid']['validate']['type'] = 'og';
  $handler->display->display_options['arguments']['gid']['validate']['fail'] = 'empty';
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['operator'] = 'not in';
  $handler->display->display_options['filters']['type']['value'] = array(
    'page' => 'page',
  );

  /* Display: Recent Page */
  $handler = $view->new_display('page', 'Recent Page', 'recent_page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['display_description'] = 'Sort by term weight, sticky, post date';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: OG membership: OG membership from Node */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_opg_status_target_id']['id'] = 'field_opg_status_target_id';
  $handler->display->display_options['relationships']['field_opg_status_target_id']['table'] = 'field_data_field_opg_status';
  $handler->display->display_options['relationships']['field_opg_status_target_id']['field'] = 'field_opg_status_target_id';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['relationship'] = 'field_opg_status_target_id';
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['operator'] = 'not in';
  $handler->display->display_options['filters']['type']['value'] = array(
    'opg_admin_post' => 'opg_admin_post',
    'page' => 'page',
  );
  $handler->display->display_options['path'] = 'opg-core/%/recent';
  $handler->display->display_options['menu']['title'] = 'Recent proposals';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'GenericForumTitle';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Recent PageBlock */
  $handler = $view->new_display('block', 'Recent PageBlock', 'recent_pageblock');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['display_description'] = 'Same as Recent Page display but a Block';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_opg_status_target_id']['id'] = 'field_opg_status_target_id';
  $handler->display->display_options['relationships']['field_opg_status_target_id']['table'] = 'field_data_field_opg_status';
  $handler->display->display_options['relationships']['field_opg_status_target_id']['field'] = 'field_opg_status_target_id';
  /* Relationship: OG membership: OG membership from Node */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['required'] = TRUE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['relationship'] = 'field_opg_status_target_id';
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['group'] = 1;
  /* Filter criterion: Taxonomy term: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'field_opg_status_target_id';
  $handler->display->display_options['filters']['name']['operator'] = 'not_starts';
  $handler->display->display_options['filters']['name']['value'] = 'Admin';
  $handler->display->display_options['filters']['name']['group'] = 1;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['operator'] = 'not in';
  $handler->display->display_options['filters']['type']['value'] = array(
    'page' => 'page',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: Recent Block */
  $handler = $view->new_display('block', 'Recent Block', 'recent_block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Recent Proposals';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['operator'] = 'not in';
  $handler->display->display_options['filters']['type']['value'] = array(
    'opg_admin_post' => 'opg_admin_post',
    'page' => 'page',
  );

  /* Display: MyBlock */
  $handler = $view->new_display('block', 'MyBlock', 'my_block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'My Proposals';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'og_context';
  $handler->display->display_options['access']['perm'] = 'view body field';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '6';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'myproposals';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No results markup';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<?php if (!$GLOBALS[\'user\']->uid) : ?>
<p>[current-opg:login:text] to see links for accessing your [current-opg:lcnoun]s</p>
<?php else : ?>
<ul class="icon submission-open">
<li class="pointer"><a href="[current-opg:path]/create">Add your [current-opg:lcnoun]</a></li>
</ul>
<ul class="submission-closed"><li>[current-opg:noun] submission is closed.</li></ul>
<?php endif; ?>';
  $handler->display->display_options['empty']['area']['format'] = 'php_code';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_class'] = 'edit-link';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: OG membership: Group ID */
  $handler->display->display_options['arguments']['gid']['id'] = 'gid';
  $handler->display->display_options['arguments']['gid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['gid']['field'] = 'gid';
  $handler->display->display_options['arguments']['gid']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['arguments']['gid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['gid']['default_argument_type'] = 'og_context';
  $handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['gid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['gid']['validate']['type'] = 'og';
  $handler->display->display_options['arguments']['gid']['validate']['fail'] = 'empty';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['operator'] = 'not in';
  $handler->display->display_options['filters']['type']['value'] = array(
    'opg_admin_post' => 'opg_admin_post',
    'page' => 'page',
  );
  /* Filter criterion: Content: Author uid */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'node';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['operator'] = 'not in';
  $handler->display->display_options['filters']['uid']['value'] = array(
    0 => 0,
  );

  /* Display: Popular Page */
  $handler = $view->new_display('page', 'Popular Page', 'popular_page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Most Liked Proposals';
  $handler->display->display_options['display_description'] = 'Sort by votes, post date';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Total score */
  $handler->display->display_options['relationships']['votingapi_cache']['id'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['ui_name'] = 'Content: Total score';
  $handler->display->display_options['relationships']['votingapi_cache']['label'] = 'Total score';
  $handler->display->display_options['relationships']['votingapi_cache']['votingapi'] = array(
    'value_type' => 'points',
    'tag' => 'vote',
    'function' => 'sum',
  );
  /* Relationship: Content: Number of votes */
  $handler->display->display_options['relationships']['votingapi_cache_1']['id'] = 'votingapi_cache_1';
  $handler->display->display_options['relationships']['votingapi_cache_1']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache_1']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache_1']['ui_name'] = 'Content: Number of votes';
  $handler->display->display_options['relationships']['votingapi_cache_1']['label'] = 'Number of votes';
  $handler->display->display_options['relationships']['votingapi_cache_1']['votingapi'] = array(
    'value_type' => 'points',
    'tag' => 'vote',
    'function' => 'count',
  );
  /* Relationship: OG membership: OG membership from Node */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['required'] = TRUE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Vote results: Value */
  $handler->display->display_options['sorts']['value']['id'] = 'value';
  $handler->display->display_options['sorts']['value']['table'] = 'votingapi_cache';
  $handler->display->display_options['sorts']['value']['field'] = 'value';
  $handler->display->display_options['sorts']['value']['relationship'] = 'votingapi_cache';
  $handler->display->display_options['sorts']['value']['order'] = 'DESC';
  $handler->display->display_options['sorts']['value']['coalesce'] = 1;
  /* Sort criterion: Vote results: Value */
  $handler->display->display_options['sorts']['value_1']['id'] = 'value_1';
  $handler->display->display_options['sorts']['value_1']['table'] = 'votingapi_cache';
  $handler->display->display_options['sorts']['value_1']['field'] = 'value';
  $handler->display->display_options['sorts']['value_1']['relationship'] = 'votingapi_cache_1';
  $handler->display->display_options['sorts']['value_1']['order'] = 'DESC';
  $handler->display->display_options['sorts']['value_1']['coalesce'] = 1;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['operator'] = 'not in';
  $handler->display->display_options['filters']['type']['value'] = array(
    'opg_admin_post' => 'opg_admin_post',
    'page' => 'page',
  );
  $handler->display->display_options['path'] = 'opg-core/%/popular';
  $handler->display->display_options['menu']['title'] = 'Recent proposals';
  $handler->display->display_options['menu']['weight'] = '50';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'GenericForumTitle';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Popular Block */
  $handler = $view->new_display('block', 'Popular Block', 'popular_block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Most Liked Proposals';
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'popular_page';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '6';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Total score */
  $handler->display->display_options['relationships']['votingapi_cache']['id'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['ui_name'] = 'Content: Total score';
  $handler->display->display_options['relationships']['votingapi_cache']['label'] = 'Total score';
  $handler->display->display_options['relationships']['votingapi_cache']['votingapi'] = array(
    'value_type' => 'points',
    'tag' => 'vote',
    'function' => 'sum',
  );
  /* Relationship: Content: Number of votes */
  $handler->display->display_options['relationships']['votingapi_cache_1']['id'] = 'votingapi_cache_1';
  $handler->display->display_options['relationships']['votingapi_cache_1']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache_1']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache_1']['ui_name'] = 'Content: Number of votes';
  $handler->display->display_options['relationships']['votingapi_cache_1']['label'] = 'Number of votes';
  $handler->display->display_options['relationships']['votingapi_cache_1']['votingapi'] = array(
    'value_type' => 'points',
    'tag' => 'vote',
    'function' => 'count',
  );
  /* Relationship: OG membership: OG membership from Node */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['required'] = TRUE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Vote results: Value */
  $handler->display->display_options['sorts']['value']['id'] = 'value';
  $handler->display->display_options['sorts']['value']['table'] = 'votingapi_cache';
  $handler->display->display_options['sorts']['value']['field'] = 'value';
  $handler->display->display_options['sorts']['value']['relationship'] = 'votingapi_cache';
  $handler->display->display_options['sorts']['value']['order'] = 'DESC';
  $handler->display->display_options['sorts']['value']['coalesce'] = 1;
  /* Sort criterion: Vote results: Value */
  $handler->display->display_options['sorts']['value_1']['id'] = 'value_1';
  $handler->display->display_options['sorts']['value_1']['table'] = 'votingapi_cache';
  $handler->display->display_options['sorts']['value_1']['field'] = 'value';
  $handler->display->display_options['sorts']['value_1']['relationship'] = 'votingapi_cache_1';
  $handler->display->display_options['sorts']['value_1']['order'] = 'DESC';
  $handler->display->display_options['sorts']['value_1']['coalesce'] = 1;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['operator'] = 'not in';
  $handler->display->display_options['filters']['type']['value'] = array(
    'opg_admin_post' => 'opg_admin_post',
    'page' => 'page',
  );

  /* Display: Active Page */
  $handler = $view->new_display('page', 'Active Page', 'active_page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Most Commented Proposals';
  $handler->display->display_options['display_description'] = 'Sort by number of comments, post date';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Comment count */
  $handler->display->display_options['sorts']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['sorts']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['sorts']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['sorts']['comment_count']['order'] = 'DESC';
  /* Sort criterion: Content: Last comment time */
  $handler->display->display_options['sorts']['last_comment_timestamp']['id'] = 'last_comment_timestamp';
  $handler->display->display_options['sorts']['last_comment_timestamp']['table'] = 'node_comment_statistics';
  $handler->display->display_options['sorts']['last_comment_timestamp']['field'] = 'last_comment_timestamp';
  $handler->display->display_options['sorts']['last_comment_timestamp']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['path'] = 'opg-core/%/active';
  $handler->display->display_options['menu']['title'] = 'Recent proposals';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'GenericForumTitle';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Active Block */
  $handler = $view->new_display('block', 'Active Block', 'active_block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Most Commented Proposals';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '6';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Comment count */
  $handler->display->display_options['sorts']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['sorts']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['sorts']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['sorts']['comment_count']['order'] = 'DESC';
  /* Sort criterion: Content: Last comment time */
  $handler->display->display_options['sorts']['last_comment_timestamp']['id'] = 'last_comment_timestamp';
  $handler->display->display_options['sorts']['last_comment_timestamp']['table'] = 'node_comment_statistics';
  $handler->display->display_options['sorts']['last_comment_timestamp']['field'] = 'last_comment_timestamp';
  $handler->display->display_options['sorts']['last_comment_timestamp']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';

  /* Display: Search Page */
  $handler = $view->new_display('page', 'Search Page', 'search_page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Search Proposals';
  $handler->display->display_options['display_description'] = 'Search results for OG group content';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'full';
  $handler->display->display_options['row_options']['links'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<h2>Your search yielded no results.</h2>
<ul>
<li>Check if your spelling is correct.</li>
<li>Remove quotes around phrases to match each word individually: <em>"blue smurf"</em> will match less than <em>blue smurf</em>.</li>
<li>Consider loosening your query with <em>OR</em>: <em>blue smurf</em> will match less than <em>blue OR smurf</em>.</li>
</ul>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Search: Score */
  $handler->display->display_options['sorts']['score']['id'] = 'score';
  $handler->display->display_options['sorts']['score']['table'] = 'search_index';
  $handler->display->display_options['sorts']['score']['field'] = 'score';
  $handler->display->display_options['sorts']['score']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: OG membership: Group ID */
  $handler->display->display_options['arguments']['gid']['id'] = 'gid';
  $handler->display->display_options['arguments']['gid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['gid']['field'] = 'gid';
  $handler->display->display_options['arguments']['gid']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['arguments']['gid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['gid']['default_argument_type'] = 'og_context';
  $handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['gid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['gid']['validate']['type'] = 'og';
  $handler->display->display_options['arguments']['gid']['validate']['fail'] = 'empty';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Search: Search Terms */
  $handler->display->display_options['filters']['keys']['id'] = 'keys';
  $handler->display->display_options['filters']['keys']['table'] = 'search_index';
  $handler->display->display_options['filters']['keys']['field'] = 'keys';
  $handler->display->display_options['filters']['keys']['operator'] = 'required';
  $handler->display->display_options['filters']['keys']['group'] = 1;
  $handler->display->display_options['filters']['keys']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['label'] = 'Enter your keywords:';
  $handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keys';
  $handler->display->display_options['filters']['keys']['expose']['remember_roles'] = array(
    2 => '2',
    3 => 0,
    1 => 0,
    6 => 0,
    10 => 0,
    4 => 0,
    5 => 0,
    11 => 0,
    8 => 0,
    7 => 0,
    9 => 0,
  );
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['group'] = 1;
  $handler->display->display_options['path'] = 'opg-core/%/search';
  $handler->display->display_options['menu']['title'] = 'Recent proposals';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'GenericForumTitle';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Taxonomy Page */
  $handler = $view->new_display('page', 'Taxonomy Page', 'taxonomy_page');
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'taxonomy no results';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No results found for the term \'!2\' (%2).';
  $handler->display->display_options['empty']['area']['format'] = 'user_wysiwyg';
  $handler->display->display_options['empty']['area']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['required'] = TRUE;
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'op_itc2013_status' => 0,
    'op_pilot2013_status' => 0,
    'op_demos16_status' => 0,
    'op_archivex_status' => 0,
    'op_br_challenge_status' => 0,
    'op_br_template_status' => 0,
    'op_chvcw2_status' => 0,
    'op_chvc2p2_status' => 0,
    'op_chvdsi_status' => 0,
    'op_cpsp14_status' => 0,
    'op_ren10_status' => 0,
    'op_adsup11_status' => 0,
    'op_stim09_status' => 0,
    'op_ctsi2016_status' => 0,
    'op_pilot2012_status' => 0,
    'op_demo_status' => 0,
    'op_dompc_status' => 0,
    'op_domsp13_status' => 0,
    'op_edin2014_status' => 0,
    'op_edin2015_status' => 0,
    'op_etacsheq_status' => 0,
    'op_etacround2_status' => 0,
    'op_generic_status' => 0,
    'op_hrmaps_status' => 0,
    'op_itcontest_status' => 0,
    'op_ksink_status' => 0,
    'op_osgadget_status' => 0,
    'op_pcariprog_status' => 0,
    'op_phcollab_status' => 0,
    'vocabulary_6' => 0,
    'op_rrpcores_status' => 0,
    'op_bbust2013_status' => 0,
    'op_somlr2014_status' => 0,
    'op_somttg14_status' => 0,
    'op_md_demo_status' => 0,
    'op_md_saf2020_status' => 0,
    'op_md_template_status' => 0,
    'op_coursera_status' => 0,
    'op_archivex_singleterm' => 0,
    'op_br_template_singleterm' => 0,
    'op_ren10_singleterm' => 0,
    'op_adsup11_singleterm' => 0,
    'op_pilot2012_singleterm' => 0,
    'op_edin2014_singleterm' => 0,
    'op_edin2015_singleterm' => 0,
    'op_generic_singleterm' => 0,
    'op_ksink_singleterm' => 0,
    'op_md_template_singleterm' => 0,
    'op_pilot2013_multiterm' => 0,
    'op_archivex_multiterm' => 0,
    'op_br_challenge_multiterm' => 0,
    'op_br_template_multiterm' => 0,
    'op_chvc2p2_multiterm' => 0,
    'op_cpsp14_multiterm' => 0,
    'op_ren10_multiterm' => 0,
    'op_adsup11_multiterm' => 0,
    'op_pilot2012_multiterm' => 0,
    'op_demo_multiterm' => 0,
    'departments' => 0,
    'op_generic_multiterm' => 0,
    'op_hrmaps_multiterm' => 0,
    'op_ksink_multiterm' => 0,
    'op_phcollab_multiterm' => 0,
    'schools' => 0,
    'op_somttg14_multiterm' => 0,
    'op_md_template_multiterm' => 0,
  );
  /* Relationship: OG membership: OG membership from Node */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['required'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: OG membership: Group ID */
  $handler->display->display_options['arguments']['gid']['id'] = 'gid';
  $handler->display->display_options['arguments']['gid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['gid']['field'] = 'gid';
  $handler->display->display_options['arguments']['gid']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['arguments']['gid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['gid']['default_argument_type'] = 'og_context';
  $handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['gid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['gid']['validate']['type'] = 'og';
  $handler->display->display_options['arguments']['gid']['validate']['fail'] = 'empty';
  /* Contextual filter: Taxonomy term: Name */
  $handler->display->display_options['arguments']['name']['id'] = 'name';
  $handler->display->display_options['arguments']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['name']['field'] = 'name';
  $handler->display->display_options['arguments']['name']['relationship'] = 'term_node_tid';
  $handler->display->display_options['arguments']['name']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['name']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['name']['title'] = 'Proposals on %2';
  $handler->display->display_options['arguments']['name']['breadcrumb_enable'] = TRUE;
  $handler->display->display_options['arguments']['name']['breadcrumb'] = '%2';
  $handler->display->display_options['arguments']['name']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['name']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['name']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['name']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['name']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['name']['validate']['fail'] = 'empty';
  $handler->display->display_options['arguments']['name']['limit'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['path'] = 'opg-core/%/topic/%';

  /* Display: Recent Comments Block */
  $handler = $view->new_display('block', 'Recent Comments Block', 'comments_block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Latest Comments';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '6';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Comment: Comments of the node */
  $handler->display->display_options['relationships']['cid']['id'] = 'cid';
  $handler->display->display_options['relationships']['cid']['table'] = 'node';
  $handler->display->display_options['relationships']['cid']['field'] = 'cid';
  $handler->display->display_options['relationships']['cid']['required'] = TRUE;
  /* Relationship: Comment: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'comment';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['relationship'] = 'cid';
  $handler->display->display_options['relationships']['uid']['label'] = 'comment author';
  /* Relationship: OG membership: OG membership from Node */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Comment: ID */
  $handler->display->display_options['fields']['cid']['id'] = 'cid';
  $handler->display->display_options['fields']['cid']['table'] = 'comment';
  $handler->display->display_options['fields']['cid']['field'] = 'cid';
  $handler->display->display_options['fields']['cid']['relationship'] = 'cid';
  $handler->display->display_options['fields']['cid']['label'] = '';
  $handler->display->display_options['fields']['cid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['cid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['cid']['link_to_comment'] = FALSE;
  /* Field: Realname: Real name */
  $handler->display->display_options['fields']['realname']['id'] = 'realname';
  $handler->display->display_options['fields']['realname']['table'] = 'realname';
  $handler->display->display_options['fields']['realname']['field'] = 'realname';
  $handler->display->display_options['fields']['realname']['relationship'] = 'uid';
  $handler->display->display_options['fields']['realname']['label'] = '';
  $handler->display->display_options['fields']['realname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['realname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['realname']['link_to_user'] = FALSE;
  /* Field: Comment: Author */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'comment';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'cid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Comment: Author uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'comment';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'cid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['text'] = '[realname]';
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['empty'] = '[name]';
  $handler->display->display_options['fields']['uid']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'node/[nid]#comment-[cid]';
  $handler->display->display_options['fields']['title']['alter']['alt'] = '[title]';
  $handler->display->display_options['fields']['title']['alter']['link_class'] = 'forum-comment-link';
  $handler->display->display_options['fields']['title']['alter']['prefix'] = '[uid] on: ';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '50';
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Comment: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'comment';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['relationship'] = 'cid';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['operator'] = 'not in';
  $handler->display->display_options['filters']['type']['value'] = array(
    'page' => 'page',
  );
  /* Filter criterion: Content: Comment count */
  $handler->display->display_options['filters']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['filters']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['filters']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['filters']['comment_count']['operator'] = '>';
  $handler->display->display_options['filters']['comment_count']['value']['value'] = '0';

  /* Display: Admin Post Page */
  $handler = $view->new_display('page', 'Admin Post Page', 'admin_post_page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Announcements';
  $handler->display->display_options['display_description'] = 'Full list of admin posts';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<p>Follow individual announcements (look for the links below each one) to hear questions and comments from [current-opg:lcgroupword] participants.</p>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<p>Helpful guidance and information on the progress of this [current-opg:lcgroupword] will be posted here.</p>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_opg_status_target_id']['id'] = 'field_opg_status_target_id';
  $handler->display->display_options['relationships']['field_opg_status_target_id']['table'] = 'field_data_field_opg_status';
  $handler->display->display_options['relationships']['field_opg_status_target_id']['field'] = 'field_opg_status_target_id';
  /* Relationship: OG membership: OG membership from Node */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['required'] = TRUE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'opg_admin_post' => 'opg_admin_post',
  );
  $handler->display->display_options['path'] = 'opg-core/%/announcements';
  $handler->display->display_options['menu']['title'] = 'Recent proposals';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'GenericForumTitle';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Admin Post Block */
  $handler = $view->new_display('block', 'Admin Post Block', 'adminpost_block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Latest Announcement';
  $handler->display->display_options['display_description'] = 'Section for admin posts';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'See all announcements';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'full';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['label'] = 'See all';
  $handler->display->display_options['footer']['area']['content'] = '<p class="seemore">
<a href="[current-opg:path]/announcements">See all announcements </a>
</p>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_opg_status_target_id']['id'] = 'field_opg_status_target_id';
  $handler->display->display_options['relationships']['field_opg_status_target_id']['table'] = 'field_data_field_opg_status';
  $handler->display->display_options['relationships']['field_opg_status_target_id']['field'] = 'field_opg_status_target_id';
  /* Relationship: OG membership: OG membership from Node */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['required'] = TRUE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['relationship'] = 'field_opg_status_target_id';
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['group'] = 1;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'opg_admin_post' => 'opg_admin_post',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = '>=';
  $handler->display->display_options['filters']['date_filter']['granularity'] = 'second';
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_text';
  $handler->display->display_options['filters']['date_filter']['default_date'] = '-2 weeks';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'node.created' => 'node.created',
  );
  $export['opg_core'] = $view;

  $view = new view();
  $view->name = 'opg_core_fields';
  $view->description = 'Open Proposal Groups field blocks';
  $view->tag = 'opg';
  $view->base_table = 'node';
  $view->human_name = 'opg_core_fields';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: NavBar */
  $handler->display->display_options['fields']['field_opg_navbar']['id'] = 'field_opg_navbar';
  $handler->display->display_options['fields']['field_opg_navbar']['table'] = 'field_data_field_opg_navbar';
  $handler->display->display_options['fields']['field_opg_navbar']['field'] = 'field_opg_navbar';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'og_context';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'og';

  /* Display: Navbar Block */
  $handler = $view->new_display('block', 'Navbar Block', 'navbar_block');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: NavBar */
  $handler->display->display_options['fields']['field_opg_navbar']['id'] = 'field_opg_navbar';
  $handler->display->display_options['fields']['field_opg_navbar']['table'] = 'field_data_field_opg_navbar';
  $handler->display->display_options['fields']['field_opg_navbar']['field'] = 'field_opg_navbar';
  $handler->display->display_options['fields']['field_opg_navbar']['label'] = '';
  $handler->display->display_options['fields']['field_opg_navbar']['element_type'] = '0';
  $handler->display->display_options['fields']['field_opg_navbar']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_opg_navbar']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_opg_navbar']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_opg_navbar']['element_default_classes'] = FALSE;

  /* Display: NavBlock Block */
  $handler = $view->new_display('block', 'NavBlock Block', 'navblock_block');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'og_context';
  $handler->display->display_options['access']['perm'] = 'view field_opg_navblock field';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<h2>This [current-opg:groupword]</h2>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Add Post Button */
  $handler->display->display_options['fields']['field_opg_addbtn_auth']['id'] = 'field_opg_addbtn_auth';
  $handler->display->display_options['fields']['field_opg_addbtn_auth']['table'] = 'field_data_field_opg_addbtn_auth';
  $handler->display->display_options['fields']['field_opg_addbtn_auth']['field'] = 'field_opg_addbtn_auth';
  $handler->display->display_options['fields']['field_opg_addbtn_auth']['label'] = '';
  $handler->display->display_options['fields']['field_opg_addbtn_auth']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_opg_addbtn_auth']['element_type'] = '0';
  $handler->display->display_options['fields']['field_opg_addbtn_auth']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_opg_addbtn_auth']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_opg_addbtn_auth']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_opg_addbtn_auth']['element_default_classes'] = FALSE;
  /* Field: Content: Add Post Button (Anon) */
  $handler->display->display_options['fields']['field_opg_addbtn_anon']['id'] = 'field_opg_addbtn_anon';
  $handler->display->display_options['fields']['field_opg_addbtn_anon']['table'] = 'field_data_field_opg_addbtn_anon';
  $handler->display->display_options['fields']['field_opg_addbtn_anon']['field'] = 'field_opg_addbtn_anon';
  $handler->display->display_options['fields']['field_opg_addbtn_anon']['label'] = '';
  $handler->display->display_options['fields']['field_opg_addbtn_anon']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_opg_addbtn_anon']['element_type'] = '0';
  $handler->display->display_options['fields']['field_opg_addbtn_anon']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_opg_addbtn_anon']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_opg_addbtn_anon']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_opg_addbtn_anon']['element_default_classes'] = FALSE;
  /* Field: OPG: OPG: current UID */
  $handler->display->display_options['fields']['opg_current_uid']['id'] = 'opg_current_uid';
  $handler->display->display_options['fields']['opg_current_uid']['table'] = 'opg_core';
  $handler->display->display_options['fields']['opg_current_uid']['field'] = 'opg_current_uid';
  $handler->display->display_options['fields']['opg_current_uid']['label'] = '';
  $handler->display->display_options['fields']['opg_current_uid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['opg_current_uid']['alter']['text'] = '[field_opg_addbtn_auth]';
  $handler->display->display_options['fields']['opg_current_uid']['element_type'] = '0';
  $handler->display->display_options['fields']['opg_current_uid']['element_label_type'] = '0';
  $handler->display->display_options['fields']['opg_current_uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['opg_current_uid']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['opg_current_uid']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['opg_current_uid']['empty'] = '[field_opg_addbtn_anon]';
  $handler->display->display_options['fields']['opg_current_uid']['empty_zero'] = TRUE;
  /* Field: Content: NavBlock */
  $handler->display->display_options['fields']['field_opg_navblock']['id'] = 'field_opg_navblock';
  $handler->display->display_options['fields']['field_opg_navblock']['table'] = 'field_data_field_opg_navblock';
  $handler->display->display_options['fields']['field_opg_navblock']['field'] = 'field_opg_navblock';
  $handler->display->display_options['fields']['field_opg_navblock']['label'] = '';
  $handler->display->display_options['fields']['field_opg_navblock']['element_type'] = '0';
  $handler->display->display_options['fields']['field_opg_navblock']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_opg_navblock']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_opg_navblock']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_opg_navblock']['element_default_classes'] = FALSE;
  /* Field: Content: Group Admin NavBlock */
  $handler->display->display_options['fields']['field_opg_group_admin_navblock']['id'] = 'field_opg_group_admin_navblock';
  $handler->display->display_options['fields']['field_opg_group_admin_navblock']['table'] = 'field_data_field_opg_group_admin_navblock';
  $handler->display->display_options['fields']['field_opg_group_admin_navblock']['field'] = 'field_opg_group_admin_navblock';
  $handler->display->display_options['fields']['field_opg_group_admin_navblock']['label'] = '';
  $handler->display->display_options['fields']['field_opg_group_admin_navblock']['element_type'] = '0';
  $handler->display->display_options['fields']['field_opg_group_admin_navblock']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_opg_group_admin_navblock']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_opg_group_admin_navblock']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_opg_group_admin_navblock']['element_default_classes'] = FALSE;
  /* Field: Content: Site Admin NavBlock */
  $handler->display->display_options['fields']['field_opg_admin_navblock']['id'] = 'field_opg_admin_navblock';
  $handler->display->display_options['fields']['field_opg_admin_navblock']['table'] = 'field_data_field_opg_admin_navblock';
  $handler->display->display_options['fields']['field_opg_admin_navblock']['field'] = 'field_opg_admin_navblock';
  $handler->display->display_options['fields']['field_opg_admin_navblock']['label'] = '';
  $handler->display->display_options['fields']['field_opg_admin_navblock']['element_type'] = '0';
  $handler->display->display_options['fields']['field_opg_admin_navblock']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_opg_admin_navblock']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_opg_admin_navblock']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_opg_admin_navblock']['element_default_classes'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit Group';
  /* Field: Global: Contextual Links */
  $handler->display->display_options['fields']['contextual_links']['id'] = 'contextual_links';
  $handler->display->display_options['fields']['contextual_links']['table'] = 'views';
  $handler->display->display_options['fields']['contextual_links']['field'] = 'contextual_links';
  $handler->display->display_options['fields']['contextual_links']['label'] = '';
  $handler->display->display_options['fields']['contextual_links']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['contextual_links']['fields'] = array(
    'edit_node' => 'edit_node',
    'field_opg_addbtn_auth' => 0,
    'field_opg_addbtn_anon' => 0,
    'opg_current_uid' => 0,
    'field_opg_navblock' => 0,
    'field_opg_group_admin_navblock' => 0,
    'field_opg_admin_navblock' => 0,
  );

  /* Display: Body Block */
  $handler = $view->new_display('block', 'Body Block', 'body_block');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['ui_name'] = 'Body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_type'] = '0';
  $handler->display->display_options['fields']['body']['element_label_type'] = '0';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;

  /* Display: Form Intro Block */
  $handler = $view->new_display('block', 'Form Intro Block', 'form_intro_block');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Form Instructions */
  $handler->display->display_options['fields']['field_opg_form_intro']['id'] = 'field_opg_form_intro';
  $handler->display->display_options['fields']['field_opg_form_intro']['table'] = 'field_data_field_opg_form_intro';
  $handler->display->display_options['fields']['field_opg_form_intro']['field'] = 'field_opg_form_intro';
  $handler->display->display_options['fields']['field_opg_form_intro']['label'] = '';
  $handler->display->display_options['fields']['field_opg_form_intro']['element_type'] = '0';
  $handler->display->display_options['fields']['field_opg_form_intro']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_opg_form_intro']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_opg_form_intro']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_opg_form_intro']['element_default_classes'] = FALSE;
  /* Field: Content: Submission Resources */
  $handler->display->display_options['fields']['field_opg_submission_templates']['id'] = 'field_opg_submission_templates';
  $handler->display->display_options['fields']['field_opg_submission_templates']['table'] = 'field_data_field_opg_submission_templates';
  $handler->display->display_options['fields']['field_opg_submission_templates']['field'] = 'field_opg_submission_templates';
  $handler->display->display_options['fields']['field_opg_submission_templates']['label'] = 'Submission Templates / Resources';
  $handler->display->display_options['fields']['field_opg_submission_templates']['element_label_type'] = 'h3';
  $handler->display->display_options['fields']['field_opg_submission_templates']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_opg_submission_templates']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_opg_submission_templates']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_opg_submission_templates']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_opg_submission_templates']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_opg_submission_templates']['multi_type'] = 'ul';
  /* Field: Content: Link to Details */
  $handler->display->display_options['fields']['field_opg_details_link']['id'] = 'field_opg_details_link';
  $handler->display->display_options['fields']['field_opg_details_link']['table'] = 'field_data_field_opg_details_link';
  $handler->display->display_options['fields']['field_opg_details_link']['field'] = 'field_opg_details_link';
  $handler->display->display_options['fields']['field_opg_details_link']['label'] = '';
  $handler->display->display_options['fields']['field_opg_details_link']['element_label_colon'] = FALSE;

  /* Display: Logo Block */
  $handler = $view->new_display('block', 'Logo Block', 'logo_block');
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Logo */
  $handler->display->display_options['fields']['field_opg_logo']['id'] = 'field_opg_logo';
  $handler->display->display_options['fields']['field_opg_logo']['table'] = 'field_data_field_opg_logo';
  $handler->display->display_options['fields']['field_opg_logo']['field'] = 'field_opg_logo';
  $handler->display->display_options['fields']['field_opg_logo']['label'] = '';
  $handler->display->display_options['fields']['field_opg_logo']['element_type'] = '0';
  $handler->display->display_options['fields']['field_opg_logo']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_opg_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_opg_logo']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_opg_logo']['element_default_classes'] = FALSE;

  /* Display: Right Header Block */
  $handler = $view->new_display('block', 'Right Header Block', 'r_header_block');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Right header */
  $handler->display->display_options['fields']['field_opg_right_header']['id'] = 'field_opg_right_header';
  $handler->display->display_options['fields']['field_opg_right_header']['table'] = 'field_data_field_opg_right_header';
  $handler->display->display_options['fields']['field_opg_right_header']['field'] = 'field_opg_right_header';
  $handler->display->display_options['fields']['field_opg_right_header']['label'] = '';
  $handler->display->display_options['fields']['field_opg_right_header']['element_type'] = '0';
  $handler->display->display_options['fields']['field_opg_right_header']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_opg_right_header']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_opg_right_header']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_opg_right_header']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_opg_right_header']['empty'] = '<h3 id="optopright"><a href="/">UCSF Open Proposals</a></h3>';

  /* Display: Powered By Block */
  $handler = $view->new_display('block', 'Powered By Block', 'poweredby_block');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'poweredby';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Powered by */
  $handler->display->display_options['fields']['field_opg_poweredby']['id'] = 'field_opg_poweredby';
  $handler->display->display_options['fields']['field_opg_poweredby']['table'] = 'field_data_field_opg_poweredby';
  $handler->display->display_options['fields']['field_opg_poweredby']['field'] = 'field_opg_poweredby';
  $handler->display->display_options['fields']['field_opg_poweredby']['label'] = '';
  $handler->display->display_options['fields']['field_opg_poweredby']['element_type'] = '0';
  $handler->display->display_options['fields']['field_opg_poweredby']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_opg_poweredby']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_opg_poweredby']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_opg_poweredby']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_opg_poweredby']['empty'] = '<p><img src="/files/images/ctsi16.png" alt="CTSI" style="vertical-align:-2px" /> <a href="http://ctsi.ucsf.edu">Powered by CTSI at UCSF</a></p>';

  /* Display: About Page */
  $handler = $view->new_display('page', 'About Page', 'aboutpage');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Noun */
  $handler->display->display_options['fields']['field_opg_noun']['id'] = 'field_opg_noun';
  $handler->display->display_options['fields']['field_opg_noun']['table'] = 'field_data_field_opg_noun';
  $handler->display->display_options['fields']['field_opg_noun']['field'] = 'field_opg_noun';
  $handler->display->display_options['fields']['field_opg_noun']['label'] = '';
  $handler->display->display_options['fields']['field_opg_noun']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_opg_noun']['element_label_colon'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: About Page */
  $handler->display->display_options['fields']['field_opg_about']['id'] = 'field_opg_about';
  $handler->display->display_options['fields']['field_opg_about']['table'] = 'field_data_field_opg_about';
  $handler->display->display_options['fields']['field_opg_about']['field'] = 'field_opg_about';
  $handler->display->display_options['fields']['field_opg_about']['label'] = '';
  $handler->display->display_options['fields']['field_opg_about']['element_label_colon'] = FALSE;
  /* Field: Content: Submission Resources */
  $handler->display->display_options['fields']['field_opg_submission_templates']['id'] = 'field_opg_submission_templates';
  $handler->display->display_options['fields']['field_opg_submission_templates']['table'] = 'field_data_field_opg_submission_templates';
  $handler->display->display_options['fields']['field_opg_submission_templates']['field'] = 'field_opg_submission_templates';
  $handler->display->display_options['fields']['field_opg_submission_templates']['element_label_type'] = 'h2';
  $handler->display->display_options['fields']['field_opg_submission_templates']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_opg_submission_templates']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_opg_submission_templates']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_opg_submission_templates']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_opg_submission_templates']['multi_type'] = 'ul';
  /* Field: Content: Timeline */
  $handler->display->display_options['fields']['field_opg_phases']['id'] = 'field_opg_phases';
  $handler->display->display_options['fields']['field_opg_phases']['table'] = 'field_data_field_opg_phases';
  $handler->display->display_options['fields']['field_opg_phases']['field'] = 'field_opg_phases';
  $handler->display->display_options['fields']['field_opg_phases']['element_label_type'] = 'h2';
  $handler->display->display_options['fields']['field_opg_phases']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_opg_phases']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_opg_phases']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_opg_phases']['settings'] = array(
    'edit' => '',
    'delete' => '',
    'add' => '',
    'description' => 0,
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_opg_phases']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_opg_phases']['separator'] = '';
  $handler->display->display_options['fields']['field_opg_phases']['field_api_classes'] = TRUE;
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_opg_mgr_email']['id'] = 'field_opg_mgr_email';
  $handler->display->display_options['fields']['field_opg_mgr_email']['table'] = 'field_data_field_opg_mgr_email';
  $handler->display->display_options['fields']['field_opg_mgr_email']['field'] = 'field_opg_mgr_email';
  $handler->display->display_options['fields']['field_opg_mgr_email']['label'] = '';
  $handler->display->display_options['fields']['field_opg_mgr_email']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_opg_mgr_email']['element_label_colon'] = FALSE;
  /* Field: Content: Name */
  $handler->display->display_options['fields']['field_opg_mgr_name']['id'] = 'field_opg_mgr_name';
  $handler->display->display_options['fields']['field_opg_mgr_name']['table'] = 'field_data_field_opg_mgr_name';
  $handler->display->display_options['fields']['field_opg_mgr_name']['field'] = 'field_opg_mgr_name';
  $handler->display->display_options['fields']['field_opg_mgr_name']['label'] = '';
  $handler->display->display_options['fields']['field_opg_mgr_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_opg_mgr_name']['element_label_colon'] = FALSE;
  /* Field: Content: Photo */
  $handler->display->display_options['fields']['field_opg_mgr_photo']['id'] = 'field_opg_mgr_photo';
  $handler->display->display_options['fields']['field_opg_mgr_photo']['table'] = 'field_data_field_opg_mgr_photo';
  $handler->display->display_options['fields']['field_opg_mgr_photo']['field'] = 'field_opg_mgr_photo';
  $handler->display->display_options['fields']['field_opg_mgr_photo']['label'] = '';
  $handler->display->display_options['fields']['field_opg_mgr_photo']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_opg_mgr_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_opg_mgr_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_opg_mgr_photo']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Phone */
  $handler->display->display_options['fields']['field_opg_mgr_phone']['id'] = 'field_opg_mgr_phone';
  $handler->display->display_options['fields']['field_opg_mgr_phone']['table'] = 'field_data_field_opg_mgr_phone';
  $handler->display->display_options['fields']['field_opg_mgr_phone']['field'] = 'field_opg_mgr_phone';
  $handler->display->display_options['fields']['field_opg_mgr_phone']['label'] = '';
  $handler->display->display_options['fields']['field_opg_mgr_phone']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_opg_mgr_phone']['alter']['text'] = '<p><a href="#top" class="top">Back to top</a></p>  
<div class="mgrphoto">[field_opg_mgr_photo]</div>
<ul class="pointer">
<li class="inline">Application questions should be sent by email to <a href="mailto:[field_opg_mgr_email]?Subject=Open%20Proposals%20Question">[field_opg_mgr_name]</a> or call [field_opg_mgr_phone]</li>
<li class="afterinline">For technical issues, contact <a href="mailto:Open.Proposal@ucsf.edu?Subject=Open%20Proposals%20Help">Open.Proposal@ucsf.edu</a></li>
<li><strong><a href="[path]#posts">View [field_opg_noun]s</a></strong></li>
</ul>
';
  $handler->display->display_options['fields']['field_opg_mgr_phone']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['path'] = 'opg-core/%/details';

  /* Display: Follow Group Login Block */
  $handler = $view->new_display('block', 'Follow Group Login Block', 'sublogin_block');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Follow Group Login Text */
  $handler->display->display_options['fields']['field_opg_sublogin']['id'] = 'field_opg_sublogin';
  $handler->display->display_options['fields']['field_opg_sublogin']['table'] = 'field_data_field_opg_sublogin';
  $handler->display->display_options['fields']['field_opg_sublogin']['field'] = 'field_opg_sublogin';
  $handler->display->display_options['fields']['field_opg_sublogin']['label'] = '';
  $handler->display->display_options['fields']['field_opg_sublogin']['element_type'] = '0';
  $handler->display->display_options['fields']['field_opg_sublogin']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_opg_sublogin']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_opg_sublogin']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_opg_sublogin']['element_default_classes'] = FALSE;
  $export['opg_core_fields'] = $view;

  $view = new view();
  $view->name = 'opg_core_reports';
  $view->description = 'Open Proposal Groups standard reports';
  $view->tag = 'opg';
  $view->base_table = 'node';
  $view->human_name = 'opg_core_reports';
  $view->core = 6;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'GenericForumTitle';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'counter' => 'counter',
    'name' => 'name',
    'field_opg_pa_url' => 'field_opg_pa_url',
    'field_opg_pa_first' => 'field_opg_pa_first',
    'field_opg_pa_last' => 'field_opg_pa_last',
    'field_opg_not_pa' => 'field_opg_not_pa',
    'title' => 'title',
    'name_1' => 'name_1',
    'created' => 'created',
    'comment_count' => 'comment_count',
    'value' => 'value',
    'version_count' => 'version_count',
    'expression' => 'expression',
    'version_count_1' => 'version_count_1',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'counter' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_opg_pa_url' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_opg_pa_first' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_opg_pa_last' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_opg_not_pa' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'comment_count' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'value' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'version_count' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'expression' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'version_count_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Content: Vote results */
  $handler->display->display_options['relationships']['votingapi_cache']['id'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['label'] = 'votes';
  $handler->display->display_options['relationships']['votingapi_cache']['votingapi'] = array(
    'value_type' => 'points',
    'tag' => 'vote',
    'function' => 'sum',
  );
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_opg_status_target_id']['id'] = 'field_opg_status_target_id';
  $handler->display->display_options['relationships']['field_opg_status_target_id']['table'] = 'field_data_field_opg_status';
  $handler->display->display_options['relationships']['field_opg_status_target_id']['field'] = 'field_opg_status_target_id';
  /* Relationship: Content: Primary Author (field_opg_primary_author) */
  $handler->display->display_options['relationships']['field_opg_primary_author_value']['id'] = 'field_opg_primary_author_value';
  $handler->display->display_options['relationships']['field_opg_primary_author_value']['table'] = 'field_data_field_opg_primary_author';
  $handler->display->display_options['relationships']['field_opg_primary_author_value']['field'] = 'field_opg_primary_author_value';
  $handler->display->display_options['relationships']['field_opg_primary_author_value']['delta'] = '-1';
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '';
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = FALSE;
  /* Field: Field collection item: UCSF Profiles URL */
  $handler->display->display_options['fields']['field_opg_pa_url']['id'] = 'field_opg_pa_url';
  $handler->display->display_options['fields']['field_opg_pa_url']['table'] = 'field_data_field_opg_pa_url';
  $handler->display->display_options['fields']['field_opg_pa_url']['field'] = 'field_opg_pa_url';
  $handler->display->display_options['fields']['field_opg_pa_url']['relationship'] = 'field_opg_primary_author_value';
  $handler->display->display_options['fields']['field_opg_pa_url']['label'] = '';
  $handler->display->display_options['fields']['field_opg_pa_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_opg_pa_url']['element_label_colon'] = FALSE;
  /* Field: Field collection item: First Name */
  $handler->display->display_options['fields']['field_opg_pa_first']['id'] = 'field_opg_pa_first';
  $handler->display->display_options['fields']['field_opg_pa_first']['table'] = 'field_data_field_opg_pa_first';
  $handler->display->display_options['fields']['field_opg_pa_first']['field'] = 'field_opg_pa_first';
  $handler->display->display_options['fields']['field_opg_pa_first']['relationship'] = 'field_opg_primary_author_value';
  $handler->display->display_options['fields']['field_opg_pa_first']['label'] = '';
  $handler->display->display_options['fields']['field_opg_pa_first']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_opg_pa_first']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Last Name */
  $handler->display->display_options['fields']['field_opg_pa_last']['id'] = 'field_opg_pa_last';
  $handler->display->display_options['fields']['field_opg_pa_last']['table'] = 'field_data_field_opg_pa_last';
  $handler->display->display_options['fields']['field_opg_pa_last']['field'] = 'field_opg_pa_last';
  $handler->display->display_options['fields']['field_opg_pa_last']['relationship'] = 'field_opg_primary_author_value';
  $handler->display->display_options['fields']['field_opg_pa_last']['label'] = '';
  $handler->display->display_options['fields']['field_opg_pa_last']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_opg_pa_last']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_opg_pa_last']['alter']['text'] = '[field_opg_pa_first] [field_opg_pa_last]';
  $handler->display->display_options['fields']['field_opg_pa_last']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_opg_pa_last']['alter']['path'] = '[field_opg_pa_url]';
  $handler->display->display_options['fields']['field_opg_pa_last']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['field_opg_pa_last']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_opg_pa_last']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['field_opg_pa_last']['element_label_colon'] = FALSE;
  /* Field: Field collection item: opg not pa */
  $handler->display->display_options['fields']['field_opg_not_pa']['id'] = 'field_opg_not_pa';
  $handler->display->display_options['fields']['field_opg_not_pa']['table'] = 'field_data_field_opg_not_pa';
  $handler->display->display_options['fields']['field_opg_not_pa']['field'] = 'field_opg_not_pa';
  $handler->display->display_options['fields']['field_opg_not_pa']['relationship'] = 'field_opg_primary_author_value';
  $handler->display->display_options['fields']['field_opg_not_pa']['label'] = 'Author';
  $handler->display->display_options['fields']['field_opg_not_pa']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_opg_not_pa']['alter']['text'] = '[field_opg_pa_last]';
  $handler->display->display_options['fields']['field_opg_not_pa']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_opg_not_pa']['empty'] = '[name]';
  $handler->display->display_options['fields']['field_opg_not_pa']['empty_zero'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Proposal Title';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = TRUE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['relationship'] = 'field_opg_status_target_id';
  $handler->display->display_options['fields']['name_1']['label'] = 'Status';
  $handler->display->display_options['fields']['name_1']['element_label_colon'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['label'] = 'Com- ments';
  /* Field: Vote results: Value */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['relationship'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value']['label'] = 'Likes';
  $handler->display->display_options['fields']['value']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['value']['precision'] = '0';
  $handler->display->display_options['fields']['value']['separator'] = '';
  /* Field: Content: Version Count */
  $handler->display->display_options['fields']['version_count']['id'] = 'version_count';
  $handler->display->display_options['fields']['version_count']['table'] = 'node';
  $handler->display->display_options['fields']['version_count']['field'] = 'version_count';
  $handler->display->display_options['fields']['version_count']['label'] = '';
  $handler->display->display_options['fields']['version_count']['exclude'] = TRUE;
  $handler->display->display_options['fields']['version_count']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['version_count']['separator'] = '';
  /* Field: Global: Math expression */
  $handler->display->display_options['fields']['expression']['id'] = 'expression';
  $handler->display->display_options['fields']['expression']['table'] = 'views';
  $handler->display->display_options['fields']['expression']['field'] = 'expression';
  $handler->display->display_options['fields']['expression']['label'] = '';
  $handler->display->display_options['fields']['expression']['exclude'] = TRUE;
  $handler->display->display_options['fields']['expression']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['expression']['precision'] = '0';
  $handler->display->display_options['fields']['expression']['separator'] = '';
  $handler->display->display_options['fields']['expression']['expression'] = '[version_count] - 1';
  /* Field: Sortable Version Count */
  $handler->display->display_options['fields']['version_count_1']['id'] = 'version_count_1';
  $handler->display->display_options['fields']['version_count_1']['table'] = 'node';
  $handler->display->display_options['fields']['version_count_1']['field'] = 'version_count';
  $handler->display->display_options['fields']['version_count_1']['ui_name'] = 'Sortable Version Count';
  $handler->display->display_options['fields']['version_count_1']['label'] = 'Revi- sions';
  $handler->display->display_options['fields']['version_count_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['version_count_1']['alter']['text'] = '[expression]';
  $handler->display->display_options['fields']['version_count_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['version_count_1']['separator'] = '';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  /* Contextual filter: OG membership: Group ID */
  $handler->display->display_options['arguments']['gid']['id'] = 'gid';
  $handler->display->display_options['arguments']['gid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['gid']['field'] = 'gid';
  $handler->display->display_options['arguments']['gid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['gid']['default_argument_type'] = 'og_context';
  $handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['gid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['gid']['validate']['type'] = 'og';
  $handler->display->display_options['arguments']['gid']['validate']['fail'] = 'empty';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['operator'] = 'not in';
  $handler->display->display_options['filters']['type']['value'] = array(
    'page' => 'page',
  );
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  /* Filter criterion: Taxonomy term: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'field_opg_status_target_id';
  $handler->display->display_options['filters']['name']['operator'] = 'not_starts';
  $handler->display->display_options['filters']['name']['value'] = 'Admin';

  /* Display: Summary Report */
  $handler = $view->new_display('page', 'Summary Report', 'summary_page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'counter' => 'counter',
    'name' => 'name',
    'field_opg_pa_url' => 'field_opg_pa_url',
    'field_opg_pa_first' => 'field_opg_pa_first',
    'field_opg_pa_last' => 'field_opg_pa_last',
    'field_opg_not_pa' => 'field_opg_not_pa',
    'field_last_name' => 'field_last_name',
    'title' => 'title',
    'name_1' => 'name_1',
    'created' => 'created',
    'comment_count' => 'comment_count',
    'value' => 'value',
    'version_count' => 'version_count',
    'expression' => 'expression',
    'version_count_1' => 'version_count_1',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'counter' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_opg_pa_url' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_opg_pa_first' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_opg_pa_last' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_opg_not_pa' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_last_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'comment_count' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'value' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'version_count' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'expression' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'version_count_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['text']['id'] = 'text';
  $handler->display->display_options['header']['text']['table'] = 'views';
  $handler->display->display_options['header']['text']['field'] = 'area';
  $handler->display->display_options['header']['text']['content'] = '<h1>Summary of [current-opg:nouns]</h1>
<ul class="summary-new">
<li><strong>Total [current-opg:lcnouns]:<span>[current-opg:counts:proposals]</span></strong></li>
<li><strong>Total comments:<span>[current-opg:counts:comments]</span></strong></li>
<li><strong>Most comments on a [current-opg:lcnoun]:<span>[current-opg:counts:max_node_comments]</span></strong></li>
<li><strong>Withdrawn [current-opg:lcnouns]:<span>[current-opg:counts:by_status-Withdrawn]</span></strong></li>
<li><strong>Total revised [current-opg:lcnouns]:<span>[current-opg:counts:changed]</span></strong></li>
<li><strong>Total commenters:<span>[current-opg:counts:commenters]</span></strong></li>
<li><strong>Total voters:<span>[current-opg:counts:voters]</span></strong></li>
</ul>

<ul style="display:inline-block;float: right;">
<li><a href="[current-opg:path]/printable-content">Printable [current-opg:noun] Content</a></li>
<li><a href="[current-opg:path]/printable-comments">Printable [current-opg:noun] Content with Comments</a></li>
</ul>
';
  $handler->display->display_options['header']['text']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '';
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = FALSE;
  /* Field: Field collection item: UCSF Profiles URL */
  $handler->display->display_options['fields']['field_opg_pa_url']['id'] = 'field_opg_pa_url';
  $handler->display->display_options['fields']['field_opg_pa_url']['table'] = 'field_data_field_opg_pa_url';
  $handler->display->display_options['fields']['field_opg_pa_url']['field'] = 'field_opg_pa_url';
  $handler->display->display_options['fields']['field_opg_pa_url']['relationship'] = 'field_opg_primary_author_value';
  $handler->display->display_options['fields']['field_opg_pa_url']['label'] = '';
  $handler->display->display_options['fields']['field_opg_pa_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_opg_pa_url']['element_label_colon'] = FALSE;
  /* Field: Field collection item: First Name */
  $handler->display->display_options['fields']['field_opg_pa_first']['id'] = 'field_opg_pa_first';
  $handler->display->display_options['fields']['field_opg_pa_first']['table'] = 'field_data_field_opg_pa_first';
  $handler->display->display_options['fields']['field_opg_pa_first']['field'] = 'field_opg_pa_first';
  $handler->display->display_options['fields']['field_opg_pa_first']['relationship'] = 'field_opg_primary_author_value';
  $handler->display->display_options['fields']['field_opg_pa_first']['label'] = '';
  $handler->display->display_options['fields']['field_opg_pa_first']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_opg_pa_first']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Last Name */
  $handler->display->display_options['fields']['field_opg_pa_last']['id'] = 'field_opg_pa_last';
  $handler->display->display_options['fields']['field_opg_pa_last']['table'] = 'field_data_field_opg_pa_last';
  $handler->display->display_options['fields']['field_opg_pa_last']['field'] = 'field_opg_pa_last';
  $handler->display->display_options['fields']['field_opg_pa_last']['relationship'] = 'field_opg_primary_author_value';
  $handler->display->display_options['fields']['field_opg_pa_last']['label'] = '';
  $handler->display->display_options['fields']['field_opg_pa_last']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_opg_pa_last']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_opg_pa_last']['alter']['text'] = '[field_opg_pa_first] [field_opg_pa_last]';
  $handler->display->display_options['fields']['field_opg_pa_last']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_opg_pa_last']['alter']['path'] = '[field_opg_pa_url]';
  $handler->display->display_options['fields']['field_opg_pa_last']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['field_opg_pa_last']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_opg_pa_last']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['field_opg_pa_last']['element_label_colon'] = FALSE;
  /* Field: Field collection item: opg not pa */
  $handler->display->display_options['fields']['field_opg_not_pa']['id'] = 'field_opg_not_pa';
  $handler->display->display_options['fields']['field_opg_not_pa']['table'] = 'field_data_field_opg_not_pa';
  $handler->display->display_options['fields']['field_opg_not_pa']['field'] = 'field_opg_not_pa';
  $handler->display->display_options['fields']['field_opg_not_pa']['relationship'] = 'field_opg_primary_author_value';
  $handler->display->display_options['fields']['field_opg_not_pa']['label'] = '';
  $handler->display->display_options['fields']['field_opg_not_pa']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_opg_not_pa']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_opg_not_pa']['alter']['text'] = '[field_opg_pa_last]
[name]';
  $handler->display->display_options['fields']['field_opg_not_pa']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_opg_not_pa']['empty'] = '[name]';
  $handler->display->display_options['fields']['field_opg_not_pa']['empty_zero'] = TRUE;
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_last_name']['label'] = 'Author';
  $handler->display->display_options['fields']['field_last_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_last_name']['alter']['text'] = '[field_opg_not_pa] ';
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Proposal Title';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = TRUE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['relationship'] = 'field_opg_status_target_id';
  $handler->display->display_options['fields']['name_1']['label'] = 'Status';
  $handler->display->display_options['fields']['name_1']['element_label_colon'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['label'] = 'Com- ments';
  /* Field: Vote results: Value */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['relationship'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value']['label'] = 'Likes';
  $handler->display->display_options['fields']['value']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['value']['precision'] = '0';
  $handler->display->display_options['fields']['value']['separator'] = '';
  /* Field: Content: Version Count */
  $handler->display->display_options['fields']['version_count']['id'] = 'version_count';
  $handler->display->display_options['fields']['version_count']['table'] = 'node';
  $handler->display->display_options['fields']['version_count']['field'] = 'version_count';
  $handler->display->display_options['fields']['version_count']['label'] = '';
  $handler->display->display_options['fields']['version_count']['exclude'] = TRUE;
  $handler->display->display_options['fields']['version_count']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['version_count']['separator'] = '';
  /* Field: Global: Math expression */
  $handler->display->display_options['fields']['expression']['id'] = 'expression';
  $handler->display->display_options['fields']['expression']['table'] = 'views';
  $handler->display->display_options['fields']['expression']['field'] = 'expression';
  $handler->display->display_options['fields']['expression']['label'] = '';
  $handler->display->display_options['fields']['expression']['exclude'] = TRUE;
  $handler->display->display_options['fields']['expression']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['expression']['precision'] = '0';
  $handler->display->display_options['fields']['expression']['separator'] = '';
  $handler->display->display_options['fields']['expression']['expression'] = '[version_count] - 1';
  /* Field: Sortable Version Count */
  $handler->display->display_options['fields']['version_count_1']['id'] = 'version_count_1';
  $handler->display->display_options['fields']['version_count_1']['table'] = 'node';
  $handler->display->display_options['fields']['version_count_1']['field'] = 'version_count';
  $handler->display->display_options['fields']['version_count_1']['ui_name'] = 'Sortable Version Count';
  $handler->display->display_options['fields']['version_count_1']['label'] = 'Revi- sions';
  $handler->display->display_options['fields']['version_count_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['version_count_1']['alter']['text'] = '[expression]';
  $handler->display->display_options['fields']['version_count_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['version_count_1']['separator'] = '';
  $handler->display->display_options['path'] = 'opg-core/%/summary';

  /* Display: Printable Proposal Content */
  $handler = $view->new_display('page', 'Printable Proposal Content', 'page_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'printable';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'full';
  $handler->display->display_options['row_options']['links'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['text']['id'] = 'text';
  $handler->display->display_options['header']['text']['table'] = 'views';
  $handler->display->display_options['header']['text']['field'] = 'area';
  $handler->display->display_options['header']['text']['content'] = '<style type="text/css">
@media print
{
.views-row {page-break-after:always;}
#header-region, .title, h1 {display:none;}
}
</style>
<h1>Printable [current-opg:noun] Content</h1>
<p class="title">Use your browser\'s print function to output [current-opg:lcnoun] content only, with each [current-opg:lcnoun] starting a new page. Print to Adobe PDF to produce a file. (Note: Chrome and IE9 do not support starting a new page for each [current-opg:lcnoun].)</p>
';
  $handler->display->display_options['header']['text']['format'] = 'php_code';
  $handler->display->display_options['path'] = 'opg-core/%/printable-content';
  $handler->display->display_options['menu']['title'] = 'Recent proposals';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'GenericForumTitle';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Printable Proposal Content */
  $handler = $view->new_display('page', 'Printable Proposal Content', 'page_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'printable';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'full';
  $handler->display->display_options['row_options']['links'] = FALSE;
  $handler->display->display_options['row_options']['comments'] = TRUE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['text']['id'] = 'text';
  $handler->display->display_options['header']['text']['table'] = 'views';
  $handler->display->display_options['header']['text']['field'] = 'area';
  $handler->display->display_options['header']['text']['content'] = '<style type="text/css">
@media print
{
.views-row {page-break-after:always;}
#header-region, .title, h1 {display:none;}
#mainContent {width:700px;}
}
</style>
<h1>Printable [current-opg:noun] Content with Comments</h1>
<p class="title">Use your browser\'s print function to output [current-opg:lcnoun] content only, with each [current-opg:lcnoun] starting a new page. Print to Adobe PDF to produce a file. (Note: Chrome and IE9 do not support starting a new page for each [current-opg:lcnoun].)</p>
';
  $handler->display->display_options['header']['text']['format'] = 'php_code';
  $handler->display->display_options['path'] = 'opg-core/%/printable-comments';
  $handler->display->display_options['menu']['title'] = 'Recent proposals';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'GenericForumTitle';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Summary CSV */
  $handler = $view->new_display('views_data_export', 'Summary CSV', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'generic-forum-url-summary-%timestamp-full.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 1;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['path'] = 'opg-core/%/summary/csv';
  $handler->display->display_options['displays'] = array(
    'default' => 0,
    'page_2' => 0,
    'page_3' => 0,
    'page_4' => 0,
    'page_1' => 0,
  );
  $handler->display->display_options['use_batch'] = '0';

  /* Display: Summary Excel */
  $handler = $view->new_display('views_data_export', 'Summary Excel', 'views_data_export_2');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'generic-forum-url-summary-%timestamp-full.xls';
  $handler->display->display_options['style_options']['parent_sort'] = 1;
  $handler->display->display_options['path'] = 'opg-core/%/summary/download';
  $handler->display->display_options['displays'] = array(
    'page_2' => 'page_2',
    'default' => 0,
    'page_3' => 0,
    'page_4' => 0,
  );
  $handler->display->display_options['use_batch'] = '0';

  /* Display: Awards */
  $handler = $view->new_display('page', 'Awards', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Awards';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'field_last_name_value' => 'field_last_name_value',
    'title' => 'title',
    'comment_count' => 'comment_count',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 0,
      'separator' => '',
    ),
    'field_last_name_value' => array(
      'sortable' => 0,
      'separator' => '',
    ),
    'title' => array(
      'sortable' => 0,
      'separator' => '',
    ),
    'comment_count' => array(
      'sortable' => 0,
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['summary'] = 'GenericForumTitle Proposals';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = FALSE;
  /* Field: Field collection item: UCSF Profiles URL */
  $handler->display->display_options['fields']['field_opg_pa_url']['id'] = 'field_opg_pa_url';
  $handler->display->display_options['fields']['field_opg_pa_url']['table'] = 'field_data_field_opg_pa_url';
  $handler->display->display_options['fields']['field_opg_pa_url']['field'] = 'field_opg_pa_url';
  $handler->display->display_options['fields']['field_opg_pa_url']['relationship'] = 'field_opg_primary_author_value';
  $handler->display->display_options['fields']['field_opg_pa_url']['label'] = '';
  $handler->display->display_options['fields']['field_opg_pa_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_opg_pa_url']['element_label_colon'] = FALSE;
  /* Field: Field collection item: First Name */
  $handler->display->display_options['fields']['field_opg_pa_first']['id'] = 'field_opg_pa_first';
  $handler->display->display_options['fields']['field_opg_pa_first']['table'] = 'field_data_field_opg_pa_first';
  $handler->display->display_options['fields']['field_opg_pa_first']['field'] = 'field_opg_pa_first';
  $handler->display->display_options['fields']['field_opg_pa_first']['relationship'] = 'field_opg_primary_author_value';
  $handler->display->display_options['fields']['field_opg_pa_first']['label'] = '';
  $handler->display->display_options['fields']['field_opg_pa_first']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_opg_pa_first']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Last Name */
  $handler->display->display_options['fields']['field_opg_pa_last']['id'] = 'field_opg_pa_last';
  $handler->display->display_options['fields']['field_opg_pa_last']['table'] = 'field_data_field_opg_pa_last';
  $handler->display->display_options['fields']['field_opg_pa_last']['field'] = 'field_opg_pa_last';
  $handler->display->display_options['fields']['field_opg_pa_last']['relationship'] = 'field_opg_primary_author_value';
  $handler->display->display_options['fields']['field_opg_pa_last']['label'] = '';
  $handler->display->display_options['fields']['field_opg_pa_last']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_opg_pa_last']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_opg_pa_last']['alter']['text'] = '[field_opg_pa_first] [field_opg_pa_last]';
  $handler->display->display_options['fields']['field_opg_pa_last']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_opg_pa_last']['alter']['path'] = '[field_opg_pa_url]';
  $handler->display->display_options['fields']['field_opg_pa_last']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['field_opg_pa_last']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_opg_pa_last']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['field_opg_pa_last']['element_label_colon'] = FALSE;
  /* Field: Field collection item: opg not pa */
  $handler->display->display_options['fields']['field_opg_not_pa']['id'] = 'field_opg_not_pa';
  $handler->display->display_options['fields']['field_opg_not_pa']['table'] = 'field_data_field_opg_not_pa';
  $handler->display->display_options['fields']['field_opg_not_pa']['field'] = 'field_opg_not_pa';
  $handler->display->display_options['fields']['field_opg_not_pa']['relationship'] = 'field_opg_primary_author_value';
  $handler->display->display_options['fields']['field_opg_not_pa']['label'] = 'Author';
  $handler->display->display_options['fields']['field_opg_not_pa']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_opg_not_pa']['alter']['text'] = '[field_opg_pa_last]';
  $handler->display->display_options['fields']['field_opg_not_pa']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_opg_not_pa']['empty'] = '[name]';
  $handler->display->display_options['fields']['field_opg_not_pa']['empty_zero'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Proposal Title';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = TRUE;
  /* Field: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['label'] = 'Number of Comments';
  /* Field: Content: Version Count */
  $handler->display->display_options['fields']['version_count']['id'] = 'version_count';
  $handler->display->display_options['fields']['version_count']['table'] = 'node';
  $handler->display->display_options['fields']['version_count']['field'] = 'version_count';
  $handler->display->display_options['fields']['version_count']['label'] = '';
  $handler->display->display_options['fields']['version_count']['exclude'] = TRUE;
  $handler->display->display_options['fields']['version_count']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['version_count']['separator'] = '';
  /* Field: Global: Math expression */
  $handler->display->display_options['fields']['expression']['id'] = 'expression';
  $handler->display->display_options['fields']['expression']['table'] = 'views';
  $handler->display->display_options['fields']['expression']['field'] = 'expression';
  $handler->display->display_options['fields']['expression']['label'] = '';
  $handler->display->display_options['fields']['expression']['exclude'] = TRUE;
  $handler->display->display_options['fields']['expression']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['expression']['precision'] = '0';
  $handler->display->display_options['fields']['expression']['separator'] = '';
  $handler->display->display_options['fields']['expression']['expression'] = '[version_count] - 1';
  /* Field: Sortable Version Count */
  $handler->display->display_options['fields']['version_count_1']['id'] = 'version_count_1';
  $handler->display->display_options['fields']['version_count_1']['table'] = 'node';
  $handler->display->display_options['fields']['version_count_1']['field'] = 'version_count';
  $handler->display->display_options['fields']['version_count_1']['ui_name'] = 'Sortable Version Count';
  $handler->display->display_options['fields']['version_count_1']['label'] = 'Number of Revisions';
  $handler->display->display_options['fields']['version_count_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['version_count_1']['alter']['text'] = '[expression]';
  $handler->display->display_options['fields']['version_count_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['version_count_1']['separator'] = '';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['operator'] = 'not in';
  $handler->display->display_options['filters']['type']['value'] = array(
    'page' => 'page',
  );
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  /* Filter criterion: Taxonomy term: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'field_opg_status_target_id';
  $handler->display->display_options['filters']['name']['value'] = 'Awarded';
  $handler->display->display_options['path'] = 'opg-core/%/awards';

  /* Display: Bulk Updates */
  $handler = $view->new_display('page', 'Bulk Updates', 'page_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Bulk Proposal Updates';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'og_context';
  $handler->display->display_options['access']['perm'] = 'update group';
  $handler->display->display_options['access']['group_id_arg'] = '1';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'name' => 'name',
    'field_opg_pa_url' => 'field_opg_pa_url',
    'field_opg_pa_first' => 'field_opg_pa_first',
    'field_opg_pa_last' => 'field_opg_pa_last',
    'field_opg_not_pa' => 'field_opg_not_pa',
    'title' => 'title',
    'name_1' => 'name_1',
    'created' => 'created',
    'comment_count' => 'comment_count',
    'version_count' => 'version_count',
    'expression' => 'expression',
    'version_count_1' => 'version_count_1',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_opg_pa_url' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_opg_pa_first' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_opg_pa_last' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_opg_not_pa' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'comment_count' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'version_count' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'expression' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'version_count_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::op_common_update_node_rate_expiration_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::opg_core_update_node_comment_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::opg_core_update_node_status_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = FALSE;
  /* Field: Field collection item: UCSF Profiles URL */
  $handler->display->display_options['fields']['field_opg_pa_url']['id'] = 'field_opg_pa_url';
  $handler->display->display_options['fields']['field_opg_pa_url']['table'] = 'field_data_field_opg_pa_url';
  $handler->display->display_options['fields']['field_opg_pa_url']['field'] = 'field_opg_pa_url';
  $handler->display->display_options['fields']['field_opg_pa_url']['relationship'] = 'field_opg_primary_author_value';
  $handler->display->display_options['fields']['field_opg_pa_url']['label'] = '';
  $handler->display->display_options['fields']['field_opg_pa_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_opg_pa_url']['element_label_colon'] = FALSE;
  /* Field: Field collection item: First Name */
  $handler->display->display_options['fields']['field_opg_pa_first']['id'] = 'field_opg_pa_first';
  $handler->display->display_options['fields']['field_opg_pa_first']['table'] = 'field_data_field_opg_pa_first';
  $handler->display->display_options['fields']['field_opg_pa_first']['field'] = 'field_opg_pa_first';
  $handler->display->display_options['fields']['field_opg_pa_first']['relationship'] = 'field_opg_primary_author_value';
  $handler->display->display_options['fields']['field_opg_pa_first']['label'] = '';
  $handler->display->display_options['fields']['field_opg_pa_first']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_opg_pa_first']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Last Name */
  $handler->display->display_options['fields']['field_opg_pa_last']['id'] = 'field_opg_pa_last';
  $handler->display->display_options['fields']['field_opg_pa_last']['table'] = 'field_data_field_opg_pa_last';
  $handler->display->display_options['fields']['field_opg_pa_last']['field'] = 'field_opg_pa_last';
  $handler->display->display_options['fields']['field_opg_pa_last']['relationship'] = 'field_opg_primary_author_value';
  $handler->display->display_options['fields']['field_opg_pa_last']['label'] = '';
  $handler->display->display_options['fields']['field_opg_pa_last']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_opg_pa_last']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_opg_pa_last']['alter']['text'] = '[field_opg_pa_first] [field_opg_pa_last]';
  $handler->display->display_options['fields']['field_opg_pa_last']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_opg_pa_last']['alter']['path'] = '[field_opg_pa_url]';
  $handler->display->display_options['fields']['field_opg_pa_last']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['field_opg_pa_last']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_opg_pa_last']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['field_opg_pa_last']['element_label_colon'] = FALSE;
  /* Field: Field collection item: opg not pa */
  $handler->display->display_options['fields']['field_opg_not_pa']['id'] = 'field_opg_not_pa';
  $handler->display->display_options['fields']['field_opg_not_pa']['table'] = 'field_data_field_opg_not_pa';
  $handler->display->display_options['fields']['field_opg_not_pa']['field'] = 'field_opg_not_pa';
  $handler->display->display_options['fields']['field_opg_not_pa']['relationship'] = 'field_opg_primary_author_value';
  $handler->display->display_options['fields']['field_opg_not_pa']['label'] = 'Author';
  $handler->display->display_options['fields']['field_opg_not_pa']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_opg_not_pa']['alter']['text'] = '[field_opg_pa_last]';
  $handler->display->display_options['fields']['field_opg_not_pa']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_opg_not_pa']['empty'] = '[name]';
  $handler->display->display_options['fields']['field_opg_not_pa']['empty_zero'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Proposal Title';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = TRUE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['relationship'] = 'field_opg_status_target_id';
  $handler->display->display_options['fields']['name_1']['label'] = 'Status';
  $handler->display->display_options['fields']['name_1']['element_label_colon'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['label'] = 'Number of Comments';
  /* Field: Content: Version Count */
  $handler->display->display_options['fields']['version_count']['id'] = 'version_count';
  $handler->display->display_options['fields']['version_count']['table'] = 'node';
  $handler->display->display_options['fields']['version_count']['field'] = 'version_count';
  $handler->display->display_options['fields']['version_count']['label'] = '';
  $handler->display->display_options['fields']['version_count']['exclude'] = TRUE;
  $handler->display->display_options['fields']['version_count']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['version_count']['separator'] = '';
  /* Field: Global: Math expression */
  $handler->display->display_options['fields']['expression']['id'] = 'expression';
  $handler->display->display_options['fields']['expression']['table'] = 'views';
  $handler->display->display_options['fields']['expression']['field'] = 'expression';
  $handler->display->display_options['fields']['expression']['label'] = '';
  $handler->display->display_options['fields']['expression']['exclude'] = TRUE;
  $handler->display->display_options['fields']['expression']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['expression']['precision'] = '0';
  $handler->display->display_options['fields']['expression']['separator'] = '';
  $handler->display->display_options['fields']['expression']['expression'] = '[version_count] - 1';
  /* Field: Sortable Version Count */
  $handler->display->display_options['fields']['version_count_1']['id'] = 'version_count_1';
  $handler->display->display_options['fields']['version_count_1']['table'] = 'node';
  $handler->display->display_options['fields']['version_count_1']['field'] = 'version_count';
  $handler->display->display_options['fields']['version_count_1']['ui_name'] = 'Sortable Version Count';
  $handler->display->display_options['fields']['version_count_1']['label'] = 'Number of Revisions';
  $handler->display->display_options['fields']['version_count_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['version_count_1']['alter']['text'] = '[expression]';
  $handler->display->display_options['fields']['version_count_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['version_count_1']['separator'] = '';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['operator'] = 'not in';
  $handler->display->display_options['filters']['type']['value'] = array(
    'page' => 'page',
  );
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  /* Filter criterion: Taxonomy term: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'field_opg_status_target_id';
  $handler->display->display_options['filters']['name']['operator'] = 'not_starts';
  $handler->display->display_options['filters']['name']['value'] = 'Admin';
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Current Status';
  $handler->display->display_options['filters']['name']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['remember_roles'] = array(
    2 => '2',
    3 => 0,
    1 => 0,
    6 => 0,
    10 => 0,
    4 => 0,
    5 => 0,
    11 => 0,
    8 => 0,
    7 => 0,
    9 => 0,
  );
  $handler->display->display_options['path'] = 'opg-core/%/bulk-updates';

  /* Display: Summary ART CSV */
  $handler = $view->new_display('views_data_export', 'Summary ART CSV', 'views_data_export_3');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'generic-forum-url-artexport-%timestamp-full.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 1;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 1;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  /* Field: Field collection item: First Name */
  $handler->display->display_options['fields']['field_opg_pa_first']['id'] = 'field_opg_pa_first';
  $handler->display->display_options['fields']['field_opg_pa_first']['table'] = 'field_data_field_opg_pa_first';
  $handler->display->display_options['fields']['field_opg_pa_first']['field'] = 'field_opg_pa_first';
  $handler->display->display_options['fields']['field_opg_pa_first']['relationship'] = 'field_opg_primary_author_value';
  $handler->display->display_options['fields']['field_opg_pa_first']['label'] = '';
  $handler->display->display_options['fields']['field_opg_pa_first']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_opg_pa_first']['element_label_colon'] = FALSE;
  /* Field: Field collection item: opg not pa */
  $handler->display->display_options['fields']['field_opg_not_pa']['id'] = 'field_opg_not_pa';
  $handler->display->display_options['fields']['field_opg_not_pa']['table'] = 'field_data_field_opg_not_pa';
  $handler->display->display_options['fields']['field_opg_not_pa']['field'] = 'field_opg_not_pa';
  $handler->display->display_options['fields']['field_opg_not_pa']['relationship'] = 'field_opg_primary_author_value';
  $handler->display->display_options['fields']['field_opg_not_pa']['label'] = 'First Name';
  $handler->display->display_options['fields']['field_opg_not_pa']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_opg_not_pa']['alter']['text'] = '[field_opg_pa_first]';
  $handler->display->display_options['fields']['field_opg_not_pa']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_opg_not_pa']['empty'] = '[field_first_name]';
  $handler->display->display_options['fields']['field_opg_not_pa']['empty_zero'] = TRUE;
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Last Name */
  $handler->display->display_options['fields']['field_opg_pa_last']['id'] = 'field_opg_pa_last';
  $handler->display->display_options['fields']['field_opg_pa_last']['table'] = 'field_data_field_opg_pa_last';
  $handler->display->display_options['fields']['field_opg_pa_last']['field'] = 'field_opg_pa_last';
  $handler->display->display_options['fields']['field_opg_pa_last']['relationship'] = 'field_opg_primary_author_value';
  $handler->display->display_options['fields']['field_opg_pa_last']['label'] = '';
  $handler->display->display_options['fields']['field_opg_pa_last']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_opg_pa_last']['element_label_colon'] = FALSE;
  /* Field: Field collection item: opg not pa */
  $handler->display->display_options['fields']['field_opg_not_pa_1']['id'] = 'field_opg_not_pa_1';
  $handler->display->display_options['fields']['field_opg_not_pa_1']['table'] = 'field_data_field_opg_not_pa';
  $handler->display->display_options['fields']['field_opg_not_pa_1']['field'] = 'field_opg_not_pa';
  $handler->display->display_options['fields']['field_opg_not_pa_1']['relationship'] = 'field_opg_primary_author_value';
  $handler->display->display_options['fields']['field_opg_not_pa_1']['label'] = 'Last Name';
  $handler->display->display_options['fields']['field_opg_not_pa_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_opg_not_pa_1']['alter']['text'] = '[field_opg_pa_last]';
  $handler->display->display_options['fields']['field_opg_not_pa_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_opg_not_pa_1']['empty'] = '[field_last_name]';
  $handler->display->display_options['fields']['field_opg_not_pa_1']['empty_zero'] = TRUE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Full Name';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_opg_not_pa] [field_opg_not_pa_1]';
  $handler->display->display_options['fields']['nothing']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['relationship'] = 'uid';
  $handler->display->display_options['fields']['mail']['label'] = '';
  $handler->display->display_options['fields']['mail']['exclude'] = TRUE;
  $handler->display->display_options['fields']['mail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  /* Field: Field collection item: Email */
  $handler->display->display_options['fields']['field_opg_pa_email']['id'] = 'field_opg_pa_email';
  $handler->display->display_options['fields']['field_opg_pa_email']['table'] = 'field_data_field_opg_pa_email';
  $handler->display->display_options['fields']['field_opg_pa_email']['field'] = 'field_opg_pa_email';
  $handler->display->display_options['fields']['field_opg_pa_email']['relationship'] = 'field_opg_primary_author_value';
  $handler->display->display_options['fields']['field_opg_pa_email']['label'] = '';
  $handler->display->display_options['fields']['field_opg_pa_email']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_opg_pa_email']['element_label_colon'] = FALSE;
  /* Field: Field collection item: opg not pa */
  $handler->display->display_options['fields']['field_opg_not_pa_2']['id'] = 'field_opg_not_pa_2';
  $handler->display->display_options['fields']['field_opg_not_pa_2']['table'] = 'field_data_field_opg_not_pa';
  $handler->display->display_options['fields']['field_opg_not_pa_2']['field'] = 'field_opg_not_pa';
  $handler->display->display_options['fields']['field_opg_not_pa_2']['relationship'] = 'field_opg_primary_author_value';
  $handler->display->display_options['fields']['field_opg_not_pa_2']['label'] = 'Email';
  $handler->display->display_options['fields']['field_opg_not_pa_2']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_opg_not_pa_2']['alter']['text'] = '[field_opg_pa_email]';
  $handler->display->display_options['fields']['field_opg_not_pa_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_opg_not_pa_2']['empty'] = '[mail]';
  $handler->display->display_options['fields']['field_opg_not_pa_2']['empty_zero'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['relationship'] = 'field_opg_status_target_id';
  $handler->display->display_options['fields']['name_1']['label'] = 'Status';
  $handler->display->display_options['fields']['name_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['path'] = 'opg-core/%/summary/artcsv';
  $handler->display->display_options['displays'] = array(
    'page_2' => 'page_2',
    'default' => 0,
    'page_3' => 0,
    'page_4' => 0,
    'page_1' => 0,
    'page_5' => 0,
  );
  $handler->display->display_options['use_batch'] = '0';
  $export['opg_core_reports'] = $view;

  $view = new view();
  $view->name = 'opg_groups';
  $view->description = 'A listing of all node groups.';
  $view->tag = 'OG Extras';
  $view->base_table = 'node';
  $view->human_name = 'OPG Groups';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Groups';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'type' => 'type',
    'body' => 'body',
    'name' => 'name',
    'created' => 'created',
    'group_group' => 'group_group',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'group_group' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = FALSE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: OG membership: OG membership from Node group */
  $handler->display->display_options['relationships']['og_membership_rel_group']['id'] = 'og_membership_rel_group';
  $handler->display->display_options['relationships']['og_membership_rel_group']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel_group']['field'] = 'og_membership_rel_group';
  $handler->display->display_options['relationships']['og_membership_rel_group']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Team';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Field: Content: Project Description */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Description';
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '300';
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Manager';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created';
  $handler->display->display_options['fields']['created']['date_format'] = 'time ago';
  /* Field: Content: Group */
  $handler->display->display_options['fields']['group_group']['id'] = 'group_group';
  $handler->display->display_options['fields']['group_group']['table'] = 'field_data_group_group';
  $handler->display->display_options['fields']['group_group']['field'] = 'group_group';
  $handler->display->display_options['fields']['group_group']['label'] = 'Join Link';
  $handler->display->display_options['fields']['group_group']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['group_group']['type'] = 'og_group_subscribe';
  $handler->display->display_options['fields']['group_group']['settings'] = array(
    'field_name' => '0',
  );
  /* Sort criterion: Content: Published */
  $handler->display->display_options['sorts']['status']['id'] = 'status';
  $handler->display->display_options['sorts']['status']['table'] = 'node';
  $handler->display->display_options['sorts']['status']['field'] = 'status';
  $handler->display->display_options['sorts']['status']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'groups';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Groups';
  $handler->display->display_options['menu']['weight'] = '10';
  $handler->display->display_options['menu']['name'] = 'user-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['opg_groups'] = $view;

  $view = new view();
  $view->name = 'opg_status_er';
  $view->description = 'Entity Reference view for limiting group content status terms';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'opg_status_er';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_opg_status_voc_node']['id'] = 'reverse_field_opg_status_voc_node';
  $handler->display->display_options['relationships']['reverse_field_opg_status_voc_node']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['relationships']['reverse_field_opg_status_voc_node']['field'] = 'reverse_field_opg_status_voc_node';
  $handler->display->display_options['relationships']['reverse_field_opg_status_voc_node']['required'] = TRUE;
  /* Relationship: OG membership: OG membership from Node group */
  $handler->display->display_options['relationships']['og_membership_rel_group']['id'] = 'og_membership_rel_group';
  $handler->display->display_options['relationships']['og_membership_rel_group']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel_group']['field'] = 'og_membership_rel_group';
  $handler->display->display_options['relationships']['og_membership_rel_group']['relationship'] = 'reverse_field_opg_status_voc_node';
  $handler->display->display_options['relationships']['og_membership_rel_group']['required'] = TRUE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Contextual filter: OG membership: Group ID */
  $handler->display->display_options['arguments']['gid']['id'] = 'gid';
  $handler->display->display_options['arguments']['gid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['gid']['field'] = 'gid';
  $handler->display->display_options['arguments']['gid']['relationship'] = 'og_membership_rel_group';
  $handler->display->display_options['arguments']['gid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['gid']['default_argument_type'] = 'og_context';
  $handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['gid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['gid']['validate']['type'] = 'og';

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'name' => 'name',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'name' => 'name',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['opg_status_er'] = $view;

  $view = new view();
  $view->name = 'opg_user_groups';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'og_membership';
  $view->human_name = 'opg_user_groups';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Group Memberships';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: OG membership: Group Node from OG membership */
  $handler->display->display_options['relationships']['og_membership_related_node_group']['id'] = 'og_membership_related_node_group';
  $handler->display->display_options['relationships']['og_membership_related_node_group']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['og_membership_related_node_group']['field'] = 'og_membership_related_node_group';
  /* Relationship: OG membership: User from OG membership */
  $handler->display->display_options['relationships']['og_membership_related_user']['id'] = 'og_membership_related_user';
  $handler->display->display_options['relationships']['og_membership_related_user']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['og_membership_related_user']['field'] = 'og_membership_related_user';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['relationship'] = 'og_membership_related_node_group';
  /* Field: OG membership: Og membership ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'og_membership';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['label'] = 'ID';
  /* Field: OG membership: Group_type */
  $handler->display->display_options['fields']['group_type']['id'] = 'group_type';
  $handler->display->display_options['fields']['group_type']['table'] = 'og_membership';
  $handler->display->display_options['fields']['group_type']['field'] = 'group_type';
  $handler->display->display_options['fields']['group_type']['label'] = '';
  $handler->display->display_options['fields']['group_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['group_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['group_type']['machine_name'] = TRUE;
  /* Field: OG membership: Group ID */
  $handler->display->display_options['fields']['gid']['id'] = 'gid';
  $handler->display->display_options['fields']['gid']['table'] = 'og_membership';
  $handler->display->display_options['fields']['gid']['field'] = 'gid';
  $handler->display->display_options['fields']['gid']['label'] = '';
  $handler->display->display_options['fields']['gid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['gid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['gid']['separator'] = '';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'og_membership_related_node_group';
  /* Field: Content: Project Description */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['relationship'] = 'og_membership_related_node_group';
  $handler->display->display_options['fields']['body']['label'] = 'Description';
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Owner';
  /* Field: OG membership: Created */
  $handler->display->display_options['fields']['created_1']['id'] = 'created_1';
  $handler->display->display_options['fields']['created_1']['table'] = 'og_membership';
  $handler->display->display_options['fields']['created_1']['field'] = 'created';
  $handler->display->display_options['fields']['created_1']['label'] = 'Joined';
  $handler->display->display_options['fields']['created_1']['date_format'] = 'medium';
  $handler->display->display_options['fields']['created_1']['second_date_format'] = 'long';
  /* Field: leave group link */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'leave group link';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Leave This Group';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'group/[group_type]/[gid]/unsubscribe';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: OG membership: Created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'og_membership';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: OG membership: Entity id */
  $handler->display->display_options['arguments']['etid']['id'] = 'etid';
  $handler->display->display_options['arguments']['etid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['etid']['field'] = 'etid';
  $handler->display->display_options['arguments']['etid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['etid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['etid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['etid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['etid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['etid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['etid']['validate']['type'] = 'user';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'user/%/groups';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Groups';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['opg_user_groups'] = $view;

  return $export;
}
