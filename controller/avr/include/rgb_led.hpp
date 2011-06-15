/*
** rgb_led.hpp
** Login : <Amoriello>
** Started on  Sat Jun 11 16:31:39 2011
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

#ifndef   	RGB_LED_HPP_
# define   	RGB_LED_HPP_

# include <stdint.h>
# include <util/delay.h>

# include "led.hpp"
# include "uncopyable.hpp"

class RgbLed : private uncopyable
{
public:
  explicit RgbLed(uint8_t red_led_pin,
                  uint8_t green_led_pin,
                  uint8_t blue_led_pin);


  enum color_enum
  {
    red,
    green,
    blue,
    white,
    yellow,
    pink,
    num_of_colors
  };

  void  set_rgb(uint8_t R, uint8_t G, uint8_t B);

  void  set_rgb(uint32_t value);

  void  set_color(color_enum color);

  void  demo_mode();


private:
  uint32_t      default_color_tab[num_of_colors];

private:
  Led   red_led_;
  Led   green_led_;
  Led   blue_led_;
};

# include "impl/rgb_led.ipp"

#endif	    /* !RGB_LED_PP_ */
