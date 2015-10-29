(function ($) {
  Drupal.behaviors.opMisc = {
    attach: function(context, settings) {

      // External links in new tab
      if (typeof settings.base_host != 'undefined') {
        $('a[href^="http"]:not([href*="' + settings.base_host + '"])').attr('target','_blank');
      }

      // Active menu links
      if ($('#proposalCount').length) $('#home').addClass('active');
      if ($('.thispage').length) $('#about').addClass('active');
      if ($('.thispage').length) $('h1.page-title').hide();

      // Responsive tabs
      $("#oppsTab").easyResponsiveTabs({
        type: 'vertical', //Types: default, vertical, accordion
        width: 'auto', //auto or any custom width
        fit: true,   // 100% fits in a container
      });

    }
  };

})(jQuery);

