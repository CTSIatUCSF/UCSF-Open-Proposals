<?php

/**
 * Implements hook_form_BASE_FORM_ID_alter().
 */
function opbamboo_form_node_form_alter(&$form, &$form_state, $form_id) {
  // dpm(compact('form','form_state','form_id'), __FUNCTION__);

  // add optimistic English to explain what "preview" means
  if (isset($form['actions']['preview']) and empty($form['actions']['preview']['#prefix'])) {
    $form['actions']['preview']['#prefix'] = '<p><br />Use the preview to check your work - it will appear above the input form with a shaded background. When you are satisfied, hit Save.</p>';
  }

}

/**
 * Implements hook_preprocess().
 *
 * Keep this around so we can check out various hook variables
 *  without having to redefine theme registry entries.
 */
function opbamboo_preprocess(&$vars, $hook) {
  static $hooks = array();
  if (empty($hooks[$hook])) {
    // dpm($hook);
    $hooks[$hook] = $hook;
  }
}

/**
 * Implements hook_preprocess_views_view().
 */
function opbamboo_preprocess_views_view(&$vars) {
  static $dome = true;

  $view = $vars['view'];
  if ($view->name == 'opg_core') {
    $defaults = array();
    opg_core_get_nouns($defaults);
    opg_core_get_groupword($defaults);
    if ($view->current_display == 'admin_post_page') {
      // dpm(compact('vars','defaults'), __FUNCTION__ . '::' . $view->current_display . ' vars');
      if (isset($vars['header']) and strpos($vars['header'], $defaults['lcgroupword']) !== FALSE) {
        if ($opg = opbamboo_get_view_opg($view)) {
          if (!empty($opg['lcgroupword']) and $opg['lcgroupword'] != $defaults['lcgroupword']) {
            $vars['header'] = str_replace($defaults['lcgroupword'], $opg['lcgroupword'], $vars['header']);
          }
        }
      }
      if (isset($vars['empty']) and strpos($vars['empty'], $defaults['lcgroupword']) !== FALSE) {
        if ($opg = opbamboo_get_view_opg($view)) {
          if (!empty($opg['lcgroupword']) and $opg['lcgroupword'] != $defaults['lcgroupword']) {
            $vars['empty'] = str_replace($defaults['lcgroupword'], $opg['lcgroupword'], $vars['empty']);
          }
        }
      }
    }
    // TODO there may be other places where we can't set a dynamic value in the view itself.
    if (isset($view->build_info['title']) and strpos($view->build_info['title'], $defaults['noun']) !== FALSE) {
      if ($opg = opbamboo_get_view_opg($view)) {
        if (!empty($opg['noun']) and $opg['noun'] != $defaults['noun']) {
          if (strpos($view->build_info['title'], $opg['nouns']) === FALSE) {
            $view->build_info['title'] = str_replace($defaults['nouns'], $opg['nouns'], $view->build_info['title']);
          }
          if (strpos($view->build_info['title'], $opg['noun']) === FALSE) {
            $view->build_info['title'] = str_replace($defaults['noun'], $opg['noun'], $view->build_info['title']);
          }
        }
      }
    }
    else {
      // dpm('no title or des not contain ' . $defaults['noun'] . ' for ' . $vars['display_id']);
    }
  }
}

/**
 * Get an OPG group from view arguments if possible
 */
function opbamboo_get_view_opg($view) {
  static $got = array();

  if (!empty($view->display_handler->handlers['argument']['gid']->argument)) {
    $gid = $view->display_handler->handlers['argument']['gid']->argument;
    if (isset($got[$gid])) {
      return $got[$gid];
    }
    if ($group = opg_core_gid_to_group($gid)) {
      if ($opg = opg_core_load_opg($group)) {
        $got[$gid] = $opg;
        return $opg;
      }
      else {
        dpm(compact('gid','group','opg'), 'could not load opg for group');
      }
    }
    else {
      dpm(compact('gid','group'), 'could not load group for gid');
    }
  }
  else {
    dpm($view->display_handler->handlers['argument'], 'view->display_handler->handlers[argument] has no gid for ' . $view->current_display);
  }
}

/**
 * Implements hook_preprocess_page().
 */
function opbamboo_preprocess_page(&$vars) {
  global $theme_path;
  global $base_root;

  // dpm($vars, __FUNCTION__);

  // for use by external link redirect javascript
  $base_parts = parse_url($base_root);
  $base_host = empty($base_parts['host']) ? '' : $base_parts['host'];
  drupal_add_js(array('base_host' => $base_host), 'setting');

  if ($group = og_context()) {
    $opg = opg_core_load_opg($group);
  }
  else {
    $opg = array();
    opg_core_get_nouns($opg);
    opg_core_get_groupwords($opg);
  }
  $jsopg = array();
  foreach ($opg as $k => $v) {
    if (is_scalar($v)) {
      $jsopg[$k] = $v;
    }
  }
  drupal_add_js(array('opg' => $jsopg), 'setting');

  // an English name for the site that isn't installation-dependent
  drupal_add_js(array('siteName' => 'UCSF Open Proposals'), 'setting');

  // because eg double quotes were displaying as &quot;
  $vars['section_title'] = empty($vars['section_title']) ? '' : filter_xss(html_entity_decode($vars['section_title']));
  $vars['section_subtitle'] = empty($vars['section_subtitle']) ? '' : filter_xss(html_entity_decode($vars['section_subtitle']));

  if (strpos($_GET['q'], 'goto/subscribe/add/type') === 0) {
    drupal_set_title('Open Proposals Updates');
  }
  elseif (strpos($_GET['q'], 'goto/subscribe/add/node') === 0) {
    drupal_set_title('Open Proposals Updates');
  }

}

/**
 * Implements hook_ctsi_node_sublinks_alter()
 */
function opbamboo_ctsi_node_sublinks_alter(&$links, $node) {
  global $user;
  // dpm(compact('links','node'), __FUNCTION__);

  $op_forum = op_common_op_forum_load($node->type);
  $noun = isset($op_forum->noun) ? $op_forum->noun : 'proposal';
  $nouns = isset($op_forum->nouns) ? $op_forum->nouns : 'proposals';

  $titles = array(
    'add' => array(
      'node' => 'Follow',
      'type' => 'Follow all ' . $nouns,
    ),
    'del' => array(
      'node' => 'Unfollow',
      'type' => 'Unfollow all ' . $nouns,
    ),
  );
  foreach ($links as $name => &$link) {
    if (empty($link['href'])) {
      // text only link entry
      continue;
    }
    $subargs = ctsi_subs_args($link['href']);
    if (empty($subargs)) {
      dpm(compact('name','link','subargs'), __FUNCTION__ . ' sees an invalid sublink entry?');
      continue;
    }
    if (empty($link['attributes']['class'])) {
      // let preceding modules signal customization by setting a class
      $link['attributes']['class'][] = 'opbamboo-sublink';
      op_common_sublink_custom_title($link, $titles, $subargs);
    }
    if (empty($user->uid)) {
      $target = ltrim(url($link['href'], $link), '/');
      // dpm(compact('target','link'), 'anon target for ' . $name);
      $node_type = false;
      if ($subargs['subtype'] == 'type') {
        $node_type = $subargs['subarg'];
      }
      elseif ($subargs['subtype'] == 'node') {
        if ($node = node_load($subargs['subarg'])) {
          $node_type = $node->type;
        }
      }
      elseif ($subargs['subtype'] == 'group') {
        if ($node = node_load($subargs['subarg'])) {
          $node_type = $node->type;
        }
      }
      if ($node_type) {
        // $options = array('query' => array('destination' => $target));
        $options = array('extra_path' => $target);
        if ($group = og_context()) {
          $opg = opg_core_load_opg($group);
          $options['login_type'] = $opg['login_type'];
          $options['op_login'] = $options['login'] = $opg['login'];
        }
        elseif ($op_forum = op_common_op_forum_load($node_type)) {
          $options['forum'] = $op_forum;
          $options['login_type'] = $op_forum->login_type;
        }
        else {
          $options['login_type'] = op_common_get_login_type($node_type);
        }
        $login_text = theme('op_login_text', $options);
      }
      else {
        // everything as a default
        $login_text = '<a href="/goto/login/saml/{$target}">UCSF</a>&nbsp;|&nbsp;<a href="/goto/login/drupal/{$target}">non-UCSF</a>';
      }
      $words = $link['title'];
      $link['title'] = '<a class="clicktext">' . $words . '</a>';
      $link['title'] .= '<span class="clicktextlong" style="display:none;">' . $login_text . ' to ' . strtolower($words) . '</span>';
      unset($link['query']);
      unset($link['href']);
    }
  }
  // dpm(compact('links','node'), __FUNCTION__ . ' result');
}

/**
 * Implements hook_preprocess_comment().
 */
function opbamboo_preprocess_comment(&$vars) {
  global $user;
  // dpm($vars, __FUNCTION__);

  if (!empty($vars['content']['links']['comment'])) {

    // move likeme to a link
    if (!empty($vars['content']['rate_likeme']['#markup'])) {
      if (empty($vars['content']['links']['rate'])) {
        $vars['content']['links']['rate'] = array('#theme' => 'links__comment__rate', '#links' => array()) + $vars['content']['links']['comment'];
      }
      $vars['content']['links']['rate']['#links']['ctsi-likeme'] = array(
        'title' => str_replace(array('<div','div>'), array('<span','span>'), $vars['content']['rate_likeme']['#markup']),
        'html' => TRUE,
      );
      unset($vars['content']['rate_likeme']);
    }

    // if we aren't seeing the complete comment, add a link to it (on the node page, not directly)
    if (!empty($vars['content']['comment_body']['#items'][0]['safe_value'])
      and (empty($vars['content']['comment_body'][0]['#markup']) or $vars['content']['comment_body'][0]['#markup'] != $vars['content']['comment_body']['#items'][0]['safe_value'])
    ) {
      // we have to rebuild the list to make this one first
      $newlinks = array(
        'comment-full' => array(
          'title' => t('Read Full Comment'),
          'href' => 'node/' . $vars['comment']->nid,
          'fragment' => 'comment-' . $vars['comment']->cid,
        ),
      );
      if (!empty($vars['content']['links']['comment']['#links'])) {
        foreach ($vars['content']['links']['comment']['#links'] as $key => $link) {
          $newlinks[$key] = $link;
        }
      }
      $vars['content']['links']['comment']['#links'] = $newlinks;
      // dpm($vars['content']['links'], 'adding Read Full Comment for comment ' . $vars['comment']->cid);
    }
  }
}

/**
 * Implements hook_preprocess_node().
 */
function opbamboo_preprocess_node(&$vars) {
  global $user;

  $node = $vars['node'];

  // don't bother during preview
  if (!empty($node->nid) and !empty($vars['content']['links'])) {

    foreach ($vars['content']['links'] as $group => &$links) {

      switch ($group) {

        case 'comment':
          if (empty($links['#links']['comment-add'])) {
            if ($node->comment == COMMENT_NODE_OPEN 
              and user_access('post comments')
              and ($user->uid or variable_get('ctsi_allow_anonymous_comments_' . $node->type, 0))
            ) {
              $links['#links']['comment-add'] = array(
                'title' => t('Comment'),
                'href' => "comment/reply/$node->nid",
                'attributes' => array('title' => t('Add a new comment to this page.')),
                'fragment' => 'comment-form',
              );
            }
          }
          else {
            $links['#links']['comment-add']['title'] = t('Comment');
          }

          // purge these old-style things
          unset($links['#links']['comment-comments']);
          unset($links['#links']['comment-new-comments']);

          break;

        case 'ctsi':
          // only node subscription link survives
          foreach (array_keys($links['#links']) as $link_key) {
            if ($link_key !== 'subscriptions_node_nid_' . $node->nid) {
              unset($links['#links'][$link_key]);
            }
          }
          break;
      }
    }

    // add image link for comment count
    //  for some reason when the node is displayed by a view 
    //    $vars['node']->comment is showing up as FALSE
    //    even though $vars['comment'] has the real value

    if (!empty($node->nid) and $vars['comment'] != COMMENT_NODE_HIDDEN) { 
      $comments = $vars['comment_count'];
      if ($new = comment_num_new($node->nid)) {
        $comments .= " ({$new} new)";
      }
      $vars['content']['links']['comment']['#links']['count-comments'] = array(
        'title' => '<span class="count-comments">' . $comments . '</span>',
        'html' => TRUE,
      );
    }

    // add image link for follower count
    if ($nodesubs = opg_core_node_subs($node->nid)) {
      $followers = empty($nodesubs['total']) ? 0 : count($nodesubs['total']);
      $vars['content']['links']['ctsi']['#links']['count-follows'] = array(
        'title' => '<span class="count-follows">' . $followers . '</span>',
        'html' => TRUE,
      );
    }

    // move likeme to a link
    if (!empty($vars['content']['rate_likeme']['#markup'])) {
      if (empty($vars['content']['links']['rate'])) {
        $vars['content']['links']['rate'] = array('#theme' => 'links__node__rate', '#links' => array()) + $vars['content']['links']['node'];
      }
      $vars['content']['links']['rate']['#links']['ctsi-likeme'] = array(
        'title' => str_replace(array('<div','div>'), array('<span','span>'), $vars['content']['rate_likeme']['#markup']),
        'html' => TRUE,
      );
      unset($vars['content']['rate_likeme']);
    }

  }

  // Show only the username in submitted, the date is handled by node.tpl.php.
  $vars['submitted'] = t('Submitted by !username',
    array('!username' => ctsi_username_link($node))
  );

  if (!array_key_exists('primary_author', $vars)) {
    $vars['primary_author'] = null;
  }

  // do not display Rate widget(s) title
  if (!empty($vars['content']['rate_thumbs_up']['#title'])) {
    $vars['content']['rate_thumbs_up']['#title'] = '';
  }
  if (!empty($vars['content']['rate_likeme']['#title'])) {
    $vars['content']['rate_likeme']['#title'] = '';
  }

  if (empty($vars['teaser'])) {
    // dpm('is not teaser');
  }
  elseif (isset($vars['content']['comments'])) {
    // dpm($vars['content'], 'has comments in content');
  }
  else {
    if ($group = opg_core_node_in_group($node)) {
      $teaser_comments = 0;
      if ($group_entity = opg_core_get_entity($group)) {
        $wrapper = entity_metadata_wrapper($group['group_type'], $group_entity);
        if (isset($wrapper->field_opg_teaser_comments)) {
          $teaser_comments = (int)$wrapper->field_opg_teaser_comments->value();
        }
        else {
          // dpm(compact('node','group','group_entity'), 'no teaser comments field in group entity');
        }
      }
      else {
        dpm(compact('node','group','group_entity'), 'could not get group entity');
      }
      if (isset($_GET['teaser_comments'])) {
        $teaser_comments = $_GET['teaser_comments'];
      }
      if ($teaser_comments) {
        switch ($node->type) {
          // don't show comments for these content types
          case 'opg_admin_post':
            // dpm(compact('node'), 'node type ' . $node->type . ' should not show comments');
            break;

          default:
            // everybody else
            if ($view = views_get_view('opg_comments')) {
              $display_id = 'default';
              if ($view->access($display_id)) {
                $view->items_per_page = $teaser_comments;
                $args = array($node->nid);
                $vars['content']['comments']['#markup'] = $view->preview($display_id, $args);
              }
              else {
                dpm(compact('display_id','view'), 'no access to display');
              }
            }
            else {
              dpm('no such view opg_comments i guess');
            }
            break;
        }
      }
      else {
        // dpm(compact('group','group_entity','teaser_comments'), 'group does not set a number of comments to add to teaser');
      }
    }
    else {
      // dpm(compact('node','group'), 'node is not part of current group');
    }
  }

}

/**
 * Track Rate widget contexts that originally have a mode of RATE_CLOSED
 *  for later use by anonymous users
 *  because it's dumb that way.
 */
function opbamboo_rate_widget_closed($content_type, $content_id, $value=NULL) {
  static $closed = array();
  if ($value !== NULL) {
    $closed[$content_type][$content_id] = $value;
  }
  return isset($closed[$content_type][$content_id]) ? $closed[$content_type][$content_id] : NULL;
}

/**
 * Implements hook_rate_widget_alter().
 */
function opbamboo_rate_widget_alter($widget, &$context) {
  $content_type = isset($context['content_type']) ? $context['content_type'] : NULL;
  $content_id = isset($context['content_id']) ? $context['content_id'] : NULL;
  if ($widget->mode == RATE_CLOSED) {
    // dpm($context, 'this thing is CLOSED');
    opbamboo_rate_widget_closed($content_type, $content_id, TRUE);
  }
  else {
    // dpm($context, 'this thing is not CLOSED');
    opbamboo_rate_widget_closed($content_type, $content_id, FALSE);
  }
}

/**
 * Preprocess variables for Rate module Thumbs Up widget
 */
function opbamboo_preprocess_rate_template_thumbs_up(&$vars) {
  global $user;

  $class = 'rate-thumbs-up-btn-up';
  $text = 'Like';
  if (empty($vars['results']['user_vote'])) {
    $class .= ' vh-not-voted';
  }
  else {
    $class .= ' vh-voted';
    $text = 'Unlike';
  }
  foreach ($vars['links'] as $i => &$link) {
    if ($link['text'] == 'up') {
      $link['text'] = $text;
    }
  }
  $process_anon = false;
  if (empty($user->uid)) {
    if (opbamboo_rate_widget_closed($vars['content_type'], $vars['content_id'])) {
      $vars['mode'] = RATE_CLOSED;
    }
    else {
      $class .= ' vh-vote-anon clicktext-right';
      $process_anon = true;
    }
  }
  switch ($vars['mode']) {
    case RATE_CLOSED:
      // you could change the button here as well
      $vars['info'] = format_plural($vars['results']['count'], '@count Like', '@count Likes');
      $class .= ' vh-vote-closed';
      break;
    case RATE_COMPACT:
    case RATE_COMPACT_DISABLED:
      break;
    default:
      $vars['info'] = format_plural($vars['results']['count'], '@count Like', '@count Likes');
      break;
  }
  $vars['up_button'] = theme('rate_button', array('text' => $vars['links'][0]['text'], 'href' => $vars['links'][0]['href'],  'class' => $class));
  if ($process_anon and $vars['content_type'] == 'node' and $node = node_load($vars['content_id'])) {
    $options = array();
    if ($op_forum = op_common_op_forum_load($node->type)) {
      $options['op_login'] = $op_forum->login;
    }
    else {
      $login_type = op_common_get_login_type($node->type);
      $options['op_login'] = op_common_op_login_load($login_type);
    }
    $login_text = theme('op_login_text', $options);
    $vars['up_button'] .= <<<EOT
<span class="clicktextlong" style="display:none;">
{$login_text} and click again to Like
</span>
EOT;
  }
}

/**
 * Preprocess variables for Rate module likeme widget
 */
function opbamboo_preprocess_rate_widget(&$vars) {
  global $user;

  if ($vars['display_options']['title'] != 'likeme') {
    return;
  }

  $class = 'rate-btn';
  $text = 'Like';
  if (empty($vars['results']['user_vote'])) {
    $class .= ' vh-not-voted user-not-voted';
  }
  else {
    $class .= ' vh-voted user-voted';
    $text = 'Unlike';
  }
  $process_anon = false;
  if (empty($user->uid)) {
    if (opbamboo_rate_widget_closed($vars['content_type'], $vars['content_id'])) {
      $vars['mode'] = RATE_CLOSED;
    }
    else {
      $class .= ' vh-vote-anon clicktext-right';
      $process_anon = true;
    }
  }
  switch ($vars['mode']) {
    case RATE_CLOSED:
      // you could change the button here as well
      // $vars['info'] = format_plural($vars['results']['count'], '@count Like', '@count Likes');
      $text = '';
      $vars['info'] = '<span>' . $vars['results']['count'] . '</span>';
      $class .= ' vh-vote-closed';
      break;
    case RATE_COMPACT:
    case RATE_COMPACT_DISABLED:
      break;
    default:
      // $vars['info'] = format_plural($vars['results']['count'], '@count Like', '@count Likes');
      $vars['info'] = '<span>' . $vars['results']['count'] . '</span>';
      break;
  }
  foreach ($vars['links'] as $link) {
    $link['text'] = $text;
    $button = theme('rate_button', array('text' => $text, 'href' => $link['href'],  'class' => $class));
  }
  if ($vars['content_type'] == 'node' and $node = node_load($vars['content_id'])) {
    $node->votecount = $vars['results']['count'];
  }
  elseif ($vars['content_type'] == 'comment' and $comment = comment_load($vars['content_id'])) {
    $comment->votecount = $vars['results']['count'];
    $node = node_load($comment->nid);
  }
  if ($process_anon and $node) {
    $button = str_replace(array('<span','span>'), array('<a', 'a>'), $button);
    $options = array();
    if ($group = opg_core_node_in_group($node)) {
      $opg = opg_core_load_opg($group);
      $login_type = $opg['login_type'];
      $options['op_login'] = $options['login'] = $opg['login'];
    }
    elseif ($op_forum = op_common_op_forum_load($node->type)) {
      $options['op_login'] = $op_forum->login;
    }
    else {
      $login_type = op_common_get_login_type($node->type);
      $options['op_login'] = op_common_op_login_load($login_type);
    }
    $login_text = theme('op_login_text', $options);
    $button .= <<<EOT
<span class="clicktextlong" style="display:none;">
{$login_text} and click again to Like
</span>
EOT;
  }
  $vars['buttons'] = array($button);
  $vars['button'] = $button;
}

/**
 * Process variables for theme_username().
 */
function opbamboo_process_username(&$vars, $hook) {

  // set the user link path to their UCSF Profiles URL if available
  if (empty($vars['link_path'])) {
    // we need an actual user object, but skip anons
    if (isset($vars['account']->init)) {
      $account = $vars['account'];
    }
    elseif (!empty($vars['account']->uid)) {
      $account = user_load($vars['account']->uid);
    }
    if (isset($account) and $profiles_url = ctsi_field_first_value('user', $account, 'field_ucsf_profiles_url')) {
      $vars['link_path'] = $profiles_url;
    }
  }

}

/**
 * Preprocess variables for theme_link().
 */
function opbamboo_preprocess_link(&$vars) {
  if (!empty($vars['path']) and empty($vars['options']['query']['destination'])) {
    switch ($vars['path']) {
      case 'user':
      case 'user/login':
      case 'user/register':
      case 'user/password':
        if ($destination = ctsi_destination()) {
          // dpm("adding destination {$destination} to path {$vars['path']}");
          $vars['options']['query']['destination'] = $destination;
        }
        break;
    }
  }
}

/**
 * Implements hook_preprocess_date_textfield_element()
 *
 * Change text field size.
 */
function opbamboo_preprocess_date_textfield_element(&$vars) {
  // We can change this to alter all date textfields.
  switch ($vars['element']['#name']) {
    case 'rate_expiration_likeme_begin[date]':
    case 'rate_expiration_likeme_end[date]':
      $vars['element']['#size'] = 20;
      break;
  }
}

/**
 * Theme the Views Data Export XLS feed icon 
 */
function opbamboo_views_data_export_feed_icon__xls($vars) {
  global $theme_path;
  extract($vars, EXTR_SKIP);
  $url_options = array('html' => true);
  if ($query) {
    $url_options['query'] = $query;
  }
  $text = 'Export to Spreadsheet';
  $link = l($text, $url, $url_options);
  return "<br /><span class='button'>{$link}</span>\n";
}

/**
 * Theme the Views Data Export feed link for ART Export CSV displays 
 */
function opbamboo_views_data_export_feed_icon__csv($vars) {
  extract($vars, EXTR_SKIP);
  if (substr($url, -6) == 'artcsv') {
    $url_options = array('html' => true);
    if ($query) {
      $url_options['query'] = $query;
    }
    $text = 'Export for ART';
    $link = l($text, $url, $url_options);
    return "<br /><br /><span class='button art'>{$link}</span>\n";
  }
  return theme_views_data_export_feed_icon($vars);
}

/**
 * Theme form element labels.
 *
 * If element #description (like field help text) is defined,
 *  add it after the label and remove it from the element.
 *  Seems to work.
 *
 * @see theme_form_element_label()
 */
function opbamboo_form_element_label($vars) {
  $output = theme_form_element_label($vars);
  if (!empty($vars['element']['#description'])) {
    $output .= '<div class="description">' . $vars['element']['#description'] . "</div>\n";
    $vars['element']['#description'] = '';
  }
  return $output;
}

/**
 * Theme an Open Proposal forum's login text
 *
 * @see theme_op_login_text()
 */
function opbamboo_op_login_text($vars) {
  $output = 'something is wrong';
  $login_type = 'all';
  if (!empty($vars['login_type'])) {
    $login_type = $vars['login_type'];
  }
  elseif (!empty($vars['op_login_type'])) {
    $login_type = $vars['op_login_type'];
  }
  elseif (!empty($vars['login'])) {
    $login = $vars['login'];
    $login_type = $login->type;
  }
  elseif (!empty($vars['op_login'])) {
    $login = $vars['op_login'];
    $login_type = $login->type;
  }
  elseif (!empty($vars['node'])) {
    $login_type = op_common_get_login_type($node->type);
  }
  elseif (!empty($vars['content_type'])) {
    $login_type = op_common_get_login_type($vars['content_type']);
  }

  $extra_path = empty($vars['extra_path']) ? '' : '/' . $vars['extra_path'];
  $drupal_path = 'goto/login/drupal' . $extra_path;
  $saml_path = 'goto/login/saml' . $extra_path;

  switch ($login_type) {
    case 'drupal':
      $output = l(t('Login'), $drupal_path, $vars);
      break;
    case 'saml':
      $output = l(t('Login with MyAccess'), $saml_path, $vars);
      break;
    case 'all':
      $saml = l(t('UCSF'), $saml_path, $vars);
      $drupal = l(t('non-UCSF'), $drupal_path, $vars);
      $output = t('Login (!saml | !drupal)', array('!saml' => $saml, '!drupal' => $drupal));
      break;
  }
  return $output;
}

/**
 * Theme an Open Proposal forum's text prompting for login to create content
 *
 * @see theme_op_create_text()
 */
function opbamboo_op_create_text($vars) {
  $output = '<h3>';
  if ($vars['login_type'] == 'all') {
    $output .= 'Login (<a href="/goto/login/saml">UCSF</a>&nbsp;|&nbsp;<a href="/goto/login/drupal">non-UCSF</a>)';
  }
  elseif ($vars['login_type'] == "saml") {
    $output .= '<a href="/goto/login/saml">Login with MyAccess</a>';
  }
  else {
    $output .= '<a href="/goto/login/drupal">Login</a>';
  }
  $output .= ' is required to create ';
  if (!empty($vars['nouns'])) {
    $output .= $vars['nouns'];
  }
  else {
    $output .= 'a proposal / idea';
  }
  $output .= '</h3>';
  return $output;
}

/**
 * Preprocess a comment_form template.
 */
function opbamboo_preprocess_comment_form(&$vars, $hook) {
  global $user;

  $node_type = $vars['form']['#node']->type;

  $vars['theme_hook_suggestions'][] = 'comment_form__node_' . $node_type;

  $vars['node_type'] = $node_type;
  $vars['is_anon'] = empty($user->uid);
  $vars['anon_allowed'] = variable_get('ctsi_allow_anonymous_comments_' . $node_type, 0);
  $vars['anon_contact'] = variable_get('comment_anonymous_' . $node_type, COMMENT_ANONYMOUS_MAYNOT_CONTACT);

  if ($group = og_context()) {
    $opg = opg_core_load_opg($group);
    $vars['login_type'] = $opg['login_type'];
    $vars['login'] = $opg['login'];
    $vars['login_text'] = $opg['login']->text;
    $vars['noun'] = $opg['noun'];
    $vars['nouns'] = $opg['nouns'];
  }
  elseif ($op_forum = op_common_op_forum_load($node_type)) {
    $vars['login_type'] = $op_forum->login_type;
    $vars['login'] = $op_forum->login;
    $vars['login_text'] = $op_forum->login->text;
    $vars['noun'] = empty($op_forum->noun) ? 'proposal' : $op_forum->noun;
    $vars['nouns'] = empty($op_forum->nouns) ? 'proposals' : $op_forum->nouns;
  }
  else {
    $vars['login_type'] = op_common_get_login_type($node_type);
    $vars['login'] = op_common_op_login_load($vars['login_type']);
    $vars['login_text'] = op_common_op_login_text($vars);
    $vars['noun'] = 'proposal';
    $vars['nouns'] = 'proposals';
  }
  $login_urls = array();
  if ($vars['login']) {
    foreach ($vars['login']->login_types as $login_type => $login_info) {
      $login_urls[$login_type] = $login_info->url;
    }
  }
  else {
    if ($login_types = op_common_get_ctsi_login_types($login_type)) {
      foreach ($login_types as $k => $v) {
        $login_urls[$k] = $v->url;
      }
    }
    else {
      // dpm($login_type, 'unable to get ctsi login type info for this OP login type');
    }
  }
  $vars['login_urls'] = $login_urls;

  $vars['me'] = __FUNCTION__;
}

/**
 * Implements hook_form_FORM_ID_alter() on the Subscriptions add form
 *
 *  Add Cancel button
 */
function opbamboo_form_subscriptions_add_form_alter(&$form, &$form_state) {
  // dpm(compact('form','form_state'),__FUNCTION__);
  if ($form['stype']['#value'] == 'node') {
    if ($node = node_load($form['sid']['#value'])) {
      drupal_set_title('Follow <em>' . filter_xss($node->title) . '</em>', PASS_THROUGH);
    }
  }
  elseif ($form['stype']['#value'] == 'type') {
    $type = $form['sid']['#value'];
    if ($type_name = node_type_get_name($type)) {
      $op_forum = op_common_op_forum_load($type);
      $nouns = isset($op_forum->nouns) ? $op_forum->nouns : 'proposals';
      drupal_set_title('Follow all <em>' . filter_xss($type_name) . '</em> ' . $nouns, PASS_THROUGH);
    }
  }
  elseif ($form['stype']['#value'] == 'group') {
    $gid = $form['sid']['#value'];
    if ($group = opg_core_gid_to_group($gid) and $opg = opg_core_load_opg($group)) {
      drupal_set_title('Follow all <em>' . filter_xss($opg['label']) . '</em> ' . $opg['nouns'], PASS_THROUGH);
    }
  }
  if (!empty($form['submit']['#value']) and $form['submit']['#value'] == 'Subscribe') {
    $form['submit']['#value'] = 'Follow';
  }
  if (empty($form['actions']['cancel'])) {
    $form['actions']['cancel'] = array(
      '#type' => 'submit',
      '#value' => t('Cancel'),
      '#submit' => array('drupal_goto'),
      '#limit_validation_errors' => array(),
    );
  }
}

/**
 * Implements hook_form_FORM_ID_alter() on the Subscriptions delete form
 */
function opbamboo_form_subscriptions_del_form_alter(&$form, &$form_state) {
  // dpm(compact('form','form_state'),__FUNCTION__);

  if (empty($form['data']['#value'][1])) {
    dpm(compact('form','form_state'), __FUNCTION__ . ' no subscription key? form[data][#value][1] is empty');
  }
  elseif ($form['data']['#value'][1] == 'nid') {
    if ($node = node_load($form['data']['#value'][2])) {
      drupal_set_title('Unfollow <em>' . filter_xss($node->title) . '</em>', PASS_THROUGH);
    }
  }
  elseif ($form['data']['#value'][1] == 'type') {
    $type = $form['data']['#value'][2];
    if ($type_name = node_type_get_name($type)) {
      $op_forum = op_common_op_forum_load($type);
      $nouns = isset($op_forum->nouns) ? $op_forum->nouns : 'proposals';
      drupal_set_title('Unfollow all <em>' . filter_xss($type_name) . '</em> ' . $nouns, PASS_THROUGH);
    }
  }
  elseif ($form['data']['#value'][1] == 'gid') {
    $gid = $form['data']['#value'][2];
    if ($group = opg_core_gid_to_group($gid) and $opg = opg_core_load_opg($group)) {
      drupal_set_title('Unfollow all <em>' . filter_xss($opg['label']) . '</em> ' . $opg['nouns'], PASS_THROUGH);
      $form['description']['#markup'] = 'Are you sure you want to stop following this ' . $opg['lcgroupword'] . '?';
    }
  }
  if ($form['actions']['submit']['#value'] == 'Unsubscribe') {
    $form['actions']['submit']['#value'] = 'Unfollow';
  }
  // make it look buttony - ?
  $form['actions']['cancel']['#attributes']['class'][] = 'btn';
}

/**
 * Implements hook_form_FORM_ID_alter() on the user content type subs form
 *
 * Note: admin users see this form in the admin theme because admin I guess.
 *  Thus, this code won't apply to you, most likely. Don't be fooled.
 */
function opbamboo_form_subscriptions_page_form_alter(&$form, &$form_state) {
  // dpm(compact('form','form_state'), __FUNCTION__);
  if (!empty($form[0]['checkboxes'])) {
    $types = array_keys($form[0]['checkboxes']);
    foreach ($types as $type) {
      if (empty($form[0]['checkboxes'][$type][-1]['#default_value'])) {
        unset($form[0]['labels'][$type]);
        unset($form[0]['author'][$type]);
        unset($form[0]['send_interval'][$type]);
        unset($form[0]['checkboxes'][$type]);
        unset($form[0]['send_comments'][$type]);
        unset($form[0]['send_updates'][$type]);
      }
    }
  }
  if (empty($form[0]['checkboxes'])) {
    unset($form[0]);
    unset($form['header']);
    $form['footer']['#description'] = t('There are no available content types.');
    unset($form['submit']);
  }
}

/**
 * Implements hook_form_FORM_ID_alter() on the user login form
 */
function opbamboo_form_user_login_alter(&$form, &$form_state) {
  // dpm(compact('form','form_state'), __FUNCTION__);

  $register = l('Create one now', 'user/register');
  $form['#prefix'] = <<<EOT
<div id="userlogin-wrapper">
  <p class="notice">UCSF employees: <a href="/goto/login/saml">Login with MyAccess</a></p>
  <p>All others login below. Don't have an account? {$register}</p>
EOT;

  $form['#suffix'] = <<<EOT
  </div>
</div>
EOT;

}

/**
 * Implements theme_fieldset().
 */
function opbamboo_fieldset($vars) {
  if (isset($vars['element']['#attributes']['class'])
    and is_array($vars['element']['#attributes']['class'])
    and in_array('filter-wrapper', $vars['element']['#attributes']['class'])
  ) {
    // collapse all of those enormous text format fieldsets
    $vars['element']['#collapsible'] = true;
    $vars['element']['#collapsed'] = true;
    $vars['element']['#attributes']['class'][] = 'collapsible';
    $vars['element']['#attributes']['class'][] = 'collapsed';
    $vars['element']['#attached']['library'][0][] = 'drupal.collapse';
    if (empty($vars['element']['#title'])) {
      $vars['element']['#title'] = 'Text Formatting';
    }
  }
  return theme_fieldset($vars);
}

/**
 * Implements theme_text_format_wrapper()
 */
function opbamboo_text_format_wrapper($vars) {
  if (isset($vars['element']['#title_display']) and $vars['element']['#title_display'] == 'before') {
    $tag = '</label>';
    if (!empty($vars['element']['#description']) and $pos = strpos($vars['element']['#children'], $tag)) {
      $description = '<div class="description">' . $vars['element']['#description'] . '</div>';
      $pos += strlen($tag);
      $new = substr($vars['element']['#children'], 0, $pos) . $description . substr($vars['element']['#children'], $pos+1);
      // dpm(array('old' => $vars['element']['#children'], 'new' => $new), 'moving textarea help text for ' . $vars['element']['#id']);
      $vars['element']['#children'] = $new;
      $vars['element']['#description'] = '';
    }
  }
  return theme_text_format_wrapper($vars);
}

/*
 * Change profile update messages
 * - adapted from http://drupal.org/node/162697#comment-811684
 */
function opbamboo_status_messages($display=null) {
  global $user;
  global $is_admin;

  $GLOBALS['one-time-login'] = false;
  if (!empty($_SESSION['messages'])) {
    foreach (array_keys($_SESSION['messages']) as $type) {
      $messages = $_SESSION['messages'][$type];
      $change = false;
      foreach (array_keys($messages) as $key) {
        $message = $messages[$key];
        if ($message == 'You have just used your one-time login link. It is no longer necessary to use this link to login. Please change your password.') {
          $messages[$key] = 'You have used your one-time login. <strong>Please create a password (see below)</strong> for subsequent logins. You can easily be reminded of your password or change it electronically.';
          $messages[] = 'Logins are only necessary if you need to request a consultation or other service.';
          $messages[] = "Once you've created your password, you can ".l(t('browse the site'),'').' or go back to the '.l(t('consult request page'),'consult').' to submit a request.';
          $GLOBALS['one-time-login'] = true;
          $change = true;
        }
      }
      if ($change) {
        // renumber status items or it screws up
        $_SESSION['messages'][$type] = array_values($messages);
      }
    }
  }
  return theme_status_messages($display);
}

/**
 * Implements hook_field_widget_WIDGET_TYPE_form_alter().
 *
 *  This is here as an example I guess?
 */
/* uncomment to use
function opbamboo_field_widget_entityreference_autocomplete_tags_form_alter(&$element, &$form_state, $context) {
  // dpm(compact('element','form_state','context'), __FUNCTION__);

  if (empty($element['#description'])) {
    // $element['#description'] = 'you better not pout';
  }
}
*/
