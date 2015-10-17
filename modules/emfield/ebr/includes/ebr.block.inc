<?php 

/**
 * Implements hook_block_info().
 */
function ebr_block_info() {
	$blocks['meta_primary'] = array(
		'info' => t('EBR meta primary'), 
	);
	$blocks['meta_secondary'] = array(
		'info' => t('EBR meta secondary'), 
	);
	$blocks['content_after'] = array(
		'info' => t('EBR content after'), 
	);
	return $blocks;
}

/**
 * Implements hook_block_view().
 */
function ebr_block_view($delta = '') {	
  $block = array();
  $page_node = menu_get_object();
  switch ($delta) {
	
	// The primary supporting meta content for the current page
	case 'meta_primary':
		if (drupal_is_front_page()) {
			$block['content'] = ebr_internal_content_get_markup('site-summary');
		} 
		else 
		if (!empty($page_node)) {
			switch ($page_node->type) {
				case 'essay':
					$thread_nid = _ebr_get_field_value($page_node, 'field_thread');
					$thread_node = node_load($thread_nid);
					$thread_essays = views_embed_view('thread_essays', 'block', $thread_nid);
					$thread_name = _ebr_get_field_value($thread_node, 'field_name');
					$footer = '<div>'.l('View all essays in this thread...', "thread/$thread_name").'</div>';
					$block['content'] = '<h2 class="thread-title">'.l($thread_node->title, request_path().'/..').'</h2>'.$thread_essays.$footer;
					break;
				case 'thread':
					$block['content'] = _ebr_render_field($page_node, 'body', 'full');
					break;
			}
		}
      	break;
	
	// The secondary supporting meta content for the current page
	case 'meta_secondary':
		if (!empty($page_node)) {
			switch ($page_node->type) {
				case 'thread':
					$block['content'] = _ebr_render_field($page_node, 'field_thread_notes', 'teaser');
					break;
				case 'essay':
					$block['content'] = _ebr_render_field($page_node, 'field_tags', 'full');
					break;
			}
		}
      	break;
	
	// Content to add after the main content on the current page	
	case 'content_after':
		if (drupal_is_front_page()) {
			$block['content'] = views_embed_view('recent_essays');
		} 
		else 
		if (!empty($page_node)) {
			switch ($page_node->type) {
				case 'thread':
					$block['content'] = views_embed_view('thread_essays', 'block_1');
					break;
				case 'author': 
					//$block['content'] = views_embed_view('threads_edited_by_author');
					$block['content'] = views_embed_view('essays_by_author');
					break;
			}
		}
      	break;
	
  }
  return $block;
}

