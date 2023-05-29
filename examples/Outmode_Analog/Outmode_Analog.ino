/**
 **************************************************
 *
 * @file        Outmode_Analog.ino
 * @brief       Output an analog value from the rotation sensor and measure it. See more at solde.red/333183
 *
 *
 *
 * @authors     Robert Soric for Soldered.com
 ***************************************************/

#include "Position-sensor-AS5600-breakout-SOLDERED.h"

PositionSensor sensor; // Create sensor object

const byte ANALOG_PIN = 0;

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
 * AS5600                       Dasduino
 * OUT------------------------->ANALOG_PIN (set by user)
 *
 */

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

    sensor.setOutputMode(AS5600_OUTMODE_ANALOG_90); // Sets the output mode to analog
                                                    // AS5600_OUTMODE_ANALOG_90 is a reduced output range (10% to 90%)
                                                    // AS5600_OUTMODE_ANALOG_100 is the full output range
}

void loop()
{
    Serial.print("Angle: ");
    Serial.println(sensor.readAngle()); // Measure and print the angle
    Serial.print("AnalogRead: ");
    Serial.println(analogRead(ANALOG_PIN)); // Print the measurement of the generated signal
    delay(1000);                            // Wait before making the next measurement, so output isn't too fast
}
