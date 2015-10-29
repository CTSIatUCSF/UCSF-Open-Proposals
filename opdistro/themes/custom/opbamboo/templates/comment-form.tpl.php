<?php
/**
* @file
* Theme template to display the comment form.
*
* You can write explicit HTML using the login URLs - example:
*   <a href="<?php print $login_urls['drupal']; ?>">Log in</a> to comment on this <?php print $noun; ?>.
* Or you can use the standard login text for the content type - example:
*   <?php print $login_text; ?> to comment on this <?php print $noun; ?>.
*
* Available variables:
* - $form: the form to be displayed
* - $login_urls: the correct URLs for logging in and returning to this comment form
* - $node_type: the internal content type name (eg page, op_generic)
* - $login_type: the type of login(s) allowed for this content type - drupal, saml, or all
* - $login_text: the standard login text for the type of login(s) allowed for this content type
* - $is_anon: the current user is anonymous
* - $anon_allowed: anonymous comments are allowed on this content type
* - $anon_contact: whether anonymous users must, may, or may not supply contact info
* - $noun: the word for a node of this content type
* - $nouns: the word for nodes of this content type
*
* @see opbamboo_preprocess_comment_form()
*/
global $user;

if ($is_anon and $anon_contact == COMMENT_ANONYMOUS_MAYNOT_CONTACT) {
  // uncomment to hide the Name field
  hide($form['author']);
}
?>
<?php if ($is_anon and empty($form['comment_preview'])) : ?>

  <?php if (!$anon_allowed) : ?>

<div id="comment_form">
  <h2>Add Your Comment</h2>

  <?php print $login_text; ?> to comment on this <?php print $noun; ?>.
</div>
  <?php drupal_render_children($form); // render it to clear it away but don't print it. ?>

  <?php else : ?>


    <?php if ($anon_contact == COMMENT_ANONYMOUS_MAY_CONTACT) : ?>

<div id="anoncomment-notice">
<h2>Add Your Comment</h2>
<span class="notice">We want to give you credit!</span><br />
      <?php if ($login_type == 'drupal' or $login_type == 'saml') : ?>
<a href="<?php print $login_urls[$login_type]; ?>">Please login to claim authorship of your comment</a>, or identify yourself below.
      <?php else : ?>
Please login to claim authorship of your comment: <a href="<?php print $login_urls['saml']; ?>">UCSF</a> | <a href="<?php print $login_urls['drupal']; ?>">non-UCSF</a>
<br/>
<strong>OR</strong> identify yourself below, using your institution's website for your homepage.
      <?php endif; ?>
</div>

    <?php endif; ?>
  <?php endif; ?>
<?php endif; ?>
<?php 
// when none of the above has applied
print drupal_render_children($form);
?>
