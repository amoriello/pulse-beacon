/*
** led.hpp
** Login : <Amoriello>
** Started on  Sat Jun 11 12:58:17 2011
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

#ifndef   	LED_HPP_
# define   	LED_HPP_

# include <stdint.h>

# include "pwm_manager.hpp"
# include "uncopyable.hpp"


class Led : private uncopyable
{
public:

  /*!
  ** Led CTOR
  ** @param led_pin the pin on which the led is pinned
  ** @param bright  the brightness [0-0xFF]
  **
  ** @return
  */
  explicit Led(uint8_t led_pin, uint8_t bright = 0);


  /*!
  ** Reduces current brightness of given value
  ** @param value  [0-0xFF]
  **
  ** @return reference on *this
  */
  Led&  operator -=(uint8_t value);


  /*!
  ** Set current brightness to given bright
  ** @param bright  [0-0xFF]
  **
  ** @return
  */
  Led&  operator =(uint8_t bright);


  /*!
  ** Augment current brightness of given value
  ** @param value  [0-0xFF]
  **
  ** @return
  */
  Led&  operator +=(uint8_t value);


  /*!
  ** Turn of the led
  */
  void  turn_off();

private:

  /*!
  ** Adjusts pwm on current led
  **
  ** @param bright [0-0xFF]
  */
  void  set_bright_(uint8_t bright);


private:
  uint8_t       led_pin_;
  uint8_t       curr_bright_;
};

# include "impl/led.ipp"

#endif 	    /* !LED_HPP_ */
