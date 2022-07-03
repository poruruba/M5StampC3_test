#include <Arduino.h>
#include <SPIFFS.h>

#include "lib_json.h"

long spiffs_initialize(void)
{
  SPIFFS.begin();

  return 0;
}

String read_config_string(const char *fname)
{
  File fp = SPIFFS.open(fname, FILE_READ);
  if( !fp )
    return String("");

  String text = fp.readString();
  fp.close();

  return text;
}

long write_config_string(const char *fname, const char *text)
{
  File fp = SPIFFS.open(fname, FILE_WRITE);
  if( !fp )
    return -1;

  long ret = fp.write((uint8_t*)text, strlen(text));
  fp.close();
  if( ret != strlen(text) )
    return -1;

  return 0;
}

long read_config_json(const char *fname)
{
  File fp = SPIFFS.open(fname, FILE_READ);
  if( !fp )
    return -1;

  String text = fp.readString();
  fp.close();

  return json_deserialize0(text.c_str());
}

long write_config_json(const char *fname)
{
  File fp = SPIFFS.open(fname, FILE_WRITE);
  if( !fp )
    return -1;

  char *p_buffer = json_serialize0();
  long ret = fp.write((uint8_t*)p_buffer, strlen(p_buffer));
  fp.close();
  free(p_buffer);
  if( ret != strlen(p_buffer) )
    return -1;

  return 0;
}
