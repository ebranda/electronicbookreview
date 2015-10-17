jQuery(document).ready(function() {
	var searchForm = jQuery("#block-search-form");
	var field = jQuery("#block-search-form .form-text");
	field.attr("placeholder", "search");
	var threadLinksContainer = jQuery(".region-header-secondary .view-thread-links .view-content");
	var formContainer = jQuery("<div class='search-form thread'></div>").appendTo(threadLinksContainer);
	jQuery("<div class='search-form-arrow search-form-arrow-left'></div>").appendTo(formContainer);
	jQuery(searchForm).appendTo(formContainer);
	jQuery("<div class='search-form-arrow search-form-arrow-right'></div>").appendTo(formContainer);
	// For IE
    field.focus(function () {
        if ($(this).val() == $(this).attr('placeholder')) {
            $(this).val('');
        }
    }).blur(function () {
        if ($(this).val() == '') {
            $(this).val($(this).attr('placeholder'));
       }
    });
});