/*
** pwm_manager.cc
** Login : <Amoriello>
** Started on  Sat Jun 11 13:12:31 2011
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

#include "pwm_manager.hpp"

namespace /* anonymous */
{
//-----------------------------------------------------------------------------
template <typename T1, typename T2>
void set_pwm_duty(volatile T1&  port,
                  uint8_t       com_id,
                  volatile T2&  ctr,
                  uint8_t       duty)
{
  if (0 == duty)
  {
    disable(port, com_id);
    return;
  }

  enable(port, com_id);
  ctr = duty;
}


//-----------------------------------------------------------------------------
void    set_pwm_duty_oc1b(uint8_t duty)
{
  set_pwm_duty(TCCR1A, COM1B1, OCR1B, duty);
}


//-----------------------------------------------------------------------------
void    set_pwm_duty_oc1a(uint8_t duty)
{
  set_pwm_duty(TCCR1A, COM1A1, OCR1A, duty);
}


//-----------------------------------------------------------------------------
void    set_pwm_duty_oc2a(uint8_t duty)
{
  set_pwm_duty(TCCR2A, COM2A1, OCR2A, duty);
}


//-----------------------------------------------------------------------------
//
// Clear OC1A/OC1B on Compare Match, set OC1A/OC1B at BOTTOM (non-inverting mode)
//
//    |=====================================================================
//    |   Mode operation  |    TOP   | Update OXR1x at | TOV1 Flag set on  |
//    ---------------------------------------------------------------------|
//    |  Fast PWM, 8-bit  |   0xFF   |    BOTTOM       |      TOP          |
//    |====================================================================|
//
// source : Atmega48A/PA/88A/PA/168A/PA/328/P documentation
//          16.11.1-2 TCCR1A TCCR1B Control Registern (p138)
//
void    init_pwm_oc1()
{
  //Stop timer
  TCCR1B = 0;
  TCCR1A = 0;
  TCCR1C = 0;

  TCCR1A = _ZERO(COM1A1) |  _ZERO(COM1A0) |
           _ZERO(COM1B1) |  _ZERO(COM1B0) |
           _ZERO(WGM11)  |  _BV(WGM10);

  OCR1A = 0x0;
  OCR1B = 0x0;

  TCCR1B = _ZERO(WGM13) | _BV(WGM12) |
           _ZERO(CS12) | _ZERO(CS11) | _BV(CS10);
}


//-----------------------------------------------------------------------------
//
// Clear 0C2A on Compare Match, set OC2A at BOTTOM (non-inverting mode)
// Normal port operation, OC2B disconnected (we only need 3 LED on pwm :
// OC1A, OC1B, OC2A).
//
//    |=====================================================================
//    |   Mode operation  |    TOP   | Update OCRx at  | TOV Flag set on   |
//    ---------------------------------------------------------------------|
//    |      Fast PWM     |  0xFF    |    BOTTOM       |      MAX          |
//    |====================================================================|
//
// source : Atmega48A/PA/88A/PA/168A/PA/328/P documentation
//          18.11.1-2 TCCR2A Control Registern (p162)
//
void    init_pwm_oc2()
{
  //Stop timer
  TCCR2B = 0;
  TCCR2A = 0;
  OCR2A = 0x0;
  OCR2B = 0x0;

  TCCR2A = _ZERO(COM2A1) | _ZERO(COM2A0) |
           _ZERO(COM2B1) | _ZERO(COM2B0) |
           _BV(WGM21) | _BV(WGM20);

  TCCR2B = _ZERO(WGM22) | _ZERO(CS22) | _ZERO(CS21) | _BV(CS20);
}

} // !namespace anoymous


namespace pwm
{

//-----------------------------------------------------------------------------
void    set_duty(uint8_t led_id, uint8_t duty)
{
  switch (led_id)
  {
  case RED_LED_PIN:
    set_pwm_duty_oc1a(duty);
    break;
  case GREEN_LED_PIN:
    set_pwm_duty_oc1b(duty);
    break;
  case BLUE_LED_PIN:
    set_pwm_duty_oc2a(duty);
    break;
  default:
    break;
  }
}


//-----------------------------------------------------------------------------
void    init()
{
  enable(RED_LED_DDR, RED_LED_PIN);
  enable(GREEN_LED_DDR, GREEN_LED_PIN);
  enable(BLUE_LED_DDR, BLUE_LED_PIN);

  init_pwm_oc1();
  init_pwm_oc2();
}

} // !namespace pwm
