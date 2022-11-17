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

PositionSensor sensor;  // Create sensor object

byte PWM_PIN = 4;       // Will be reading PWM input on pin 4

void setup()
{
  Serial.begin(115200); // Begin serial communication (for printing)
  sensor.begin();       // Initialize the sensor
  
  sensor.setOutputMode(AS5600_OUTMODE_PWM); // Set the output mode to PWM
  sensor.setPWMFrequency(AS5600_PWM_920);   // Set the PWM frequency, possible values are:
                                            // AS5600_PWM_115: 115 Hz
                                            // AS5600_PWM_230: 230 Hz
                                            // AS5600_PWM_460: 460 Hz
                                            // AS5600_PWM_920: 920 Hz
  pinMode(4, INPUT);
}

void loop()
{
  Serial.print("Angle: ");
  Serial.println(sensor.readAngle());             // Measure and print the angle
  Serial.print("AnalogRead (PWM): ");                     
  Serial.println(pulseIn(PWM_PIN, HIGH));         // Print the measurement of the generated PWM signal
  delay(250);                                     // Wait before making the next measurement, so output isn't too fast 
}
