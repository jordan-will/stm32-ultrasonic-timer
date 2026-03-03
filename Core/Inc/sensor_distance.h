/*
 * sensor_distance.h
 *
 *  Created on: 19 de fev. de 2026
 *      Author: Jordan Willian Marques Pereira
 */

#ifndef INC_SENSOR_DISTANCE_H_
#define INC_SENSOR_DISTANCE_H_

#include "stm32c0xx_hal.h"
#include <stdint.h>

//TRIG PIN ON SENSOR
#define DIST_TRIG_PORT GPIOA
#define DIST_TRIG_PIN GPIO_PIN_9

//ECHO PIN ON SENSOR
#define DIST_ECHO_PORT GPIOA
#define DIST_ECHO_PIN GPIO_PIN_10

//check if the sensor is working correctly
#define DIST_TIMEOUT 30000U

#define DIST_MAX_CM 80

void DistanceSensor_Init(void);

//Read raw echo duration (polling)
uint32_t DistanceSensor_ReadRaw(void);

uint8_t DistanceSensor_GetDistanceCm(void);

#endif /* INC_SENSOR_DISTANCE_H_ */
