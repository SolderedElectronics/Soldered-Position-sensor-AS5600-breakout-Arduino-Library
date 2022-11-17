/**
 **************************************************
 *
 * @file        Direction.ino
 * @brief       Change the rotation direction of AS5600. See more at solde.red/333003
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

  sensor.setDirection(AS5600_COUNTERCLOCK_WISE);  // Set direction to counterclockwise, can be changed in loop() as well
}

void loop()
{
  // Angle will increase with counter clockwise rotation, decrease with clockwise rotation

  Serial.print(sensor.readAngle());                           // Get angle value as an integer
  Serial.print("\t");                                         // Tab space for readable output
  Serial.println(sensor.rawAngle() * AS5600_RAW_TO_DEGREES);  // Calculate and print degree value of current angle
  delay(250);                                                 // Wait before making the next measurement, so output isn't too fast
}
