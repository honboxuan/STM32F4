#ifndef I2C_H
#define I2C_H

#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_i2c.h"
#include "misc.h"

void i2c_init(void);
void i2c_start(I2C_TypeDef* I2Cx, uint8_t address, uint8_t direction);
void i2c_write(I2C_TypeDef* I2Cx, uint8_t data);
uint8_t i2c_read_ack(I2C_TypeDef* I2Cx);
uint8_t i2c_read_nack(I2C_TypeDef* I2Cx);
void i2c_stop(I2C_TypeDef* I2Cx);

#endif
