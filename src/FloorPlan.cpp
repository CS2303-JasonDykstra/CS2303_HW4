/*
 * FloorPlan.cpp
 *
 *  Created on: Sep 15, 2019
 *      Author: jasondykstra
 */

#include "FloorPlan.h"

FloorPlan::FloorPlan() {
	// TODO Auto-generated constructor stub
	Production prod;
	edges = prod.readFile().floorPlan;
	nRooms = prod.readFile().numRooms;
	position = 0;
	treasureFound = 0;
	roomsVisited = 0;



	rooms[0].wasVisited();
}

FloorPlan::~FloorPlan() {
	// TODO Auto-generated destructor stub
}

void FloorPlan::listPossibleMoves(){
	cout << "Currently in room: " << position << endl;
	cout << "Possible moves include room(s): ";
	for(int i = 0; i < nRooms; i++){
		if(edges -> isEdge(position, i)){
			cout << i << " ";
		}
	}
	cout << endl;
}

void FloorPlan::moveRooms(){

	int nextRoom = 0;

	cout << "Which room would you like to move to?: ";
	cin >> nextRoom;

	//make sure its a possible move
	bool legal = false;
	for(int i = 0; i < nRooms; i++){
		if(edges -> isEdge(position, nextRoom)){
			legal = true;
		}
	}

	//if user makes a legal move, go on with the program and move rooms
	if(legal){
		ofstream output;
		output.open("output.txt", std::ios_base::app);
		position = nextRoom;
		if(!rooms[position].getVisited()){
			treasureFound += rooms[position].treasure;
			rooms[position].wasVisited();
			roomsVisited++;
			cout << "You found " << rooms[position].treasure << " treasure in this room!" << endl;

			//also write to file
			output << position << " " << treasureFound << endl;
		} else {
			cout << "No treasure found, you've already visited this room." << endl;
		}
		cout << "Total treasure so far: " << treasureFound << endl;
		cout << "Total rooms visited: " << roomsVisited << endl;

		output.close();
	} else {
		cout << "You can not move to this room, please pick a different room." << endl;
	}



}

void FloorPlan::initRooms(){
	//get contents of rooms.txt in an array, line by line
	string data[20];
	std::ifstream roomData("rooms.txt");
	int counter = 0;
	for(std::string line; getline(roomData, line);){
		data[counter] = line;
		counter++;
	}

	//interpret data
	//start reading treasure amounts after the adj matrix
	for(int i = 0; i < nRooms; i++){
		rooms[i].setTreasure(stof(data[i + nRooms + 1]));
		cout << "set room " << i << " to " << stof(data[i + nRooms + 1]) << " treasure" << endl;
	}


}
