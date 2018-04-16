#include "stdafx.h"
#include "Player.h"
#include <ctime>

Player::Player()
{
}


Player::~Player()
{
}

void Player::Show()
{

	std::cout << ' ';
	for (int i = 0; i < 10; i++) std::cout << i;
	std::cout << "\n ";

	for (int i = 0; i < 10; i++) std::cout << '_';
	std::cout << '\n';

	//map draw loop
	for (int i = 0; i<10; i++)
	{
		std::cout << i;

		for (int j = 0; j<10; j++)
		{
			switch (map[i][j])
			{
			case CellState::Deck:
				std::cout << '*';
				break;
			case CellState::Punched:
				std::cout << '.';
				break;
			case CellState::Damaged:
				std::cout << '+';
				break;
			case CellState::DeadShip:
				std::cout << 'X';
				break;
			case CellState::Empty:
				std::cout << ' ';
				break;
			default:
				std::cout << ' ';
			}
		}
		std::cout << '\n';
	}
}


bool Player::MakePunch(Bot* bot)
{
	int x, y;
	std::cout << "\nPlease input x, y: ";
	std::cin >> x >> y;
 	bot->map[x][y] = CellState::Punched;
	
	
	//ÀÍÄĞÅÅÉ ß ÒÅÁß ÏĞÈĞÅÆÓ çà ãîâíîêîä

	for (int k = 0; k<10; k++)
	{
		if (bot->ships[k].IsDeck(x, y))
		{
			bot->ships[k].DecHP();
			bot->map[x][y] = CellState::Damaged;

			if (bot->ships[k].IsDead())
				bot->info = "\n DEAD SHIP! \n";
			else
				bot->info = "\nShip was damaged\n";

			return true;
		}
	}
	return false;
}
