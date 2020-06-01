/*
 * service.c
 *
 *  Created on: May 30, 2020
 *      Author: Luan_Pham
 */
#include "stm32f4xx_hal.h"
void Put_bit(uint8_t* const Data,uint8_t BitPn,uint8_t Value)
{
uint8_t temp= (Value)?1u:0u;
*Data=(*Data & ((uint8_t)~(1u<<BitPn))) | ((uint8_t)((uint8_t)temp<<BitPn));
}

void LaunchPad_out(uint8_t output_data)
{
	if(output_data==0x03)
	{
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_12 |GPIO_PIN_13,SET);
	}
	else if (output_data==0x02) {
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_12,SET);
	}
	else if (output_data==0x01) {
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_13,SET);

	}
	else
	{
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_12 |GPIO_PIN_13,RESET);
	}

}

uint8_t LaunchPad_input(void)
{
	uint8_t temp =0;
	if (HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_1)==1)
	{
		Put_bit(&temp,1,1);
		Put_bit(&temp,2,0);
	}
	else if (HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_2)==1) {
		Put_bit(&temp,2,1);
		Put_bit(&temp,1,0);
	}
	else if (HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_2|GPIO_PIN_1)==1)
			{
		Put_bit(&temp,2,1);
		Put_bit(&temp,1,1);
	}
	else
	{
		Put_bit(&temp,2,1);
		Put_bit(&temp,1,1);
	}
		return temp;
}
