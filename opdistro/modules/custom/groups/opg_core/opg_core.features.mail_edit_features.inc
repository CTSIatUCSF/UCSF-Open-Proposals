<?php
/**
 * @file
 * opg_core.features.mail_edit_features.inc
 */

/**
 * Implements hook_default_mail_edit_features().
 */
function opg_core_default_mail_edit_features() {
  $mail_edit_features = array();

  // Exported mail edit: subscriptions_mail_node-type-opg_admin_post--en
  $mail_edit_features['subscriptions_mail_node-type-opg_admin_post--en'] = array(
    'id' => 'subscriptions_mail_node-type-opg_admin_post',
    'language' => 'en',
    'description' => 'OG Announcement Subscriptions template',
    'subject' => '{{[subs:is-new]==0?New activity:New proposal}} on [node:title] on [site:name]',
    'body' => '{{MAIL@Greetings, [current-user:name].

---------------------------------------------------
}}{{[subs:is-new]==0?:New }}{{[subs:is-updated]#Updated }}{{[subs:is-old]#New comments on an }}announcement by [node:author:name], titled "[node:title]"

View&nbsp;announcement:&nbsp;[node:url]
{{![subs:is-old]#{{!![subs:files:field_files:count]#| Attached files:
{{[subs:files:field_files:count]#| [subs:files:field_files:index:#0:url]
}}}}}}{{![subs:comments:count]?---------------------------------------------------
:
---------------------------------------------------
[subs:comments:join:
]
}}
{{MAIL@
You received this notification because you have chosen to follow updates or contributed to a forum on [site:name]. To manage your notifications, go to [subs:manage-url]

To stop following this content, go to:
[subs:unsubscribe-url]

[site:name]
[site:url]
Contact us at [site:mail]
}}
',
    'subscriptions_comment_body' => '{{[subs:is-published]?:UNPUBLISHED }}[comment:author:name] commented:
&nbsp;
[comment:body]

Join&nbsp;the&nbsp;discussion:&nbsp;[comment:url]
{{!![subs:files:field_files:count]#| Attached files:
{{[subs:files:field_files:count]#| [subs:files:field_files:index:#0:url]
}}}}---------------------------------------------------',
    'module' => 'subscriptions_mail',
    'mailkey' => 'node-type-opg_admin_post',
    'registry_description' => 'Notifications for <em class="placeholder">OPG Admin Post</em> content type subscriptions',
  );

  return $mail_edit_features;
}
