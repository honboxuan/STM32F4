#include <stdio.h>

#include "stm32f4xx.h"
#include "gpio.h"
#include "timer.h"
#include "usart.h"
#include "spi.h"
#include "i2c.h"

#include "MadgwickAHRS.h"

__IO uint32_t millis = 0;

uint8_t usart_buffer[] = "Testing DMA USART3.\n";

int main(void) {
	RCC_HSEConfig(RCC_HSE_ON);
	while(!RCC_WaitForHSEStartUp());

	gpio_init();
	base_timer_init();
	usart_init();
	//usart_dma_init(usart_buffer, sizeof(usart_buffer));

	printf(" ");


	uint8_t first, second, third;


	/*printf("ESC:\n");
	uint16_t speed = 256;
	spi2_init();

	for (speed; speed < 350; speed++) {
		while (millis < 100);
		millis = 0;

		SPI_Cmd(SPI2, ENABLE);

		SPI_I2S_SendData(SPI2, 222);
		while(SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_RXNE) == RESET);
		first = SPI_I2S_ReceiveData(SPI2);
		printf("%u, ", first);

		SPI_I2S_SendData(SPI2, (speed >> 8));
		while(SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_RXNE) == RESET);
		second = SPI_I2S_ReceiveData(SPI2);
		printf("%u, ", second);

		SPI_I2S_SendData(SPI2, (speed & 255));
		while(SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_RXNE) == RESET);
		third = SPI_I2S_ReceiveData(SPI2);
		printf("%u\n", third);

		while(SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_BSY) == SET);
		SPI_Cmd(SPI2, DISABLE);
		//printf("%u,%u,%u\n", first, second, third);
	}
	for (speed; speed > 256; speed--) {
		while (millis < 100);
		millis = 0;

		SPI_Cmd(SPI2, ENABLE);

		SPI_I2S_SendData(SPI2, 222);
		while(SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_RXNE) == RESET);
		first = SPI_I2S_ReceiveData(SPI2);
		printf("%u, ", first);

		SPI_I2S_SendData(SPI2, (speed >> 8));
		while(SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_RXNE) == RESET);
		second = SPI_I2S_ReceiveData(SPI2);
		printf("%u, ", second);

		SPI_I2S_SendData(SPI2, (speed & 255));
		while(SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_RXNE) == RESET);
		uint8_t third = SPI_I2S_ReceiveData(SPI2);
		printf("%u\n", third);

		while(SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_BSY) == SET);
		SPI_Cmd(SPI2, DISABLE);
		//printf("%u,%u,%u\n", first, second, third);
	}*/






	printf("I2C:\n");
	//I2C Test
	i2c_init();

	//0x1E (5883L & 5983)
	//0x68 (MPU6050)

	printf("Start:\n");
	//i2c_start(I2C2, 0x68 << 1, I2C_Direction_Transmitter);
	i2c_start(I2C2, 0x1E << 1, I2C_Direction_Transmitter);
	printf("Write 1:\n");
	//i2c_write(I2C2, 0x75); //WHOAMI (MPU)
	//i2c_write(I2C2, 0x3B); //ACCEL_XOUT_H
	//i2c_write(I2C2, 0x03); //Data Output X MSB
	i2c_write(I2C2, 0x0A); //Identification Register A (01001000 = 72)

	//NOTHING WORKS!??!?!?! POWER!?!?

	printf("Stop:\n");
	i2c_stop(I2C2);

	printf("Start:\n");
	i2c_start(I2C2, 0x1E << 1, I2C_Direction_Receiver);

	printf("Read:\n");

	first = i2c_read_ack(I2C2);
	printf("ID A: %u\t", first);

/*
	first = i2c_read_ack(I2C2);
	second = i2c_read_nack(I2C2);
	printf("X: %d\t", ((int16_t)first << 8) | second);

	first = i2c_read_ack(I2C2);
	second = i2c_read_nack(I2C2);
	printf("Y: %d\t", ((int16_t)first << 8) | second);

	first = i2c_read_ack(I2C2);
	second = i2c_read_nack(I2C2);
	printf("Z: %d\t", ((int16_t)first << 8) | second);
*/
/*
	printf("Start:\n");
	i2c_start(I2C2, 0x68 << 1, I2C_Direction_Receiver);

	printf("Read:\n");

	first = i2c_read_ack(I2C2);
	second = i2c_read_nack(I2C2);
	printf("AccelX: %d\t", ((int16_t)first << 8) | second);

	first = i2c_read_ack(I2C2);
	second = i2c_read_nack(I2C2);
	printf("AccelY: %d\t", ((int16_t)first << 8) | second);

	first = i2c_read_ack(I2C2);
	second = i2c_read_nack(I2C2);
	printf("AccelZ: %d\t", ((int16_t)first << 8) | second);

	first = i2c_read_ack(I2C2);
	second = i2c_read_nack(I2C2);
	printf("Temp: %d\t", ((int16_t)first << 8) | second);

	first = i2c_read_ack(I2C2);
	second = i2c_read_nack(I2C2);
	printf("GyroX: %d\t", ((int16_t)first << 8) | second);

	first = i2c_read_ack(I2C2);
	second = i2c_read_nack(I2C2);
	printf("GyroY: %d\t", ((int16_t)first << 8) | second);

	first = i2c_read_ack(I2C2);
	second = i2c_read_nack(I2C2);
	printf("GyroZ: %d\n", ((int16_t)first << 8) | second);
*/

	i2c_stop(I2C2);




	printf("Tests ended:\n");

	while(1) {
		if (millis >= 500) {
			//usart_dma_start();
			millis = 0;
			GPIO_ToggleBits(GPIOC, GPIO_Pin_9);
		}
		//printf("%lu\n", millis); //Happens ~2kHz for 5 byte transfers

	}
	return 0;
}

void TIM6_DAC_IRQHandler(void) {
	TIM_ClearITPendingBit(TIM6, TIM_IT_Update);
	millis++;
}
