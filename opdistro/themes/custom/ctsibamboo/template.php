<?php

/**
 * Implements hook_preprocess().
 *
 * Keep this around so we can check out various hook variables
 *  without having to redefine theme registry entries.
 */
function ctsibamboo_preprocess(&$vars, $hook) {
  static $hooks = array();
  if (empty($hooks[$hook])) {
    // dpm($hook);
    $hooks[$hook] = $hook;
  }
}

/**
 * Implements hook_preprocess_page().
 */
function ctsibamboo_preprocess_page(&$vars) {

  // This js code needs to be processed before Beauty Tips js 
  //  JS_LIBRARY > JS_MODULE > JS_THEME
  //  that plus the weight seems to do it
  drupal_add_js(drupal_get_path('theme','ctsibamboo') . '/js/profiletip.js', array('type' => 'file', 'scope' => 'header', 'group' => JS_LIBRARY, 'weight' => -20));

}

/**
 * Implements hook_preprocess_node().
 */
function ctsibamboo_preprocess_node(&$vars) {
  global $user;

  $node = $vars['node'];

  if (!empty($vars['content']['links'])) {
    foreach ($vars['content']['links'] as $group => &$links) {
      switch ($group) {

        case 'comment':
          if ($node->comment != COMMENT_NODE_HIDDEN) {
            if (empty($links['#links']['comment-add']) 
              and $node->comment == COMMENT_NODE_OPEN 
              and user_access('post comments')
              and ($user->uid or variable_get('ctsi_allow_anonymous_comments_' . $node->type, 0))
            ) {
              $links['#links']['comment-add'] = array(
                'title' => t('Add new comment'),
                'href' => "comment/reply/$node->nid",
                'attributes' => array('title' => t('Add a new comment to this page.')),
                'fragment' => 'comment-form',
              );
            }
            if (empty($links['#links']['comment-comments'])) {
              $links['#links']['comment-comments'] = array(
                'title' => (empty($node->comment_count) ? 'No comments yet' : format_plural($node->comment_count, '1 comment', '@count comments')),
                'href' => "node/$node->nid",
                'attributes' => array('title' => t('Jump to the first comment of this posting.')),
                'fragment' => 'comments',
                'html' => TRUE,
              );
            }
          }
          break;
      }
    }
  }

  // Show only the username in submitted, the date is handled by node.tpl.php.
  $vars['submitted'] = t('Submitted by !username',
    array('!username' => ctsi_username_link($node))
  );

}

/**
 * Process variables for theme_username().
 */
function ctsibamboo_process_username(&$vars, $hook) {

  // set the user link path to their UCSF Profiles URL if available
  if (empty($vars['link_path'])) {
    // we need an actual user object
    if (isset($vars['account']->init)) {
      $account = $vars['account'];
    }
    elseif (isset($vars['account']->uid)) {
      $account = user_load($vars['account']->uid);
    }
    else {
      $account = NULL;
    }
    if (isset($account->uid) and $profiles_url = ctsi_field_first_value('user', $account, 'field_ucsf_profiles_url')) {
      $vars['link_path'] = $profiles_url;
    }
  }

}

/**
 * Preprocess variables for theme_link().
 */
function ctsibamboo_preprocess_link(&$vars) {
  if (!empty($vars['path']) and empty($vars['options']['query']['destination'])) {
    switch ($vars['path']) {
      case 'user':
      case 'user/login':
      case 'user/register':
      case 'user/password':
        if ($destination = ctsi_destination()) {
          $vars['options']['query']['destination'] = $destination;
        }
        break;
    }
  }
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
function ctsibamboo_form_element_label($vars) {
  $output = theme_form_element_label($vars);
  if (!empty($vars['element']['#description'])) {
    $output .= '<div class="description">' . $vars['element']['#description'] . "</div>\n";
    $vars['element']['#description'] = '';
  }
  return $output;
}

/**
 * Implements hook_form_FORM_ID_alter() on the user login form
 */
function ctsibamboo_form_user_login_alter(&$form, &$form_state) {
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

/*
 * Change profile update messages
 * - adapted from http://drupal.org/node/162697#comment-811684
 */
function ctsibamboo_status_messages($display=null) {
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

