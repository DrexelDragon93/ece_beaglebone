/*
 * main.cpp
 *
 *  Created on: Mar 31, 2016
 *      Author: ececlass
 */

#include <iostream>
#include<stdio.h>

using namespace std;

float fib(float n){

	if(n<=1)
		return n;
	return fib(n-1) + fib(n-2);

}

int main() {

	float x0,result,result2,goldenratio;

	cout << "Enter a single number: ";
	cin >> x0;

	result = fib(x0);
	result2 = fib(x0+1);
	goldenratio = result2/result;

	cout << "The Fibonacci number is: ";
	cout << result << endl;
	cout << "The Golden Ratio is: ";
	cout << goldenratio << endl;

	return 0;
}
