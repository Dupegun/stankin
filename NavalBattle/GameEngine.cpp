#include "stdafx.h"
#include "GameEngine.h"
#include <ctime>
#include <iostream>
using namespace std;


//need edit
GameEngine::GameEngine()
{
	
	
}

GameEngine::~GameEngine()
{
}

//edited
void GameEngine::InstPref()
{
	player.GlobalInit(player.ships, player.map);
	bot.GlobalInit(bot.ships, bot.map);
}

//edited
void GameEngine::MapUpdate()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k<10; k++)
			{
				if (bot.ships[k].IsDeck(i, j) && bot.ships[k].IsDead())
				{
					bot.map[i][j] = bot.CellState::DeadShip;

					break;
				}
				if (player.ships[k].IsDeck(i, j) && player.ships[k].IsDead())
				{
					player.map[i][j] = player.CellState::DeadShip;

					break;
				}
			}
		}
	}
} 

void GameEngine::Show()
{

	player.Show();

	cout << "\n";
	bot.Show(bot.map);
	player.MakePunch(&bot);
	PrintInfo();

}


void GameEngine::PrintInfo()
{
	for (size_t i = 0; i<bot.info.size(); i++)
		std::cout << bot.info[i];


}