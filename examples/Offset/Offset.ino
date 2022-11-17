/**
 **************************************************
 *
 * @file        Offset.ino
 * @brief       Demonstration of how to apply offset to AS5600. See more at solde.red/333183
 *
 *
 *
 * @authors     Robert Soric for Soldered.com
 ***************************************************/

#include "Position-sensor-AS5600-breakout-SOLDERED.h"

PositionSensor sensor;

void setup()
{
  Serial.begin(115200); // Begin serial communication
  sensor.begin(0);      // Initialize the sensor
}


void loop()
{
  sensor.setOffset(0);                                              // Reset the offset to 0
  Serial.print("Measurement without offset: ");                     
  Serial.print("\t");                                               // Tab space for readable output
  Serial.println(sensor.rawAngle() * AS5600_RAW_TO_DEGREES);        // Print measurement without offset

  sensor.setOffset(45);                                             // Set offset to 45 degrees
  Serial.print("Measurement with offset: ");  
  Serial.print("\t");
  Serial.print("\t");                   
  Serial.println(sensor.rawAngle() * AS5600_RAW_TO_DEGREES);        // Print measurement with offset

  delay(250);
}
