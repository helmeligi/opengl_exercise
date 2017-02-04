/*
 * main.cpp
 *
 *  Created on: Feb 4, 2017
 *      Author: hisham
 */

#include <iostream>

using namespace std;

extern int test0(void);
extern int test1(void);

int main(void){

	int testNumber=0;

	cout<<"Enter test number to run\n "
			"0 --> Initial test for testing environment\n "
			"1 --> Tutorial1: Creating a window\n "
			"*****************************************************\n";

	cin>>testNumber;

	switch(testNumber){
	case 0:
		test0(); //Testing Environment
		break;
	case 1:
		test1(); //Creating a window
		break;
	default:
		break;
	}

	return 0;

}
