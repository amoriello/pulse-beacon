/*
** pulse_beacon.pde
** Login : <Amoriello>
** Started on  Mon Jun 6 22:10:31 2011
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

const unsigned int  red_led_pin = 9;
const unsigned int  green_led_pin = 10;
const unsigned int  blue_led_pin = 11;


class Led
{
private:
  typedef unsigned char  uint8_type;

public:
  //------------------------------------------------------------------
  Led(unsigned int led_pin, unsigned char bright = 0)
    : led_pin_(led_pin), curr_bright_(bright)
  {
    set_bright(bright);
  }

  //------------------------------------------------------------------
  Led& operator -=(unsigned char value)
  {
    if (curr_bright_ >= value) {
      curr_bright_ -= value;
    }
    else {
      curr_bright_ = 0;
    }
    set_bright(curr_bright_);
    return (*this);
  }

  //------------------------------------------------------------------
  Led& operator =(uint8_type value) {
    set_bright(value);
  }

  //------------------------------------------------------------------
  Led& operator +=(uint8_type value)
  {

    if ((0xFF - value) > curr_bright_) {
      curr_bright_ += value;
    }
    else {
      curr_bright_ = 0xFF;
    }

    set_bright(curr_bright_);
  }

  //------------------------------------------------------------------
  void  off() {
    set_bright(0);
  }

  //------------------------------------------------------------------
  void set_bright(uint8_type value)
  {
    analogWrite(led_pin_, value);
    curr_bright_ = value;
  }

  //------------------------------------------------------------------
  unsigned char get_bright() const {
    return (curr_bright_);
  }

private:
  unsigned int   led_pin_;
  unsigned char  curr_bright_;
};


class RgbLed
{
private:
  typedef unsigned char  uint8_type;

public:
  RgbLed(unsigned int  red_id,
         unsigned int  green_id,
         unsigned int  blue_id)
    : red_led_(red_id), green_led_(green_id), blue_led_(blue_id)
  {
    /// @see http://www.tayloredmktg.com/rgb/
    default_color_tab[red]    = 0xff0000;
    default_color_tab[green]  = 0x00ff00;
    default_color_tab[blue]   = 0x0000ff;
    default_color_tab[white]  = 0xffffff;
    default_color_tab[yellow] = 0xffa500;
    default_color_tab[pink]   = 0xff1493;
  }

  enum color_enum
  {
    red,
    green,
    blue,
    white,
    yellow,
    pink,
    num_of_color
  };

  //------------------------------------------------------------------
  void  off()
  {
    red_led_.off();
    green_led_.off();
    blue_led_.off();
  }

  //------------------------------------------------------------------
  void  set_rgb(unsigned long value) {
    uint8_type R = (value & 0xff0000) >> 16;
    uint8_type G = (value & 0xff00) >> 8;
    uint8_type B = (value & 0xff);

    set_rgb(R, G, B);
  }

  //------------------------------------------------------------------
  void  set_rgb(uint8_type R, uint8_type G, uint8_type B)
  {
    red_led_ = R;
    green_led_ = G;
    blue_led_ = B;
  }

  //------------------------------------------------------------------
  void  set_color(color_enum  color)
  {
    if (color < num_of_color) {
       set_rgb(default_color_tab[color]);
    }
  }

  //------------------------------------------------------------------
  void  demo_mode()
  {
    uint8_type  step = 1;  // step % oxff == 0
    uint8_type  step_delay = 100;
    
    //red to green
    green_led_ = 0;
    blue_led_ = 0;
    for (uint8_type green_intensity = 0;
         green_intensity <= (0xff - step);
         green_intensity += step)
    {
      green_led_ = green_intensity;
      red_led_ = 0xff - green_intensity;
      delay(step_delay);
    }

    //green to blue
    for (uint8_type blue_intensity = 0;
         blue_intensity <= (0xff - step);
         blue_intensity += step)
    {
      blue_led_ = blue_intensity;
      green_led_ = 0xff - blue_intensity;
      delay(step_delay);
    }

    //blue to red
    for (uint8_type red_intensity = 0;
         red_intensity <= (0xff - step);
         red_intensity += step)
    {
      red_led_ = red_intensity;
      blue_led_ = 0xff - red_intensity;
      delay(step_delay);
    }

  }



private:
  unsigned long default_color_tab[num_of_color];

private:
  Led      red_led_;
  Led      green_led_;
  Led      blue_led_;
};


void   setup()
{
}


void  loop()
{

  RgbLed  rgb_led(red_led_pin, green_led_pin, blue_led_pin);

  rgb_led.demo_mode();
}

