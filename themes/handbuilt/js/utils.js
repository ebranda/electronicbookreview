function getElementPath(element) {
	var pathElements = [];
	pathElements.push(element);
 	jQuery(element).parents().not('html').each(function() {
		pathElements.push(this);
	});
	pathElements.reverse();
	var pathElementNames = [];
	for (var i=0; i<pathElements.length; ++i) {
		var entry = pathElements[i].tagName.toLowerCase();
        if (pathElements[i].className) {
            entry += "." + pathElements[i].className.replace(/ /g, '.');
        }
        pathElementNames.push(entry);
	}
	return pathElementNames.join(" ");
}


function truncate_text(text, maxChars) {
	if (text.length < maxChars) return text;
	var truncated = '';
	var idx = maxChars;
	if (text.charAt(idx) != ' ') {
		var substr = text.substring(0, idx);
		truncated = substr.substring(0, substr.lastIndexOf(' '));
	} else {
		truncated = text.substring(0, idx);
	}
	return truncated + '&hellip;';
}