#include <Arduino.h>
#include "lib_pir.h"

static PirDetectCallback g_callback;
static int last_pir = 0;

void pir_initialize(void){
  pinMode(PIR_PORT, INPUT_PULLUP);
}

void pir_set_callback(PirDetectCallback callback)
{
  g_callback = callback;
}

void pir_update(void)
{
  int pir = digitalRead(PIR_PORT);

  if( pir != last_pir ){
    if( g_callback != NULL )
      g_callback( pir ? true : false);
    last_pir = pir;
  }
}