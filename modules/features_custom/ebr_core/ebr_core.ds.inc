<?php
/**
 * @file
 * ebr_core.ds.inc
 */

/**
 * Implements hook_ds_view_modes_info().
 */
function ebr_core_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'teaser_compact';
  $ds_view_mode->label = 'Teaser compact';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['teaser_compact'] = $ds_view_mode;

  return $export;
}
