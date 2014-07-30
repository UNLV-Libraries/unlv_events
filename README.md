# UNLV Events Calendar  
Contains content types and views to import and display UNLV Events  

## Module Version Dependencies  

 - calendar **7.x-3.4**
 - ctools **7.x-1.3**
 - date **7.x-2.7**
 - features **7.x-1.0**
 - views **7.x-3.5**  

 These are the module version that this feature was created with. Newer module versions of the above might work, but your milage may vary.

## SWAG  

### Content Types  
 - **Feed from UNLV Calendar** - *feed_unlv_calendar*
 > Node type that holds the UNLV calendar event feed location *(URL)*
 
 - **Feed Item from UNLV Calendar** - *feed_unlv_calendar_item*
 > Node type that holds the actual events from UNLV calendar event feeds

### Feeds importers
 - **RSS UNLV Event XML** - *rss_unlv_event_xml*
 > An RSS feed importer used to import official UNLV events

### Views
 - **Calendar** - *calendar_unlv_events*
 > A calendar view that provides a calendar of events that contains the content from the first of the above content types *(feed_unlv_calendar_item)*. By default is provides different calendar display views at:
  - `/events` *(month view)*
  - `/events/week`
  - `/events`