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

/**
 * Connecting diagram:
 *
 * AS5600                       Dasduino Core / Connect / ConnectPlus
 * VCC------------------------->VCC
 * GND------------------------->GND
 * SCL------------------------->A5/IO5/IO22
 * SDA------------------------->A4/IO4/IO21
 * 
 * Or, simply use an easyC cable!
 * 
 */

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
    Serial.print("Raw angle value: ");
    Serial.println(sensor.readAngle()); // Get angle raw value as an integer
                                        // Ranges from values 0 to 4048
    Serial.print("Angle in degrees: ");
    Serial.println(sensor.rawAngle() * AS5600_RAW_TO_DEGREES); // Calculate and print degree value of current angle
    Serial.print("Angle in radians: ");
    Serial.println(sensor.rawAngle() * AS5600_RAW_TO_RADIANS); // Calculate and print radians value of current angle
    Serial.println("");                                        // Print a blank line for readability

    delay(1000); // Wait before making the next measurement, so output isn't too fast
}
