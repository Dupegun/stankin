#pragma once
#include "Ship.h"
#include <iostream>

class BasicLogic
{
public:
	enum CellState { Empty, Deck, Punched, Damaged, DeadShip };

	BasicLogic();
	virtual ~BasicLogic();

	void ShipsInit(Ship* ships);

	void MapInit(Ship* ships, CellState map[10][10]);

	void Show(CellState map[10][10]);

	void GlobalInit(Ship* ships, CellState map[10][10]);
	
	std::string info;

	

};


