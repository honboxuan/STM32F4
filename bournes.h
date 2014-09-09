#ifndef BOURNES_H
#define BOURNES_H

#include <stdio.h>
#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"

void bournes_init(void);
uint8_t bournes_position_get(uint8_t value);

#endif
