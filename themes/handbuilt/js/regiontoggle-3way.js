jQuery(document).ready(function() {
	var elements = [".region-content-primary", ".region-content-secondary", ".region-content-tertiary"];
	jQuery(".region-content-primary").click(function() {
		clickContentElement(".region-content-primary", elements);
	});
	jQuery(".region-content-secondary").click(function() {
		clickContentElement(".region-content-secondary", elements);
	});
	jQuery(".region-content-tertiary").click(function() {
		clickContentElement(".region-content-tertiary", elements);
	});
});

function clickContentElement(clickedObj, allObjs) {
	reorderZ(clickedObj, allObjs);
}

function reorderZ(clickedObj, allObjs) {
	var objs = new Array();
	var topObj = null;
	for (var i=0; i<allObjs.length; i++) {
		var obj = jQuery(allObjs[i]);
		obj.z = parseInt(obj.css('z-index'), 10);
		obj.identifier = allObjs[i];
		obj.clicked = clickedObj == obj.identifier;
		objs.push(obj);
		if (topObj == null) {
			topObj = obj;
		} else {
			topObj = topObj.z < obj.z ? obj : topObj;
		}
	}
	if (!topObj.clicked) {
		// Sort by current z value to preserve order of non-clicked elements
		objs = objs.sort(function(a,b){return b.z - a.z});
		// Move the clicked object to the front of the array
		var clicked = null;
		for (var i=0; i<objs.length; i++) {
		  if (objs[i].identifier == clickedObj) {
		    clicked = objs[i];
		    objs.splice(i, 1); 
		    break;
		  }
		}
		objs.unshift(clicked);
		// Now set the new zvalues 
		var zMax = topObj.z;
		for (var i=0; i<objs.length; i++) {
			objs[i].css("z-index", zMax--);
		}
	}
}