/*
 * main.cpp
 *
 *  Created on: Apr 12, 2016
 *      Author: ececlass
 */

#include <iostream>
#include <string>
#include <unistd.h>
#include "SimpleGPIO.h"
#include "GPIO.h"
using namespace std;

unsigned int LEDGPIO = 49;   // GPIO1_17 = (1x32) + 17 = 49
unsigned int ButtonGPIO = 116;   //  GPIO3_20 = (3x32) +  20 = 116
unsigned int Button2GPIO = 115;   // GPIO3_19 = (3x32) + 19 = 115

int main(int argc, char *argv[]){

gpio_export(LEDGPIO);    // The LED
gpio_export(ButtonGPIO); // push button 1
gpio_export(Button2GPIO); // push button 1
gpio_set_dir(LEDGPIO, OUTPUT_PIN);   // The LED is an output
gpio_set_dir(ButtonGPIO, INPUT_PIN);   // The push button input
gpio_set_dir(Button2GPIO, INPUT_PIN); // The push button 2 input

unsigned int value_fast = LOW;
unsigned int value_slow = LOW;

while(1){
	do {
			gpio_get_value(ButtonGPIO, &value_fast);
			gpio_get_value(Button2GPIO, &value_slow);
			usleep(1000);      // sleep for one millisecond
		} while (value_slow !=HIGH && value_fast !=HIGH);

	if(value_fast == HIGH){
		do{
		gpio_set_value(LEDGPIO, HIGH);
		usleep(100000);
		gpio_set_value(LEDGPIO, LOW);
		usleep(100000);
		gpio_get_value(ButtonGPIO, &value_fast);
		gpio_get_value(Button2GPIO, &value_slow);
		usleep(1000);
		} while(value_slow !=HIGH && value_fast !=HIGH);
	}
	else if(value_slow == HIGH){
		do{
		gpio_set_value(LEDGPIO, HIGH);
		usleep(1000000);
		gpio_set_value(LEDGPIO, LOW);
		usleep(1000000);
		gpio_get_value(ButtonGPIO, &value_fast);
		gpio_get_value(Button2GPIO, &value_slow);
		usleep(1000);
		} while(value_slow !=HIGH && value_fast !=HIGH);
	}
}


gpio_unexport(LEDGPIO);     // unexport the LED
gpio_unexport(ButtonGPIO);
gpio_unexport(Button2GPIO);// unexport the push button
return 0;
}

