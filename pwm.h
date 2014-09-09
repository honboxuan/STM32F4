#ifndef PWM_H
#define PWM_H

#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_tim.h"
#include "misc.h"

void pwm_init(void);
void pwm_dutycycle_set(uint32_t value);

#endif
