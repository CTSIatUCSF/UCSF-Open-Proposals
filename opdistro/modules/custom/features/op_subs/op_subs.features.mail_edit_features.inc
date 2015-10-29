<?php
/**
 * @file
 * op_subs.features.mail_edit_features.inc
 */

/**
 * Implements hook_default_mail_edit_features().
 */
function op_subs_default_mail_edit_features() {
  $mail_edit_features = array();

  // Exported mail edit: subscriptions_mail_.DEFAULT--en
  $mail_edit_features['subscriptions_mail_.DEFAULT--en'] = array(
    'id' => 'subscriptions_mail_.DEFAULT',
    'language' => 'en',
    'description' => 'Default Subscriptions template',
    'subject' => '{{[subs:is-new]==0?New activity:New proposal}} on [node:content-type] on [site:name]',
    'body' => '{{MAIL@Greetings, [current-user:name].

---------------------------------------------------
}}{{[subs:is-new]==0?:New }}{{[subs:is-updated]#Updated }}{{[subs:is-old]#New comments on a }}proposal by [node:author:name], titled "[node:title]", on [node:content-type] 

View&nbsp;proposal:&nbsp;[node:url]
{{![subs:is-old]#{{!![subs:files:field_files:count]#| Attached files:
{{[subs:files:field_files:count]#| [subs:files:field_files:index:#0:url]
}}}}}}{{![subs:comments:count]?---------------------------------------------------
:
---------------------------------------------------
[subs:comments:join:
]
}}
{{MAIL@
You received this notification because you have chosen to follow updates or contributed to the [node:content-type] forum on [site:name]. To manage your notifications, go to [subs:manage-url]

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

Join&nbsp;the&nbsp;conversation:&nbsp;[comment:url]
{{!![subs:files:field_files:count]#| Attached files:
{{[subs:files:field_files:count]#| [subs:files:field_files:index:#0:url]
}}}}---------------------------------------------------',
    'module' => 'subscriptions_mail',
    'mailkey' => '.DEFAULT',
    'registry_description' => 'Default Subscriptions template',
  );

  return $mail_edit_features;
}
