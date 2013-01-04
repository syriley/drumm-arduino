// Do not remove the include below
#include "drumm-arduino.h"
#include "SensorManager.h"
#include <SoftwareSerial.h>

const int rxPin = 2;
const int txPin = 3;


SensorManager sensorManager;
SoftwareSerial bluetooth = SoftwareSerial(rxPin, txPin);


//The setup function is called once at startup of the sketch
void setup()
{
	  Serial.begin(4800);
	  Serial.println("Start Arduino");

	  SoftwareSerial bluetooth = SoftwareSerial(rxPin, txPin);
	  bluetooth.begin(115200);
	  bluetooth.println("Bluetooth Started");
}

void loop()
{
	//sensorManager.printStates();

	int *states = sensorManager.getActiveStates();
	Serial.println("");
	if(states[0] == 1) {

		bluetooth.begin(115200);
		bluetooth.println();
		for(int i = 1; i < 4; i++){
			int state = states[i];
			bluetooth.print(state);
			bluetooth.print(":");
			Serial.print(state);
			Serial.print(":");
		}

	}
	delay(10);
}
