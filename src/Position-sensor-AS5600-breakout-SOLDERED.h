/**
 **************************************************
 *
 * @file        Generic-easyC-SOLDERED.h
 * @brief       Header file for sensor specific code.
 *
 *
 * @copyright GNU General Public License v3.0
 * @authors     @ soldered.com
 ***************************************************/

#ifndef __AS5600__
#define __AS5600__

#include "Arduino.h"
#include "libs/Generic-easyC/easyC.hpp"

class AS5600: public EasyC
{
  public:
    AS5600();
    bool begin();

  protected:
    void initializeNative();

  private:
};

#endif
