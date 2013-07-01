#ifndef _SXHKD_H
#define _SXHKD_H

#include <xcb/xcb_keysyms.h>
#include <stdio.h>
#include <stdbool.h>
#include "types.h"
#include "helpers.h"

#define CONFIG_HOME_ENV  "XDG_CONFIG_HOME"
#define SXHKD_SHELL_ENV  "SXHKD_SHELL"
#define SHELL_ENV        "SHELL"
#define CONFIG_PATH      "sxhkd/sxhkdrc"
#define TIMEOUT          3

xcb_connection_t *dpy;
xcb_window_t root;
xcb_key_symbols_t *symbols;

char *shell;
char config_file[MAXLEN];
char *config_path;
char **extra_confs;
int num_extra_confs;
int redir_fd;
int timeout;

hotkey_t *hotkeys, *hotkeys_tail;
bool running, reload, bell, chained;

uint16_t num_lock;
uint16_t caps_lock;
uint16_t scroll_lock;

void hold(int);
void setup(void);
void cleanup(void);
void reload_cmd(void);
void key_button_event(xcb_generic_event_t *, uint8_t);
void motion_notify(xcb_generic_event_t *, uint8_t);

#endif
