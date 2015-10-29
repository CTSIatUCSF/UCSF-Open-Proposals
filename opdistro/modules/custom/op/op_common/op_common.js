
(function ($) {

/**
 * Assign AJAX results to a set of fields for a person,
 *  typically "Primary Author" (thus, pa)
 */
Drupal.op_common_pa_lookup = function(that, autoval, fields) {
  // console.log('lookup that:'); console.log(that);
  // console.log('lookup autoval:'); console.log(autoval);
  // console.log('lookup fields:'); console.log(fields);
  if (autoval) {
    var vf = autoval.split('|');
    if (vf.length >= 5) {
      fields.first.val(vf[0]);
      fields.last.val(vf[1]);
      fields.email.val(vf[2]);
      fields.org.val(vf[3]);
      fields.url.val('');
      var personid = vf[4];
      var profileurl = vf[4];
      if (!isNaN(personid) && personid > 0) {
        var url = '';
        url = 'http://profiles.ucsf.edu/CustomAPI/v1/JSONProfile.aspx?source=open-proposals.ucsf.edu&Person=' + personid;
        url = Drupal.settings.basePath + 'op/ajax/get_ucsfprofile/' + personid;
        $.get(url, null, function(data) {
          if (data.profiles_url > '') {
            fields.url.val(data.profiles_url);
          }
        }, 'json');
      }
    }
    else {
      // console.log('too few parts ' + vf.length);
      // console.log(vf);
    }
  }
  else {
    // console.log('no autoval:'); console.log(autoval);
  }
  that.input.value = '';
}

/**
 * customize autocomplete functions on a given field
 *  see http://www.scaled-solutions.com/blog/taking-control-drupal-autocomplete-fields
 */
Drupal.op_common_pa_autocomplete = function (lsid, fields) {
  // console.log('lookup lsid:'); console.log(lsid);
  // console.log('lookup fields:'); console.log(fields);
  var url = $('#' + lsid + '-autocomplete').val();
  // console.log('lookup url:'); console.log(url);
  var acdb = new Drupal.ACDB(url);
  var $input = $('#' + lsid)
    .attr('autocomplete', 'OFF')
    .attr('aria-autocomplete', 'list');
  $($input[0]).unbind();
  $($input[0].form).submit(Drupal.autocompleteSubmit);
  $input.parent()
    .attr('role', 'application')
    .append($('<span class="element-invisible" aria-live="assertive"></span>')
      .attr('id', $input.attr('id') + '-autocomplete-aria-live')
    );
  var cow = new Drupal.jsAC($input, acdb);
  cow.prototype = Drupal.jsAC.prototype;
  cow.prototype.urSelect = Drupal.jsAC.prototype.select;
  cow.prototype.select = function (node) {
    if (this.input.id == lsid) {
      // console.log('cow.select called because of this.input.id:'); console.log(this.input.id);

      // from the original:
      // this.input.value = $(node).data('autocompleteValue');
      Drupal.op_common_pa_lookup(this, $(node).data('autocompleteValue'), fields);

      // from the original:
      //  seems OK to do
      $(this.input).trigger('autocompleteSelect', [node]);
    }
    else {
      this.urSelect(node);
    }
  };
  cow.prototype.urHidePopup = Drupal.jsAC.prototype.hidePopup;
  cow.prototype.hidePopup = function (keycode) {
    if (this.input.id == lsid) {
      // Select item if the right key or mousebutton was pressed
      if (this.selected && ((keycode && keycode != 46 && keycode != 8 && keycode != 27) || !keycode)) {
        this.select(this.selected);
      }
      // Hide popup
      var popup = this.popup;
      if (popup) {
        this.popup = null;
        $(popup).fadeOut('fast', function() { $(popup).remove(); });
      }
      this.selected = false;
    }
    else {
      this.urHidePopup(keycode);
    }
  };
};

})(jQuery);
