<?php 

// dpm(basename(__FILE__));
// dpm($variables);

// uncomment these two lines to just display the default form
// drupal_render_children($form);
// return;

drupal_set_title("Congratulations, you have logged in successfully to MyAccess.");

?>

<p><strong>To complete the process of enabling your UCSF MyAccess account 
for CTSI access, please provide the following information.</strong>
<em>This is a one-time step which will enable you to login 
to CTSI with your MyAccess username and password.</em>
</p>

<p>
Enter your email address to set up a new account with CTSI, and automatically link it to your MyAccess account:
</p> 

<!-- begin email field -->
<?php print drupal_render_children($form['email']); ?>
<!-- end email field -->

<!-- begin submit button -->
<?php print drupal_render_children($form['submit']); ?>
<!-- end submit button -->

<!-- begin remainder of form -->
<?php print drupal_render_children($form); ?>
<!-- end remainder of form -->

