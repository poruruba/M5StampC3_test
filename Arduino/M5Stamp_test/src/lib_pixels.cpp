#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#include "lib_pixels.h"

static Adafruit_NeoPixel pixels(PIXELS_NUMPIXELS, PIXELS_PIN, NEO_GRB + NEO_KHZ800);
static uint32_t last_colors[PIXELS_NUMPIXELS] = { 0 };
static bool pixels_onoff = true;

long pixels_begin(void)
{
  pixels.begin();

  return 0;
}

long pixels_clear(void)
{
  pixels.clear();
  pixels.show();

  return 0;
}

long pixels_set_onoff(bool onoff)
{
  if( onoff ){
    for( int i = 0 ; i < PIXELS_NUMPIXELS ; i++ )
      pixels.setPixelColor(i, last_colors[i]);
  }else{
    for( int i = 0 ; i < PIXELS_NUMPIXELS ; i++ )
      last_colors[i] = pixels.getPixelColor(i);
      pixels.clear();
  }
  pixels.show();

  pixels_onoff = onoff;

  return 0;
}

bool pixels_get_onoff(void)
{
  return pixels_onoff;
}

long pixels_setPixelColor(uint16_t index, uint32_t color)
{
  pixels.setPixelColor(index, color);
  pixels.show();

  pixels_onoff = true;

  return 0;
}

uint32_t pixels_getPixelColor(uint16_t index)
{
  return pixels.getPixelColor(index);
}