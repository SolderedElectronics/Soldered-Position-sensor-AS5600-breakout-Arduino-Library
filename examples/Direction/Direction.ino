/**
 **************************************************
 *
 * @file        Direction.ino
 * @brief       Change the rotation direction of AS5600. See more at solde.red/333183
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

    // Set direction of angle increment to counterclockwise, can be changed in loop() as well
    sensor.setDirection(AS5600_COUNTERCLOCK_WISE);
}

void loop()
{
    // Angle will increase with counter clockwise rotation, decrease with clockwise rotation

    Serial.print(sensor.readAngle());                          // Get angle value as an integer
    Serial.print("\t");                                        // Tab space for readable output
    Serial.println(sensor.rawAngle() * AS5600_RAW_TO_DEGREES); // Calculate and print degree value of current angle

    delay(1000); // Wait before making the next measurement, so output isn't too fast
}
