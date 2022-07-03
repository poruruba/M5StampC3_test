#ifndef _LIB_SPIFFS_H_
#define _LIB_SPIFFS_H_

#include <Arduino.h>

long spiffs_initialize(void);
String read_config_string(const char *fname);
long write_config_string(const char *fname, const char *text);
long read_config_json(const char *fname);
long write_config_json(const char *fname);

#endif
