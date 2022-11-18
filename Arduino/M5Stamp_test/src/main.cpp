#include <Arduino.h>
#if defined(ARDUINO_M5Stick_C)
#include <M5StickC.h>
#elif defined(ARDUINO_M5Stack_ATOM)
#include <M5Atom.h>
#endif

#include "lib_linebeacon.h"
#include "lib_ibeacon.h"
#include "lib_pixels.h"
#include "lib_wireless.h"
#include "lib_ir.h"
#include "lib_udp.h"
#include "lib_pir.h"
#include "lib_json.h"

const uint8_t LINE_BEACON_HWID[] = { 0x01, 0x02, 0x03, 0x04, 0x05 }; // LINE BEACON HWID

long ir_callback(uint16_t address, uint16_t command)
{
  Serial.printf("address=%d command=%d\n", address, command);
  return 0;
}

long pir_callback(bool detected)
{
  Serial.printf("detect=%d\n", detected);
  return 0;
}

long udp_callback(const char *p_message)
{
  Serial.println("udp callback called");
  Serial.println(p_message);
  return 0;
}

void setup() {
  // put your setup code here, to run once:
#if defined(ARDUINO_M5Stick_C)
  M5.begin(true, true, true);
#elif defined(ARDUINO_M5Stack_ATOM)
  M5.update(true, true, false);
#else
  Serial.begin(115200);
#endif

//  uint8_t uuid[16] = { 0 };
//  for( int i = 0 ; i < sizeof(uuid) ; i++ )
//    uuid[i] = i;
//  ibeacon_initialize(uuid, 0x1234, 0x5678, -56);
//  ibeacon_start();

  linebeacon_initialize(LINE_BEACON_HWID, -56);
  linebeacon_start();

  pixels_begin();
  pixels_setPixelColor(0, 0xff0000);

  wireless_connect();

  udp_initialize();
  udp_set_callback(udp_callback);

  ir_initialize();
  ir_set_callback(ir_callback);

  pir_initialize();
  pir_set_callback(pir_callback);

  Serial.println("setup finished");
}

void loop() {
  // put your main code here, to run repeatedly:
#if defined(ARDUINO_M5Stick_C)
  M5.update();
#elif defined(ARDUINO_M5Stack_ATOM)
  M5.update();
#endif

  pir_update();
  ir_receive_update();
  udp_update();
}
