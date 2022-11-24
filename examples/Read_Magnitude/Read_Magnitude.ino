
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
    Serial.print("Magnitude: ");
    Serial.print(sensor.readMagnitude() * 0.001); // Read and print the current magnitude of the CORDIC in milliteslas
                                                  // Correlates with the strength of the magnetic field vector of the magnet
    Serial.println(" mT");
    delay(250);
}
