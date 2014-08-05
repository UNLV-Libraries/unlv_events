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
    'description' => 'An RSS feed importer used to import official UNLV events',
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
          'xpathparser:1' => 'description',
          'xpathparser:2' => 'link',
          'xpathparser:3' => 'guid',
          'xpathparser:4' => 'event:eventdate',
          'xpathparser:5' => 'event:eventdate2',
          'xpathparser:11' => 'event:eventdate',
          'xpathparser:6' => 'event:buildinglink',
          'xpathparser:7' => 'event:buildingname',
          'xpathparser:8' => 'event:eventlocation',
          'xpathparser:9' => 'event:eventcost',
          'xpathparser:10' => 'event:eventsponsor',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:1' => 0,
          'xpathparser:2' => 0,
          'xpathparser:3' => 0,
          'xpathparser:4' => 0,
          'xpathparser:5' => 0,
          'xpathparser:11' => 0,
          'xpathparser:6' => 0,
          'xpathparser:7' => 0,
          'xpathparser:8' => 0,
          'xpathparser:9' => 0,
          'xpathparser:10' => 0,
        ),
        'context' => '//item',
        'exp' => array(
          'errors' => 0,
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:1' => 0,
            'xpathparser:2' => 0,
            'xpathparser:3' => 0,
            'xpathparser:4' => 0,
            'xpathparser:5' => 0,
            'xpathparser:11' => 0,
            'xpathparser:6' => 0,
            'xpathparser:7' => 0,
            'xpathparser:8' => 0,
            'xpathparser:9' => 0,
            'xpathparser:10' => 0,
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
            'source' => 'xpathparser:1',
            'target' => 'field_unlv_eventdescription',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'xpathparser:2',
            'target' => 'field_unlv_eventlink:url',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'xpathparser:3',
            'target' => 'guid',
            'unique' => 1,
          ),
          4 => array(
            'source' => 'xpathparser:4',
            'target' => 'field_unlv_eventdate:start',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'xpathparser:5',
            'target' => 'field_unlv_eventdate:end',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'xpathparser:11',
            'target' => 'field_unlv_eventdate_text',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'xpathparser:6',
            'target' => 'field_unlv_eventdate_buildlink:url',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'xpathparser:7',
            'target' => 'field_unlv_eventdate_buildname',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'xpathparser:8',
            'target' => 'field_unlv_eventdate_location',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'xpathparser:9',
            'target' => 'field_unlv_eventdate_cost',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'xpathparser:10',
            'target' => 'field_unlv_eventdate_sponsor',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '0',
        'input_format' => 'html_limited',
        'skip_hash_check' => 0,
        'bundle' => 'feed_unlv_calendar_item',
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
