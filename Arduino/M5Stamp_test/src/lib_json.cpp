#include <Arduino.h>
#include <ArduinoJson.h>

#include "lib_json.h"

StaticJsonDocument<JSON_CAPACITY> jsonDoc;

long json_deserialize(JsonDocument& json, const char *p_buffer)
{
  DeserializationError err = deserializeJson(json, p_buffer);
  if (err) {
    Serial.print(F("deserializeJson() failed with code "));
    Serial.println(err.f_str());

    return -1;
  }

  return 0;
}

long json_deserialize0(const char *p_buffer)
{
  return json_deserialize(jsonDoc, p_buffer);
}

long json_measure(JsonDocument& json)
{
  return measureJson(json);
}

long json_measure0(void)
{
  return json_measure(jsonDoc);
}

char *json_serialize(JsonDocument& json)
{
  long size = json_measure(json);
  if( size <= 0 )
    return NULL;
  char *p_buffer = (char*)malloc(size + 1);
  long len = serializeJson(json, p_buffer, size);
  if( len <= 0 ){
    free(p_buffer);
    return NULL;
  }
  p_buffer[len] = '\0';

  return p_buffer;
}

char *json_serialize0(void)
{
  return json_serialize(jsonDoc);
}