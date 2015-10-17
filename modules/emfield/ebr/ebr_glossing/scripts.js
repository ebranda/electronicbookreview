// Don't use document ready with dynamically-loaded fonts like Google fonts. 
// Vertical positioning will be calculated before font is loaded. Instead,
// use window load.
//jQuery(document).ready(function() { 
jQuery(window).load(function(){  
	var bodyField = jQuery('.node.glossable > .content > .field-name-body > .field-items > .field-item');
	window.glosser = new Glosser(); 
	glosser.init(bodyField);
});


function Glosser() {
	if (typeof Drupal.settings.ebr_glossing.glossLeft == 'undefined') {
		this.glossLeft = -1;
	} else {
		this.glossLeft = Drupal.settings.ebr_glossing.glossLeft;
	} 
	this.glossZIndex = Drupal.settings.ebr_glossing.zIndex;
	this.nid = Drupal.settings.ebr_glossing.nid;
	this.showGlossNid = Drupal.settings.ebr_glossing.showGlossNid;
	this.userCanAddGlosses = Drupal.settings.ebr_glossing.canAddGlosses;
	this.glossingOn = Drupal.settings.ebr_glossing.startState;
	this.showGlossOnStartup = this.showGlossNid > 0;
};

Glosser.prototype.init = function(bodyField) {
	// Build the existing gloss groups display
	this.buildGlossGroups(bodyField);
	// Enable glossing tools
	if (this.userCanAddGlosses) {
		this.enableGlossCreation(bodyField);
	}
	this.showControls();
	if (this.glossingOn) {
		this.turnOnGlossing();
	}
	// Handle optional display of gloss at startup
	if (this.showGlossOnStartup) {
		if (!this.glossingOn) this.turnOnGlossing();
		var groupElement = jQuery("#node-"+this.showGlossNid).parents('.gloss-group');
		this.expandGlossGroup(groupElement); 
		this.scrollTo(groupElement, 1000);
	}
	// Add global event handling
	jQuery('body').click(function(event) {
		glosser.collapseAll();
	});
};

Glosser.prototype.getFirstBlockLevelParent = function(element, rootElement) {
	var parent = element;
	while (parent.css("display") !== "block") {
		parent = parent.parent();
		if (this.elementsEqual(parent, rootElement)) {
			break; // Don't go any higher in the tree than the root element
		}
	}
	return parent;
}

Glosser.prototype.getGlossPositionLeft = function(p) {
	if (this.glossLeft == -1) {
		return p.outerWidth(true);
	} else {
		return this.glossLeft;
	}
}
	
// Format and position the glosses relative to the markers
Glosser.prototype.buildGlossGroups = function(bodyField) {
	
	// Wrap each gloss in a new gloss-group element and 
	// position each group relative to the path target
	bodyField.css("position", "relative"); // Allow absolute positioning of child elements
	jQuery(".gloss-path-group").each(function() {
		var glossPathGroup = jQuery(this).detach();
		var path = jQuery(".path", glossPathGroup).text();
		var target = bodyField.find('> '+path);
		var p = (typeof target[0] == 'undefined' || target[0].tagName === 'P') ? target : target.parents('p')[0];
		var group = jQuery('<div class="gloss-group"></div>').prependTo(p);
		// We need to embed the gloss group into the paragraph so that if the theme layer
		// modifies the dom the positions of the glosses will remain tied to the paragraphs.
		/*
		var top = target.position().top + bodyField.position().top;
		var targetTopMargin = target.css('marginTop').replace('px', '');
		if (!isNaN(targetTopMargin)) {
			top += parseInt(targetTopMargin);
		}
		top += 5; // Fine-tuning
		//top += target.outerHeight() - 5; // Position the gloss at the target bottom
				*/
		var left = glosser.getGlossPositionLeft(p);
		group.css({
			'left' : left+'px', 
		   	'z-index' : this.glossZIndex
		});
		glosser.collapseGlossGroup(group);
		glossPathGroup.appendTo(group).show();
	});
	
	// Now check for gloss-group overlaps and merge glosses into groups if needed
	var previousGlossGroup;
	jQuery(".gloss-group").each(function(index) {
		var group = jQuery(this);
		if (overlapsVertical(previousGlossGroup, group)) {
			jQuery(".node-gloss", group).appendTo(previousGlossGroup);
			group.remove();
		} else {
			previousGlossGroup = group;
		}
	});
	
	// Finally, bind events to handle clicks and rollovers
	jQuery('.gloss-group').each(function() {
		var group = jQuery(this);
		group.mouseover(function() {
			group.addClass("hover");
		});
		group.mouseout(function() {
			group.removeClass("hover");
		});
		group.click(function(event) {
			glosser.glossGroupClicked(jQuery(this), event);
		});
	});
};

Glosser.prototype.glossGroupClicked = function(group, event) {
	if (group.hasClass("collapsed")) {
		this.collapseAllGlossGroups();
		this.expandGlossGroup(group);
	} else {
		this.collapseGlossGroup(group);
	}
	event.stopPropagation();
}

Glosser.prototype.elementsEqual = function(e1, e2) {
	if (e1.length != e2.length) return false;
	for (var i = 0; i < e1.length; ++i) {
		if (e1[i] !== e2[i]) {
			return false;
		}
	}
	return true;
};


/**
 * Sets up behaviors for creating glosses. Selecting a text range
 * will display a "create gloss" link, which in turn displays 
 * an ajax form overlay.
 */
Glosser.prototype.enableGlossCreation = function(bodyField) {
	// Set up the add link that will be displayed when a text is selected
	jQuery('#gloss-add').hide().css("z-index", this.glossZIndex+1).appendTo(bodyField);
	// Set up the double-click handler
	bodyField.dblclick(function(event) {
		var glossAdd = jQuery('#gloss-add');
		glosser.collapseAllGlossGroups();
		if (jQuery(event.target).closest('.gloss-tab').length > 0) {
			glossAdd.hide();
			return;
		}
		var clickedP = glosser.getRootParentParagraph(jQuery(event.target));
		var path = glosser.buildPathToElement(clickedP, '.field-item');
		if (path.length > 0) {
			jQuery.ajax({ url: "../../glosses/set-path/"+glosser.nid+"/"+path }); // Store the selection path in the user session
			//var top = event.pageY - jQuery('#gloss-add').outerHeight();
			var top = event.pageY - bodyField.offset().top - jQuery('#gloss-add').height() + 10;
			//var left = (event.pageX+20);
			var left = glosser.getGlossPositionLeft(clickedP) + 10;
			glossAdd.css({
				"top" : top+"px",
				"left" : left+"px"
			}).show();
			jQuery('a', glossAdd).click(function() {
				glossAdd.hide();
			});
			event.stopPropagation();
		}
	});
	jQuery('body').click(function() {
		jQuery('#gloss-add').hide();
	});
};

Glosser.prototype.scrollTo = function(targetElement, speed) {
	var topPadding = 50;
	jQuery('html, body').animate({
		scrollTop: jQuery(targetElement).offset().top - topPadding
	}, speed);
}

Glosser.prototype.getGlossNid = function(glossElement) {
	return glossElement.attr("id").substring("node-".length);
};

Glosser.prototype.getGlossPath = function(glossElement) {
	return jQuery(glossElement.find('.gloss-path')[0]).text();
};

Glosser.prototype.getRootParentParagraph = function(startElement) {
	return jQuery(startElement).closest('.field-item > p');
}

Glosser.prototype.buildPathToElement = function(element, root) {
	var path = new Array();
	path.push(element);
	jQuery(element).parents(root).each(function() {
		path.push(jQuery(this));
	});
	path.reverse();
	path.shift();
	var pathStrings = new Array();
	for (var i=0; i<path.length; i++) {
		pathStrings.push(path[i][0].tagName+":nth-child("+(path[i].index()+1)+")");
	}
	return pathStrings.join(' > ');
}

// Add the show/hide glosses controls
Glosser.prototype.showControls = function() {
	jQuery('<div class="gloss-controls"><a href="#"></a></div>').appendTo(this.glossableFieldElement);
	jQuery('.gloss-controls a').click(function() {
		toggleGlossing(); // TODO
		return false;
	});
};

Glosser.prototype.turnOnGlossing = function() {
	jQuery(".gloss-group").fadeIn(500);
	jQuery('.gloss-controls a').text("Turn off glossing");
	this.glossingOn = true;
};

Glosser.prototype.turnOffGlossing = function() {
	jQuery(".gloss-group").fadeOut(500);
	jQuery('.gloss-controls a').text("Turn on glossing");
	this.glossingOn = false;
};

Glosser.prototype.toggleGlossing = function() {
	if (this.glossingOn) {
		turnOffGlossing();
	} else {
		turnOnGlossing();
	}
};

Glosser.prototype.collapseGlossGroup = function(groupElement) {
	groupElement.addClass("collapsed");
	groupElement.css('z-index', this.glossZIndex);
};

Glosser.prototype.expandGlossGroup = function(groupElement) {
	groupElement.removeClass("collapsed");
	//groupElement.animate({width:"200px", height:"auto"}, 250);
	groupElement.css('z-index', this.glossZIndex + 5000);
}

Glosser.prototype.collapseAllGlossGroups = function() {
	jQuery(".gloss-group").addClass("collapsed");
	jQuery(".gloss-group").css('z-index', this.glossZIndex);
	//jQuery('#gloss-add').fadeOut(500);
};

Glosser.prototype.collapseAll = function() {
	this.collapseAllGlossGroups();
}



// UTILITIES //

function overlapsVertical(element1, element2) {
	if (typeof element1 == 'undefined' || typeof element2 == 'undefined') return false;
	if (element1 == null || element2 == null) return false;
	var t1 = element1.position().top;
	var h1 = element1.height();
	var b1 = t1 + h1;
	var t2 = element2.position().top;
	var h2 = element2.height();
	var b2 = t2 + h2;
	return (b1 >= t2 && b2 >= t1);
}
