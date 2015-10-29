<?php
// dpm($variables, __FILE__);

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php if ($rows): ?>
  <?php if (!empty($title)): ?>
    <h2><?php print $title; ?></h2>
  <?php endif; ?>
  <ol class="search-results node-results">
    <?php foreach ($rows as $id => $row): ?>
    <?php
      $view = $variables['view'];
      $node = node_load($view->result[$id]->nid);
      // dpm($node, 'da node for ' . $id . ':' . $view->result[$id]->nid);
      $title = l($node->title, 'node/' . $node->nid);
      $url = url('node/' . $node->nid);
      $keys = $view->exposed_raw_input['keys'];
      $snippet = search_excerpt($keys, $row);
      $username = theme('username', array('account' => $node));
      $date = date('n/j/Y - G:i', $node->created);
      $numcomments = format_plural('@count comment', '@count comments', $node->comment_count);
    ?>
<li<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  } ?><?php print $attributes; ?>>
  <?php print render($title_prefix); ?>
  <h3 class="title"<?php print $title_attributes; ?>>
    <a href="<?php print $url; ?>"><?php print $title; ?></a>
  </h3>
  <?php print render($title_suffix); ?>
  <div class="search-snippet-info">
    <p class="search-snippet"<?php print $content_attributes; ?>><?php print $snippet; ?></p>
    <p class="search-info"><?php print $username; ?> - <?php print $date; ?> - <?php $numcomments; ?></p>
  </div>
</li>
    <?php endforeach; ?>
  </ol>
<?php else : ?>
  <h2><?php print t('Your search yielded no results');?></h2>
<?php endif; ?>
