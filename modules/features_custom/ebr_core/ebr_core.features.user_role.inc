<?php
/**
 * @file
 * ebr_core.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function ebr_core_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 6,
  );

  // Exported role: anonymous user.
  $roles['anonymous user'] = array(
    'name' => 'anonymous user',
    'weight' => 0,
  );

  // Exported role: authenticated user.
  $roles['authenticated user'] = array(
    'name' => 'authenticated user',
    'weight' => 1,
  );

  // Exported role: editor.
  $roles['editor'] = array(
    'name' => 'editor',
    'weight' => 4,
  );

  // Exported role: email test.
  $roles['email test'] = array(
    'name' => 'email test',
    'weight' => 8,
  );

  // Exported role: reviewer.
  $roles['reviewer'] = array(
    'name' => 'reviewer',
    'weight' => 2,
  );

  // Exported role: thread editor.
  $roles['thread editor'] = array(
    'name' => 'thread editor',
    'weight' => 5,
  );

  // Exported role: user administrator.
  $roles['user administrator'] = array(
    'name' => 'user administrator',
    'weight' => 7,
  );

  // Exported role: weaver.
  $roles['weaver'] = array(
    'name' => 'weaver',
    'weight' => 3,
  );

  return $roles;
}
