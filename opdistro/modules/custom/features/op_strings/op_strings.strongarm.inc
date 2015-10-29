<?php
/**
 * @file
 * op_strings.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function op_strings_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'locale_custom_disabled_strings_en';
  $strongarm->value = array();
  $export['locale_custom_disabled_strings_en'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'locale_custom_strings_en';
  $strongarm->value = array(
    '' => array(
      'A CTSI account already exists with the email address %mail. In order to preserve your existing CTSI account and link it to your MyAccess account, please choose the \'Yes\' option below, and complete the subsequent step.' => 'An account already exists with the email address %mail. Please <a href="mailto:Open.Proposal@ucsf.edu?Subject=Open%20Proposals%20Existing%20Account">contact us</a> for assistance.',
      'CAPTCHA session reuse attack detected.' => 'Sorry, there was an error processing the Security Check question. Please answer the question again.',
      'CAPTCHA validation error: unknown CAPTCHA session ID. Contact the site administrator if this problem persists.' => 'CAPTCHA validation error: unknown CAPTCHA session ID. Contact the site administrator if this problem persists.',
      'Create your @profile_node.' => 'Provide @profile_node about yourself.',
      'Error saving user account. E-mail address is already used.' => 'An account already exists with the specified email address. Please <a href="mailto:Open.Proposal@ucsf.edu?Subject=Open%20Proposals%20Existing%20Account">contact us</a> for assistance.',
      'Log in' => 'Login',
      'Pages/Threads' => 'Proposals/Threads',
      'Posts of type @type' => '@type posts',
      'Send subscriptions notifications ' => 'Send email notifications to followers',
      'Subscribe to: !name' => 'Subscribe to !name',
      'The answer you entered for the CAPTCHA was not correct.' => 'The answer you entered for the Security Check question was not correct.',
      'The trimmed version of your post shows what your post looks like when promoted to the main page or when exported for syndication.<span class="no-js"> You can insert the delimiter "&lt;!--break--&gt;" (without the quotes) to fine-tune where your post gets split.</span>' => 'The trimmed version of your post shows what it looks like on the main page of the forum. You can customize the trimmed text by editing the Project Description summary.',
      'This post' => 'this post',
      'Unsubscribe from: !name' => 'Unsubscribe from !name',
    ),
  );
  $export['locale_custom_strings_en'] = $strongarm;

  return $export;
}
