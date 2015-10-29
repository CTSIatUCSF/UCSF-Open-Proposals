<?php

/**
 * @file
 * Token callbacks for the og_subscriptions module.
 */

/**
 * Implements hook_token_info().
 *
 * @return array
 */
function og_subscriptions_token_info() {
  $info = array();

  $info['tokens']['subs']['group'] = array(
    'name' => t("Group"),
    'description' => t("The group, if this notification was triggered by a %Group subscription.", array('%Group' => t('Group'))),
    'type' => 'term',
  );

  return $info;
}

/** TODO: REWRITE
 * Implements hook_tokens().
 *
 * @param $type
 * @param $tokens
 * @param array $data
 * @param array $options
 *
 * @return array
 *
 * @ingroup hooks
 */
function og_subscriptions_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $url_options = array('absolute' => TRUE);
  if (isset($options['language'])) {
    $url_options['language'] = $options['language'];
    $language_code = $options['language']->language;
  }
  else {
    $language_code = NULL;
  }
  $sanitize = !empty($options['sanitize']);
  $replacements = array();
  if ($type == 'subs' && !empty($data['subs']['group'])) {
    $group = $data['subs']['group'];

    if (is_array($group)) {
      if (empty($group['group_type']) and empty($group['gid'])) {
        dpm(compact('type','tokens','data','options'), 'invalid group array');
        return $replacements;
      }
      if (empty($group['group_entity'])) {
        if ($group_entity = entity_load_single($group['group_type'], $group['gid'])) {
          $group['group_entity'] = $group_entity;
        }
      }
      else {
        $group_entity = $group['group_entity'];
      }
    }
    elseif (is_object($group)) {
      if (isset($group->nid)) {
        // it's a node
        $group_entity = $group;
        $group = array('group_type' => 'node', 'gid' => $group_entity->nid, 'group_entity' => $group_entity);
      }
    }
    if (empty($group_entity)) {
      dpm(compact('type','tokens','data','options'), 'unknown group');
      return $replacements;
    }
    $wrapper = entity_metadata_wrapper($group['group_type'], $group_entity);
    foreach ($tokens as $name => $original) {
      switch ($name) {
          // Default values for the chained tokens handled below.
        case 'group':
          $replacements[$original] = $sanitize ? filter_xss($wrapper->label()) : $wrapper->label();
          break;
      }
    }

    if ($group_tokens = token_find_with_prefix($tokens, 'group')) {
      $replacements += token_generate('group', $group_tokens, array('group' => $group), $options);
    }
  }
  return $replacements;
}

