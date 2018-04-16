#pragma once
#include "Ship.h"
#include <iostream>
#include "Bot.h"
#include "Player.h"

class GameEngine
{
public:
	GameEngine();
	~GameEngine();
	void MapUpdate();
	void Show();
	void PrintInfo();
	void InstPref();
private:
	Bot bot;
	Player player;

};
