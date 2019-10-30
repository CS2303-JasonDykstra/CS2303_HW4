/*
 * Room.h
 *
 *  Created on: Sep 15, 2019
 *      Author: jasondykstra
 */

#ifndef ROOM_H_
#define ROOM_H_

#include <cstdlib>
#include <iostream>

class Room {
public:
	float treasure;
	bool hasBeenVisited;
	Room();
	virtual ~Room();
	bool hasTreasure();
	void wasVisited();
	bool getVisited();
	void setTreasure(float t);
};

#endif /* ROOM_H_ */
