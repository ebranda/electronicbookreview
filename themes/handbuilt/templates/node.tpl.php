<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php print $user_picture; ?>
  
  <?php if (isset($full_screen_icon)) { ?>
    <?php print $full_screen_icon; ?>
  <?php } ?>

  <?php if (isset($teaser_icon)) { ?>
    <?php print $teaser_icon; ?>
    <div class="main-content">
  <?php } ?>
  
  <?php if (!empty($header)): ?>
    <div class="node-header"><?php print $header; ?></div>
  <?php endif; ?>
  
    <?php if ($title): ?>
      <?php if ($view_mode != 'full'): ?>
        <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print render($title_prefix); print $title; print render($title_suffix); ?></a></h2>
      <?php else: ?>
        <h2<?php print $title_attributes; ?>><?php print render($title_prefix); print $title; print render($title_suffix); ?></h2>
      <?php endif; ?>
    <?php endif; ?>
    
    <?php if ($unpublished && !$teaser): ?>
      <!--<div class="unpublished"><?php print t('Unpublished'); ?></div>-->
	  <?php if ($workflow_state): ?>
      	<div class="workflow-state">Workflow: <?php print $workflow_state; ?></div>
	  <?php endif; ?>
    <?php endif; ?>

    <?php if ($display_submitted): ?>
      <div class="submitted">
        <?php print $submitted; ?>
      </div>
    <?php endif; ?>

    <div class="content"<?php print $content_attributes; ?>>
      <?php
        // We hide the comments and links now so that we can render them later.
        hide($content['comments']);
        hide($content['links']);
        print render($content);
      ?>
    </div>

    <?php print render($content['links']); ?>

    <?php print render($content['comments']); ?>
    
    <?php if (isset($teaser_icon)) { ?>
      </div><!-- .main-content -->
    <?php } ?>

</div><!-- /.node -->
