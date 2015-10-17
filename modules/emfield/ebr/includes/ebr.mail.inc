<?php 

/**
 * Implements hook_mail()
 */
function ebr_mail($key, &$message, $params) {
  $function = __FUNCTION__ . '_' . $key;
  if (function_exists($function)) {
    $function($message, $params);
  }
}

function ebr_mail_notify_thread_editor_new_essay(&$message, $params) {
  _ebr_mail_set_html($message);
  $message['subject'] = "New EBR essay in your thread ".$params['thread_title'];
  $message['body'][] = 'This is an automatic notification from the Electronic Book Review sent to you in your '.
                      'capacity as an editor of the '.$params['thread_title'].' thread. A new essay has been added to your thread. '.
                      'You can view the essay '.l('here', $params['essay_path']).'.';
}

function ebr_mail_notify_editors_new_essay(&$message, $params) {
  _ebr_mail_set_html($message);
  $message['subject'] = "New EBR essay available for editing";
  $message['body'][] = 'This is an automatic notification from the Electronic Book Review. The essay "'.
                      $params['essay_title'].'" has been added to your thread. '.
                      'You can view the essay '.l('here', $params['essay_path']).'.';
}

/**
 * Helper function to set a message header to support HTML
 */
function _ebr_mail_set_html(&$message) {
  $message['headers']['MIME-Version'] = '1.0';
  $message['headers']['Content-Type'] = 'text/html;charset=utf-8';
}

// Used to send status report email
function ebr_get_essay_status_report_as_text() {
	$html = views_embed_view("essay_status_report", "page_1");
	$txt = strip_tags($html);
	$txt = html_entity_decode($txt, ENT_QUOTES, 'UTF-8');
	$lines = explode("\n", $txt);
	$cleaned = array();
	$hr = '';
	for ($i=0; $i<40; $i++) $hr .= '_';
	foreach ($lines as $line) {
		$l = trim(preg_replace('/[\s]+/',' ', $line));
		if (!empty($l)) {
			$heading = strpos($l, 'Workflow state') !== FALSE;
			if ($heading) {
				$cleaned[] = "\n\n$hr\n$l\n";
			} else {
				$cleaned[] = $l . "\n";
			}
		}
	}
	return implode("\n", $cleaned);
}