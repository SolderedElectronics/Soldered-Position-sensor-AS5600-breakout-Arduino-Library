/**
 **************************************************
 *
 * @file        Angular_Speed.ino
 * @brief       Read the angular speed of the magnet mesaured by AS5600. See more at solde.red/333183
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
  Serial.print("\tω = ");
  Serial.println(sensor.getAngularSpeed()); // Measure and print current angular speed
  delay(250);
}
