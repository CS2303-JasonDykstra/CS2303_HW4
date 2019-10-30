/*
 * tests.h
 *
 *  Created on: Sep 13, 2019
 *      Author: jasondykstra
 */

#ifndef TESTS_H_
#define TESTS_H_

#include "AdjMatrix.h"
#include "Production.h"
#include "FloorPlan.h"
#include <iostream>
using namespace std;

class Tests {
public:
	Tests();
	virtual ~Tests();
	bool tests();
	bool testReadFile();
	bool testConstructAdjacencyMatrix();
	bool testIsEdge();
	bool testAddEdge();
	bool testRemoveEdge();
	bool testListPossibleMoves();
	bool testInitRooms();
	bool testSetTreasure();
};

#endif /* TESTS_H_ */
