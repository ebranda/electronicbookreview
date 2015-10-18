<?php
/**
 * @file
 * ebr_core.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function ebr_core_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_about:node/2357.
  $menu_links['main-menu_about:node/2357'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/2357',
    'router_path' => 'node/%',
    'link_title' => 'About',
    'options' => array(
      'alter' => TRUE,
      'identifier' => 'main-menu_about:node/2357',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: main-menu_books-received:books-received.
  $menu_links['main-menu_books-received:books-received'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'books-received',
    'router_path' => 'books-received',
    'link_title' => 'Books received',
    'options' => array(
      'identifier' => 'main-menu_books-received:books-received',
      'alter' => TRUE,
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
  );
  // Exported menu link: main-menu_books-reviewed:books-reviewed.
  $menu_links['main-menu_books-reviewed:books-reviewed'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'books-reviewed',
    'router_path' => 'books-reviewed',
    'link_title' => 'Books reviewed',
    'options' => array(
      'identifier' => 'main-menu_books-reviewed:books-reviewed',
      'alter' => TRUE,
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
  );
  // Exported menu link: main-menu_ebr-authors:ebr-authors.
  $menu_links['main-menu_ebr-authors:ebr-authors'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'ebr-authors',
    'router_path' => 'ebr-authors',
    'link_title' => 'EBR Authors',
    'options' => array(
      'attributes' => array(
        'title' => 'A list of all authors published on EBR.',
      ),
      'identifier' => 'main-menu_ebr-authors:ebr-authors',
      'alter' => TRUE,
    ),
    'module' => 'system',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: main-menu_ebr-contributors:node/2259.
  $menu_links['main-menu_ebr-contributors:node/2259'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/2259',
    'router_path' => 'node/%',
    'link_title' => 'EBR Contributors',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_ebr-contributors:node/2259',
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: main-menu_editorial-resources:node/2422.
  $menu_links['main-menu_editorial-resources:node/2422'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/2422',
    'router_path' => 'node/%',
    'link_title' => 'Editorial resources',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_editorial-resources:node/2422',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: main-menu_essays-for-review:p2p.
  $menu_links['main-menu_essays-for-review:p2p'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'p2p',
    'router_path' => 'p2p',
    'link_title' => 'Essays for review',
    'options' => array(
      'identifier' => 'main-menu_essays-for-review:p2p',
      'alter' => TRUE,
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -43,
    'customized' => 1,
  );
  // Exported menu link: main-menu_essays-index:essays-index.
  $menu_links['main-menu_essays-index:essays-index'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'essays-index',
    'router_path' => 'essays-index',
    'link_title' => 'Essays index',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_essays-index:essays-index',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: main-menu_home:<front>.
  $menu_links['main-menu_home:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Home',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_home:<front>',
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: main-menu_log-in:user/login.
  $menu_links['main-menu_log-in:user/login'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'user/login',
    'router_path' => 'user/login',
    'link_title' => 'Log in',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_log-in:user/login',
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -42,
    'customized' => 1,
  );
  // Exported menu link: main-menu_policies-and-submissions:node/2050.
  $menu_links['main-menu_policies-and-submissions:node/2050'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/2050',
    'router_path' => 'node/%',
    'link_title' => 'Policies and Submissions',
    'options' => array(
      'alter' => TRUE,
      'identifier' => 'main-menu_policies-and-submissions:node/2050',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('About');
  t('Books received');
  t('Books reviewed');
  t('EBR Authors');
  t('EBR Contributors');
  t('Editorial resources');
  t('Essays for review');
  t('Essays index');
  t('Home');
  t('Log in');
  t('Policies and Submissions');

  return $menu_links;
}
