; opdistro make file for local development
core = "7.x"
api = "2"

projects[drupal][version] = "7.x"
; include the d.o. profile base
includes[] = "drupal-org.make"
includes[] = "patches.make"

; +++++ Libraries +++++

; Profiler
libraries[profiler][directory_name] = "profiler"
libraries[profiler][type] = "library"
libraries[profiler][destination] = "../../profiles/opdistro/libraries"
libraries[profiler][download][type] = "get"
libraries[profiler][download][url] = "http://ftp.drupal.org/files/projects/profiler-7.x-2.x-dev.tar.gz"

; grammar_parser
libraries[grammar_parser][directory_name] = "grammar_parser"
libraries[grammar_parser][type] = "library"
libraries[grammar_parser][destination] = "libraries"
libraries[grammar_parser][download][type] = "get"
libraries[grammar_parser][download][url] = "http://ftp.drupal.org/files/projects/grammar_parser-7.x-1.2.tar.gz"

; tinymce_3.5b1
libraries[tinymce_3.5b1][directory_name] = "tinymce"
libraries[tinymce_3.5b1][type] = "library"
libraries[tinymce_3.5b1][destination] = "libraries"
libraries[tinymce_3.5b1][download][type] = "get"
libraries[tinymce_3.5b1][download][url] = "https://github.com/downloads/tinymce/tinymce/tinymce_3.5b1.zip"

; spyc
libraries[spyc][directory_name] = "spyc"
libraries[spyc][type] = "library"
libraries[spyc][destination] = "libraries"
libraries[spyc][download][type] = "get"
libraries[spyc][download][url] = "https://github.com/mustangostang/spyc/archive/0.5.1.tar.gz"

