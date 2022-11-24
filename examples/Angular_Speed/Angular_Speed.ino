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

    if (!sensor.begin()) // Initialize the sensor
    {
        Serial.print("AS5600 not found!");
        while (true)
        {
            delay(1000);
        }
    }

    Serial.print("AS5600 found!");

    while (!sensor.detectMagnet()) // If a magnet is not detected, print message
    {
        Serial.println("Magnet not detected!");
        delay(1000);
    }
}

void loop()
{
  Serial.print("\tω = ");
  Serial.print(sensor.getAngularSpeed()); // Measure and print current angular speed
  Serial.println("deg/s");
  
  delay(1000); // Wait before making the next measurement, so output isn't too fast
}
