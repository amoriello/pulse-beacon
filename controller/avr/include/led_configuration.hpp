/*
** led_configuration.hpp
** Login : <Amoriello>
** Started on  Fri Jun 10 12:34:50 2011
**
** Author(s):
**  - Amoriello Hutti <amoriello.hutti@gmail.com>
**
** Copyright (C) 2011 Amoriello Hutti
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation; either version 3 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/

#ifndef   	LED_CONFIGURATION_HPP_
# define   	LED_CONFIGURATION_HPP_

# include "avr_macro_helper.hpp"

// ATMEL ATMEGA8 & 168 / ARDUINO
//                  +-\/-+
//            PC6  1|    |28  PC5 (AI 5)
//      (D 0) PD0  2|    |27  PC4 (AI 4)
//      (D 1) PD1  3|    |26  PC3 (AI 3)
//      (D 2) PD2  4|    |25  PC2 (AI 2)
// PWM+ (D 3) PD3  5|    |24  PC1 (AI 1)
//      (D 4) PD4  6|    |23  PC0 (AI 0)
//            VCC  7|    |22  GND
//            GND  8|    |21  AREF
//            PB6  9|    |20  AVCC
//            PB7 10|    |19  PB5 (D 13)
// PWM+ (D 5) PD5 11|    |18  PB4 (D 12)
// PWM+ (D 6) PD6 12|    |17  PB3 (D 11) PWM  --> (Blue LED)  (0C2A)
//      (D 7) PD7 13|    |16  PB2 (D 10) PWM  --> (Green LED) (0C1B)
//      (D 8) PB0 14|    |15  PB1 (D 9)  PWM  --> (Red LED)   (OC1A)
//                  +----+

//using hardware enabled pwm
# define RED_LED_PORT_ID        B
# define RED_LED_PIN_ID         1

# define GREEN_LED_PORT_ID      B
# define GREEN_LED_PIN_ID       2

# define BLUE_LED_PORT_ID       B
# define BLUE_LED_PIN_ID        3


# define RED_LED_DDR            DDR(RED_LED_PORT_ID)
# define RED_LED_PIN            PIN(RED_LED_PORT_ID, RED_LED_PIN_ID)
# define RED_LED_PORT           PORT(RED_LED_PORT_ID)

# define GREEN_LED_DDR          DDR(GREEN_LED_PORT_ID)
# define GREEN_LED_PIN          PIN(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID)
# define GREEN_LED_PORT         PORT(GREEN_LED_PORT_ID)

# define BLUE_LED_DDR           DDR(BLUE_LED_PORT_ID)
# define BLUE_LED_PIN           PIN(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID)
# define BLUE_LED_PORT          PORT(BLUE_LED_PORT_ID)


#endif 	    /* !LED_CONFIGURATION_HPP_ */
