/*
 * FloorPlan.h
 *
 *  Created on: Sep 15, 2019
 *      Author: jasondykstra
 */

#ifndef FLOORPLAN_H_
#define FLOORPLAN_H_

#include "Production.h"
#include "AdjMatrix.h"
#include "Room.h"

struct point{
	int x;
	int y;
};


class FloorPlan {
public:
	AdjMatrix* edges;
	int position;
	int nRooms;
	Room rooms[6];
	float treasureFound;
	int roomsVisited;
	FloorPlan();
	virtual ~FloorPlan();
	void listPossibleMoves();
	void moveRooms();
	void initRooms();
};

#endif /* FLOORPLAN_H_ */
