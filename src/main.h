#define SETTINGS_KEY 0

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

typedef struct persist{
  uint8_t up;
  uint8_t select;
  uint8_t down;
  bool theme;
}__attribute__((__packed__)) persist;

persist settings = {
  .up = 120,
  .select = 90,
  .down = 60,
  .theme = 0
};

char m_up[]="000";
char m_select[]="000";
char m_down[]="000";
