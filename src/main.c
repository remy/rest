#include <pebble.h>
#include "main.h"

// BEGIN AUTO-GENERATED UI CODE; DO NOT MODIFY
static Window *s_window;
static GBitmap *s_res_image_go;
static GFont s_res_roboto_bold_subset_49;
static GFont s_res_bitham_34_medium_numbers;
static GFont s_res_roboto_condensed_21;
static ActionBarLayer *s_actionbarlayer_main;
static TextLayer *s_textlayer_120;
static TextLayer *s_textlayer_60;
static TextLayer *s_textlayer_90;
static TextLayer *s_textlayer_count;
static TextLayer *s_textlayer_over;

static void initialise_ui(void) {
  s_window = window_create();
  window_set_background_color(s_window, GColorBlack);
  window_set_fullscreen(s_window, false);
  
  s_res_image_go = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_GO);
  s_res_roboto_bold_subset_49 = fonts_get_system_font(FONT_KEY_ROBOTO_BOLD_SUBSET_49);
  s_res_bitham_34_medium_numbers = fonts_get_system_font(FONT_KEY_BITHAM_34_MEDIUM_NUMBERS);
  s_res_roboto_condensed_21 = fonts_get_system_font(FONT_KEY_ROBOTO_CONDENSED_21);
  // s_actionbarlayer_main
  s_actionbarlayer_main = action_bar_layer_create();
  action_bar_layer_add_to_window(s_actionbarlayer_main, s_window);
  action_bar_layer_set_background_color(s_actionbarlayer_main, GColorWhite);
  action_bar_layer_set_icon(s_actionbarlayer_main, BUTTON_ID_UP, s_res_image_go);
  action_bar_layer_set_icon(s_actionbarlayer_main, BUTTON_ID_SELECT, s_res_image_go);
  action_bar_layer_set_icon(s_actionbarlayer_main, BUTTON_ID_DOWN, s_res_image_go);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_actionbarlayer_main);
  
  // s_textlayer_120
  s_textlayer_120 = text_layer_create(GRect(15, 4, 100, 42));
  text_layer_set_background_color(s_textlayer_120, GColorBlack);
  text_layer_set_text_color(s_textlayer_120, GColorWhite);
  text_layer_set_text(s_textlayer_120, "120");
  text_layer_set_text_alignment(s_textlayer_120, GTextAlignmentRight);
  text_layer_set_font(s_textlayer_120, s_res_bitham_34_medium_numbers);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_textlayer_120);
  
  // s_textlayer_60
  s_textlayer_60 = text_layer_create(GRect(15, 102, 100, 42));
  text_layer_set_background_color(s_textlayer_60, GColorBlack);
  text_layer_set_text_color(s_textlayer_60, GColorWhite);
  text_layer_set_text(s_textlayer_60, "60");
  text_layer_set_text_alignment(s_textlayer_60, GTextAlignmentRight);
  text_layer_set_font(s_textlayer_60, s_res_bitham_34_medium_numbers);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_textlayer_60);
  
  // s_textlayer_90
  s_textlayer_90 = text_layer_create(GRect(15, 54, 100, 34));
  text_layer_set_background_color(s_textlayer_90, GColorBlack);
  text_layer_set_text_color(s_textlayer_90, GColorWhite);
  text_layer_set_text(s_textlayer_90, "90");
  text_layer_set_text_alignment(s_textlayer_90, GTextAlignmentRight);
  text_layer_set_font(s_textlayer_90, s_res_bitham_34_medium_numbers);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_textlayer_90);
  
  // s_textlayer_count
  s_textlayer_count = text_layer_create(GRect(20, 36, 104, 60));
  text_layer_set_background_color(s_textlayer_count, GColorBlack);
  text_layer_set_text_color(s_textlayer_count, GColorWhite);
  text_layer_set_text(s_textlayer_count, "0");
  text_layer_set_text_alignment(s_textlayer_count, GTextAlignmentCenter);
  text_layer_set_font(s_textlayer_count, s_res_roboto_bold_subset_49);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_textlayer_count);
  
  // s_textlayer_over
  s_textlayer_over = text_layer_create(GRect(61, 91, 80, 28));
  text_layer_set_background_color(s_textlayer_over, GColorBlack);
  text_layer_set_text_color(s_textlayer_over, GColorWhite);
  text_layer_set_text(s_textlayer_over, "0:00");
  text_layer_set_font(s_textlayer_over, s_res_roboto_condensed_21);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_textlayer_over);
}

static void destroy_ui(void) {
  window_destroy(s_window);
  action_bar_layer_destroy(s_actionbarlayer_main);
  text_layer_destroy(s_textlayer_120);
  text_layer_destroy(s_textlayer_60);
  text_layer_destroy(s_textlayer_90);
  text_layer_destroy(s_textlayer_count);
  text_layer_destroy(s_textlayer_over);
  gbitmap_destroy(s_res_image_go);
}
// END AUTO-GENERATED UI CODE

void tick_handler(struct tm *tick_time, TimeUnits units_changed){
  if (m_timeout != 0) {

    time_t now = time(NULL) - m_timeout;
    struct tm *t = localtime(&now);

  //  m_elapsed = time_ms(NULL, NULL) - m_timeout;
//    localtime(time_ms() - m_timeout);
    strftime(m_over, sizeof(m_over), "%m:%S", t);
//    snprintf(m_counter, sizeof(m_over), "%d", m_timeout);
    text_layer_set_text(s_textlayer_over, m_over);
    return;  
  }
  
  m_timer--;
  
  if (m_timer == 0) {
    vibes_long_pulse();
    text_layer_set_text(s_textlayer_count, "0");
    m_timeout = time_ms(NULL, NULL);
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
  
  vibes_short_pulse();
  
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
  layer_set_hidden(text_layer_get_layer(s_textlayer_count), false);
  
  tick_timer_service_subscribe(SECOND_UNIT, tick_handler);
}

void handle_press_down(ClickRecognizerRef recognizer, void *context) {
  start_counter(6);
}

void handle_press_select(ClickRecognizerRef recognizer, void *context) {
  start_counter(9);
}

void handle_press_up(ClickRecognizerRef recognizer, void *context) {
  start_counter(12);
}

void handle_press_back(ClickRecognizerRef recognizer, void *context) {
  if (m_in_menu) {
    window_stack_pop(true);
  } else {
    tick_timer_service_unsubscribe();
    
    vibes_short_pulse();
    
    // hide counter
    layer_set_hidden(text_layer_get_layer(s_textlayer_count), true);
    layer_set_hidden(text_layer_get_layer(s_textlayer_over), true);
    
    // show all others
    layer_set_hidden(text_layer_get_layer(s_textlayer_60), false);
    layer_set_hidden(text_layer_get_layer(s_textlayer_90), false);
    layer_set_hidden(text_layer_get_layer(s_textlayer_120), false);
    layer_set_hidden(action_bar_layer_get_layer(s_actionbarlayer_main), false);
  
    m_in_menu = true;
  }
}

void click_config_provider(void *context) {
  window_single_click_subscribe(BUTTON_ID_DOWN, (ClickHandler) handle_press_down);
  window_single_click_subscribe(BUTTON_ID_UP, (ClickHandler) handle_press_up);
  window_single_click_subscribe(BUTTON_ID_BACK, (ClickHandler) handle_press_back);
  window_single_click_subscribe(BUTTON_ID_SELECT, (ClickHandler) handle_press_select);
}

static void handle_window_unload(Window* window) {
  destroy_ui();
}

static void handle_window_load(Window* window) {
  // Set the click config provider:
  action_bar_layer_set_click_config_provider(s_actionbarlayer_main, click_config_provider);
  layer_set_hidden(text_layer_get_layer(s_textlayer_count), true);
}

void hide_main(void) {
  window_stack_remove(s_window, true);
}

void show_main(void) {
  initialise_ui();
  window_set_window_handlers(s_window, (WindowHandlers) {
    .load = handle_window_load,
    .unload = handle_window_unload,
  });
  window_stack_push(s_window, true);
}

int main(void) {
  show_main();
  app_event_loop();
  hide_main();
}
