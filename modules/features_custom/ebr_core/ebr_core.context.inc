<?php
/**
 * @file
 * ebr_core.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function ebr_core_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'author_page';
  $context->description = 'Content for author page';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'author' => 'author',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-essays_by_author-block' => array(
          'module' => 'views',
          'delta' => 'essays_by_author-block',
          'region' => 'content-primary',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Content for author page');
  $export['author_page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'essay_page';
  $context->description = 'Content for essay page.';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'essay' => 'essay',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'ebr-essay_thread_essays' => array(
          'module' => 'ebr',
          'delta' => 'essay_thread_essays',
          'region' => 'content-sidebar-left',
          'weight' => '-10',
        ),
        'ebr-node_tags' => array(
          'module' => 'ebr',
          'delta' => 'node_tags',
          'region' => 'content-sidebar-right',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Content for essay page.');
  $export['essay_page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'homepage';
  $context->description = 'Home page content';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-recent_essays-block' => array(
          'module' => 'views',
          'delta' => 'recent_essays-block',
          'region' => 'content-primary',
          'weight' => '-10',
        ),
        'ebr-site_summary' => array(
          'module' => 'ebr',
          'delta' => 'site_summary',
          'region' => 'content-sidebar-left',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Home page content');
  $export['homepage'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sitewide_page_template';
  $context->description = 'All page components for EBR site';
  $context->tag = '';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'ebr-site_name' => array(
          'module' => 'ebr',
          'delta' => 'site_name',
          'region' => 'header-primary',
          'weight' => '-10',
        ),
        'system-main-menu' => array(
          'module' => 'system',
          'delta' => 'main-menu',
          'region' => 'header-secondary',
          'weight' => '-10',
        ),
        'social_share-social_share' => array(
          'module' => 'social_share',
          'delta' => 'social_share',
          'region' => 'header-secondary',
          'weight' => '-9',
        ),
        'views-thread_links-block_1' => array(
          'module' => 'views',
          'delta' => 'thread_links-block_1',
          'region' => 'header-secondary',
          'weight' => '-8',
        ),
        'search-form' => array(
          'module' => 'search',
          'delta' => 'form',
          'region' => 'header-secondary',
          'weight' => '-7',
        ),
        'ebr-ohp_logo' => array(
          'module' => 'ebr',
          'delta' => 'ohp_logo',
          'region' => 'footer',
          'weight' => '-10',
        ),
        'ebr-cc_icon' => array(
          'module' => 'ebr',
          'delta' => 'cc_icon',
          'region' => 'footer',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('All page components for EBR site');
  $export['sitewide_page_template'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'thread_page';
  $context->description = 'Content for thread page';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'thread' => 'thread',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-thread_essays-block_1' => array(
          'module' => 'views',
          'delta' => 'thread_essays-block_1',
          'region' => 'content-primary',
          'weight' => '-10',
        ),
        'ebr-node_body_rendered' => array(
          'module' => 'ebr',
          'delta' => 'node_body_rendered',
          'region' => 'content-sidebar-left',
          'weight' => '-10',
        ),
        'ebr-thread_notes' => array(
          'module' => 'ebr',
          'delta' => 'thread_notes',
          'region' => 'content-sidebar-right',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Content for thread page');
  $export['thread_page'] = $context;

  return $export;
}
