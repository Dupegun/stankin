#pragma once
#include "BasicLogic.h"
#include "Bot.h"
class Player :
	public BasicLogic
{
public:
	Player();
	~Player();
	bool MakePunch(Bot* bot);
	void Show();
	Ship ships[10]; //(0-3) - 1 deck, (4-6) - 2 deck, (7-8) - 3 deck, (9) - 4 deck
	CellState map[10][10];
};

