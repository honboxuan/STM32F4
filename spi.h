#ifndef SPI_H
#define SPI_H

#include "stm32f4xx.h"
#include "stm32f4xx_dma.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_spi.h"
#include "misc.h"

void spi_init(void);
void spi_dma_init(uint8_t* Buffer, uint16_t Size);
void spi2_init(void);
#endif
