/*
 * main.cpp

 *
 *  Created on: Mar 29, 2016
 *      Author: ececlass
 */

#include <iostream>
using namespace std;

int main() {

	float x0,x1,x2,x3,x4,x5,x6,x7,x8,x9,sum,sumSquares;

	cout << "Enter 10 integers, each separated by space, eg: 1 2 3 4 5 6 7 8 9 10" << endl;
	cin >> x0;
	cin >> x1;
	cin >> x2;
	cin >> x3;
	cin >> x4;
	cin >> x5;
	cin >> x6;
	cin >> x7;
	cin >> x8;
	cin >> x9;

	sum = x0+x1+x2+x3+x4+x5+x6+x7+x8+x9;
	sumSquares = x0*x0+x1*x1+x2*x2+x3*x3+x4*x4+x5*x5+x6*x6+x7*x7+x8*x8+x9*x9;

	cout << "The sum is: ";
	cout << sum << endl;
	cout << "The sum of the squares is: ";
	cout << sumSquares << endl;
	return 0;

}



