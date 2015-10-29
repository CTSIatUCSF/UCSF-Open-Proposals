<?php
// dpm($variables, basename(__FILE__));

/**
 * @file
 * Default theme implementation for field collection items.
 *
 * Available variables:
 * - $content: An array of comment items. Use render($content) to print them all, or
 *   print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $title: The (sanitized) field collection item label.
 * - $url: Direct url of the current entity if specified.
 * - $page: Flag for the full page state.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. By default the following classes are available, where
 *   the parts enclosed by {} are replaced by the appropriate values:
 *   - entity-field-collection-item
 *   - field-collection-item-{field_name}
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_entity()
 * @see template_process()
 */
$active = empty($field_opg_phase_active[0]['value']) ? '' : 'active-phase';
$html = render($content['field_opg_phase_html']);
// rendered values are all wrapped up in divs
$name = empty($content['field_opg_phase_name'][0]['#markup']) ? '' : $content['field_opg_phase_name'][0]['#markup'];
$end = empty($content['field_opg_phase_end'][0]['#markup']) ? '' : $content['field_opg_phase_end'][0]['#markup'];
if ($end) {
  $end .= ': ';
}
?>
<div class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <div class="content"<?php print $content_attributes; ?>>
    <?php if ($html): ?>
    <li class="vhtoggle plus <?php print $active; ?>"><?php print $name; ?>
      <div class="reveal"><?php print $html; ?></div>
    </li>
    <?php else: ?>
    <li class="dot <?php print $active; ?>"><?php print $name; ?></li>
    <?php endif; ?>
  </div>
</div>
