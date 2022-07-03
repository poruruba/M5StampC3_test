#ifndef _LIB_PIR_H_
#define _LIB_PIR_H_

#include <Arduino.h>

#if defined(ARDUINO_M5Stick_C)
#define PIR_PORT  36
#elif defined(ARDUINO_M5Stack_ATOM)
#define PIR_PORT  21
#elif defined(ARDUINO_ESP32C3_DEV)
#define PIR_PORT  18
#endif

typedef long(*PirDetectCallback)(bool);

void pir_initialize(void);
void pir_set_callback(PirDetectCallback callback);
void pir_update(void);

#endif
