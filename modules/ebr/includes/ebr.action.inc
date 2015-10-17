<?php 

// Currently assigned in Workflow tab of Triggers page

/**
 * Implements hook_action_info()
 */
function ebr_action_info() {
  return array(
    'ebr_notify_thread_editor_new_essay_action' => array(
      'type' => 'node', 
      'label' => t('Notify thread editor of new essay'), 
      'configurable' => FALSE, 
      'triggers' => array('any'),
    ), 
   'ebr_notify_editors_new_essay_action' => array(
      'type' => 'node', 
      'label' => t('Notify all editors of new essay'), 
      'configurable' => FALSE, 
      'triggers' => array('any'),
    ),
    'ebr_update_publication_date_action' => array(
      'type' => 'node', 
      'label' => t('Update essay publication date to now'), 
      'configurable' => FALSE, 
      'triggers' => array('any'),
    ),
  );
}

function ebr_notify_editors_new_essay_action(&$node, $context = array()) {
  $recipients = array();
  $view = views_get_view('editor_users');
  $view->execute();
  foreach ($view->result as $result) {
    $recipients[] = $result->users_mail;
  }
  $params['essay_title'] = $node->title;
  $params['essay_path'] = _ebr_essay_path($node);
  drupal_mail('ebr', 'notify_editors_new_essay', join(', ', $recipients), language_default(), $params);
  drupal_set_message("All editors have been notified of this new essay.");
}

function ebr_notify_thread_editor_new_essay_action(&$node, $context = array()) {
  $uid = $node->thread->field_thread_editor_user['und'][0]['uid'];
  $editor_user = user_load($uid);
  $params['thread_title'] = $node->thread->title;
  $params['essay_path'] = _ebr_essay_path($node);
  drupal_mail('ebr', 'notify_thread_editor_new_essay', $editor_user->mail, user_preferred_language($editor_user), $params);
  drupal_set_message("The thread editor (".$editor_user->field_display_name['und'][0]['value'].") has been notified that this essay is available for review.");
}

function ebr_update_publication_date_action(&$node, $context = array()) {
  $node->field_publication_date['und'][0]['value'] = date("Y-m-d H:i:s", time());
  node_save($node);
}