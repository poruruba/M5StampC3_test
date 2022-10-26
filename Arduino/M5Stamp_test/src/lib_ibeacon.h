#ifndef _LIB_IBEACON_H_
#define _LIB_IBEACON_H_

#include <Arduino.h>

#if defined(ARDUINO_M5Stick_C)
#define IBEACON_DEVICE_NAME  "M5StickC"
#elif defined(ARDUINO_M5Stack_ATOM)
#define IBEACON_DEVICE_NAME  "M5Atom"
#elif defined(ARDUINO_ESP32C3_DEV)
#define IBEACON_DEVICE_NAME  "M5Stamp"
#endif

long ibeacon_initialize(const uint8_t *p_uuid, uint16_t major, uint16_t minor, uint8_t tx);
long ibeacon_start(void);
long libeacon_stop(void);

#endif
