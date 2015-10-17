<?php
/**
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/garland.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $secondary_menu_heading: The title of the menu used by the secondary links.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see template_process()
 */
?>

<div id="page" class="<?php print $classes; ?>">
  
  <?php //drupal_add_css("http://fonts.googleapis.com/css?family=Poly:400,400italic", $option['type'] = 'external') ?>
  <?php //drupal_add_css("http://fonts.googleapis.com/css?family=Open+Sans:300italic,400italic,700italic,300,400,700", $option['type'] = 'external') ?>
  <?php drupal_add_css("http://fonts.googleapis.com/css?family=Karla:700,400", $option['type'] = 'external') ?>
  <?php drupal_add_css("http://fonts.googleapis.com/css?family=Neuton:400,700,400italic", $option['type'] = 'external') ?>

  <div id="header">
    <?php print render($page['header-primary']); ?>
	<?php print render($page['header-secondary']); ?>
    <div class="clearfix"></div>
  </div>

  <div id="main">
	<div class="grid-background"></div>
    <?php print render($page['content-sidebar-left']); ?>
	<div class="region-content-primary-wrapper">
    	<?php print $messages; ?>
		<?php if (isset($title)): ?>
			<h2 class="page-title"><?php if (isset($title_prefix)) {?><span class="prefix"><?php print $title_prefix; ?>: </span><?php } ?><?php print $title; ?><?php if (isset($title_suffix)) {?><span class="suffix">: <?php print $title_suffix; ?></span><?php } ?></h2>
		<?php endif; ?>
    	<?php print render($page['content-primary']); ?> <!-- TODO theme layer template.php should add secondary content (floating tear-offs) to this content array -->
	</div>
	<?php print render($page['content-sidebar-right']); ?>
  </div><!-- /#main -->
  
  <div class="clearfix"></div><!-- Just here for making sure float content in #main sizes container correctly -->

  <?php print render($page['footer']) ?>

</div><!-- /#page -->
