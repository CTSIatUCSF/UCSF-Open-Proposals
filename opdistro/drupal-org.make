; opdistro make file for d.o. usage
core = "7.x"
api = "2"

; +++++ Modules +++++

projects[admin_menu][subdir] = "contrib"

projects[admin_theme][version] = "1.0"
projects[admin_theme][subdir] = "contrib"

projects[admin_views][subdir] = "contrib"

projects[adminrole][subdir] = "contrib"

projects[advanced_help][subdir] = "contrib"

projects[backup_migrate][version] = "3.1"
projects[backup_migrate][subdir] = "contrib"

projects[beautytips][version] = "2.x-dev"
projects[beautytips][subdir] = "contrib"

projects[better_exposed_filters][subdir] = "contrib"

projects[better_formats][version] = "1.0-beta1"
projects[better_formats][subdir] = "contrib"

projects[boxes][version] = "1.2"
projects[boxes][subdir] = "contrib"

projects[bundle_copy][version] = "2.x-dev"
projects[bundle_copy][subdir] = "contrib"

projects[conditional_fields][subdir] = "contrib"

projects[content_access][subdir] = "contrib"

projects[content_taxonomy][version] = "1.x-dev"
projects[content_taxonomy][subdir] = "contrib"

projects[context][version] = "3.6"
projects[context][subdir] = "contrib"

projects[context_disable_context][version] = "3.x-dev"
projects[context_disable_context][subdir] = "contrib"

projects[context_og][version] = "2.1"
projects[context_og][subdir] = "contrib"

projects[context_respect][subdir] = "contrib"

projects[ctools][subdir] = "contrib"

projects[date][version] = "2.9"
projects[date][subdir] = "contrib"

projects[devel][version] = "1.5"
projects[devel][subdir] = "contrib"

projects[diff][subdir] = "contrib"

projects[entity][subdir] = "contrib"

projects[entity_autocomplete][subdir] = "contrib"

projects[entity_view_mode][subdir] = "contrib"

projects[entityreference][version] = "1.1"
projects[entityreference][subdir] = "contrib"

projects[entityreference_prepopulate][version] = "1.x-dev"
projects[entityreference_prepopulate][subdir] = "contrib"

projects[environment][version] = "1.0"
projects[environment][subdir] = "contrib"

projects[features][subdir] = "contrib"

projects[features_extra][subdir] = "contrib"

projects[features_override][version] = "2.0-rc2"
projects[features_override][subdir] = "contrib"

projects[field_collection][version] = "1.0-beta10"
projects[field_collection][subdir] = "contrib"

projects[field_group][subdir] = "contrib"

projects[field_permissions][subdir] = "contrib"

projects[field_tools][subdir] = "contrib"

projects[filter_perms][subdir] = "contrib"

projects[globalredirect][subdir] = "contrib"

projects[google_analytics][subdir] = "contrib"

projects[honeypot][subdir] = "contrib"

projects[identicon][subdir] = "contrib"

projects[imce][subdir] = "contrib"

projects[imce_wysiwyg][subdir] = "contrib"

projects[job_scheduler][subdir] = "contrib"

projects[jquery_plugin][subdir] = "contrib"

projects[jquery_update][subdir] = "contrib"

projects[kissinsights][subdir] = "contrib"

projects[libraries][subdir] = "contrib"

projects[logging_alerts][version] = "2.x-dev"
projects[logging_alerts][subdir] = "contrib"

projects[logintoboggan][version] = "1.5"
projects[logintoboggan][subdir] = "contrib"

projects[mail_edit][subdir] = "contrib"

projects[mail_edit_features][version] = "1.x-dev"
projects[mail_edit_features][subdir] = "contrib"

projects[mail_logger][version] = "1.1"
projects[mail_logger][subdir] = "contrib"

projects[markup][subdir] = "contrib"

projects[mimedetect][subdir] = "contrib"

projects[module_filter][subdir] = "contrib"

projects[mollom][subdir] = "contrib"

projects[node_export][version] = "3.0"
projects[node_export][subdir] = "contrib"

projects[object_log][subdir] = "contrib"

projects[og][version] = "2.7"
projects[og][subdir] = "contrib"

projects[og_vocab][version] = "1.2"
projects[og_vocab][subdir] = "contrib"

projects[pathauto][subdir] = "contrib"

projects[pathologic][subdir] = "contrib"

projects[persistent_login][subdir] = "contrib"

projects[profiler_builder][subdir] = "contrib"

projects[rate][version] = "1.7"
projects[rate][subdir] = "contrib"

projects[realname][subdir] = "contrib"

projects[redirect][subdir] = "contrib"

projects[reroute_email][version] = "1.2"
projects[reroute_email][subdir] = "contrib"

projects[rules][version] = "2.9"
projects[rules][subdir] = "contrib"

projects[safeword][subdir] = "contrib"

projects[securelogin][subdir] = "contrib"

projects[stage_file_proxy][subdir] = "contrib"

projects[stringoverrides][subdir] = "contrib"

projects[strongarm][subdir] = "contrib"

projects[subscriptions][version] = "1.1"
projects[subscriptions][subdir] = "contrib"

projects[tagadelic][version] = "2.x-dev"
projects[tagadelic][subdir] = "contrib"

projects[token][subdir] = "contrib"

projects[token_filter][version] = "1.x-dev"
projects[token_filter][subdir] = "contrib"

projects[transliteration][subdir] = "contrib"

projects[uuid][subdir] = "contrib"

projects[views][version] = "3.11"
projects[views][subdir] = "contrib"

projects[views_bulk_operations][version] = "3.3"
projects[views_bulk_operations][subdir] = "contrib"

projects[views_data_export][subdir] = "contrib"

projects[votingapi][subdir] = "contrib"

projects[wysiwyg][version] = "2.x-dev"
projects[wysiwyg][subdir] = "contrib"

; +++++ Themes +++++

; bamboo
projects[bamboo][type] = "theme"
projects[bamboo][subdir] = "contrib"

; +++++ Libraries +++++

; Profiler
libraries[profiler][directory_name] = "profiler"
libraries[profiler][type] = "library"
libraries[profiler][destination] = "libraries"
libraries[profiler][download][type] = "get"
libraries[profiler][download][url] = "http://ftp.drupal.org/files/projects/profiler-7.x-2.x-dev.tar.gz"

