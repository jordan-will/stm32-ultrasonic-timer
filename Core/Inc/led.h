/*
 * led.h
 *
 *  Created on: 19 de fev. de 2026
 *      Author: Jordan Willian Marques Pereira
 */

#ifndef INC_LED_H_
#define INC_LED_H_


#include "stm32c0xx_hal.h"
#include <stdint.h>

/*
 * ALL LEDS IS ON GPIOB (PB0-PB7)
 * LED ON -> 0 LED OFF -> 1
 */
#define LED_ACTIVE_LOW   0


//BUS CONFIG
#define LED_PORT GPIOB
#define LED_MASK 0x00FFU // It guarantees that only PB0-PB7 will be changed.


void Led_Init();
void Led_On(uint8_t index);
void Led_Off(uint8_t index);

//WRITE A SET OF MASK
void Led_Write(uint8_t value);

#endif /* INC_LED_H_ */
