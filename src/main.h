void show_main(void);
void hide_main(void);
void handle_press_up(ClickRecognizerRef recognizer, void *context);
void handle_press_back(ClickRecognizerRef recognizer, void *context);
void handle_press_select(ClickRecognizerRef recognizer, void *context);
void handle_press_down(ClickRecognizerRef recognizer, void *context);
void click_config_provider(void *context);
void tick_handler(struct tm *tick_time, TimeUnits units_changed);
void start_counter(int seconds);

char m_counter[]="000";
char m_over[]="00:00";
static int16_t m_timer;
time_t m_timeout, m_elapsed;
int m_in_menu = true;
