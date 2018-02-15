#include "Current.h"
 
Current::Current()
{
}
 
 void Current::init(const int sensorPin,const int devicePin)
 {
   digitalWrite(devicePin,HIGH);
  acOffset = analogRead(sensorPin);
  float total=0.0,current=0.0,currentRms=0.0;
  int sensorValue=0,i=0;
  unsigned long period=millis();
  while((millis()-period)<21){
    sensorValue = analogRead(sensorPin);
    current=(sensorValue-acOffset)*1000.0*5.0/1024.0/185.0;
    total+=current*current;
    i+=1;
  }
  currentRmsOffset=sqrt(total/i);
  Serial.print(currentRmsOffset);Serial.println("  init");
 }

 float Current::rmsCurrent(const int sensorPin)
 {
 	float total=0.0;
 	float current=0.0;
 	float currentRms=0.0;
 	int sensorValue=0,i=0;
 	unsigned long period=millis();
  while((millis()-period)<21){
    sensorValue = analogRead(sensorPin);
    current=(sensorValue-acOffset)*1000.0*5.0/1024.0/185.0;
    total=total+(current*current);
    i+=1  ;
    }
  currentRms=sqrt(total/i)-currentRmsOffset;
  return currentRms;
 }

 int Current::deviceState(const int pin,float current, float currentHigh)
 {
 	if(digitalRead(pin)==HIGH && current>(0.85*currentHigh)){
    return 0;
  }
  if(digitalRead(pin)==LOW && current<(0.15*currentHigh)){
    return 0;
  }
  if(digitalRead(pin)==LOW && current>(0.85*currentHigh)){
    return 2;
  }
  if(digitalRead(pin)==HIGH && current<(0.15*currentHigh)){
    return 1;
  }
 }