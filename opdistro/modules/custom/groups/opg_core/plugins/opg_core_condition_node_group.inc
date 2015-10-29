<?php

/**
 * Expose node views/node forms of group node types as a context condition.
 */
class opg_core_condition_node_group extends context_condition {
  function condition_values() {
    $values = array(
      '_any_'=>'Any group type',
      '_none_'=>'Not a group type'
    );
    foreach (node_type_get_types() as $type) {
      if (og_is_group_type('node', $type->type)) {
        $values[$type->type] = $type->name;
      }
    }
    return $values;
  }

  function options_form($context) {
    $defaults = $this->fetch_from_context($context, 'options');
    return array(
      'node_form' => array(
        '#title' => t('Set on node form'),
        '#type' => 'select',
        '#options' => array(
           CONTEXT_NODE_VIEW => t('No'),
           CONTEXT_NODE_FORM => t('Yes'),
           CONTEXT_NODE_FORM_ONLY => t('Only on node form')
        ),
        '#description' => t('Set this context on node forms'),
        '#default_value' => isset($defaults['node_form']) ? $defaults['node_form'] : TRUE,
      ),
    );
  }

  function execute($node, $op) {
    $type = (isset($node->type) and og_is_group_type('node', $node->type)) ? $node->type : '_none_';
    $contexts = $this->get_contexts($type);
    $this->values[$type] = array();
    foreach ($contexts as $context) {
      $this->_check_node_form($op, $context, $type);
    }

    // check if we are in _any_ group as well
    if ($type != '_none_') {
      $allcontexts = $this->get_contexts('_any_');
      $this->values['_any_'] = array();
      foreach($allcontexts as $acontext) {
        $this->_check_node_form($op, $acontext, '_any_');
      }
    }
  }

  function _check_node_form($op, $context, $type) {
    $options = $this->fetch_from_context($context, 'options');
    if ($op === 'form') {
      if (!empty($options['node_form']) && in_array($options['node_form'], array(CONTEXT_NODE_FORM, CONTEXT_NODE_FORM_ONLY))) {
        $this->condition_met($context, $type);
      }
    }
    elseif (empty($options['node_form']) || $options['node_form'] != CONTEXT_NODE_FORM_ONLY) {
      $this->condition_met($context, $type);
    }
  }
}
