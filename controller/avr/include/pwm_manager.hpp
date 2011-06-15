/*
** pwm_manager.hpp
** Login : <Amoriello>
** Started on  Sat Jun 11 12:58:25 2011
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

#ifndef   	PWM_MANAGER_HPP_
# define   	PWM_MANAGER_HPP_

# include <stdint.h>
# include <avr/io.h>

# include "avr_macro_helper.hpp"
# include "led_configuration.hpp"

namespace pwm
{

/*!
** Enables RED_LED_DDR, GREEN_LED_DDR and BLUE_LED_DDR, then
** enables hardware pwm using OCR1A, OCR1B and OCR1C
** This function should be called in main
**
*/
void    init();

/*!
** sets the duty cycle for led_pin.
**
** This pwm uses OCR1A, OCR1B and OCR2A counters
** provided by atemga's hardware
**
** Currend supported led_pin are :
**     - RED_LED_PIN
**     - GREEN_LED_PIN
**     - BLUE_LED_PIN
**
** @param led_id   the led we want to change the duty_cycle
** @param duty     the duty cycle
*/
void    set_duty(uint8_t led_id, uint8_t duty);

} //!namespace pwm

#endif	    /* !PWM_MANAGER_PP_ */
