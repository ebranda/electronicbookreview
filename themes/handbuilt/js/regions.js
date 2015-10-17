jQuery(document).ready(function() {
	// Populate the background grid
	createGrid();
	// Set up foreground and background content containers
	var fgRegion = ".region-content-primary-wrapper";
	var bgRegion = ".region-content-sidebar-left";
	jQuery(fgRegion).addClass("foreground");
	jQuery(bgRegion).addClass("background");
	suppressLinks(fgRegion);
	suppressLinks(bgRegion);
	jQuery(fgRegion).click(function() {
		clickRegion(this, bgRegion);
	});
	jQuery(bgRegion).click(function() {
		clickRegion(this, fgRegion);
	});
});

function createGrid() {
	var container = jQuery("#main .grid-background");
	var containerWidth = jQuery(container).width();
	var containerHeight = jQuery(container).height(); // TODO read these from jquery, but take padding into account
	var numberOfCols = Math.floor(containerWidth / 18);
	var numberOfRows = Math.floor(containerHeight / 18);
	var row;
	for (var i=0; i<numberOfRows; i++) {
		if (i == numberOfRows - 1) {
			row = jQuery("<div class='row last'></div>");
		} else {
			row = jQuery("<div class='row'></div>");
		}
		jQuery(row).appendTo(container);
		for (var j=0; j<numberOfCols; j++) {
			if (j == numberOfCols -1) {
				jQuery("<div class='last'></div>").appendTo(row);
			} else {
				jQuery("<div></div>").appendTo(row);
			}
		}
	}
}

function suppressLinks(region) {
	jQuery(region).find('a').click(function (e) {
	    if (jQuery(region).hasClass('background')) {
	        e.preventDefault();
	    } 
	});
}

function clickRegion(clickedRegion, otherRegion) {
	var clicked = jQuery(clickedRegion);
	var other = jQuery(otherRegion);
	var clickedZ = parseInt(clicked.css('z-index'), 10);
	var otherZ = parseInt(other.css('z-index'), 10);
	if (clickedZ < otherZ) {
		var bgOpacity = parseFloat(clicked.css('opacity'), 10);
		clicked.removeClass("background").addClass("foreground");
		clicked.css("z-index", otherZ);
		clicked.css("opacity", 1);
		other.removeClass("foreground").addClass("background");
		other.css("z-index", clickedZ);
		other.css("opacity", bgOpacity);
	}
}