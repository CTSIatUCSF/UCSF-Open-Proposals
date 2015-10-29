# UCSF-Open-Proposals
Drupal 7 installation profile for Organic Groups based proposal forums

Basic installation steps
------------------------
To create a Drupal installation in a directory named "docroot",
parallel to the "opdistro" directory:

drush make opdistro/opdistro.make docroot 
rsync -r opdistro/ docroot/profiles/opdistro/

Then go to the installation in docroot/ in your browser and install Drupal as normal.
