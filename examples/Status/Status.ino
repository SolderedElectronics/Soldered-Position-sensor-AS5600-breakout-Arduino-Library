/**
 **************************************************
 *
 * @file        Status.ino
 * @brief       Read ing the status registers of the AS5600. See more at solde.red/333183
 *
 *
 *
 * @authors     Robert Soric for Soldered.com
 ***************************************************/

#include "Position-sensor-AS5600-breakout-SOLDERED.h"

PositionSensor sensor;   // Create sensor object


void setup()
{
  Serial.begin(115200); // Begin serial communication (for printing)
  sensor.begin();       // Initialize the sensor
}

void loop()
{
  // The status registers can offer valuable insight in what state the device is currently in

  // Raw read of the status register (see figure 21 of AS5600 datasheet)
  Serial.print("STATUS:\t ");
  Serial.println(sensor.readStatus(), HEX);

  // Raw read of the configuration register (see figure 22 of AS5600 datasheet)
  Serial.print("CONFIG:\t ");
  Serial.println(sensor.getConfigure(), HEX);

  // Read the currently set automatic gain
  // Should be 80 in hex (see "AGC Register" in AS5600 datasheet)
  Serial.print("GAIN:\t ");
  Serial.println(sensor.readAGC(), HEX);

  // Check if a magnet is currently detected, returns true if yes, false if not
  Serial.print("DETECT:\t ");
  Serial.println(sensor.detectMagnet(), HEX);

  // Check if the magnet is too strong or too weak to make good measurements
  Serial.print("M HIGH:\t ");
  Serial.println(sensor.magnetTooStrong(), HEX);
  Serial.print("M  LOW:\t ");
  Serial.println(sensor.magnetTooWeak(), HEX);
  Serial.println();

  delay(2000); // Wait before next print, so output isn't too fast
}
