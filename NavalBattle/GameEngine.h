#pragma once
#include "Ship.h"
#include <iostream>

class GameEngine
{
public:
	GameEngine();
	~GameEngine();

	void ShipsInit();

	void MapInit();

	void MapUpdate();

	void Show();

	void PrintInfo();

	bool MakePunch();

	enum CellState {Empty, Deck, Punched, Damaged, DeadShip};
private:
	Ship ships[10]; //(0-3) - 1 deck, (4-6) - 2 deck, (7-8) - 3 deck, (9) - 4 deck

	CellState map[10][10];

	std::string info;
};

