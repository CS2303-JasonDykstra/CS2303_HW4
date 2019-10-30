/*
 * production.h
 *
 *  Created on: Sep 13, 2019
 *      Author: jasondykstra
 */

#ifndef PRODUCTION_H_
#define PRODUCTION_H_

#define FILENAMELENGTHALLOWANCE 50

#include "AdjMatrix.h"
#include "FloorPlan.h"
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct floorLayout{
	int numRooms;
	AdjMatrix* floorPlan;
};





class Production {
public:
	int maxRooms;
	int maxTreasure;
	Production();
	virtual ~Production();
	bool production(int argc, char* argv[]);
	floorLayout readFile();
};
#endif /* PRODUCTION_H_ */

