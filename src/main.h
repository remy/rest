#define UP_KEY 0
#define SELECT_KEY 1
#define DOWN_KEY 2
#define THEME_KEY 3

void init(void);
void deinit(void);
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

char m_up[]="000";
char m_select[]="000";
char m_down[]="000";

persist settings = {
  .up = 120,
  .select = 90,
  .down = 60,
  .theme = 0
};