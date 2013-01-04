/*
 * SensorManager.cpp
 *
 *  Created on: 18 Oct 2012
 *      Author: simon
 */
#include <CapSense.h>
#include "SensorManager.h"

CapSense   sensor1 = CapSense(9,14);
CapSense   sensor2 = CapSense(9,15);
CapSense   sensor3 = CapSense(9,16);


const int SENSOR_THRESHOLD = 1;
const int ACTIVE = 0;
int empty[6];

void SensorManager::init(){
	Serial.println("Initializing Sensor");
}

SensorManager::SensorManager() {
}

SensorManager::~SensorManager() {}

int* SensorManager::getStates(int states []){
	states[1] = sensor1.capSense(30);
	states[2] = sensor2.capSense(30);
	states[3] = sensor3.capSense(30);
	return states;
}

int* SensorManager::printStates(){
	int *states = getStates(empty);
	Serial.begin(4800);
	Serial.println();

	for(int i = 0; i < 3; i++){
		int state = states[i];
		Serial.print(state);
		Serial.print(" ");
	}

	return states;
}

int* SensorManager::getActiveStates(){
	int *states = getStates(empty);
	states[ACTIVE] = -1;
	for(int i = 1; i < 4; i++){
		if(states[i] > SENSOR_THRESHOLD) {
			states[ACTIVE] = 1;
			states[i] = 1;
		}
		else {
			states[i] = 0;
		}
	}
	return states;
}

