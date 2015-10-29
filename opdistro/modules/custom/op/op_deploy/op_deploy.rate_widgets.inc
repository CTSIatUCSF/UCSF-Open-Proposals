<?php
/**
 * @file
 * op_deploy.rate_widgets.inc
 */

/**
 * Does an initial setup of known Rate custom widgets.
 *
 * We don't track these as Features items because they change constantly
 *  to reflect local db content.
 *
 */
function op_deploy_setup_rate_widgets() {
  $roles = user_roles();
  $rids = array_flip($roles);
  if (isset($rids['authenticated user'])) {
    $auth_rid = $rids['authenticated user'];
  }
  else {
    throw new Exception("No 'authenticated user' role!");
  }

  $custom = array();

  $custom['thumbs_up'] = (object) array(
    'name' => 'thumbs_up',
    'tag' => 'vote',
    'title' => 'Thumbs Up',
    'node_types' => array(),
    'comment_types' => array(),
    'options' => array(
      0 => array(
        0 => 1,
        1 => 'up',
      ),
    ),
    'template' => 'thumbs_up',
    'node_display' => '2',
    'teaser_display' => TRUE,
    'comment_display' => '2',
    'node_display_mode' => '1',
    'teaser_display_mode' => '1',
    'comment_display_mode' => '1',
    'roles' => array(
      $auth_rid => (string)$auth_rid,
    ),
    'allow_voting_by_author' => 1,
    'noperm_behaviour' => '3',
    'displayed' => '2',
    'displayed_just_voted' => '2',
    'description' => '',
    'description_in_compact' => TRUE,
    'delete_vote_on_second_click' => '1',
    'use_source_translation' => TRUE,
    'value_type' => 'points',
    'theme' => 'rate_template_thumbs_up',
    'css' => 'sites/all/modules/contrib/rate/templates/thumbs-up/thumbs-up.css',
    'translate' => TRUE,
    'expiration' => '-1',
    'expiration_allow_override' => TRUE,
  );

  $custom['likeme'] = (object) array(
    'name' => 'likeme',
    'tag' => 'vote',
    'title' => 'likeme',
    'node_types' => array(),
    'comment_types' => array(),
    'options' => array(
      0 => array(
        0 => '1',
        1 => 'Like',
      ),
    ),
    'template' => 'custom',
    'node_display' => '2',
    'teaser_display' => TRUE,
    'comment_display' => '2',
    'node_display_mode' => '1',
    'teaser_display_mode' => '1',
    'comment_display_mode' => '1',
    'roles' => array(
      $auth_rid => (string)$auth_rid,
    ),
    'allow_voting_by_author' => 1,
    'noperm_behaviour' => '3',
    'displayed' => '2',
    'displayed_just_voted' => '2',
    'description' => '',
    'description_in_compact' => TRUE,
    'delete_vote_on_second_click' => '1',
    'use_source_translation' => TRUE,
    'value_type' => 'points',
    'translate' => TRUE,
    'expiration' => '-1',
    'expiration_allow_override' => TRUE,
  );

  $widgets = variable_get('rate_widgets', array());
  $names = array();
  $changed = FALSE;
  foreach ($widgets as $widget) {
    $names[$widget->name] = $widget->name;
  }

  foreach ($custom as $name => $widget) {
    if (!isset($names[$name])) {
      drupal_set_message("Add custom rate widget '{$name}'");
      $widgets[] = $widget;
      $changed = TRUE;
    }
  }

  if ($changed) {
    drupal_set_message("Updating 'rate_widgets' variable");
    variable_set('rate_widgets', $widgets);
  }
}
