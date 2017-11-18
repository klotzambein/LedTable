#ifndef WIFI_H
#define WIFI_H

#include "Arduino.h"

#include "macro.h"
#if (SERIAL1_RX_BUFFER_SIZE != 512)
#pragma message("SERIAL1_RX_BUFFER_SIZE=" STRINGIFY(SERIAL1_RX_BUFFER_SIZE) " not equal to 512")
#endif

void wifi_init();


#endif