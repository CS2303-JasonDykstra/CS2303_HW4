/*
 * tests.cpp
 *
 *  Created on: Sep 13, 2019
 *      Author: jasondykstra
 */

#include "Tests.h"


Tests::Tests() {
	// TODO Auto-generated constructor stub

}

Tests::~Tests() {
	// TODO Auto-generated destructor stub
}

bool Tests::tests(){
	bool answer = true;

	bool ok1 = testReadFile();
	bool ok2 = testConstructAdjacencyMatrix();
	bool ok3 = testIsEdge();
	bool ok4 = testAddEdge();
	bool ok5 = testRemoveEdge();
	bool ok6 = testListPossibleMoves();
	bool ok7 = testInitRooms();
	bool ok8 = testSetTreasure();
	answer = ok1 && ok2 && ok3 && ok4 && ok5 && ok6 && ok7 && ok8;
	return answer;
}

bool Tests::testReadFile(){
	bool ans = false;
	cout << "Testing read file" << endl;
	Production* prod = new Production();
	int howManyRooms = prod -> readFile().numRooms;
	if(howManyRooms == 6){
		ans = true;
	} else {
		cout << "testReadFile failed." << endl;
		cout << "read " << howManyRooms << " rooms instead of 6" << endl;
	}
	return ans;
}

bool Tests::testConstructAdjacencyMatrix(){
	bool answer = false;
	AdjMatrix* amP = new AdjMatrix(12);
	std::cout << "Constructed" << endl;

	if(amP -> isEdge(4, 3)){
		cout << "Edge too soon." << endl;
	}
	amP -> addEdge(3,4);
	if(amP -> isEdge(4,3)){
		answer = true;
	} else {
		cout << "testConstructAdjacencyMatrix failed." << endl;
	}
	return answer;
}

bool Tests::testIsEdge(){
	bool answer = true;
	AdjMatrix* amP = new AdjMatrix(12);
	std::cout << "Constructed" << endl;

	amP -> addEdge(3, 4);
	if(!amP -> isEdge(4,3)){
		answer = false;
		cout << "testIsEdge failed." << endl;
	}
	return answer;
}

bool Tests::testAddEdge(){
	bool answer = true;
	AdjMatrix* amP = new AdjMatrix(12);
	std::cout << "Constructed" << endl;

	amP -> addEdge(3, 4);
	if(!amP -> isEdge(4,3)){
		answer = false;
		cout << "testAddEdge failed." << endl;
	}
	return answer;
}

bool Tests::testRemoveEdge(){
	bool answer = true;
	AdjMatrix* amP = new AdjMatrix(12);

	if(amP -> isEdge(4, 3)){
		cout << "Edge too soon." << endl;
	}
	amP -> addEdge(4, 3);
	if(amP -> isEdge(4, 3)){
		cout << "Edge added." << endl;
	}
	amP -> removeEdge(4, 3);
	if(amP -> isEdge(4, 3)){
		cout << "testRemoveEdge failed." << endl;
		cout << "Edge not removed." << endl;
		answer = false;
	}
	cout << "Edge removed." << endl;
	return answer;
}

bool Tests::testListPossibleMoves(){
	bool answer = true;
	return answer;
}

bool Tests::testInitRooms(){
	bool answer = false;
	FloorPlan fp;
	fp.initRooms();
	for(int i = 0; i < fp.nRooms; i++){
		if(fp.rooms[i].treasure != 0){
			answer = true;
		}
	}

	if(answer == false){
		cout << "testInitRooms failed" << endl;
	}

	return answer;
}

bool Tests::testSetTreasure(){
	bool answer = false;
	Room r;
	r.setTreasure(5);
	if(r.treasure == 5){
		answer = true;
	} else {
		cout << "testSetTreasure failed" << endl;
	}
	return answer;
}
