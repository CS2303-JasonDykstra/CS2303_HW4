/*
 * AdjMatrix.cpp
 *
 *  Created on: Sep 13, 2019
 *      Author: jasondykstra
 */

#include "AdjMatrix.h"

AdjMatrix::AdjMatrix() {
	// TODO Auto-generated constructor stub
	AdjMatrix(10); //default size is 10


}

AdjMatrix::AdjMatrix(int nVerticies) {
	this -> numVerticies = nVerticies;
	adjMatrixArray = new bool*[numVerticies];
	for(int i = 0; i < numVerticies; i++){
		adjMatrixArray[i] = new bool[numVerticies];
		for(int j = 0; j < numVerticies; j++){
			//initialize array to be false
			adjMatrixArray[i][j] = false;
		}
	}
}

//creates arrows both ways, from room i to j and from room j to i
void AdjMatrix::addEdge(int i, int j){
	adjMatrixArray[i][j] = true;
	adjMatrixArray[j][i] = true;
}

void AdjMatrix::removeEdge(int i, int j){
	adjMatrixArray[i][j] = false;
	adjMatrixArray[j][i] = false;
}

bool AdjMatrix::isEdge(int i, int j){
	return adjMatrixArray[i][j];
}

int AdjMatrix::howManyVerticies(){
	return numVerticies;
}

AdjMatrix::~AdjMatrix(){
	// TODO Auto-generated destructor stub
}


