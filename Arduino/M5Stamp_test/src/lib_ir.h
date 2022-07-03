#ifndef _LIB_IR_H_
#define _LIB_IR_H_

#include <Arduino.h>

#if defined(ARDUINO_M5Stick_C)
#define IR_SEND_PORT 32
#define IR_RECV_PORT 33
#elif defined(ARDUINO_M5Stack_ATOM)
#define IR_SEND_PORT 26
#define IR_RECV_PORT 32
#elif defined(ARDUINO_ESP32C3_DEV)
#define IR_SEND_PORT 1
#define IR_RECV_PORT 0
#endif

typedef long(*IrReceiveCallback)(uint16_t address, uint16_t command);

long ir_initialize(void);
long ir_send(uint16_t address, uint16_t command);
long ir_send_value(uint32_t value);
void ir_set_callback(IrReceiveCallback callback);
void ir_receive_update(void);

#endif
