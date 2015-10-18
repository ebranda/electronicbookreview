<?php 

/**
 * Implements hook_block_info().
 */
function ebr_block_info() {
	$blocks['site_name'] = array(
		'info' => t('Site name'), 
	);
	$blocks['site_summary'] = array(
		'info' => t('Site summary'), 
	);
	$blocks['essay_thread_essays'] = array(
		'info' => t('Thread table of contents for essay page'), 
	);
	$blocks['node_body_rendered'] = array(
		'info' => t('Rendered contents of node body'), 
	);
	$blocks['thread_notes'] = array(
		'info' => t('Thread notes field for thread page'), 
	);
	$blocks['node_tags'] = array(
		'info' => t('Rendered tags field for any node page'), 
	);
	$blocks['cc_icon'] = array(
		'info' => t('Creative Commons icon'), 
	);
	$blocks['ohp_logo'] = array(
		'info' => t('OHP logo'), 
	);
	$blocks['p2p_welcome_message'] = array(
		'info' => t('P2P reviewer welcome message'), 
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

		case 'site_name':
			$block['content'] = l(variable_get('site_name', "Default site name"), '');
			break;

		case 'site_summary':
			$block['content'] = ebr_internal_content_get_markup('site-summary');
			break;
		
		case 'essay_thread_essays':
			if (!empty($page_node)) {
				$thread_nid = _ebr_get_field_value($page_node, 'field_thread');
				$thread_node = node_load($thread_nid);
				$thread_essays = views_embed_view('thread_essays', 'block', $thread_nid);
				$thread_name = _ebr_get_field_value($thread_node, 'field_name');
				$footer = '<div>'.l('View all essays in this thread...', "thread/$thread_name").'</div>';
				$block['content'] = '<h2 class="thread-title">'.l($thread_node->title, request_path().'/..').'</h2>'.$thread_essays.$footer;
			}
			break;
	
		case 'node_body_rendered':
			if (!empty($page_node)) {
				$block['content'] = _ebr_render_field($page_node, 'body', 'full');
			}
			break;
	
		case 'thread_notes':
			if (!empty($page_node)) {
				$block['content'] = _ebr_render_field($page_node, 'field_thread_notes', 'teaser');
			}
			break;
	
		case 'node_tags':
			if (!empty($page_node)) {
				$block['content'] = _ebr_render_field($page_node, 'field_tags', 'full');
			}
			break;
		
		case 'cc_icon':
			$block['content'] = '<a href="http://creativecommons.org/licenses/by-nc-sa/2.5/" target="_blank"><img src="'.base_path() . path_to_theme().'/images/somerights20.gif" alt="" /></a>';
			break;

		case 'ohp_logo':
			$block['content'] = 'Part of <a href="http://openhumanitiespress.org/" target="_blank"><img src="'. base_path() . path_to_theme() . '/images/ohp-logo-web-small.gif" alt="" /></a>';
			break;

		case 'p2p_welcome_message':
			$block['content'] = 'You are currently logged in as a Peer-to-peer reviewer. Start the review process by selecting \"Essays for review\" in the menu above or by <a href="p2p">clicking here</a>.';
			break;
			
  }
  return $block;
}

