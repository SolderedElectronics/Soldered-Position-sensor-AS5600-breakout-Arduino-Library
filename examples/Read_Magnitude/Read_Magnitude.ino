
/**
 **************************************************
 *
 * @file        Read_Magnitude.ino
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
  Serial.print("Magnitude: ");
  Serial.println(sensor.readMagnitude()); // Read and print the current magnitude of the CORDIC
                                          // Correlates with the strength of the magnetic field vector of the magnet
  delay(250);                             
}
