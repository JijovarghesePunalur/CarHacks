/****************************************************************************
 * CAN Read Demo CAN Bus Shield. 
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
  Serial.println("CAN-bus Reading Started - Testing receival of CAN Bus message");  
  delay(1000);

  if(Canbus.init(CANSPEED_500))  
    Serial.println("CAN-bus Initialization done");
  else
    Serial.println("CAN-bus Initialization failed");

  delay(1000);
}

void loop(){

  tCAN message;
  if (mcp2515_check_message()) 
  {
    if (mcp2515_get_message(&message)) 
    {

      Serial.print("ID: ");
      Serial.print(message.id,HEX);
      Serial.print(", ");
      Serial.print("Bit Length: ");
      Serial.print(message.header.length,DEC);
      Serial.println("Data: ");
      for(int i=0;i<message.header.length;i++) 
      {	
        Serial.print(message.data[i],HEX);
        Serial.print(" ");
      }
      Serial.println("");

    }
  }

}

