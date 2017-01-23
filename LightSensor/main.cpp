/*
 * main.cpp
 *
 *  Created on: Apr 22, 2016
 *      Author: ececlass
 */

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include "SimpleGPIO.h"
#include "GPIO.h"
using namespace std;

#define LDR_PATH "/sys/bus/iio/devices/iio:device0/in_voltage"
unsigned int LEDGPIO = 49;   // GPIO1_17 = (1x32) + 17 = 49

int readAnalog(int number){ // returns the input as an int
stringstream ss;
ss << LDR_PATH << number << "_raw";
fstream fs;
fs.open(ss.str().c_str(), fstream::in);
fs >> number;
fs.close();
return number;
}

int main(int argc, char* argv[]){

	gpio_export(LEDGPIO);    // The LED
	gpio_set_dir(LEDGPIO, OUTPUT_PIN);   // The LED is an output

	cout << "Starting the readLDR program" << endl;

	while(1){
		int value = readAnalog(0);
		cout << "The LDR value was " << value << " out of 4095." << endl;
		if(value <= 500){
			gpio_set_value(LEDGPIO, HIGH);
		}
		else if(value >500){
			gpio_set_value(LEDGPIO, LOW);
		}
	}

	return 0;
}


