#ifndef Current_h
#define Current_h
 
#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
  #include "pins_arduino.h"
  #include "WConstants.h"
#endif
 
 class Current {
public:
	Current();
    int acOffset=0,i=0;
    float currentRmsOffset=0.0;
	void init(const int sensorPin,const int devicePin);
	float rmsCurrent(const int sensorPin);
	int deviceState(const int pin,float current, float currentHigh);
	
};


 
#endif