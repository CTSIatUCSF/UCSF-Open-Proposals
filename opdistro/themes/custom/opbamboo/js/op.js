(function ($) {
  Drupal.behaviors.opGenl = {
    attach: function(context, settings) {

      // Search placeholder text
      function initiateSearchText(){
        $("#search-forum, #edit-search-block-form--2").css('color','#999');
        if (typeof settings.opg != 'undefined' && typeof settings.opg.groupword != 'undefined') {
          $("#search-forum").attr('value','Search this ' + settings.opg.groupword);
        }
        $(".bridges-search-form #search-forum").attr('value','Search Bridges');
        $("#edit-search-block-form--2").attr('value','Search ' + settings.siteName);
    }
    initiateSearchText();

$('#search-forum, #edit-search-block-form--2').each(function() {
    var default_value = this.value;
    $(this).focus(function() {
        if(this.value == default_value) {
            this.value = '';
            $(this).css('color','#000');
        }
    });
    $(this).blur(function() {
        if(this.value == '') {
            $(this).css('color','#989898');
            this.value = default_value;
        }
    });
});

        // Anchor links for about pages
        if ($('.view-display-id-aboutpage h2').length) { 
        $('.view-display-id-aboutpage').prepend('<div class="thispage"><p>On this page</p><ul></ul></div>');
	   $('<p><a class="top" href="#top">Back to top</a></p>').insertBefore('.view-display-id-aboutpage h2:not(:first)');
	   $('.view-display-id-aboutpage h2').each(function(){
	     var thisText = $(this).text();
	     var anchorText = thisText.replace(/ /g, "-");
	     var anchorLink = '<a name="' + anchorText + '"></a>';
	     var anchorText = '<li><a href="#' + anchorText + '">' + thisText + '</a></li>';
	     $(this).before(anchorLink);
	     $(anchorText).appendTo('.thispage ul');
	   });
	}

        // Active menu links
        if ($('#process-image').length) $('#home').addClass('active'); 
        if ($('.faq').length) $('#faq').addClass('active'); 
        if ($('.page-contact').length) $('#contact').addClass('active'); 

        // Link for jumping to comments next to node title
	if ($('.comment-wrapper').length && $('span.count-comments').length) {
	  var countcomments = $('span.count-comments').text(); 
	  if (!$('.jumpcomments').length && countcomments != '0') 
	     $("<a href='#comments' class='jumpcomments'>" + countcomments + " Comments</a>").insertBefore('.page-title');
	}

	// Don't show email link if Primary Author is linked to profile
	$('.terms .profile-tip').siblings('.mailto-link').hide();
 
	// Voting widget alignment
	$('.rate-widget').parent('.form-item').css('margin','0');

	// Voting closed title
	$('.vh-vote-closed').parent('.rate-widget').attr('title','Voting is closed');

        // Give subscription links extra class
        $('.links li[class^="subscriptions_node_nid"]').addClass('subscription-node');

        // highlight avarded proposals (possible this is too general...)
        $(".field-type-taxonomy-term-reference a:contains('Awarded')").css({color:"#990000","font-weight":"bold"});
        $(".field-type-taxonomy-term-reference a:contains('Selected')").css({color:"#990000","font-weight":"bold"});
        $(".field-name-field-opg-status a:contains('Awarded')").css({color:"#990000","font-weight":"bold"});
        $(".field-name-field-opg-status a:contains('Selected')").css({color:"#990000","font-weight":"bold"});
        $(".field-name-field-opg-status a:contains('Winner')").css({color:"#990000","font-weight":"bold"});

        // Remove empty paragraphs 
        $('p').each(function() {
          if($(this).html().replace(/\s|&nbsp;/g, '').length == 0) {
            $(this).remove();
          }
        });

        // Prevent duplicate submissions
        if ($('#inprogress').length == 0) {
          $('<p id="inprogress" class="notice">Save in progress...</span></p>').insertAfter('#edit-actions').hide();
        }
	$('.node-form #edit-submit').click(function(){
	   $('#edit-actions').hide();
	   $('#inprogress').show();
	});
	$('.comment-form #edit-submit').click(function(){
	   $('#edit-actions').hide();
	   $('#inprogress').show();
	});

    }
  };

})(jQuery);

