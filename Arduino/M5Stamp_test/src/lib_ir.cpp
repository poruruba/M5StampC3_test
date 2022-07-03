#include <Arduino.h>
#include <IRsend.h>
#include <IRrecv.h>
#include <IRutils.h>

#include "lib_ir.h"

static IRsend irsend(IR_SEND_PORT);
static IRrecv irrecv(IR_RECV_PORT);
static decode_results results;

static IrReceiveCallback g_ir_receive_callback = NULL;

long ir_initialize(void)
{
  irsend.begin();
  irrecv.enableIRIn();

  return 0;
}

long ir_send(uint16_t address, uint16_t command)
{
  uint32_t value = irsend.encodeNEC(address, command);
  irsend.sendNEC(value);

  return 0;
}

long ir_send_value(uint32_t value)
{
  irsend.sendNEC(value);

  return 0;
}

void ir_set_callback(IrReceiveCallback callback)
{
  g_ir_receive_callback = callback;
}

void ir_receive_update(void)
{
  if (irrecv.decode(&results)) {
    if(results.overflow){
//      Serial.println("Overflow");
      irrecv.resume(); 
      return;
    }
    if( results.decode_type != decode_type_t::NEC || results.repeat ){
//      Serial.println("not supported");
      irrecv.resume(); 
      return;
    }

    if( g_ir_receive_callback != NULL )
      g_ir_receive_callback(results.address, results.command);

    irrecv.resume(); 
  }
}