<?php
/**
 * Expose themes as context reactions.
 */
class op_common_context_reaction_iptest extends context_reaction {

  /**
   * Allow admins to provide list of allowed IP addresses.
   */
  function options_form($context) {
    $values = $this->fetch_from_context($context);
    if (!empty($values['subnets'])) {
      $subnets = $values['subnets'];
      $cidrs = ctsi_ip_subnets_to_cidrs($subnets);
    }
    elseif (!empty($values['cidrs'])) {
      $cidrs = $values['cidrs'];
      $subnets = ctsi_cidrs_to_subnets($cidrs);
    }
    else {
      $cidrs = '';
      $subnets = array();
    }
    // dpm(compact('subnets','cidrs','values','context'), __METHOD__);
    $form = array();
    $form['cidrs'] = array(
      '#title' => t('IP addresses'),
      '#description' => t('Define a set of IP subnets to be allowed access when this context is active.'),
      '#type' => 'textarea',
      '#rows' => 10,
      '#cols' => 40,
      '#default_value' => $cidrs,
    );
    $form['redirect'] = array(
      '#type' => 'textfield',
      '#title' => 'Redirect unauthorized users to',
      '#default_value' => $this->redirect($values),
      '#description' => 'if blank, users will get an "Access Denied" error',
    );
    $form['saml'] = array(
      '#type' => 'checkbox',
      '#title' => 'Allow MyAccess accounts to bypass testing',
      '#default_value' => !empty($values['saml']),
    );
    $form['bypass'] = array(
      '#type' => 'checkbox',
      '#title' => 'Honor site-level role-based bypass',
      '#default_value' => !empty($values['bypass']),
    );
    $form['hallpass'] = array(
      '#type' => 'checkbox',
      '#title' => 'Honor site-level temporary pass',
      '#default_value' => !empty($values['hallpass']),
    );
    return $form;
  }

  /**
   * Submit handler for options form.
   */
  function options_form_submit($values) {
    // dpm($values, __METHOD__);
    $cidrs = empty($values['cidrs']) ? '' : $values['cidrs'];
    $values['subnets'] = ctsi_cidrs_to_subnets($cidrs);
    return $values;
  }

  /**
   * If IP addresses are defined, confirm that current user matches them.
   */
  function execute() {

    foreach ($this->get_contexts() as $k => $v) {
      if (empty($v->reactions[$this->plugin])) {
        continue;
      }
      $values = $v->reactions[$this->plugin];
      if (!empty($values['subnets'])) {
        $subnets = $values['subnets'];
      }
      elseif (!empty($values['cidrs'])) {
        $subnets = ctsi_cidrs_to_subnets($values['cidrs']);
      }
      if ($subnets) {
        // dpm(compact('subnets','k','v'), __METHOD__);
        // do the test
        $this->test_ip($subnets, $k, $v, $values);
      }
    }
  }

  /**
   * Validate current user's IP address against list of allowed subnets.
   *
   * @todo Add session storage of test results - needs to be context specific
   */

  function test_ip($subnets, $name, $context, $values) {
    global $user;
    // dpm(compact('subnets', 'name', 'context', 'values'), __METHOD__);

    if (!empty($values['hallpass']) and !empty($_SESSION['ctsi_ip_hallpass'])) {
      // dpm($_SESSION, '_SESSION bypass');
      // temporary admin pass
      return;
    }
    if (!empty($values['saml']) 
      and module_exists('simplesamlphp_auth')
      and isset($user->name)
      and ctsi_simplesaml_account($user->name)
    ) {
      // dpm(compact('user','values'), 'saml bypass');
      // simpleSAML MyAccess free pass
      return;
    }
    if (!empty($values['bypass']) and ctsi_ip_bypass()) {
      // dpm(compact('user','values'), 'site-level bypass');
      return;
    }

    // use site-wide debug setting for now
    $debug = variable_get('ctsi_ip_debug', 0);

    $request_uri = request_uri();
    $ip_address = ip_address();

    if (empty($subnets) or !is_array($subnets)) {
      // this shouldn't happen, but if it does - free pass
      // because otherwise an empty array will cause failure
      // and a not-an-array will cause fatal errors.
      // so log this, it's a problem.
      watchdog('op'
        , 'context reaction subnets: tests is !tests - test was attempted but subnets is empty or not an array: !subnets'
        , array(
          '!subnets' => var_export($subnets, true),
        )
        , WATCHDOG_ERROR
      );
      // move along
      return $this->pass_ip();
    }

    // are you not allowed to see?
    $ip_denied = true;
    if ($debug) {
      $rebug = '';
      $then = REQUEST_TIME;
      $times = array();
      $now = REQUEST_TIME;
      $times['before everything'] = $now - $then;
      $then = $now;
    }
    if ($userip = ip2long($ip_address)) {
      // fix for unsigned ints
      $userip = $userip > 0 ? $userip : ($userip & 0x7FFFFFFF) + 0x80000000;

      if ($debug) {
        $ipuser = long2ip($userip);
        if ($ipuser != $ip_address) {
          watchdog('op'
            , 'context reaction subnets: IP->int problem: !remote => !int => !ip'
            , array(
            '!remote' => $ip_address,
            '!int' => $userip,
            '!ip' => $ipuser,
          )
            , WATCHDOG_ERROR
          );
          // when in doubt, let them through? i guess
          return;
        }
      }

      $top = current($subnets);
      $bot = end($subnets);
      if ($debug) {
        $now = REQUEST_TIME;
        $times['after current end'] = $now - $then;
        $then = $now;
      }
      if ($userip > $top[1]) {
        if ($debug) {
          $maxip = long2ip($top[1]);
          $rebug .= "{$ip_address} > {$maxip} and there's nothing bigger\n";
        }
      }
      elseif ($userip < $bot[0]) {
        if ($debug) {
          $minip = long2ip($bot[0]);
          $rebug .= "{$ip_address} < {$minip} and there's nothing smaller\n";
        }
      }
      else {
        foreach ($subnets as $range) {
          if ($userip >= $range[0] and $userip <= $range[1]) {
            $ip_denied = false;
            break;
          }
          if ($debug) {
            $minip = long2ip($range[0]);
            $maxip = long2ip($range[1]);
            $rebug .= "{$ip_address} outside range {$minip} -> {$maxip}\n";
          }
        }
      }
      if ($debug) {
        $now = REQUEST_TIME;
        $times['after range check'] = $now - $then;
        $then = $now;
      }
    }
    else {
      watchdog('op'
        , 'context reaction subnets: IP->int problem: !remote => !int'
        , array(
        '!remote' => $ip_address,
        '!int' => var_export($userip, true),
      )
        , WATCHDOG_ERROR
      );
      // when in doubt, let them through? i guess
      return;
    }
    if ($ip_denied) {
      if ($debug) {
        $now = REQUEST_TIME;
        $times['after testing'] = $now - $then;
        $then = $now;
      }
      watchdog('op'
        , 'context reaction subnets: Access denied to !uri for !ip (!host) (!int) !name'
        , array(
        '!uri' => $request_uri,
        '!ip' => $ip_address,
        '!host' => gethostbyaddr($ip_address),
        '!int' => $userip,
        '!name' => $name,
      )
        , WATCHDOG_WARNING
      );
      if ($debug) {
        $now = REQUEST_TIME;
        $times['after watchdog'] = $now - $then;
        $then = $now;
        drupal_set_message("could not access <a href='{$request_uri}'>{$request_uri}</a>", 'info');
        drupal_set_message("<pre>{$rebug}\n{$ip_address} not found in subnets, oosp\n</pre>", 'info');
        drupal_set_message("timing: " . print_r($times, true), 'info');
      }

      // you fail
      return $this->fail_ip($this->redirect($values));
    }

    if ($debug) {
      drupal_set_message("<pre>{$rebug}\n{$ip_address} found in subnets, hooray\n</pre>", 'info');
    }
    // you pass
    return $this->pass_ip();
  }

  function fail_ip($redirect = NULL) {

    $options = array();
    if ($redirect) {
      if (!empty($_GET['q']) and !drupal_is_front_page()) {
        $here = drupal_get_path_alias($_GET['q']);
        $query = $_GET;
        unset($query['q']);
        if ($query) {
          $here .= '?' . drupal_http_build_query($query);
        }
        $options['query']['destination'] = $here;
      }
      return drupal_goto($redirect, $options);
    }
    drupal_access_denied();
    exit;
  }

  function pass_ip() {
    return TRUE;
  }

  function redirect($values) {
    static $redirect = NULL;
    if ($redirect === NULL) {
      $redirect = empty($values['redirect']) ? variable_get('ctsi_ip_redirect', '') : $values['redirect'];
    }
    return $redirect;
  }
}
