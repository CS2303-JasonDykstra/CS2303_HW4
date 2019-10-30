/*
 * Production.cpp
 *
 *  Created on: Sep 13, 2019
 *      Author: jasondykstra
 */

#include "Production.h"



Production::Production() {
	// TODO Auto-generated constructor stub
	maxRooms = 0;
	maxTreasure = 0;
}

Production::~Production() {
	// TODO Auto-generated destructor stub
}

bool Production::production(int argc, char* argv[]){
	bool answer = false;
	long maxRooms_L;
	long maxTreasure_L;
	long gens_L;
	int gens = 0;
	bool print = false;
	bool pause = false;
	char filename[FILENAMELENGTHALLOWANCE];
	FloorPlan fp;
	fp.initRooms();

	//clear output file upon start
	ofstream output;
	output.open("output.txt");
	output.close();

	if(argc == 1){
		cout << "type a number for max rooms: ";
		cin >> maxRooms;
		cout << "type a number for max treasure: ";
		cin >> maxTreasure;
	} else if(argc == 2){
		//prompt user for maxRooms and maxTreasure if not specificed in arguments
		char* ePtr = (char*) malloc(sizeof(char*));
		maxRooms_L = strtol(argv[1], &ePtr, 10);
		maxRooms = (int) maxRooms_L;
		cout << "type a number for max treasure: ";
		cin >> maxTreasure;
	} else {
		//there is interesting info from command line
		printf("Found %d arguments.\n", argc);
		fflush(stdout);

		for(int i = 1; i < argc; i++){
			//start at i=1 so you don't read the path
			char* ePtr = (char*) malloc(sizeof(char*));
			switch(i){
			case 1:
				//this is nRows
				maxRooms_L = strtol(argv[i], &ePtr, 10);
				maxRooms = (int) maxRooms_L;
				break;
			case 2:
				//this is nCols
				maxTreasure_L = strtol(argv[i], &ePtr, 10);
				maxTreasure = (int) maxTreasure_L;
				break;
			default:
				puts("Unexpected argument count.");
				break;
			}
		}
	}

	//print variables
	cout << "max rooms: " << maxRooms << " max treasure: " << maxTreasure << endl;

	//list possible moves and interpret user input to move rooms
	while(fp.treasureFound < maxTreasure && fp.roomsVisited < maxRooms){
		fp.listPossibleMoves();
		fp.moveRooms();
	}

	//set up stop conditions
	if(fp.treasureFound >= maxTreasure){
		cout << "You've reached the limit for treasure found!" << endl;
	} else if(fp.roomsVisited >= maxRooms){
		cout << "You've reached the limit for rooms visited!" << endl;
	}

	return answer;
}

//returns number of rooms
floorLayout Production::readFile(){
	floorLayout ans;
	int nRooms = -1;
	ifstream inFile("rooms.txt", ios::in);
	if(!inFile){
		cerr << "File could not be opened." << endl;
		exit(1);
	}
	inFile >> nRooms;
	int* arrayP = (int*) malloc (nRooms * nRooms * sizeof(int));

	std::cout << "read nRooms from file, obtained " << nRooms << endl;

	for(int roomR = 0; roomR < nRooms; roomR++){
		*(arrayP + (roomR * nRooms) + roomR) = 1;

		for(int roomC = 0; roomC < roomR; roomC++){
			int bit_I = -1;

			inFile >> bit_I;

			*(arrayP + (roomR * nRooms) + roomC) = bit_I;
			*(arrayP + (roomC * nRooms) + roomR) = bit_I;
		}
	}

	//lower left is filled with ints, also upper right
	//not print the matrix into the console

	for(int roomR = 0; roomR < nRooms; roomR++){
		for(int roomC = 0; roomC < nRooms; roomC++){
			//how does this line end?
			std::cout << *(arrayP + (roomR * nRooms) + roomC);
			if(roomC < (nRooms - 1)){
				std::cout << " ";
			} else {
				std::cout << std::endl;
			}
		}
	}

	//use the file content to construct the AdjMatrix instance
	AdjMatrix* amP = new AdjMatrix(nRooms);
	for(int roomR = 0; roomR < nRooms; roomR++){
		for(int roomC = 0; roomC < roomR; roomC++){
			if(*(arrayP + (roomR * nRooms) + roomC)){
				amP -> addEdge(roomR, roomC);
			}
		}
	}


	inFile.close();
	ans.numRooms = nRooms;
	ans.floorPlan = amP;
	return ans;
}
