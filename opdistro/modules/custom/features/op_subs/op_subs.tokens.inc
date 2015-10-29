<?php

/**
 * @file
 * Custom tokens for Open Proposals.
 */

/**
 * Implements hook_token_info().
 *
 * @ingroup op_subs
 */
function op_subs_token_info() {
  $info = array();

  $info['types']['op-subs'] = array(
    'name' => t('Open Proposal subscriptions'),
    'description' => t('Tokens related to subscriptions to Open Proposal content'),
  );
  $info['tokens']['op-subs']['link'] = array(
    'name' => t('Open Proposal subscriptions link'),
    'description' => t('A link to create or cancel an Open Proposal subscription'),
  );
  $info['tokens']['op-subs']['url'] = array(
    'name' => t('Open Proposal subscriptions URL'),
    'description' => t('The URL for a link to create or cancel an Open Proposal subscription'),
  );
  $info['tokens']['op-subs']['text'] = array(
    'name' => t('Open Proposal subscriptions text'),
    'description' => t('The text for a link to create or cancel an Open Proposal subscription'),
  );

  $info['tokens']['node']['op-subs'] = array(
    'name' => t('Open Proposal subscription tokens'),
    'description' => t('Open Proposal subscription tokens for the node'),
    'type' => 'op-subs',
  );
  $info['tokens']['content-type']['op-subs'] = array(
    'name' => t('Open Proposal subscription tokens'),
    'description' => t('Open Proposal tokens for the content type'),
    'type' => 'op-subs',
  );

  return $info;
}

/**
 * Implements hook_tokens().
 *
 * @ingroup op_subs
 */
function op_subs_tokens($type, $tokens, array $data = array(), array $options = array()) {
  // dpm(compact('type','tokens','data','options'), __FUNCTION__);
  $replacements = array();
  $sanitize = !empty($options['sanitize']);

  op_subs_make_token_sublinks($data, $type);

  if ($type == 'op-subs') {
    $link = empty($data['sub_link']) ? array() : $data['sub_link'];
    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'link':
          if (isset($link['title'])) {
            if (isset($link['href'])) {
              $replacements[$original] = l($link['title'], $link['href'], $link);
            }
            else {
              $replacements[$original] = $link['title'];
            }
          }
          else {
            $replacements[$original] = NULL;
          }
          break;
        case 'url':
          $replacements[$original] = isset($link['href']) ? $link['href'] : NULL;
          break;
        case 'text':
          $replacements[$original] = isset($link['title']) ? $link['title'] : NULL;
          break;
      }
    }
  }

  if ($type == 'node') {
    if ($op_subs_tokens = token_find_with_prefix($tokens, 'op-subs')) {
      $replacements += token_generate('op-subs', $op_subs_tokens, $data, $options);
    }
  }
  if ($type == 'content-type') {
    if ($op_subs_tokens = token_find_with_prefix($tokens, 'op-subs')) {
      $replacements += token_generate('op-subs', $op_subs_tokens, $data, $options);
    }
  }

  return $replacements;
}

function op_subs_make_token_sublinks(&$data, $type) {
  $sub_node = new stdClass();
  $links = array();
  if (empty($data['node']->type)) {
    if (empty($data['node_type'])) {
      if ($current_forum = op_common_current_forum($data)) {
        $sub_node->type = $current_forum->content_type;
      }
    }
    else {
      $sub_node->type = $data['node_type']->type;
    }
  }
  else {
    $sub_node = $data['node'];
  }
  if (!empty($sub_node->type)) {
    if (!isset($sub_node->nid)) {
      $sub_node->nid = '';
      $sub_node->uid = '';
    }
    ctsi_node_sublinks($links, $sub_node);
  }
  if ($type == 'node' and !empty($sub_node->nid) and !empty($links['subscriptions_node_nid_' . $sub_node->nid])) {
    $data['sub_link'] = $links['subscriptions_node_nid_' . $sub_node->nid];
  }
  elseif ($type == 'content-type' and !empty($sub_node->type) and !empty($links['subscriptions_node_type_' . $sub_node->type])) {
    $data['sub_link'] = $links['subscriptions_node_type_' . $sub_node->type];
  }
}
