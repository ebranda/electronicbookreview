<?php

/*********************************
HTML preprocessing
**********************************/

function handbuilt_preprocess_html(&$variables, $hook) {
	if (_ebr_is_node_page('essay')) {
		$essay = menu_get_object();
		$variables['classes_array'][] = 'thread-'.$essay->thread_name;
	} else if (_ebr_is_node_page('thread')) {
		$thread = menu_get_object();
		$variables['classes_array'][] = 'thread-'._ebr_get_field_value($thread, 'field_name');
	}
}



/*********************************
Page preprocessing
**********************************/

/**
 * Override or insert variables into the page templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("page" in this case.)
 */
function handbuilt_preprocess_page(&$variables, $hook) {
		
	// Reset
	unset($variables['title_prefix']);
	unset($variables['title_suffix']);
	
	// Flag for main content only without secondary content
	if (empty($variables['page']['content-secondary'])) {
	 	$variables['classes_array'][] = 'no-secondary-content';
	}
	if (drupal_is_front_page()) {
		$variables['title'] = 'Recent essays';
	}
	else if (arg(0) == 'search') {
		$variables['title_suffix'] = arg(2);
	}
	else if (arg(0) == 'taxonomy' && arg(1) == 'term') {
		$variables['title_prefix'] = 'Tag';
	}
  // Move tabs into main content region
  // Not needed because we are using Blockify module
  // if (!empty($variables['tabs'])) {
  //     array_unshift($variables['page']['content-primary'], $variables['tabs']);
  //     unset($variables['tabs']);
  //   }
}


/*********************************
Region preprocessing
**********************************/

function handbuilt_preprocess(&$variables, $hook) {
  if ($hook == 'region') {
    // For some reason, template_preprocess_region is not being called, 
    // so do it manually, for each specific region.
    $function = __FUNCTION__ . '_region_' . str_replace("-", "_", $variables['region']);
    if (function_exists($function)) {
      $function($variables);
    }
  }
}

function handbuilt_preprocess_region_content_primary(&$variables) {
  if (_ebr_is_node_page('thread')) {
    $thread = menu_get_object();
    $variables['classes_array'][] = 'thread';
    $variables['classes_array'][] = 'thread-'._ebr_get_field_value($thread, 'field_name');
  }
}

function handbuilt_preprocess_region_content_sidebar_left(&$variables) {
	$top_border = '';
	for ($i = 0; $i < 27; $i++) {
	    $top_border .= '<span class="t t-r"></span><span class="t t-l"></span>';
	}
  	$variables['content'] = $top_border . $variables['content'];
	if (_ebr_is_node_page('essay')) {
		$essay = menu_get_object();
		$variables['classes_array'][] = 'thread-'.$essay->thread_name;
	}
}



/*********************************
Node preprocessing
**********************************/

function handbuilt_preprocess_node(&$variables, $hook) {
	
  // Remove 'read more' link
  if ($variables['teaser']) {
    if (isset($variables['content']['links']['node']['#links']['node-readmore'])) {
      unset($variables['content']['links']['node']['#links']['node-readmore']);
    }
  }
	
  // Hide Submitted subtitle in all cases
  $variables['display_submitted'] = FALSE;
  
  // Add "full" to classes of node element
  if ($variables['view_mode'] == 'full') {
	$variables['classes_array'][] = 'full';
  }
  $node = $variables['node'];
	
	// Hide titles for specific node types (use page title instead)
	if ($variables['view_mode'] == 'full') {
		switch ($node->type) {
			case 'thread':
			case 'author':
				$variables['title'] = '';	
		}
	}
	
  if ($node->type == 'essay') {
    $variables['classes_array'][] = 'thread-'.$node->thread_name;
	if ($variables['view_mode'] == 'full') {
		// Add the summary before the main essay content
		$variables['content']['summary'] = array(
			'#weight' => $variables['content']['body']['#weight'],
			'#markup' => '<div class="summary markup">'.render($node->body[$node->language][0]['safe_summary']).'</div>',
		);
		$variables['content']['body']['#weight'] = strval(intval($variables['content']['body']['#weight']) + 1);
		// Hide the tags field from main essay content display 
		// since we are displaying it in the right sidebar
		hide($variables['content']['field_tags']);
	}
  } 
  else
  if ($node->type == 'thread' && $variables['view_mode'] == 'full') {
		// Thread body is being shown in left sidebar via blocks so remove it from this display
		hide($variables['content']['body']);
	}
	else
	if ($variables['node']->type == 'page' && drupal_is_front_page()) {
		// Don't show any page content on the home page
		$variables['content']['body']['#access'] = FALSE;
	}
}
	

/*********************************
Field preprocessing
**********************************/

function handbuilt_preprocess_field(&$variables) {
	// Thread body field
	// if (!empty($node->type) && $node->type == 'thread' && $variables['element']['#field_name'] == 'body') {
	// 	$thread_name = _ebr_get_field_value($variables['element']['#object'], 'field_name');
	// 	$variables['classes_array'][] = "thread-".$thread_name;
	// 	$variables['classes_array'][] = "thread-background";
	// }
}

// Note: essay author field prefixing is handled using a tpl.php override


/*********************************
Misc preprocessing
**********************************/

function handbuilt_preprocess_block(&$variables) {
	// Strip out the "&nbsp;" entity that the Social Share module adds between links
	if($variables['block']->module == 'social_share') {
		$variables['content'] = str_replace('&nbsp;', '', $variables['content']);
	}
}
