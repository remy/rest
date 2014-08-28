#include <pebble.h>
#include "persist.h"

static void clear_persist(void) {
  // persist_delete all your keys.
  if (persist_exists(SETTINGS_KEY)) {
    persist_delete(SETTINGS_KEY);
    APP_LOG(APP_LOG_LEVEL_INFO, "Deleted old persistent store");
  }
}

static void read_v1_persist(persist* settings) {
  // Read the old v1 format into some appropriate structure.
  if (persist_exists(SETTINGS_KEY)) {
    int persistvalue = persist_read_data(SETTINGS_KEY, settings, sizeof(*settings));
    APP_LOG(APP_LOG_LEVEL_INFO, "Initialised. %d bytes", persistvalue);
  } else {
    APP_LOG(APP_LOG_LEVEL_INFO, "No settings found - leaving defaults in place");
  }
}

void write_persist(persist* settings) {
  APP_LOG(APP_LOG_LEVEL_INFO, "Writing settings %d bytes", sizeof(*settings));
  persist_write_data(SETTINGS_KEY, settings, sizeof(*settings));
}

void migrate_persist(persist* settings) {
  uint32_t version = persist_read_int(SETTINGS_VERSION_KEY); // defaults to 0 if key is missing.

  if(version > CURRENT_SETTINGS_VERSION) {
    // This is more recent than what we expect; we can't know what happened, so delete it
    APP_LOG(APP_LOG_LEVEL_INFO, "setting version does not match...clearing");
    clear_persist();
  } else if(version == 1) { // v1 - more to be added as required
    APP_LOG(APP_LOG_LEVEL_INFO, "restoring v1");
    read_v1_persist(settings);
  } else {
    APP_LOG(APP_LOG_LEVEL_INFO, "version lookup fail: %d", (int)version);
    clear_persist();
  }

  persist_write_int(SETTINGS_VERSION_KEY, CURRENT_SETTINGS_VERSION);
}