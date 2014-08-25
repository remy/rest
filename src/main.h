void show_main(void);
void hide_main(void);
void handle_press_up(ClickRecognizerRef recognizer, void *context);
void handle_press_back(ClickRecognizerRef recognizer, void *context);
void handle_press_select(ClickRecognizerRef recognizer, void *context);
void handle_press_down(ClickRecognizerRef recognizer, void *context);
void click_config_provider(void *context);
void tick_handler(struct tm *tick_time, TimeUnits units_changed);
void start_counter(int seconds);

typedef struct mytimer_struct {
    int16_t min;
    int16_t sec;
	int16_t hour;
} timer;

char m_counter[]="000";
static timer m_timer;
int m_in_menu = true;