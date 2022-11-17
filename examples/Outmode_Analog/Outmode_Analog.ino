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

// For this sketch, connect the OUT pin on your AS5600 breakout board to A0 to measure the generated signal

void setup()
{
  Serial.begin(115200); // Begin serial communication (for printing)
  sensor.begin();       // Initialize the sensor

  sensor.setOutputMode(AS5600_OUTMODE_ANALOG_90); // Sets the output mode to analog
                                                  // AS5600_OUTMODE_ANALOG_90 is a reduced output range (10% to 90%)
                                                  // AS5600_OUTMODE_ANALOG_100 is the full output range
}

void loop()
{
  Serial.print("Angle: ");
  Serial.println(sensor.readAngle());             // Measure and print the angle
  Serial.print("AnalogRead: ");                     
  Serial.println(analogRead(A0));                 // Print the measurement of the generated signal
  delay(250);                                     // Wait before making the next measurement, so output isn't too fast 
}
