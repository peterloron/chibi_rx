#include <chibi.h>

byte buf[CHB_MAX_PAYLOAD];

void setup()
{
  Serial.begin(115200);
  
  // Init the chibi wireless stack
  chibiInit();
  
  // set the channel to channel 20. channel 20 is out of band of
  // 802.11 wi-fi channels
  chibiSetChannel(20);
}

void loop()
{ 
  // We're going to print anything we receive in case there are others 
  // transmitting.
  if (chibiDataRcvd() == true)
  {
    chibiGetData(buf);
    Serial.println((char *)buf);
  }

  // delay half a second between transmission
  delay(500);
}
