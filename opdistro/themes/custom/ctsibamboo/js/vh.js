(function ($) {
  Drupal.behaviors.VHMisc = {
    attach: function(context, settings) {
        // Accordion for list items containing hidden content
        $('li.vhtoggle', context).click(function () {
                 $(this).toggleClass('plus dash');
                 $(this).children('.reveal').slideToggle( "slow", function() {
                 });
        });
        $('li.vhtoggle .reveal').click(function(e) { e.stopPropagation(); });

        // Accordion for legacy clicktip markup
	$('.clicktip_target').each(function() {
                if(!$(this).hasClass('less')) $(this).addClass('more')
        });
        $(".less").parent().siblings('.clicktip').show();
        $(".clicktip_target").click(function () {
                $target = $(this);
                $target.toggleClass('more less');
                $content = $target.parent().siblings('.clicktip');
                $content.slideToggle(500, function () {
                });
        });
	// This one works on hover
	function delayHover (element) {
		timer = setTimeout ( function () {
                	$(element).addClass("hoveron");
		}, 300);
	};
        $(".hoverinfo").hover(
                function() {
			delayHover($(this));
                }, function() {
		  clearTimeout(timer);
		  $(this).removeClass("hoveron");
                  $(this).find('.clicktip').fadeOut();
                }
        );

	// Class for email links
	$('a[href^="mailto:"]').addClass('mailto-link');
 
	// Equal height function called from AU & Mosaic
      equalheight = function(container){
        var currentTallest = 0,
          currentRowStart = 0,
          rowDivs = new Array(),
          $el,
          topPosition = 0;

        $(container).each(function() {
          $el = $(this);
          $($el).height('auto')
          topPosition = $el.position().top;
          if (currentRowStart != topPosition) {
            for (currentDiv = 0 ; currentDiv < rowDivs.length ; currentDiv++) {
              rowDivs[currentDiv].height(currentTallest);
            }
            rowDivs.length = 0; // empty the array
            currentRowStart = topPosition;
            currentTallest = $el.height();
            rowDivs.push($el);
          } else {
            rowDivs.push($el);
            currentTallest = (currentTallest < $el.height()) ? ($el.height()) : (currentTallest);
          }
          for (currentDiv = 0 ; currentDiv < rowDivs.length ; currentDiv++) {
            rowDivs[currentDiv].height(currentTallest);
          }
        });
      }

    }
  };

})(jQuery);

