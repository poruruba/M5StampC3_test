#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEServer.h>

#include "lib_ibeacon.h"

static BLEAdvertising *pAdvertising;
static bool is_running = false;

long ibeacon_set_device_message(const uint8_t *p_uuid, uint16_t major, uint16_t minor, uint8_t tx)
{
  BLEAdvertisementData advertisementData = BLEAdvertisementData();
  advertisementData.setFlags(0x06);
  
  std::string strServiceData = "";

  strServiceData += (char)26;
  strServiceData += (char)0xff;
  strServiceData += (char)0x4c;
  strServiceData += (char)0x00;
  strServiceData += (char)0x02;
  strServiceData += (char)0x15;

  for( int i = 0 ; i < 16 ; i++ )
    strServiceData += (char)p_uuid[i];

  strServiceData += (char)((major >> 8) & 0xff);
  strServiceData += (char)((major >> 0) & 0xff);
  strServiceData += (char)((minor >> 8) & 0xff);
  strServiceData += (char)((minor >> 0) & 0xff);
  strServiceData += (char)tx; // Measured TxPower

  advertisementData.addData(strServiceData);
  pAdvertising->setAdvertisementData(advertisementData);

  return 0;
}

long ibeacon_initialize(const uint8_t *p_uuid, uint16_t major, uint16_t minor, uint8_t tx)
{
  BLEDevice::init(IBEACON_DEVICE_NAME);

  BLEServer *pServer = BLEDevice::createServer();
  pAdvertising = pServer->getAdvertising();

  return ibeacon_set_device_message(p_uuid, major, minor, tx);
}

long ibeacon_start(void)
{
  if( !is_running ){
    is_running = true;
    pAdvertising->start();
  }

  return 0;
}

long ibeacon_stop(void)
{
  if( is_running ){
    pAdvertising->stop();
    is_running = false;
  }

  return 0;
}
