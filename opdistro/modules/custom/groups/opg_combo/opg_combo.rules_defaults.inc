<?php
/**
 * @file
 * opg_combo.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function opg_combo_default_rules_configuration() {
  $items = array();
  $items['rules_opg_membership_propagation'] = entity_import('rules_config', '{ "rules_opg_membership_propagation" : {
      "LABEL" : "OPG Membership Propagation",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "og" ],
      "ON" : { "og_user_insert" : [] },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "og-membership:group" ], "field" : "og_group_ref" } }
      ],
      "DO" : [
        { "LOOP" : {
            "USING" : { "list" : [ "og-membership:group:og-group-ref" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : [
              { "og_subcribe_user" : { "user" : [ "account" ], "group" : [ "list-item" ] } }
            ]
          }
        }
      ]
    }
  }');
  return $items;
}
