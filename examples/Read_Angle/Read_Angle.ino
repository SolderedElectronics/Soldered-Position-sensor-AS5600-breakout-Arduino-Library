/**
 **************************************************
 *
 * @file        Read_Angle.ino
 * @brief       Read the rotation position of the magnet mesaured by AS5600. See more at solde.red/333183
 *
 *
 *
 * @authors     Robert Soric for Soldered.com
 ***************************************************/

#include "Position-sensor-AS5600-breakout-SOLDERED.h"

PositionSensor sensor; // Create sensor object

void setup()
{
  Serial.begin(115200); // Begin serial communication (for printing)
  sensor.begin();       // Initialize the sensor
}

void loop()
{
  Serial.print(sensor.readAngle());                           // Get angle value as an integer
  Serial.print("\t");                                         // Tab space for readable output
  Serial.print(sensor.rawAngle() * AS5600_RAW_TO_DEGREES);    // Calculate and print degree value of current angle
  Serial.print("\t");
  Serial.println(sensor.rawAngle() * AS5600_RAW_TO_RADIANS);  // Calculate and print radians value of current angle
  delay(250);                                                 // Wait before making the next measurement, so output isn't too fast
}
