<?php
/**
 * @file
 * ebr_core.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ebr_core_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_workflow|node|essay|form';
  $field_group->group_name = 'group_workflow';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'essay';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Solicited essay notes',
    'weight' => '12',
    'children' => array(
      0 => 'field_solicited_by',
      1 => 'field_eta',
      2 => 'field_author_temp',
      3 => 'field_subject',
      4 => 'field_workflow_notes',
      5 => 'field_draft_essay',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Solicited essay notes',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-workflow field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_workflow|node|essay|form'] = $field_group;

  return $export;
}
