<?php
/**
 * @file
 * unlv_events.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function unlv_events_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'rss_unlv_event_xml';
  $feeds_importer->config = array(
    'name' => 'RSS UNLV Event XML',
    'description' => 'An RSS feed importer for official UNLV calendar events',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => 'title',
          'xpathparser:4' => 'description',
          'xpathparser:1' => 'link',
          'xpathparser:2' => 'guid',
          'xpathparser:3' => 'event:eventdate',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:4' => 0,
          'xpathparser:1' => 0,
          'xpathparser:2' => 0,
          'xpathparser:3' => 0,
        ),
        'context' => '//item',
        'exp' => array(
          'errors' => 1,
          'debug' => array(
            'xpathparser:4' => 'xpathparser:4',
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:1' => 0,
            'xpathparser:2' => 0,
            'xpathparser:3' => 0,
          ),
        ),
        'allow_override' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => 0,
        'authorize' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'title',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'xpathparser:4',
            'target' => 'field_description',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'xpathparser:1',
            'target' => 'field_eventlink:url',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'xpathparser:2',
            'target' => 'guid',
            'unique' => 1,
          ),
          4 => array(
            'source' => 'xpathparser:3',
            'target' => 'field_eventdate:start',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '0',
        'input_format' => 'html_limited',
        'skip_hash_check' => 0,
        'bundle' => 'feed_item_unlv_calendar',
      ),
    ),
    'content_type' => 'feed_unlv_calendar',
    'update' => 0,
    'import_period' => '0',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['rss_unlv_event_xml'] = $feeds_importer;

  return $export;
}
