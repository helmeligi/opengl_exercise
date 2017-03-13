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
extern int test2_draw_triangle();
extern int test3_draw_rectangle();
extern int test4_draw_colored_triangle();

int main(void){

	int testNumber=0;

	cout<<"Enter test number to run\n "
			"0 --> Initial test for testing environment\n "
			"1 --> Tutorial1: Creating a window\n "
			"2 --> Tutorial2: Draw a Traingle\n "
			"3 --> Tutorial3: Draw a Rectangle\n "
			"4 --> Tutorial4: Shaders + Rasterization Effect\n "
			"*****************************************************\n";

	cin>>testNumber;

	switch(testNumber){
	case 0:
		test0(); //Testing Environment
		break;
	case 1:
		test1(); //Creating a window
		break;
		break;
	case 2:
		test2_draw_triangle();
		break;
	case 3:
		test3_draw_rectangle();
		break;
	case 4:
		test4_draw_colored_triangle();
		break;
	default:
		break;
	}

	return 0;

}
