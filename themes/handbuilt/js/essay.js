
// Need to position notes in this handler rather than
// document.load because accurate vertical positioning
// requires that web fonts are already loaded
jQuery(window).load(function() { 
	var essayNode = jQuery('#main .node-essay.full');
	if (essayNode.length > 0) {
		jQuery(essayNode).css("position", "relative"); // To support positioning of children
		processGlosses(essayNode);
		processNotes(essayNode);
	}
});

jQuery(document).ready(function() {
	var essayNode = jQuery('#main .node-essay.full');
	if (essayNode.length > 0) {
		//jQuery("*", jQuery(".field-name-body", essayNode)).removeAttr("style"); // Strip out inline styles
		processFullScreenIcon();
	}
});

function processGlosses(essayNode) {
	jQuery(essayNode).find('.gloss-group').each(function () {
		var group = jQuery(this);
		//var glossCount = group.find('.node-gloss').length;
		var label = 'G';
		jQuery('<div class="gloss-tab markup"><span class="arrow"></span><span class="tab-text">'+label+'</span></div>').insertBefore(this).click(function(event) {
			glosser.glossGroupClicked(group, event);
		});
	});
}

function processNotes(essayNode) {
	var bodyField = jQuery(essayNode).children().find('.field-name-body:eq(0) .field-item');
	var noteWrappers = new Array();
	jQuery(".note").each(function(index) { 
		var note = jQuery(this);
		var noteNumber = index + 1;
		var ref = jQuery('<span class="note-reference">'+noteNumber+'</span>').insertBefore(note);
		note.detach();
		var wrapper = jQuery('<div class="note-wrapper"></div>')
				.appendTo(bodyField)
				.css({
					top : (ref.position().top-2)+"px"
				});
		jQuery('<div class="note-text"></div>').append(note).appendTo(wrapper).before('<div class="note-label">Note '+noteNumber+'.</div>');
		note.css('display', 'block');
		noteWrappers.push(wrapper);
	});
	// Resolve overlapping notes
	var overlapFound = true;
	while (overlapFound) {
		overlapFound = false;
		for (var i=0; i<(noteWrappers.length - 1); i++) {
			var upper = noteWrappers[i];
			var lower = noteWrappers[i+1];
			var upperTop = upper.position().top;
			var upperBottom = upperTop + upper.outerHeight(true);
			var lowerTop = lower.position().top;
			var overlap = upperBottom - lowerTop;
			if (overlap > 0) {
				var lowerTopAdjusted = lowerTop + overlap;
				lower.css('top', lowerTopAdjusted+"px");
				overlapFound = true;
			}
		}
	}
	// Disable glossing of notes
	bodyField.dblclick(function(event) {
		var noteClicked = jQuery(event.target).closest('.note-wrapper').length > 0;
		if (noteClicked) {
			jQuery('#gloss-add').hide();
		}
		event.stopPropagation();
	});
}

function processFullScreenIcon() {
	var enterLink = jQuery('<div id="full-screen-link" class="markup"><a href="#">>-Read in Full Screen Mode-<</a></div>').prependTo('.region-content-sidebar-right');
	var exitLink = jQuery('<div id="full-screen-link-esc" class="markup"><a href="#">>-Close Full Screen Mode-<</a></div>').prependTo('.region-content-sidebar-right');
	exitLink.hide();
	jQuery('body').prepend('<div id="overlay" style="z-index: 9000;"></div>');
	jQuery('#overlay').hide();
	jQuery(document).keyup(function(e) {
	  if (e.keyCode == 27) { // esc
		exitFullScreen();
	  }
	});
	//exitFullScreen();
	jQuery(enterLink).click(function(event) {
		enterFullScreen();
		event.stopPropagation();
		return false;
	});
	jQuery(exitLink).click(function(event) {
		exitFullScreen();
		event.stopPropagation();
		return false;
	});
}

function enterFullScreen() {
	var body = jQuery('body');
	jQuery('.region-content-primary-wrapper').attr('z-index-default', jQuery('.region-content-primary-wrapper').css('z-index'));
	jQuery('.region-content-primary-wrapper').css('z-index', '9001');
	jQuery('.region-content-primary-wrapper').css('position', 'relative');
	jQuery('#full-screen-link').css('z-index', '10000');
	jQuery('#full-screen-link').css('position', 'relative');
	jQuery('#full-screen-link-esc').css('z-index', '10001');
	jQuery('#overlay').fadeIn(500);
	body.addClass('full-screen');
	jQuery('#full-screen-link').fadeOut(500);
	jQuery('#full-screen-link-esc').delay(1500).fadeIn(1500);
	jQuery('.node-essay.full .gloss-tab').fadeOut(500);
}

function exitFullScreen() {
	var body = jQuery('body');
	if (body.hasClass('full-screen')) {
		jQuery('#overlay').fadeOut(1000);
		jQuery('.region-content-primary-wrapper').css('z-index', jQuery('.region-content-primary-wrapper').attr('z-index-default'));
		jQuery('#full-screen-link').css('z-index', 'auto');
		jQuery('.region-content-primary-wrapper').css('position', 'relative');
		jQuery('.region-header-primary').css('z-index', 'auto');
		body.removeClass('full-screen');
		jQuery('#full-screen-link-esc').fadeOut(1000);
		jQuery('#full-screen-link').fadeIn(1000);
		jQuery('.node-essay.full .gloss-tab').fadeIn(1000);
	}
}

