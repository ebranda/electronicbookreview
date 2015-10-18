<?php
/**
 * @file
 * ebr_core.features.workflow_access.inc
 */

/**
 * Implements hook_workflow_access_features_default_settings().
 */
function ebr_core_workflow_access_features_default_settings() {
  $workflows = array();

  $workflows['Essay workflow'] = array();
  $workflows['Essay workflow']['Solicited'] = array();
  $workflows['Essay workflow']['Solicited']['workflow_features_author_name'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Essay workflow']['Solicited']['anonymous user'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Essay workflow']['Solicited']['authenticated user'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Essay workflow']['Solicited']['administrator'] = array(
    'grant_view' => 1,
    'grant_update' => 1,
    'grant_delete' => 1,
  );
  $workflows['Essay workflow']['Solicited']['editor'] = array(
    'grant_view' => 1,
    'grant_update' => 1,
    'grant_delete' => 1,
  );
  $workflows['Essay workflow']['Solicited']['weaver'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Essay workflow']['Solicited']['reviewer'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Essay workflow']['Solicited']['thread editor'] = array(
    'grant_view' => 1,
    'grant_update' => 1,
    'grant_delete' => 1,
  );
  $workflows['Essay workflow']['Solicited']['user administrator'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Essay workflow']['Solicited']['email test'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Essay workflow']['Under editorial review'] = array();
  $workflows['Essay workflow']['Under editorial review']['workflow_features_author_name'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Essay workflow']['Under editorial review']['anonymous user'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Essay workflow']['Under editorial review']['authenticated user'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Essay workflow']['Under editorial review']['administrator'] = array(
    'grant_view' => 1,
    'grant_update' => 1,
    'grant_delete' => 1,
  );
  $workflows['Essay workflow']['Under editorial review']['editor'] = array(
    'grant_view' => 1,
    'grant_update' => 1,
    'grant_delete' => 1,
  );
  $workflows['Essay workflow']['Under editorial review']['weaver'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Essay workflow']['Under editorial review']['reviewer'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Essay workflow']['Under editorial review']['thread editor'] = array(
    'grant_view' => 1,
    'grant_update' => 1,
    'grant_delete' => 1,
  );
  $workflows['Essay workflow']['Under editorial review']['user administrator'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Essay workflow']['Under editorial review']['email test'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Essay workflow']['In markup'] = array();
  $workflows['Essay workflow']['In markup']['workflow_features_author_name'] = array(
    'grant_view' => 1,
    'grant_update' => 1,
    'grant_delete' => 0,
  );
  $workflows['Essay workflow']['In markup']['anonymous user'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Essay workflow']['In markup']['authenticated user'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Essay workflow']['In markup']['administrator'] = array(
    'grant_view' => 1,
    'grant_update' => 1,
    'grant_delete' => 1,
  );
  $workflows['Essay workflow']['In markup']['editor'] = array(
    'grant_view' => 1,
    'grant_update' => 1,
    'grant_delete' => 1,
  );
  $workflows['Essay workflow']['In markup']['weaver'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Essay workflow']['In markup']['reviewer'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Essay workflow']['In markup']['thread editor'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Essay workflow']['In markup']['user administrator'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Essay workflow']['In markup']['email test'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Essay workflow']['In P2P review'] = array();
  $workflows['Essay workflow']['In P2P review']['workflow_features_author_name'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Essay workflow']['In P2P review']['anonymous user'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Essay workflow']['In P2P review']['authenticated user'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Essay workflow']['In P2P review']['administrator'] = array(
    'grant_view' => 1,
    'grant_update' => 1,
    'grant_delete' => 1,
  );
  $workflows['Essay workflow']['In P2P review']['editor'] = array(
    'grant_view' => 1,
    'grant_update' => 1,
    'grant_delete' => 1,
  );
  $workflows['Essay workflow']['In P2P review']['weaver'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Essay workflow']['In P2P review']['reviewer'] = array(
    'grant_view' => 1,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Essay workflow']['In P2P review']['thread editor'] = array(
    'grant_view' => 1,
    'grant_update' => 1,
    'grant_delete' => 1,
  );
  $workflows['Essay workflow']['In P2P review']['user administrator'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Essay workflow']['In P2P review']['email test'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Essay workflow']['Under review'] = array();
  $workflows['Essay workflow']['Under review']['workflow_features_author_name'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Essay workflow']['Under review']['anonymous user'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Essay workflow']['Under review']['authenticated user'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Essay workflow']['Under review']['administrator'] = array(
    'grant_view' => 1,
    'grant_update' => 1,
    'grant_delete' => 1,
  );
  $workflows['Essay workflow']['Under review']['editor'] = array(
    'grant_view' => 1,
    'grant_update' => 1,
    'grant_delete' => 1,
  );
  $workflows['Essay workflow']['Under review']['weaver'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Essay workflow']['Under review']['reviewer'] = array(
    'grant_view' => 1,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Essay workflow']['Under review']['thread editor'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Essay workflow']['Under review']['user administrator'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Essay workflow']['Reviewed'] = array();
  $workflows['Essay workflow']['Reviewed']['workflow_features_author_name'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Essay workflow']['Reviewed']['anonymous user'] = array(
    'grant_view' => 1,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Essay workflow']['Reviewed']['authenticated user'] = array(
    'grant_view' => 1,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Essay workflow']['Reviewed']['administrator'] = array(
    'grant_view' => 1,
    'grant_update' => 1,
    'grant_delete' => 1,
  );
  $workflows['Essay workflow']['Reviewed']['editor'] = array(
    'grant_view' => 1,
    'grant_update' => 1,
    'grant_delete' => 1,
  );
  $workflows['Essay workflow']['Reviewed']['weaver'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Essay workflow']['Reviewed']['reviewer'] = array(
    'grant_view' => 1,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Essay workflow']['Reviewed']['thread editor'] = array(
    'grant_view' => 1,
    'grant_update' => 1,
    'grant_delete' => 1,
  );
  $workflows['Essay workflow']['Reviewed']['user administrator'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Essay workflow']['Reviewed']['email test'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Essay workflow']['Published'] = array();
  $workflows['Essay workflow']['Published']['workflow_features_author_name'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Essay workflow']['Published']['anonymous user'] = array(
    'grant_view' => 1,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Essay workflow']['Published']['authenticated user'] = array(
    'grant_view' => 1,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Essay workflow']['Published']['administrator'] = array(
    'grant_view' => 0,
    'grant_update' => 1,
    'grant_delete' => 1,
  );
  $workflows['Essay workflow']['Published']['editor'] = array(
    'grant_view' => 0,
    'grant_update' => 1,
    'grant_delete' => 1,
  );
  $workflows['Essay workflow']['Published']['weaver'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Essay workflow']['Published']['reviewer'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Essay workflow']['Published']['thread editor'] = array(
    'grant_view' => 0,
    'grant_update' => 1,
    'grant_delete' => 1,
  );
  $workflows['Essay workflow']['Published']['user administrator'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Essay workflow']['Published']['email test'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Essay workflow']['Shelved'] = array();
  $workflows['Essay workflow']['Shelved']['workflow_features_author_name'] = array(
    'grant_view' => 1,
    'grant_update' => 1,
    'grant_delete' => 1,
  );
  $workflows['Essay workflow']['Shelved']['anonymous user'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Essay workflow']['Shelved']['authenticated user'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Essay workflow']['Shelved']['administrator'] = array(
    'grant_view' => 1,
    'grant_update' => 1,
    'grant_delete' => 1,
  );
  $workflows['Essay workflow']['Shelved']['editor'] = array(
    'grant_view' => 1,
    'grant_update' => 1,
    'grant_delete' => 1,
  );
  $workflows['Essay workflow']['Shelved']['thread editor'] = array(
    'grant_view' => 1,
    'grant_update' => 1,
    'grant_delete' => 1,
  );
  $workflows['Essay workflow']['Shelved']['user administrator'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );
  $workflows['Essay workflow']['Shelved']['email test'] = array(
    'grant_view' => 0,
    'grant_update' => 0,
    'grant_delete' => 0,
  );

  return $workflows;
}
