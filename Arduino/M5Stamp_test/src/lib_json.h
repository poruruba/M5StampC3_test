#ifndef _LIB_JSON_H_
#define _LIB_JSON_H_

#include <Arduino.h>
#include <ArduinoJson.h>

#define JSON_CAPACITY 256

extern StaticJsonDocument<JSON_CAPACITY> jsonDoc;

long json_deserialize(JsonDocument& json, const char *p_buffer);
long json_measure(JsonDocument& json);
char *json_serialize(JsonDocument& json);

long json_deserialize0(const char *p_buffer);
long json_measure0(void);
char *json_serialize0(void);

#endif
