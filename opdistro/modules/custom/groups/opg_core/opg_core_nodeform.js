
(function ($) {
  Drupal.behaviors.opg_core_nodeform = {
    attach: function(context, settings) {
      // console.log('opg_core_nodeform.js settings:'); console.log(settings);

      // jQuery code can go here

      // example function call
      // $('div').each(function() { borderMe($(this)); });

      if (typeof Drupal.jsAC !== 'undefined') {
        // console.log('opg_core_nodeform Drupal.jsAC is not undefined?');
        // console.log(Drupal.jsAC);
        var pafields = {};
        pafields.first = $('#edit-field-opg-primary-author-und-0-field-opg-pa-first-und-0-value');
        pafields.last = $('#edit-field-opg-primary-author-und-0-field-opg-pa-last-und-0-value');
        pafields.email = $('#edit-field-opg-primary-author-und-0-field-opg-pa-email-und-0-value');
        pafields.org = $('#edit-field-opg-primary-author-und-0-field-opg-pa-org-und-0-value');
        pafields.url = $('#edit-field-opg-primary-author-und-0-field-opg-pa-url-und-0-value');
        Drupal.op_common_pa_autocomplete('edit-field-opg-primary-author-und-0-field-opg-lookup-pa-und-0-value', pafields);
      }
      else {
        // console.log('opg_core_nodeform Drupal.jsAC is undefined?');
        // console.log(Drupal.jsAC);
      }

    }
  };
})(jQuery);

