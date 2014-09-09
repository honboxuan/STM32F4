#ifndef ADC_H
#define ADC_H

#include <stdio.h>
#include "stm32f4xx.h"
#include "stm32f4xx_adc.h"
#include "stm32f4xx_dma.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"

void adc_init(void);
void adc_dma_init(uint16_t* Buffer);

#endif
