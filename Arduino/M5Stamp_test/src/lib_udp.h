#ifndef _LIB_UDP_H_
#define _LIB_UDP_H_

#include <Arduino.h>

typedef long(*UdpReceiveCallback)(const char *p_message);

#define UDP_HOST  "[UDP通知先ホスト名］"
#define UDP_SEND_PORT 1401
#define UDP_RECV_PORT 1402

long udp_initialize(void);
long udp_send(const char *p_message);
void udp_set_callback(UdpReceiveCallback callback);
void udp_update(void);

#endif
