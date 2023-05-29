/**
 **************************************************
 *
 * @file        Outmode_PWM.ino
 * @brief       Output a PWM signal from the AS5600. See more at solde.red/333183
 *
 *
 *
 * @authors     Robert Soric for Soldered.com
 ***************************************************/

#include "Position-sensor-AS5600-breakout-SOLDERED.h"

PositionSensor sensor; // Create sensor object

// In this example, we will be reading the PWM output signal on the AS5600 breakout
// Connect the OUT pin on the board to digital input 16
// You may change the pin to suit your needs
// Make sure the digital pin on your Arduino compatible board supports reading PWM input and is not used for SCL/SDA or something else

const byte PWM_PIN = 16;

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
 * OUT------------------------->PWM_PIN (set by user)
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

    sensor.setOutputMode(AS5600_OUTMODE_PWM); // Set the output mode to PWM
    sensor.setPWMFrequency(AS5600_PWM_920);   // Set the PWM frequency, possible values are:
                                              // AS5600_PWM_115: 115 Hz
                                              // AS5600_PWM_230: 230 Hz
                                              // AS5600_PWM_460: 460 Hz
                                              // AS5600_PWM_920: 920 Hz
    
    pinMode(PWM_PIN, INPUT);                  // Set the PWM input pin as an input
}

void loop()
{
    Serial.print("Angle: ");
    Serial.println(sensor.readAngle()); // Measure and print the angle
    Serial.print("PWM reading: ");
    Serial.println(pulseIn(PWM_PIN, HIGH)); // Print the measurement of the generated PWM signal
    delay(1000);                            // Wait before making the next measurement, so output isn't too fast
}
