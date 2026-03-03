/*
 * led.c
 *
 *  Created on: 19 de fev. de 2026
 *      Author: Jordan Willian Marques Pereira
 */

#include "led.h"
#include "config.h"

void Led_Init(){
	LED_PORT->BSRR = LED_MASK;
}

void Led_On(uint8_t index){
    if(index < LED_COUNT){
		#if LED_ACTIVE_LOW
				LED_PORT->BSRR = (1U << (index + 16));
		#else
				LED_PORT->BSRR = (1U << index);
		#endif
    }
}

void Led_Off(uint8_t index){
    if(index < LED_COUNT){
		#if LED_ACTIVE_LOW
				LED_PORT->BSRR = (1U << index);
		#else
				LED_PORT->BSRR = (1U << (index + 16));
		#endif
    }
}

void Led_Write(uint8_t value) {
	#if LED_ACTIVE_LOW
		uint32_t set_bits   = (~value) & LED_MASK;
		uint32_t reset_bits = (value & LED_MASK) << 16;
	#else
		uint32_t set_bits = (value) & LED_MASK;
		uint32_t reset_bits = (~value & LED_MASK) << 16;
	#endif

	LED_PORT->BSRR = set_bits | reset_bits;
}

