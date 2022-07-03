#ifndef _LIB_PIXELS_H_
#define _LIB_PIXELS_H_

#include <Arduino.h>

#if defined(ARDUINO_M5Stick_C)
#define PIXELS_NUMPIXELS  1
#define PIXELS_PIN  0
#elif defined(ARDUINO_M5Stack_ATOM)
#define PIXELS_NUMPIXELS  1
#define PIXELS_PIN  27
#elif defined(ARDUINO_ESP32C3_DEV)
#define PIXELS_NUMPIXELS  1
#define PIXELS_PIN  2
#endif

long pixels_begin(void);
long pixels_clear(void);
long pixels_set_onoff(bool onoff);
bool pixels_get_onoff(void);
long pixels_setPixelColor(uint16_t index, uint32_t color);
uint32_t pixels_getPixelColor(uint16_t index);

#endif
