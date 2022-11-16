/**
 **************************************************
 *
 * @file        Template.ino
 * @brief       Example template for easyC sensors
 *
 *
 *
 * @authors     @ soldered.com
 ***************************************************/

#include "Position-sensor-AS5600-breakout-SOLDERED.h"

PositionSensor as5600;
AS5600 mysensor

void setup()
{
    Serial.begin(115200);
    delay(100);

    if(!mysensor.begin(0))
    {
        Serial.println("not connected");
        while(1)
        {
            delay(100);
        }
    }
    
    mysensor.setDirection(AS5600_CLOCK_WISE);
}

void loop()
{
    Serial.println(mysensor.readAngle());
    Serial.println(mysensor.rawAngle()*AS5600_RAW_TO_DEGREES);
    delay(100);
}
