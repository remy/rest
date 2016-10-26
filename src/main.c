#include <pebble.h>
#include "persist.h"
#include "main.h"

// BEGIN AUTO-GENERATED UI CODE; DO NOT MODIFY
static Window *s_window;
static GBitmap *s_res_image_go;
static GFont s_res_bitham_34_medium_numbers;
static GFont s_res_roboto_bold_subset_49;
static GFont s_res_roboto_condensed_21;
static ActionBarLayer *s_actionbarlayer_main;
static TextLayer *s_textlayer_120;
static TextLayer *s_textlayer_60;
static TextLayer *s_textlayer_90;
static TextLayer *s_textlayer_count;
static TextLayer *s_textlayer_over;
static TextLayer *s_textlayer_hr;

#ifdef PBL_SDK_3
static StatusBarLayer *s_status_bar;
#endif

#ifndef STATUS_BAR_LAYER_HEIGHT
#define STATUS_BAR_LAYER_HEIGHT 0
#endif

#ifndef PBL_PLATFORM_APLITE
#define MENU_TOP 12
#define MENU_MIDDLE 62
#define MENU_BOTTOM 112
#else
#define MENU_TOP 6
#define MENU_MIDDLE 54
#define MENU_BOTTOM 102
#endif


static void initialise_ui(void) {
  s_window = window_create();
  window_set_background_color(s_window, GColorBlack);
  #ifndef PBL_SDK_3
    window_set_fullscreen(s_window, false);
  #else
    // Set up the status bar last to ensure it is on top of other Layers
    s_status_bar = status_bar_layer_create();
    layer_add_child(window_get_root_layer(s_window), status_bar_layer_get_layer(s_status_bar));
  #endif

  s_res_image_go = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_GO);
  s_res_bitham_34_medium_numbers = fonts_get_system_font(FONT_KEY_BITHAM_34_MEDIUM_NUMBERS);
  s_res_roboto_bold_subset_49 = fonts_get_system_font(FONT_KEY_ROBOTO_BOLD_SUBSET_49);
  s_res_roboto_condensed_21 = fonts_get_system_font(FONT_KEY_ROBOTO_CONDENSED_21);

  // s_actionbarlayer_main
  s_actionbarlayer_main = action_bar_layer_create();
  action_bar_layer_add_to_window(s_actionbarlayer_main, s_window);
  action_bar_layer_set_background_color(s_actionbarlayer_main, GColorWhite);
  action_bar_layer_set_icon(s_actionbarlayer_main, BUTTON_ID_UP, s_res_image_go);
  action_bar_layer_set_icon(s_actionbarlayer_main, BUTTON_ID_SELECT, s_res_image_go);
  action_bar_layer_set_icon(s_actionbarlayer_main, BUTTON_ID_DOWN, s_res_image_go);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_actionbarlayer_main);

  // s_textlayer_120 (top one)
  s_textlayer_120 = text_layer_create(GRect(0, MENU_TOP, 134 - ACTION_BAR_WIDTH, 42));
  text_layer_set_background_color(s_textlayer_120, GColorBlack);
  text_layer_set_text_color(s_textlayer_120, GColorWhite);
  text_layer_set_text(s_textlayer_120, "120");
  text_layer_set_text_alignment(s_textlayer_120, GTextAlignmentRight);
  text_layer_set_font(s_textlayer_120, s_res_bitham_34_medium_numbers);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_textlayer_120);

  // s_textlayer_90 (middle)
  s_textlayer_90 = text_layer_create(GRect(0, MENU_MIDDLE, 134 - ACTION_BAR_WIDTH, 34));
  text_layer_set_background_color(s_textlayer_90, GColorBlack);
  text_layer_set_text_color(s_textlayer_90, GColorWhite);
  text_layer_set_text(s_textlayer_90, "90");
  text_layer_set_text_alignment(s_textlayer_90, GTextAlignmentRight);
  text_layer_set_font(s_textlayer_90, s_res_bitham_34_medium_numbers);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_textlayer_90);

  // s_textlayer_60 (bottom)
  s_textlayer_60 = text_layer_create(GRect(0, MENU_BOTTOM, 134 - ACTION_BAR_WIDTH, 42));
  text_layer_set_background_color(s_textlayer_60, GColorBlack);
  text_layer_set_text_color(s_textlayer_60, GColorWhite);
  text_layer_set_text(s_textlayer_60, "60");
  text_layer_set_text_alignment(s_textlayer_60, GTextAlignmentRight);
  text_layer_set_font(s_textlayer_60, s_res_bitham_34_medium_numbers);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_textlayer_60);

  // s_textlayer_count
  s_textlayer_count = text_layer_create(GRect(20, STATUS_BAR_LAYER_HEIGHT + 20, 104, 60));
  text_layer_set_background_color(s_textlayer_count, GColorClear);
  text_layer_set_text_color(s_textlayer_count, GColorWhite);
  text_layer_set_text(s_textlayer_count, "0");
  text_layer_set_text_alignment(s_textlayer_count, GTextAlignmentCenter);
  text_layer_set_font(s_textlayer_count, s_res_roboto_bold_subset_49);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_textlayer_count);

  // s_textlayer_over
  s_textlayer_over = text_layer_create(GRect(60, STATUS_BAR_LAYER_HEIGHT + 75, 80, 47));
  text_layer_set_background_color(s_textlayer_over, GColorClear);
  text_layer_set_text_color(s_textlayer_over, GColorWhite);
  text_layer_set_text(s_textlayer_over, "0:00");
  text_layer_set_font(s_textlayer_over, s_res_roboto_condensed_21);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_textlayer_over);

   // s_textlayer_hr
   s_textlayer_hr = text_layer_create(GRect(39, PBL_DISPLAY_HEIGHT - 25, 100, 25));
   text_layer_set_background_color(s_textlayer_hr, GColorBlack);
   text_layer_set_text_color(s_textlayer_hr, GColorWhite);
   text_layer_set_text(s_textlayer_hr, "");
   text_layer_set_text_alignment(s_textlayer_hr, GTextAlignmentRight);
   text_layer_set_font(s_textlayer_hr, s_res_roboto_condensed_21);
   layer_add_child(window_get_root_layer(s_window), (Layer *)s_textlayer_hr);
 }

static void destroy_ui(void) {
  window_destroy(s_window);
  action_bar_layer_destroy(s_actionbarlayer_main);
  text_layer_destroy(s_textlayer_120);
  text_layer_destroy(s_textlayer_60);
  text_layer_destroy(s_textlayer_90);
  text_layer_destroy(s_textlayer_count);
  text_layer_destroy(s_textlayer_over);
  text_layer_destroy(s_textlayer_hr);
  gbitmap_destroy(s_res_image_go);
}
// END AUTO-GENERATED UI CODE

static uint16_t s_curr_hr = 0;

void tick_handler(struct tm *tick_time, TimeUnits units_changed){
  static char s_hrm_buffer[8];

  if (s_curr_hr > 0) {
    snprintf(s_hrm_buffer, sizeof(s_hrm_buffer), "%lu BPM", (uint32_t) s_curr_hr);
    text_layer_set_text(s_textlayer_hr, s_hrm_buffer);
  }

  if (m_timeout != 0) {
    // out of time
    time_t now = time(NULL) - m_timeout;
    struct tm *t = localtime(&now);
    strftime(m_over, sizeof(m_over), "%M:%S", t);

    // hack because I couldn't work out how to get single
    // character minutes
    if (m_over[0] == '0') {
      for (int i = 0; i < 4; ++i) {
        m_over[i] = m_over[i+1];
      }
      m_over[4] = '\0';
    }
    text_layer_set_text(s_textlayer_over, m_over);
    return;
  }

  m_timer--;

  if (m_timer == 0) {
    vibes_long_pulse();
    #ifdef PBL_COLOR
      window_set_background_color(s_window, GColorDarkCandyAppleRed);
      text_layer_set_text_color(s_textlayer_count, GColorWhite);
      text_layer_set_text_color(s_textlayer_over, GColorWhite);
      status_bar_layer_set_colors(s_status_bar, GColorDarkCandyAppleRed, GColorWhite);
    #endif
    text_layer_set_text(s_textlayer_count, "0");
    m_timeout = time(NULL);
    layer_set_hidden(text_layer_get_layer(s_textlayer_over), false);
    // tick_timer_service_unsubscribe();
    return;
  }

  snprintf(m_counter, sizeof(m_counter), "%d", m_timer);
  text_layer_set_text(s_textlayer_count, m_counter);
}

void start_counter(int seconds) {
  m_timer = seconds;
  m_timeout = 0;
  m_in_menu = false;

  // set the initial state - before it's shown
  snprintf(m_counter, sizeof(m_counter), "%d", m_timer);
  text_layer_set_text(s_textlayer_count, m_counter);

  snprintf(m_over, sizeof(m_over), "0:00");
  text_layer_set_text(s_textlayer_over, m_over);

  // hide all others
  layer_set_hidden(text_layer_get_layer(s_textlayer_60), true);
  layer_set_hidden(text_layer_get_layer(s_textlayer_90), true);
  layer_set_hidden(text_layer_get_layer(s_textlayer_120), true);
  layer_set_hidden(action_bar_layer_get_layer(s_actionbarlayer_main), true);

  layer_set_hidden(text_layer_get_layer(s_textlayer_over), true);

  // show counter
  layer_set_hidden(text_layer_get_layer(s_textlayer_hr), false);
  layer_set_hidden(text_layer_get_layer(s_textlayer_count), false);


  #ifdef PBL_COLOR
    window_set_background_color(s_window, GColorDarkGreen);
    text_layer_set_text_color(s_textlayer_count, GColorWhite);
    status_bar_layer_set_colors(s_status_bar, GColorDarkGreen, GColorWhite);
  #endif

  tick_timer_service_subscribe(SECOND_UNIT, tick_handler);
}

void handle_press_down(ClickRecognizerRef recognizer, void *context) {
  start_counter(settings.down);
}

void handle_press_select(ClickRecognizerRef recognizer, void *context) {
  start_counter(settings.select);
}

void handle_press_up(ClickRecognizerRef recognizer, void *context) {
  start_counter(settings.up);
}

void handle_press_back(ClickRecognizerRef recognizer, void *context) {
  if (m_in_menu) {
    window_stack_pop(true);
  } else {
    tick_timer_service_unsubscribe();

    // hide counter
    layer_set_hidden(text_layer_get_layer(s_textlayer_count), true);
    layer_set_hidden(text_layer_get_layer(s_textlayer_over), true);
    layer_set_hidden(text_layer_get_layer(s_textlayer_hr), true);

    // show all others
    layer_set_hidden(text_layer_get_layer(s_textlayer_60), false);
    layer_set_hidden(text_layer_get_layer(s_textlayer_90), false);
    layer_set_hidden(text_layer_get_layer(s_textlayer_120), false);
    layer_set_hidden(action_bar_layer_get_layer(s_actionbarlayer_main), false);

    window_set_background_color(s_window, GColorBlack);

    #ifdef PBL_COLOR
      status_bar_layer_set_colors(s_status_bar, GColorBlack, GColorWhite);
    #endif

    m_in_menu = true;
  }
}

void click_config_provider(void *context) {
  window_single_click_subscribe(BUTTON_ID_DOWN, (ClickHandler) handle_press_down);
  window_single_click_subscribe(BUTTON_ID_UP, (ClickHandler) handle_press_up);
  window_single_click_subscribe(BUTTON_ID_BACK, (ClickHandler) handle_press_back);
  window_single_click_subscribe(BUTTON_ID_SELECT, (ClickHandler) handle_press_select);
}

void refresh_settings() {
  layer_set_hidden(text_layer_get_layer(s_textlayer_count), true);
  layer_set_hidden(text_layer_get_layer(s_textlayer_over), true);
  layer_set_hidden(text_layer_get_layer(s_textlayer_hr), true);

  snprintf(m_up, sizeof(m_up), "%d", settings.up);
  snprintf(m_select, sizeof(m_select), "%d", settings.select);
  snprintf(m_down, sizeof(m_down), "%d", settings.down);

  text_layer_set_text(s_textlayer_120, m_up);
  text_layer_set_text(s_textlayer_90, m_select);
  text_layer_set_text(s_textlayer_60, m_down);
}

void process_tuple(Tuple *t) {
  int key = t->key;
  int value = t->value->int32;

  APP_LOG(APP_LOG_LEVEL_DEBUG, "Loaded key num: %d with value %d", key, value);

  switch (key) {
    case UP_KEY:
      settings.up = value;
      break;
    case SELECT_KEY:
      settings.select = value;
      break;
    case DOWN_KEY:
      settings.down = value;
      break;
    case THEME_KEY:
      settings.theme = value;
      break;
  }

  refresh_settings();
}

static void prv_on_health_data(HealthEventType type, void *context) {
  if (type == HealthEventHeartRateUpdate) {
    s_curr_hr = (int16_t) health_service_peek_current_value(HealthMetricHeartRateBPM);
  }
}

void in_received_handler(DictionaryIterator *iter, void *context) {

  // Check for fields you expect to receive
  // Tuple *text_tuple = dict_find(iter, UP_KEY);

  // (void)context;

  Tuple *t = dict_read_first(iter);
  if (t) {
    process_tuple(t);
  }

  while(t != NULL) {
    t = dict_read_next(iter);
    if(t) {
      process_tuple(t);
    }
  }
}

static void handle_window_unload(Window* window) {
  destroy_ui();
  bool ok = health_service_set_heart_rate_sample_period(0);
}

static void handle_window_load(Window* window) {
  // Set the click config provider:
  action_bar_layer_set_click_config_provider(s_actionbarlayer_main, click_config_provider);
  refresh_settings();
}

void deinit(void) {
  write_persist(&settings);
  window_stack_remove(s_window, true);
}

void init(void) {
  initialise_ui();

  // nice fonts for different systems
  // #ifndef PBL_PLATFORM_APLITE
    // s_res_roboto_bold_subset_49 = fonts_get_system_font(FONT_KEY_LECO_42_NUMBERS);
    // s_res_roboto_condensed_21 = fonts_get_system_font(FONT_KEY_LECO_32_BOLD_NUMBERS);

    // text_layer_set_font(s_textlayer_count, s_res_roboto_bold_subset_49);
    // text_layer_set_text(s_textlayer_over, "0:00");
    // text_layer_set_font(s_textlayer_over, s_res_roboto_condensed_21);
  // #endif

  window_set_window_handlers(s_window, (WindowHandlers) {
    .load = handle_window_load,
    .unload = handle_window_unload,
  });

  app_message_register_inbox_received(in_received_handler);
  app_message_open(1028, 512);

  APP_LOG(APP_LOG_LEVEL_INFO, "migrate_persist");
  migrate_persist(&settings);
  window_stack_push(s_window, true);

   #if PBL_API_EXISTS(health_service_set_heart_rate_sample_period)
     health_service_set_heart_rate_sample_period(1);
   #endif

   // #if defined(PBL_HEALTH)
     // Subscribe and init the health handler
     s_curr_hr = (int16_t) health_service_peek_current_value(HealthMetricHeartRateBPM);
     APP_LOG(APP_LOG_LEVEL_INFO, "hr: %lu", (uint32_t) s_curr_hr);
     health_service_events_subscribe(prv_on_health_data, NULL);
   // #endif
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}
