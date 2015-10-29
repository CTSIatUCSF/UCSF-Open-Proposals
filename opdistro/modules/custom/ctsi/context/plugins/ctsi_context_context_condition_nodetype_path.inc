<?php

/**
 * Copied from Context module path and node conditions
 *  Check path for relation to node of a given type
 *  Specifically, check Subscriptions module paths
 */
class ctsi_context_context_condition_nodetype_path extends context_condition {

  function condition_values() {
    $values = array();
    foreach (node_type_get_types() as $type) {
      $values[$type->type] = check_plain($type->name);
    }
    return $values;
  }


  /**
   * Execute.
   */
  function execute() {
    if ($this->condition_used()) {
      $node_type = null;
      $current_path = $_GET['q'];
      $m = array();
      if (preg_match('#(^|/)(subscriptions|subscribe)/(add|del)/type/([^/]+)#', $current_path, $m)) {
        $node_type = $m[4];
      }
      elseif (preg_match('#(^|/)(subscriptions|subscribe)/(add|del)/(group|node)/([^/]+)#', $current_path, $m)) {
        if ($node = node_load($m[5])) {
          $node_type = $node->type;
        }
      }
      if ($node_type) {
        foreach ($this->get_contexts($node_type) as $context) {
          $this->condition_met($context, $node_type);
        }
      }
    }
  }
}
