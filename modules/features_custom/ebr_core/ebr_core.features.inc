<?php
/**
 * @file
 * ebr_core.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ebr_core_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ebr_core_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function ebr_core_node_info() {
  $items = array(
    'author' => array(
      'name' => t('Author'),
      'base' => 'node_content',
      'description' => t('An author of an essay or any other content, or a Thread editor. Includes a bio. This entity is not the same as the web user who is the author of a post.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
    'book' => array(
      'name' => t('Book'),
      'base' => 'node_content',
      'description' => t('Represents a book received or reviewed in an EBR essay.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'contributors' => array(
      'name' => t('Contributors'),
      'base' => 'node_content',
      'description' => t('A list of EBR Contributors, for editorial use.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'essay' => array(
      'name' => t('Essay'),
      'base' => 'node_content',
      'description' => t('An EBR essay.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'gathering' => array(
      'name' => t('Gathering'),
      'base' => 'node_content',
      'description' => t('A grouping of essays with an overall introduction.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'gloss' => array(
      'name' => t('Gloss'),
      'base' => 'node_content',
      'description' => t('A gloss belonging to an essay.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'internal_text' => array(
      'name' => t('Internal Text'),
      'base' => 'node_content',
      'description' => t('Used for storing texts used internally by the EBR web application. This content type should only be used by PHP developers.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
    'issue' => array(
      'name' => t('Issue'),
      'base' => 'node_content',
      'description' => t('Use this content type to submit bug reports and feature requests.'),
      'has_title' => '1',
      'title_label' => t('Short description'),
      'help' => '',
    ),
    'p2p_review' => array(
      'name' => t('P2P Review'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Basic page'),
      'base' => 'node_content',
      'description' => t('Use <em>basic pages</em> for your static content, such as an \'About us\' page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'thread' => array(
      'name' => t('Thread'),
      'base' => 'node_content',
      'description' => t('A Thread (roughly equivalent to a journal "issue").'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_workflow_default_workflows().
 */
function ebr_core_workflow_default_workflows() {
  $workflows = array();

  // Exported workflow: Essay workflow
  $workflows['Essay workflow'] = array(
    'name' => 'Essay workflow',
    'tab_roles' => '4,7',
    'options' => 'a:4:{s:16:"comment_log_node";s:1:"1";s:15:"comment_log_tab";s:1:"0";s:13:"name_as_title";s:1:"0";s:12:"watchdog_log";s:1:"1";}',
    'states' => array(
      0 => array(
        'state' => '(creation)',
        'weight' => -50,
        'sysid' => 1,
        'status' => 1,
        'name' => 'Essay workflow',
      ),
      1 => array(
        'state' => 'Solicited',
        'weight' => -19,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Essay workflow',
      ),
      2 => array(
        'state' => 'Under editorial review',
        'weight' => -18,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Essay workflow',
      ),
      3 => array(
        'state' => 'In markup',
        'weight' => -17,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Essay workflow',
      ),
      4 => array(
        'state' => 'In P2P review',
        'weight' => -16,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Essay workflow',
      ),
      5 => array(
        'state' => 'Reviewed',
        'weight' => -14,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Essay workflow',
      ),
      6 => array(
        'state' => 'Published',
        'weight' => -13,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Essay workflow',
      ),
      7 => array(
        'state' => 'Shelved',
        'weight' => -12,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Essay workflow',
      ),
    ),
    'transitions' => array(
      0 => array(
        'roles' => 'workflow_features_author_name,editor,thread editor,administrator',
        'state' => '(creation)',
        'target_state' => 'Solicited',
      ),
      1 => array(
        'roles' => '',
        'state' => '(creation)',
        'target_state' => 'In markup',
      ),
      2 => array(
        'roles' => 'editor,thread editor,administrator',
        'state' => '(creation)',
        'target_state' => 'Under editorial review',
      ),
      3 => array(
        'roles' => 'editor,thread editor,administrator',
        'state' => '(creation)',
        'target_state' => 'Shelved',
      ),
      4 => array(
        'roles' => 'editor,thread editor,administrator',
        'state' => 'Solicited',
        'target_state' => 'In markup',
      ),
      5 => array(
        'roles' => 'editor,thread editor,administrator',
        'state' => 'Solicited',
        'target_state' => 'Under editorial review',
      ),
      6 => array(
        'roles' => 'editor,thread editor,administrator',
        'state' => 'Solicited',
        'target_state' => 'Shelved',
      ),
      7 => array(
        'roles' => 'editor,thread editor,administrator',
        'state' => 'Solicited',
        'target_state' => 'In P2P review',
      ),
      8 => array(
        'roles' => 'editor,thread editor,administrator',
        'state' => 'Solicited',
        'target_state' => 'Reviewed',
      ),
      9 => array(
        'roles' => 'editor,thread editor,administrator',
        'state' => 'Solicited',
        'target_state' => 'Published',
      ),
      10 => array(
        'roles' => 'editor,thread editor,administrator',
        'state' => 'Under editorial review',
        'target_state' => 'In markup',
      ),
      11 => array(
        'roles' => 'editor,thread editor,administrator',
        'state' => 'Under editorial review',
        'target_state' => 'Solicited',
      ),
      12 => array(
        'roles' => 'editor,thread editor,administrator',
        'state' => 'Under editorial review',
        'target_state' => 'Shelved',
      ),
      13 => array(
        'roles' => 'editor,thread editor,administrator',
        'state' => 'Under editorial review',
        'target_state' => 'In P2P review',
      ),
      14 => array(
        'roles' => 'editor,thread editor,administrator',
        'state' => 'Under editorial review',
        'target_state' => 'Reviewed',
      ),
      15 => array(
        'roles' => 'editor,thread editor,administrator',
        'state' => 'Under editorial review',
        'target_state' => 'Published',
      ),
      16 => array(
        'roles' => 'editor,thread editor,administrator',
        'state' => 'In markup',
        'target_state' => 'In P2P review',
      ),
      17 => array(
        'roles' => 'editor,thread editor,administrator',
        'state' => 'In markup',
        'target_state' => 'Under editorial review',
      ),
      18 => array(
        'roles' => '',
        'state' => 'In markup',
        'target_state' => 'Solicited',
      ),
      19 => array(
        'roles' => 'editor,thread editor,administrator',
        'state' => 'In markup',
        'target_state' => 'Shelved',
      ),
      20 => array(
        'roles' => 'editor,thread editor,administrator',
        'state' => 'In P2P review',
        'target_state' => 'In markup',
      ),
      21 => array(
        'roles' => 'editor,thread editor,administrator',
        'state' => 'In P2P review',
        'target_state' => 'Reviewed',
      ),
      22 => array(
        'roles' => 'editor,thread editor,administrator',
        'state' => 'In P2P review',
        'target_state' => 'Shelved',
      ),
      23 => array(
        'roles' => 'editor,thread editor,administrator',
        'state' => 'In P2P review',
        'target_state' => 'Under editorial review',
      ),
      24 => array(
        'roles' => '',
        'state' => 'Reviewed',
        'target_state' => 'Published',
      ),
      25 => array(
        'roles' => 'editor,thread editor,administrator',
        'state' => 'Reviewed',
        'target_state' => 'In markup',
      ),
      26 => array(
        'roles' => 'editor,thread editor,administrator',
        'state' => 'Reviewed',
        'target_state' => 'Shelved',
      ),
      27 => array(
        'roles' => 'editor,thread editor,administrator',
        'state' => 'Reviewed',
        'target_state' => 'Solicited',
      ),
      28 => array(
        'roles' => 'editor,thread editor,administrator',
        'state' => 'Reviewed',
        'target_state' => 'Under editorial review',
      ),
      29 => array(
        'roles' => 'editor,thread editor,administrator',
        'state' => 'Reviewed',
        'target_state' => 'In P2P review',
      ),
      30 => array(
        'roles' => 'editor,thread editor,administrator',
        'state' => 'Published',
        'target_state' => 'Reviewed',
      ),
      31 => array(
        'roles' => 'editor,thread editor,administrator',
        'state' => 'Published',
        'target_state' => 'Shelved',
      ),
      32 => array(
        'roles' => 'editor,thread editor,administrator',
        'state' => 'Shelved',
        'target_state' => 'Solicited',
      ),
      33 => array(
        'roles' => 'editor,thread editor,administrator',
        'state' => 'Shelved',
        'target_state' => 'Under editorial review',
      ),
      34 => array(
        'roles' => 'editor,thread editor,administrator',
        'state' => 'Shelved',
        'target_state' => 'In markup',
      ),
      35 => array(
        'roles' => 'editor,thread editor,administrator',
        'state' => 'Shelved',
        'target_state' => 'In P2P review',
      ),
      36 => array(
        'roles' => 'editor,thread editor,administrator',
        'state' => 'Shelved',
        'target_state' => 'Reviewed',
      ),
      37 => array(
        'roles' => 'editor,thread editor,administrator',
        'state' => 'Shelved',
        'target_state' => 'Published',
      ),
    ),
    'node_types' => array(
      0 => 'essay',
    ),
  );

  return $workflows;
}
