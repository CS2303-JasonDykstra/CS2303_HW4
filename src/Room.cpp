/*
 * Room.cpp
 *
 *  Created on: Sep 15, 2019
 *      Author: jasondykstra
 */

#include "Room.h"

Room::Room() {
	// TODO Auto-generated constructor stub
	treasure = 0;
	hasBeenVisited = false;
}

Room::~Room() {
	// TODO Auto-generated destructor stub
}

bool Room::hasTreasure(){
	bool answer = false;
	if(treasure > 0){
		answer = true;
	}
	return answer;
}

void Room::wasVisited(){
	hasBeenVisited = true;
}

bool Room::getVisited(){
	return hasBeenVisited;
}

void Room::setTreasure(float t){
	treasure = t;
}
