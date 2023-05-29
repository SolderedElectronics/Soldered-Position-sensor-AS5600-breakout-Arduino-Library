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

PositionSensor sensor;

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
    sensor.setOffset(0); // Reset the offset to 0
    Serial.print("Measurement without offset: ");
    Serial.print("\t");                                        // Tab space for readable output
    Serial.println(sensor.rawAngle() * AS5600_RAW_TO_DEGREES); // Print measurement without offset

    sensor.setOffset(45); // Set offset to 45 degrees
    Serial.print("Measurement with offset: ");
    Serial.print("\t");
    Serial.print("\t");
    Serial.println(sensor.rawAngle() * AS5600_RAW_TO_DEGREES); // Print measurement with offset

    Serial.println(""); // Print a blank line for readability

    delay(1000); // Wait before making the next measurement, so output isn't too fast
}
