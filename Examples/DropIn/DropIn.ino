/*
*			DropIn example sketch!
*
*		This sketch is all the software that is needed for adding closed loop position control 
*		To existing 3d printer controllers. 
*		
*		All of the PID parameters and current settings can be configured from the serial monitor (baud rate: 9600)
*		After this sketch has been uploaded, and the configured settings will be saved to EEPROM, so they are
*		persistent between powercycles.
*
*		The easiest way to connect it uStepper to the external controller, is to use a 3D shield on the uStepper
*		and a stepstick shield on the external controller 
*		(https://ustepper.com/store/shields/31-59-3d-shield.html#/38-3dshield-3d_shield_stepstick_right)
*		however this is only possible if the external controller normally uses step sticks. if this is not the case,
*		then the connections should be as follows:
*		
*
*	Pin connections:
*	-----------------------------
*	| Controller | uStepper S    |
*	|----------------------------|
*	|	Enable   |		D2		 |
*	|	Step     |		D3		 |
*	|	Dir      |		D4		 |
*	|	GND      |		GND		 |
*	------------------------------	
*/

#include <uStepperS.h>
uStepperS stepper;

void setup() {

  Serial.begin(9600);
  stepper.setup(DROPIN, 200, 75, 7.0, 1.0);				// Dropin mode, 
  														// 200 fullsteps per revolution,
  														// P = 75
  														// I = 7
  														// D = 1
  stepper.checkOrientation(30.0);       				//Check orientation of motor connector
}

void loop() {
  stepper.dropinCli();			// activate CLI interface to set parameters, current etc.
}
