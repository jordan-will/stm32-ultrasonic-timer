/*
 * app.c
 *
 *  Created on: 20 de fev. de 2026
 *      Author: Jordan Willian Marques Pereira
 */

#include "app.h"
#include "led.h"
#include "led_rgb.h"
#include "sensor_distance.h"
#include "config.h"

#include <stdio.h>
#include <string.h>
extern UART_HandleTypeDef huart2;

void App_Init(){
	Led_Init();
	DistanceSensor_Init();
}

void App_Run(){
	uint8_t dist = DistanceSensor_GetDistanceCm();
	uint8_t level = dist / DIST_RAW_PER_LED;

	char msg[50];
	snprintf(msg, sizeof(msg), "dist=%d level=%d\r\n", dist, level);
	HAL_UART_Transmit(&huart2, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);

	if(level >= LED_COUNT){
	    level = LED_COUNT;
	}

	for(uint8_t i = 0; i < LED_COUNT; i++){
		if(i < level){
			Led_On(i);
		}else{
			Led_Off(i);
		}
	}

	if(dist < 20){
		RGB_SetColor(RGB_RED);
	}else if(dist < 50){
		RGB_SetColor(RGB_YELLOW);
	}
	else{
		RGB_SetColor(RGB_GREEN);
	}
	HAL_Delay(100);
}
