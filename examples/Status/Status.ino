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

PositionSensor sensor;   // Create sensor object

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
  // The status registers can offer valuable insight in what state the device is currently in

  // Raw read of the status register (see figure 21 of AS5600 datasheet)
  Serial.print("Status register:\t ");
  Serial.println(sensor.readStatus(), HEX);
  delay(1000);

  // Raw read of the configuration register (see figure 22 of AS5600 datasheet)
  Serial.print("Config register:\t ");
  Serial.println(sensor.getConfigure(), HEX);
  delay(1000);

  // Read the currently set automatic gain
  // Should be 80 in hex (see "AGC Register" in AS5600 datasheet)
  Serial.print("Gain:\t ");
  Serial.println(sensor.readAGC(), HEX);
  delay(1000);

  // Check if a magnet is currently detected, returns true if yes, false if not
  Serial.print("Detect:\t ");
  Serial.println(sensor.detectMagnet(), HEX);
  delay(1000);

  // Check if the magnet is too strong or too weak to make good measurements
  Serial.print("Magnet high:\t ");
  Serial.println(sensor.magnetTooStrong(), HEX);
  Serial.print("Magnet low:\t ");
  Serial.println(sensor.magnetTooWeak(), HEX);
  Serial.println();
  delay(1000);

  delay(2000); // Wait before next print, so output isn't too fast
}
