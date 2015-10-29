<?php
// dpm($variables, basename(__FILE__));

/**
 * @file
 * Default theme implementation for rendering book outlines within a block.
 *
 * This template is used only when the block is configured to "show block on all
 * pages", which presents multiple independent books on all pages.
 *
 * Available variables:
 * - $book_menus: Array of book outlines keyed to the parent book ID. Call
 *   render() on each to print it as an unordered list.
 *
 * @see template_preprocess_book_all_books_block()
 *
 * @ingroup themeable
 */

?>
<div>
<?php foreach ($vocabularies as $vid => $vocabulary) : ?>
  <h2><?php 
    $title = strpos($vocabulary->english, 'Browse by') === FALSE ? 'Browse by ' . $vocabulary->english : $vocabulary->english;
    print $title; 
  ?></h2>
  <ul class="<?php print (empty($vocabulary->tags) ? 'icon' : 'inline'); ?>">
  <?php foreach ($vocabulary->terms as $term) : ?>
    <li class="pointer"><?php
      $uri = entity_uri('taxonomy_term', $term);
      print l($term->name, $uri['path']);
    ?></li>
  <?php endforeach; ?>
  </ul>
<?php endforeach; ?>
</div>
