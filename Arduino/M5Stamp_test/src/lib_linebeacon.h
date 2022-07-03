#ifndef _LIB_LINEBEACON_H_
#define _LIB_LINEBEACON_H_

#include <Arduino.h>

#if defined(ARDUINO_M5Stick_C)
#define LINEBEACON_DEVICE_NAME  "M5StickC"
#define LINEBEACON_DEFAULT_DEVICE_MESSAGE LINEBEACON_DEVICE_NAME
#elif defined(ARDUINO_M5Stack_ATOM)
#define LINEBEACON_DEVICE_NAME  "M5Atom"
#define LINEBEACON_DEFAULT_DEVICE_MESSAGE LINEBEACON_DEVICE_NAME
#elif defined(ARDUINO_ESP32C3_DEV)
#define LINEBEACON_DEVICE_NAME  "M5Stamp"
#define LINEBEACON_DEFAULT_DEVICE_MESSAGE LINEBEACON_DEVICE_NAME
#endif

long linebeacon_initialize(const uint8_t *p_hwid);
long linebeacon_set_device_message(const char *p_device_message);
long linebeacon_start(void);
long linebeacon_stop(void);

#endif
