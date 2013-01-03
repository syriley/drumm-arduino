// Do not remove the include below
#include "drumm-arduino.h"


//The setup function is called once at startup of the sketch
void setup()
{
	  Serial.begin(4800);
	  Serial.println("Start Arduino");
// Add your initialization code here
}

// The loop function is called in an endless loop
void loop()
{
	Serial.println("Looping");
	delay(1000);
//Add your repeated code here
}
