/*
** led.ipp
** Login : <Amoriello>
** Started on  Sat Jun 11 13:53:55 2011
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
inline Led::Led(uint8_t led_pin, uint8_t bright)
  : led_pin_(led_pin), curr_bright_(bright)
{
  set_bright_(bright);
}


//-----------------------------------------------------------------------------
inline Led&
Led::operator -=(uint8_t value)
{
  if (curr_bright_ >= value) {
    curr_bright_ -= value;
  }
  else {
    curr_bright_ = 0;
  }
  set_bright_(curr_bright_);
  return (*this);
}


//-----------------------------------------------------------------------------
inline Led&
Led::operator =(uint8_t bright)
{
  set_bright_(bright);
  return (*this);
}


//-----------------------------------------------------------------------------
inline Led&
Led::operator +=(uint8_t value)
{
  if ((0xFF - value) > curr_bright_) {
    curr_bright_ += value;
  }
  else {
    curr_bright_ = 0xFF;
  }
  set_bright_(curr_bright_);
  return (*this);
}


//-----------------------------------------------------------------------------
inline void
Led::turn_off() {
  set_bright_(0);
}


//-----------------------------------------------------------------------------
inline void
Led::set_bright_(uint8_t bright)
{
  pwm::set_duty(led_pin_, bright);
  curr_bright_ = bright;
}
