/*
 * led_rgb.c
 *
 *  Created on: 19 de fev. de 2026
 *      Author: Jordan Willian Marques Pereira
 */

#include "led_rgb.h"

void RGB_On(uint16_t pin){
	#if RGB_ACTIVE_LOW
		RGB_PORT->BSRR = (uint32_t)pin << 16;//low active
	#else
		RGB_PORT-> BSRR = pin;//high active
	#endif
}

void RGB_Off(uint16_t pin){
		#if RGB_ACTIVE_LOW
			RGB_PORT->BSRR = pin;
		#else
			RGB_PORT->BSRR = (uint32) pin << 16;
		#endif
}

void RGB_SetColor(RGB_Color_t color)
{
    uint16_t on_mask = 0;

    switch(color)
    {
        case RGB_RED:
            on_mask = RGB_PIN_R;
            break;

        case RGB_GREEN:
            on_mask = RGB_PIN_G;
            break;

        case RGB_BLUE:
            on_mask = RGB_PIN_B;
            break;

        case RGB_YELLOW:
            on_mask = RGB_PIN_R | RGB_PIN_G;
            break;

        case RGB_CYAN:
            on_mask = RGB_PIN_G | RGB_PIN_B;
            break;

        case RGB_MAGENTA:
            on_mask = RGB_PIN_R | RGB_PIN_B;
            break;

        case RGB_WHITE:
            on_mask = RGB_PIN_R | RGB_PIN_G | RGB_PIN_B;
            break;

        case RGB_OFF:
        default:
            on_mask = 0;
            break;
    }

	#if RGB_ACTIVE_LOW
		uint32_t set_bits   = (RGB_MASK & ~on_mask);          // OFF → HIGH
		uint32_t reset_bits = (RGB_MASK & on_mask) << 16;     // ON → LOW
	#else
		uint32_t set_bits   = (RGB_MASK & on_mask);
		uint32_t reset_bits = (RGB_MASK & ~on_mask) << 16;
	#endif

    RGB_PORT->BSRR = set_bits | reset_bits;
}

