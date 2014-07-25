<?php
/**
 * @file
 * unlv_events.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function unlv_events_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function unlv_events_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function unlv_events_node_info() {
  $items = array(
    'feed_item_unlv_calendar' => array(
      'name' => t('Feed Item UNLV Calendar'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Event Title'),
      'help' => '',
    ),
    'feed_unlv_calendar' => array(
      'name' => t('Feed from UNLV Calendar'),
      'base' => 'node_content',
      'description' => t('Nodes that hold UNLV calendar event feeds'),
      'has_title' => '1',
      'title_label' => t('UNLV Calendar Feed Title'),
      'help' => '',
    ),
  );
  return $items;
}
