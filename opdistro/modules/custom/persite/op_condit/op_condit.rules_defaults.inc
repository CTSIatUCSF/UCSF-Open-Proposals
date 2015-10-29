<?php
/**
 * @file
 * op_condit.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function op_condit_default_rules_configuration() {
  $items = array();
  $items['opg_new_adminpost_notification'] = entity_import('rules_config', '{ "opg_new_adminpost_notification" : {
      "LABEL" : "OPG new AdminPost notification",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "opg" ],
      "REQUIRES" : [ "rules", "og" ],
      "ON" : { "node_insert" : [], "node_update" : [] },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "opg_admin_post" : "opg_admin_post" } }
          }
        },
        { "data_is" : { "data" : [ "node:field-opg-ap-send" ], "value" : 1 } },
        { "og_entity_is_group_content" : { "entity" : [ "node" ] } }
      ],
      "DO" : [
        { "og_get_members" : {
            "USING" : { "group_content" : [ "node" ] },
            "PROVIDE" : { "group_members" : { "group_members" : "List of group members" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "group-members" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : [
              { "mail" : {
                  "to" : [ "list-item:mail" ],
                  "subject" : "[node:title] from [node:og-group-ref]",
                  "message" : "[list-item:name],\\r\\nThe latest announcement from [node:og-group-ref] [site:current-opg:lcgroupword] on [site:name].\\r\\n\\r\\n-------------------------\\r\\n\\r\\n[node:body]\\r\\n\\r\\nView online: [site:og-context--node:url]\\r\\n\\r\\n[node:author] and [node:og-group-ref] team\\r\\n\\r\\nP.S. You are receiving this email as a participant of [node:og-group-ref] Open Proposals [site:current-opg:lcgroupword]. Contact us at [site:mail] if you would like to discontinue announcement emails.\\r\\n",
                  "from" : "\\u0022[site:og-context--node:title]\\u0022 \\u003C[site:mail]\\u003E",
                  "language" : [ "" ]
                }
              }
            ]
          }
        }
      ]
    }
  }');
  return $items;
}
