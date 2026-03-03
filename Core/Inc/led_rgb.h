/*
 * led_rgb.h
 *
 *  Created on: 19 de fev. de 2026
 *      Author: Jordan Willian Marques Pereira
 */

#ifndef INC_LED_RGB_H_
#define INC_LED_RGB_H_

#include "stm32c0xx_hal.h"
#include <stdint.h>

#define RGB_ACTIVE_LOW   1

#define RGB_PORT GPIOA

#define RGB_PIN_R GPIO_PIN_8
#define RGB_PIN_G GPIO_PIN_0
#define RGB_PIN_B GPIO_PIN_1

#define RGB_MASK (RGB_PIN_R | RGB_PIN_G | RGB_PIN_B)

typedef enum
{
    RGB_OFF = 0,
    RGB_RED,
    RGB_GREEN,
    RGB_BLUE,
    RGB_YELLOW,
    RGB_CYAN,
    RGB_MAGENTA,
    RGB_WHITE
} RGB_Color_t;

void RGB_Init(void);
void RGB_On(uint16_t pin);
void RGB_Off(uint16_t pin);
void RGB_SetColor(RGB_Color_t color);

#endif /* INC_LED_RGB_H_ */
