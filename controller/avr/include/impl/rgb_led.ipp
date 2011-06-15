/*
** rgb_led.ipp
** Login : <Amoriello>
** Started on  Sun Jun 12 11:11:25 2011
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


//-----------------------------------------------------------------------------
inline RgbLed::RgbLed(uint8_t red_led_pin,
                      uint8_t green_led_pin,
                      uint8_t blue_led_pin)
  : red_led_(red_led_pin), green_led_(green_led_pin), blue_led_(blue_led_pin)
{
  default_color_tab[red]    = 0xff0000;
  default_color_tab[green]  = 0x00ff00;
  default_color_tab[blue]   = 0x0000ff;
  default_color_tab[white]  = 0xffffff;
  default_color_tab[yellow] = 0xffa500;
  default_color_tab[pink]   = 0xff1493;
}

//-----------------------------------------------------------------------------
inline void
RgbLed::set_rgb(uint8_t R, uint8_t G, uint8_t B)
{
  red_led_ = R;
  green_led_ = G;
  blue_led_ = B;
}

//-----------------------------------------------------------------------------
inline void
RgbLed::set_rgb(uint32_t value)
{
  uint8_t r = (value & 0xff0000) >> 16;
  uint8_t g = (value & 0xff00) >> 8;
  uint8_t b = (value & 0xff);
  set_rgb(r, g, b);
}

//-----------------------------------------------------------------------------
inline void
RgbLed::set_color(color_enum color)
{
  if (color < num_of_colors) {
    set_rgb(default_color_tab[color]);
  }
}

//-----------------------------------------------------------------------------
inline void
RgbLed::demo_mode()
{
  uint8_t  step = 1; // choose step carefully : (0xff % step) == 0
  uint8_t  step_delay = 40;

  //red to green
  green_led_ = 0;
  blue_led_ = 0;
  for (uint8_t green_intensity = 0;
       green_intensity <= (0xff - step);
       green_intensity += step)
  {
    green_led_ = green_intensity;
    red_led_ = 0xff - green_intensity;
    _delay_ms(step_delay);
  }

  //green to blue
  for (uint8_t blue_intensity = 0;
       blue_intensity <= (0xff - step);
       blue_intensity += step)
  {
    blue_led_ = blue_intensity;
    green_led_ = 0xff - blue_intensity;
    _delay_ms(step_delay);
  }

  //blue to red
  for (uint8_t red_intensity = 0;
       red_intensity <= (0xff - step);
       red_intensity += step)
  {
    red_led_ = red_intensity;
    blue_led_ = 0xff - red_intensity;
    _delay_ms(step_delay);
  }
}
