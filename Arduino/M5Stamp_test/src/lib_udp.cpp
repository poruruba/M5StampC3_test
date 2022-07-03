#include <WiFi.h>
#include <WiFiUdp.h>
#include <ArduinoJson.h>
#include "lib_udp.h"
#include "lib_json.h"

static UdpReceiveCallback g_udp_receive_callback = NULL;
static WiFiUDP udp;

long udp_initialize(void)
{
  uint8_t result = udp.begin(UDP_RECV_PORT);

  return result == 1 ? 0 : -1;
}

long udp_send(const char *p_message)
{
  udp.beginPacket(UDP_HOST, UDP_SEND_PORT);
  udp.write((uint8_t*)p_message, strlen(p_message));
  udp.endPacket();

  return 0;
}

void udp_set_callback(UdpReceiveCallback callback)
{
  g_udp_receive_callback = callback;
}

void udp_update(void)
{
  int packetSize = udp.parsePacket();
  if( packetSize > 0 ){
    char *p_buffer = (char*)malloc(packetSize + 1);
    if( p_buffer == NULL )
      return;
    
    int len = udp.read(p_buffer, packetSize);
    if( len <= 0 ){
      free(p_buffer);
      return;
    }
    p_buffer[len] = '\0';

    if( g_udp_receive_callback != NULL )
      g_udp_receive_callback(p_buffer);
    
    free(p_buffer);
  }
}