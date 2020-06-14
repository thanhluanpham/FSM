/*
 * service.c
 *
 *  Created on: May 30, 2020
 *      Author: Luan_Pham
 */
#include "stm32f4xx_hal.h"
/*void Newfunct(uint32_t* const giatri)
{
 *giatri=1;
}*/ //testingonly
void Put_bit(uint8_t* const Data,uint8_t BitPn,uint8_t Value)
{
	uint8_t temp= (Value)?1u:0u;
	*Data=(*Data & ((uint8_t)~(1u<<BitPn))) | ((uint8_t)((uint8_t)temp<<BitPn));
}

void LaunchPad_out(uint8_t output_data)
{
	if(output_data==0x03)
	{
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_13 |GPIO_PIN_15,SET);
	}
	else if (output_data==0x02)
	{
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_13,SET);

		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_15,RESET);
	}
	else if (output_data==0x01) {
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_15,SET);
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_13,RESET);
	}
	else
	{
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_13 |GPIO_PIN_15,RESET);
	}

}

uint8_t LaunchPad_input(void)
{
	uint8_t temp =0;
	if ((HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_1)==1)&&(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_2)==0)) //0x01 Button1
	{
		Put_bit(&temp,0,1);
		Put_bit(&temp,1,0);
	}
	else if ((HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_2)==1)&&(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_1)==0))//0x02 Button2
	{
		Put_bit(&temp,1,1);
		Put_bit(&temp,0,0);
	}
	else if (((HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_1)==1))&&(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_2)==1))//0x03 both Button1 and Button2
	{
		Put_bit(&temp,1,1);
		Put_bit(&temp,0,1);
	}
	else//
	{
		Put_bit(&temp,1,0);
		Put_bit(&temp,0,0);
	}
	return temp;
}
