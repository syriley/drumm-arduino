/*
 * SensorManager.h
 *
 *  Created on: 18 Oct 2012
 *      Author: simon
 */

#ifndef SensorManager_H_
#define SensorManager_H_

class SensorManager {
public:
	SensorManager();
	virtual ~SensorManager();
	int* getStates (int states []);
	int* printStates();
	int* getActiveStates();
	void init();
	int freeRam();
};

#endif /* SensorManager_H_ */
