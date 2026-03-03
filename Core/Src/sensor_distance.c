/*
 * sensor_distance.c
 *
 *  Created on: 19 de fev. de 2026
 *      Author: Jordan Willian Marques Pereira
 */

#include "sensor_distance.h"
extern TIM_HandleTypeDef htim14;

//generate a micro delay
static void delay_us(uint16_t us) {
	__HAL_TIM_SET_COUNTER(&htim14, 0);
	while(__HAL_TIM_GET_COUNTER(&htim14) < us);
}

void DistanceSensor_Init(void){
	HAL_TIM_Base_Start(&htim14);
	HAL_GPIO_WritePin(DIST_TRIG_PORT, DIST_TRIG_PIN, GPIO_PIN_RESET);
}

uint32_t DistanceSensor_ReadRaw(void)
{
	uint32_t start = 0;
	uint32_t end = 0;
	uint32_t timeout;

	//ENSURE TRIG LOW
	HAL_GPIO_WritePin(DIST_TRIG_PORT, DIST_TRIG_PIN, GPIO_PIN_RESET);
	delay_us(5);

	//10us PULSE
	HAL_GPIO_WritePin(DIST_TRIG_PORT, DIST_TRIG_PIN, GPIO_PIN_SET);
	delay_us(10);
	HAL_GPIO_WritePin(DIST_TRIG_PORT, DIST_TRIG_PIN, GPIO_PIN_RESET);

	//WAIT ECHO RISE
	timeout = 30000;
	while(HAL_GPIO_ReadPin(DIST_ECHO_PORT, DIST_ECHO_PIN) == GPIO_PIN_RESET){
		if(--timeout == 0){
			return 0;
		}
	}//end while

	start = __HAL_TIM_GET_COUNTER(&htim14);

	//WAIT ECHO FALL DOWN
	timeout = 30000;
	while(HAL_GPIO_ReadPin(DIST_ECHO_PORT, DIST_ECHO_PIN) == GPIO_PIN_SET){
		if(--timeout == 0){
			break;
		}
	}//end while

	end = __HAL_TIM_GET_COUNTER(&htim14);

	if(end >= start)
	    return (end - start);
	else
	    return (0xFFFF - start + end + 1);

}

uint8_t DistanceSensor_GetDistanceCm(void)
{
	uint32_t time_us = DistanceSensor_ReadRaw();

	if(time_us == 0) return DIST_MAX_CM;

	uint32_t distance = time_us/58;

	if(distance > DIST_MAX_CM) distance = DIST_MAX_CM;

	return (uint8_t)distance;

}
