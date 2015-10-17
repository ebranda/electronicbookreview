<?php

/**
 * Get notes for referring_url/current url and
 * return as list including edit/delete etc...
 *
 * @param $variables -> contains:
 *             $variables['referring_url'] = url for notes
 *             $variables['notes'] = an array of all notes for referring url
 *             $variables['can_edit'] = a flag with permission to edit
 *             $variables['can_delete'] = a flag with permission to delete * 
 * @TODO: Customize include better themeing for listing.
 */
function theme_stickynote_list($variables) {
  $output = '';

  $header = array();
  $header[] = t('Note');
  if ($variables['can_edit']) {
    $header[] = t('Edit');
  }
  if ($variables['can_delete']) {
    $header[] = t('Delete');
  }
  $header[] = t('Date');

  if (isset($variables['notes'])) {
    $table['header'] = $header;
    $table['rows'] = $variables['notes'];

    $output = theme('table', $table);
  }

  return $output;
}

/**
 * Return confirmation links for deletion
 *
 * @param $stickynote
 */
function theme_stickynote_confirm($variables) {
  $stickynote = $variables['stickynote'];
  $token = drupal_get_token($stickynote->snid);
  
  $output = '';
  $output .= '<td colspan="4" id="note-' . $stickynote->snid . '">';
  $output .= '<div id="confirm-delete-' . $sitckynote->snid . '" style="text-align: center;">';
  $output .= 'Are you sure?</br>';
  $output .= l(t('Delete'), 'stickynote/' . $stickynote->snid . '/delete', array(
    'attributes' => array('class' => array('use-ajax')),
    'query' => array('token' => $token),
  ));
  $output .= '&nbsp;&nbsp;&nbsp;&nbsp;';
  $output .= l(t('Cancel'), 'stickynote/' . $stickynote->snid . '/cancel', array('attributes' => array('class' => array('use-ajax'))));
  $output .= '</div>';
  
  
  $output .= '</td>';
  

  return $output;
}