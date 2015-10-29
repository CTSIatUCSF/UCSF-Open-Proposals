/**
 * Using the Drupal Javascript API gets this run in the same scope as BeautyTips. 
 */
(function ($) {
  Drupal.behaviors.ProfileTips = {
    attach: function(context, settings) {
      $("a[href*='profiles.ucsf.edu/']").addClass("profile-tip").attr("title","<span class='ucsfprofiles'>UCSF Profiles</span>");
    }
  };
})(jQuery);
