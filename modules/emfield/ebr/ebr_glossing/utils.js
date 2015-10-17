// Currently not used

function interlace(array1, array2) {
	var joined = '';
	for (var i=0; i<array1.length; i++) {
		joined += array1[i];
		if (i < array2.length) {
			joined += array2[i];
		}
	}
	return joined;
}

function chunk(text, isHtml, indexes) {
	var segments = new Array();
	var rangeStart = 0;
	for (var i=0; i<indexes.length; i++) {
		var rangeEnd = indexes[i];
		var range = text.substring(rangeStart, rangeEnd);
		if (isHtml) {
			var lastTagCloseIdx = range.lastIndexOf(">");
			var lastTagOpenIdx = range.lastIndexOf("<");
			// Make sure we are not inside a tag
			if (lastTagCloseIdx < lastTagOpenIdx) {
				// We are inside an HTML tag so adjust the range
				var offset = range.length - lastTagOpenIdx;
				rangeEnd -= offset;
				range = text.substring(0, lastTagOpenIdx);
			}
		}
		segments.push(range);
		rangeStart = rangeEnd;
	}
	segments.push(text.substring(rangeStart));
	return segments;
}

function containsHtmlElements(element) {
	return jQuery(element).children().length > 0;
}