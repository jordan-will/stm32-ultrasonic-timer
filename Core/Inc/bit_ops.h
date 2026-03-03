/*
 * bit_ops.h
 *
 *  Created on: 19 de fev. de 2026
 *      Author: Jordan Willian Marques Pereira
 */

#ifndef INC_BIT_OPS_H_
#define INC_BIT_OPS_H_

#define BIT_SET(reg, bit)    ((reg) |=  (1U << (bit)))
#define BIT_CLEAR(reg, bit)  ((reg) &= ~(1U << (bit)))
#define READ_BIT(reg, bit)   (((reg) >> (bit)) & 1U)


#endif /* INC_BIT_OPS_H_ */
