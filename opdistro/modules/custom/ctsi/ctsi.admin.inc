<?php

/**
 * Admin form for finding and merging duplicate accounts.
 */
function ctsi_dupuser_form($form, &$form_state) {
  // dpm(compact('form','form_state'), __FUNCTION__);

  $dups = array();
  if ($result = db_query('select * from {users} left join {realname} using (uid) left join {authmap} using (uid) where mail in (select mail from {users} group by mail having count(*) > 1) order by uid')) {
    foreach ($result as $row) {
      $row->urmail = $row->mail;
      $row->mail = strtolower(trim($row->mail));
      $dups[$row->mail]['users'][$row->uid] = $row;
      $dups[$row->mail]['options'][$row->uid] = "#{$row->uid} {$row->name} '{$row->realname}' {$row->urmail}";
      if ($row->module) {
        $dups[$row->mail]['authmaps'][$row->module][$row->uid] = $row->authname;
      }
    }
  }
  if (empty($dups)) {
    $form['blank'] = array(
      '#markup' => t('<h4>There are no duplicate accounts at this time.</h4>'),
    );
    return $form;
  }
  // dpm($dups, 'dups');
  $default = (count($dups) == 1);
  $i = 1;
  foreach ($dups as $mail => $row) {
    $key = preg_replace('/[^A-z]+/', '_', $mail);
    $form['dup' . $i++]['mail'] = array(
      '#type' => 'radio',
      '#title' => $mail,
      '#return_value' => $key,
      '#default_value' => $default,
    );
    $form[$key] = array(
      '#type' => 'fieldset',
      '#title' => t('Merge accounts for %mail', array('%mail' => $mail)),
      '#tree' => TRUE,
      '#states' => array(
        'visible' => array(
          ':input[name="mail"]' => array('value' => $key),
        ),
      ),
    );
    $form[$key]['email'] = array(
      '#type' => 'value',
      '#value' => $mail,
    );
    $form[$key]['target'] = array(
      '#type' => 'radios',
      '#title' => t('Select the target account'),
      '#description' => t('This is the account that will be preserved - the other account(s) will be merged into this one and then disabled'),
      '#options' => array('' => 'Do not merge') + $row['options'],
    );
    foreach ($row['users'] as $uid => $urow) {
      $form[$key]['uids'][$uid] = array(
        '#type' => 'value',
        '#value' => $uid,
      );
      $form[$key][$uid] = array(
        '#type' => 'container',
        '#states' => array(
          'visible' => array(
            ':input[name="' . $key . '[target]"]' => array('value' => $uid),
          ),
        ),
      );
      $form[$key][$uid]['markup'] = array(
        '#markup' => '<h5>Preserve account #' . $uid . '</h5>',
      );
      if (empty($urow->module) and !empty($row['authmaps']['simplesamlphp_auth'])) {
        $form[$key][$uid]['convert'] = array(
          '#type' => 'radios',
          '#title' => t('Convert account #!uid to a SAML account with one of the following usernames:', array('!uid' => $uid)),
          '#options' => array('' => 'Do not convert') + $row['authmaps']['simplesamlphp_auth'],
          '#default_value' => '',
        );
      }
    }
  }

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );

  return $form;
}

function ctsi_dupuser_form_submit($form, &$form_state) {
  // dpm(compact('form','form_state'), __FUNCTION__);
  // $form_state['rebuild'] = TRUE;

  if (empty($form_state['values']['mail'])) {
    // no merge
    return;
  }
  $dupkey = $form_state['values']['mail'];

  if (empty($form_state['values'][$dupkey]['target'])) {
    // no target selected
    return;
  }
  $target_uid = $form_state['values'][$dupkey]['target'];
  if ($target = user_load($target_uid)) {
    drupal_set_message("Load target user #{$target_uid} name:{$target->name} mail:{$target->mail} realname:{$target->realname}");
  }
  else {
    dpm(compact('form','form_state','dupkey','target_uid','target'), 'error: unable to load target account');
    return;
  }

  if (empty($form_state['values'][$dupkey]['uids'])) {
    dpm(compact('form','form_state','dupkey'), 'error: no uids available for merge');
    return;
  }
  $source_uids = $form_state['values'][$dupkey]['uids'];
  unset($source_uids[$target_uid]);
  if (empty($source_uids)) {
    dpm(compact('form','form_state','dupkey','target_uid','source_uids'), 'error: no uids available for merge');
    return;
  }

  if (empty($form_state['values'][$dupkey][$target_uid]['convert'])) {
    $convert_uid = FALSE;
  }
  else {
    $convert_uid = $form_state['values'][$dupkey][$target_uid]['convert'];
    if (!isset($source_uids[$convert_uid])) {
      dpm(compact('form','form_state','dupkey','target_uid','convert_uid','source_uids'), 'error: invalid convert UID');
      return;
    }
  }

  $keys = array();
  if ($result = db_query("select table_name, column_name from information_schema.columns where table_schema = database() and column_key = 'PRI'")) {
    foreach ($result as $row) {
      $keys[$row->table_name][] = $row->column_name;
    }
  }

  $tables = $columns = array();
  if ($result = db_query("select table_name, column_name from information_schema.columns where table_schema = database() and column_name like :match and column_name != 'guid' and column_name != 'uuid'", array(':match' => '%uid%'))) {
    foreach ($result as $row) {
      switch ($row->table_name) {
        case 'converted_users':
        case 'users':
        case 'uuid_users':
        case 'authmap':
        case 'captcha_sessions':
        case 'sessions':
        case 'realname':
        case 'legal_accepted':
        case 'messaging_store':
        case 'notifications_sent':
        case 'persistent_login':
        case 'persistent_login_history':
          // skip these
          break;

        default:
          $columns[$row->column_name] = $row->column_name;
          if (isset($tables[$row->table_name])) {
            if (is_array($tables[$row->table_name])) {
              $tables[$row->table_name][] = $row->column_name;
            }
            else {
              $tables[$row->table_name] = array($tables[$row->table_name], $row->column_name);
            }
          }
          else {
            $tables[$row->table_name] = $row->column_name;
          }
      }
    }
  }

  // dpm(compact('tables','columns'), 'user related database schema');

  $queries = array();
  $userqueries = array();

  foreach ($source_uids as $source_uid) {
    if ($source = user_load($source_uid)) {
      drupal_set_message('Find content related to source user ' . $source->uid);
    }
    else {
      dpm(compact('form','form_state','dupkey','target_uid','convert_uid','source_uid','source'), 'error: unable to load source UID');
      return;
    }

    foreach ($tables as $table => $fields) {
      $fields = (array)$fields;
      $bind = array();
      $wheres = array();
      foreach ($fields as $field) {
        $key = ':' . $field;
        $wheres[] = $field . '= ' . $key;
        $bind[$key] = $source->uid;
      }
      $sql = 'select * from ' . $table . ' where ' . implode(' or ', $wheres);
      $rows = array();
      if ($result = db_query($sql, $bind)) {
        foreach ($result as $row) {
          $rows[] = (array)$row;
        }
      }
      if ($rows) {
        // dpm($rows, 'Data found in ' . $table . ' for source ' . $source->uid);
        foreach ($rows as $row) {
          $sets = array();
          foreach ($fields as $field) {
            if ($row[$field] == $source->uid) {
              $sets[] = sprintf('%s=%d', $field, $target->uid);
            }
          }
          if ($sets) {
            $w = $tw = array();
            $check_existing = false;
            $do_update = true;
            if (!empty($keys[$table])) {
              foreach ($keys[$table] as $k) {
                $w[] = sprintf("%s='%s'", $k, mysql_escape_string($row[$k]));
                if (in_array($k, $fields) and $row[$k] == $source->uid) {
                  $tw[] = sprintf("%s=%d", $k, $target->uid);
                  $check_existing = true;
                }
                else {
                  $tw[] = sprintf("%s='%s'", $k, mysql_escape_string($row[$k]));
                }
              }
              if ($check_existing) {
                if (db_query('select * from ' . $table . ' where ' . implode(' and ', $tw))->rowCount()) {
                  $do_update = false;
                  // dpm(compact('keys','fields','sets','w','tw'), 'target record in ' . $table . ' already exists');
                }
              }
            }
            else {
              foreach ($row as $k => $v) {
                $w[] = sprintf("%s='%s'", $k, mysql_escape_string($v));
              }
            }
            if ($do_update) {
              $queries[] = 'update ' . $table . ' set ' . implode(', ', $sets) . ' where ' . implode(' and ', $w);
            }
          }
        }
      }
      else {
        // dpm(compact('sql','bind'), 'no rows from ' . $table);
      }
    }

    $userqueries[] = sprintf("update users set status=0, name='moved-to-%d-on-%d', mail=concat('formerly-', mail) where uid=%d", $target->uid, time(), $source->uid);
    if ($convert_uid and $source->uid == $convert_uid) {
      $queries[] = sprintf("update authmap set uid = %d where uid = %d", $target->uid, $source->uid);
      $userqueries[] = sprintf("update users set name='%s' where uid = %d", mysql_escape_string($source->name), $target->uid);
    }
  }

  // dpm(compact('queries','userqueries'), 'Go forth and do these');

  $operations = array();
  foreach ($queries as $query) {
    $operations[] = array('ctsi_dupuser_batch_op', array($query));
  }
  foreach ($userqueries as $query) {
    $operations[] = array('ctsi_dupuser_batch_op', array($query));
  }
  $batch = array(
    'file' => drupal_get_path('module','ctsi') . '/ctsi.admin.inc',
    'operations' => $operations,
    'finished' => 'ctsi_dupuser_batch_finished',
  );
  $_SESSION['http_request_count'] = 0; // reset counter for debug information.
  batch_set($batch);

}

function ctsi_dupuser_batch_op($query, &$context) {
  drupal_set_message($query);
  db_query($query);
  $context['results'][] = $query;
  $_SESSION['http_request_count'] += 1;
}

function ctsi_dupuser_batch_finished($success, $results, $operations) {
  // dpm(compact('success','results','operations'), __FUNCTION__);
  if ($success) {
    $requests = empty($_SESSION['http_request_count']) ? 0 : $_SESSION['http_request_count'];
    drupal_set_message(t('@count results processed in @requests HTTP requests', array('@count' => count($results), '@requests' => $requests)));
  }
  else {
    $error_op = reset($operations);
    dpm($error_op[0], t('Error while processing @operation', array('@operation' => $error_op[0])));
  }
}
