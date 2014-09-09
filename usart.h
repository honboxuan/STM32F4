#ifndef USART_H
#define USART_H

#include <stdio.h>
#include "stm32f4xx.h"
#include "stm32f4xx_dma.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_usart.h"

void usart_init(void);
void usart_dma_init(uint8_t* Buffer, uint16_t Size);
void usart_dma_start(void);

#endif
