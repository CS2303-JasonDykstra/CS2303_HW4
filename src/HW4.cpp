//============================================================================
// Name        : HW3Test.cpp
// Author      : Jason Dykstra
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Tests.h"
#include "Production.h"
using namespace std;

//test to make sure this takes in command line arguments
//nRows nCols gens fileName optionalPrint optionalPause
int main(int argc, char* argv[]) {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	Tests test;
	Production prod;

	if(test.tests()){
		prod.production(argc, argv);
	} else {
		cout << "tests did not pass." << endl;
	}

	return 0;
}

