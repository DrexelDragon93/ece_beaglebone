/*
 * main.cpp
 *
 *  Created on: Apr 13, 2016
 *      Author: DiGiacomo
 */

#include <iostream>
#include <cstdio>
#include <ctime>
#include <unistd.h>
#include "SimpleGPIO.h"

unsigned int ButtonGPIO = 116;
unsigned int Button2GPIO = 115;


int main(int argc, char *argv[]){

	gpio_export(ButtonGPIO);
	gpio_export(Button2GPIO);
	gpio_set_dir(ButtonGPIO, INPUT_PIN);
	gpio_set_dir(Button2GPIO, INPUT_PIN);
	unsigned int start_stop = LOW;
	unsigned int reset = LOW;
	double duration;
	double duration2;

while(1){

	std::clock_t start;

	while(1){

	    do{
	    	gpio_get_value(ButtonGPIO, &start_stop);
	    	gpio_get_value(Button2GPIO, &reset);
	    }while(start_stop!=HIGH && reset !=HIGH);
	    if(reset==HIGH){
	    	duration2 = 0;
	    	do{
	    		gpio_get_value(ButtonGPIO, &start_stop);
	    	  }while(start_stop!=HIGH);
	     }

	    start = std::clock();
	    usleep(500000);
	    gpio_get_value(ButtonGPIO, &start_stop);
	    gpio_get_value(Button2GPIO, &reset);
	    do{
	    	gpio_get_value(ButtonGPIO, &start_stop);
	    	gpio_get_value(Button2GPIO, &reset);
	    	duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC + duration2;
	    	std::cout<< duration <<'\n';
	      }while(start_stop !=HIGH && reset != HIGH);

	    if(start_stop == HIGH){
	    	duration2 = duration;
	    	break;
	    }
	    else if(reset == HIGH){
	    	duration2 = 0;
	    	break;
	    }


	}
	usleep(500000);
}




}

/*gpio_get_value(ButtonGPIO, &start_stop);
	    do{
	    	gpio_get_value(ButtonGPIO, &start_stop);
	    	duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
	    	std::cout<< duration <<'\n';

	    }while(start_stop !=HIGH);

	    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

	    std::cout<<"printf: "<< duration <<'\n';

	    usleep(1000000);
	    gpio_get_value(Button2GPIO, &reset);
	    do{
	    	gpio_get_value(Button2GPIO, &reset);
	    }while(reset!=HIGH);

	    gpio_get_value(Button2GPIO, &reset);
	    do{
	    	gpio_get_value(ButtonGPIO, &reset);
	    	duration2 = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
	    	std::cout<< duration2-duration <<'\n';
	    }while(reset!=HIGH);*/




