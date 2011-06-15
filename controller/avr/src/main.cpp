#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>

#include "pwm_manager.hpp"
#include "rgb_led.hpp"



int     main(void)
{
  pwm::init();

  RgbLed  rgb_led(RED_LED_PIN, GREEN_LED_PIN, BLUE_LED_PIN);

  rgb_led.set_color(RgbLed::yellow);

  for (;;)
  {
    rgb_led.demo_mode();
  }

  return (0);
}
