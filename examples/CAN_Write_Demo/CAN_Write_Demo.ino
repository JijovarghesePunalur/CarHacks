/****************************************************************************
 * CAN-bus Write Demo CAN Bus Shield. 
 * 
 * 
 * Distributed as-is; no warranty is given.
 *************************************************************************/

#include <Canbus.h>
#include <defaults.h>
#include <global.h>
#include <mcp2515.h>
#include <mcp2515_defs.h>



void setup() {
  Serial.begin(9600);
  Serial.println("CAN-bus Writing Started");
  delay(1000);

  if(Canbus.init(CANSPEED_500))
    Serial.println("CAN-bus Initialization done");
  else
    Serial.println("CAN-bus Initialization failed");

  delay(1000);
}


void loop() 
{
  tCAN message;

  message.id = 0x4F0; //sample PID added here, you have to give PID in HEX format
  message.header.rtr = 0;
  message.header.length = 8; //it should be in DEC format
  message.data[0] = 0x40;
  message.data[1] = 0x05;
  message.data[2] = 0x30;
  message.data[3] = 0xFF; //format should be in HEX format
  message.data[4] = 0x00;
  message.data[5] = 0x40;
  message.data[6] = 0x00;
  message.data[7] = 0x00;

  mcp2515_bit_modify(CANCTRL, (1<<REQOP2)|(1<<REQOP1)|(1<<REQOP0), 0);
  mcp2515_send_message(&message);

  delay(1000);
}

