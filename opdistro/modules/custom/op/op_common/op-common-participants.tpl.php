
<h2><?php echo $typename; ?> Participant Lists</h2>

<?php foreach ($participants as $ptype => $row) : ?>
<div>
<h3><?php echo $row['title']; ?></h3>
  <?php if (empty($row['names'])) : ?>
<p>(none)</p>
  <?php else : ?>
<textarea rows="10" cols="50"><?php
    $comma = '';
    foreach ($row['names'] as $name) {
      if (!empty($name->mail)) {
        if (empty($name->realname)) {
          echo $comma, $name->mail;
        }
        else {
          echo $comma, $name->realname, ' &lt;', $name->mail, '&gt;';
        }
        $comma = ', ';
      }
    }
?></textarea>
  <?php endif; ?>
</div>
<?php endforeach; ?>

