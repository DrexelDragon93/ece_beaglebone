/*
 * pwm_test.cpp  Created on: 3rd Feb 2015
 * Copyright (c) 2014 Derek Molloy (www.derekmolloy.ie)
 * Made available for the book "Exploring BeagleBone"
 * See: www.exploringbeaglebone.com
 * Licensed under the EUPL V.1.1
 *
 * This Software is provided to You under the terms of the European
 * Union Public License (the "EUPL") version 1.1 as published by the
 * European Union. Any use of this Software, other than as authorized
 * under this License is strictly prohibited (to the extent such use
 * is covered by a right of the copyright holder of this Software).
 *
 * This Software is provided under the License on an "AS IS" basis and
 * without warranties of any kind concerning the Software, including
 * without limitation merchantability, fitness for a particular purpose,
 * absence of defects or errors, accuracy, and non-infringement of
 * intellectual property rights other than copyright. This disclaimer
 * of warranty is an essential part of the License and a condition for
 * the grant of any rights to this Software.
 *
 * For more details, see http://www.derekmolloy.ie/
 */

#include<iostream>
#include"PWM.h"      //placed in the current directory for ease of use
#include <unistd.h>
#include "GPIO.h"
#include <string>
#include "SimpleGPIO.h"

using namespace exploringBB;
using namespace std;

unsigned int ButtonGPIO = 116;   //  GPIO3_20 = (3x32) +  20 = 116
unsigned int Button2GPIO = 115;   // GPIO3_19 = (3x32) + 19 = 115

int main(){
	PWM pwm("pwm_test_P9_22.16");  //
	gpio_export(ButtonGPIO); // push button 1
	gpio_export(Button2GPIO); // push button 1
	gpio_set_dir(ButtonGPIO, INPUT_PIN);   // The push button input
	gpio_set_dir(Button2GPIO, INPUT_PIN); // The push button 2 input
	unsigned int button_value = 0;

	pwm.setPolarity(PWM::ACTIVE_HIGH);
	pwm.setPeriod(20000000);
	pwm.run();
	pwm.setDutyCycle(570000u);

	while(1){
		do {
					gpio_get_value(ButtonGPIO, &button_value);
					usleep(1000);      // sleep for one millisecond
				} while (button_value !=1);
		pwm.setDutyCycle(1010000u);
		usleep(1000000);
		do {
							gpio_get_value(ButtonGPIO, &button_value);
							usleep(1000);      // sleep for one millisecond
						} while (button_value !=1);
		pwm.setDutyCycle(1450000u);
		usleep(1000000);
		do {
							gpio_get_value(ButtonGPIO, &button_value);
							usleep(1000);      // sleep for one millisecond
						} while (button_value !=1);
		pwm.setDutyCycle(1890000u);
		usleep(1000000);
		do {
							gpio_get_value(ButtonGPIO, &button_value);
							usleep(1000);      // sleep for one millisecond
						} while (button_value !=1);
		pwm.setDutyCycle(2350000u);
		usleep(1000000);
		do {
							gpio_get_value(ButtonGPIO, &button_value);
							usleep(1000);      // sleep for one millisecond
						} while (button_value !=1);
		pwm.setDutyCycle(1890000u);
		usleep(1000000);
		do {
							gpio_get_value(ButtonGPIO, &button_value);
							usleep(1000);      // sleep for one millisecond
						} while (button_value !=1);
		pwm.setDutyCycle(1450000u);
		usleep(1000000);
		do {
							gpio_get_value(ButtonGPIO, &button_value);
							usleep(1000);      // sleep for one millisecond
						} while (button_value !=1);
		pwm.setDutyCycle(1010000u);
		usleep(1000000);
		do {
							gpio_get_value(ButtonGPIO, &button_value);
							usleep(1000);      // sleep for one millisecond
						} while (button_value !=1);
		pwm.setDutyCycle(570000u);
		usleep(1000000);


	}

   /*pwm.setPolarity(PWM::ACTIVE_HIGH);
   pwm.setPeriod(20000000);
   pwm.run();
   pwm.setDutyCycle(570000u);
   usleep(1000000);
   pwm.setDutyCycle(1460000u);
   usleep(1000000);
   pwm.setDutyCycle(2350000u);*/

}
