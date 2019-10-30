/*
 * AdjMatrix.h
 *
 *  Created on: Sep 13, 2019
 *      Author: jasondykstra
 */

#ifndef ADJMATRIX_H_
#define ADJMATRIX_H_

#include <iostream>
using namespace std;

class AdjMatrix {
private:
	bool** adjMatrixArray = (bool**) 0;
	int numVerticies = 10;
public:
	AdjMatrix();
	AdjMatrix(int numVerticies);
	void addEdge(int i, int j);
	void removeEdge(int i, int j);
	bool isEdge(int i, int j);
	bool formsCycle(int i, int j);
	int howManyVerticies();
	virtual ~AdjMatrix();
};

#endif /* MESSUP_H_ */
