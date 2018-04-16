#include "stdafx.h"
#include "BasicLogic.h"
#include <ctime>


BasicLogic::BasicLogic()
{
	
}

BasicLogic::~BasicLogic()
{
}

void BasicLogic::ShipsInit(Ship* ships)
{
	//default init
	ships[0].SetLocation(0, 0);
	ships[1].SetLocation(0, 9);
	ships[2].SetLocation(9, 0);
	ships[3].SetLocation(9, 9);

	ships[4].SetLocation(0, 3, 0, 4);
	ships[5].SetLocation(2, 3, 2, 4);
	ships[6].SetLocation(5, 1, 5, 2);

	ships[7].SetLocation(2, 9, 3, 9, 4, 9);
	ships[8].SetLocation(9, 2, 9, 3, 9, 4);

	ships[9].SetLocation(9, 7, 8, 7, 7, 7, 6, 7);

	srand(time(NULL) | clock());
	int RotateThem = rand() % 2;
	int MirThem = rand() % 2;
	int MirDir = rand() % 2;

	for (int i = 0; i < 10; i++)
	{
		if (RotateThem == 1)
			ships[i].RotateLocation();
		if (MirThem == 1)
			ships[i].MirroringLocation(MirDir);
	}
}

void BasicLogic::MapInit(Ship* ships, CellState map[10][10])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k<10; k++)
			{
				if (ships[k].IsDeck(i, j))
				{
					map[i][j] = CellState::Deck;
					//std::cout << "map[" << i << "][" << j << "] =" << map[i][j]<<'\n';
					break;
				}
				else
				{
					map[i][j] = CellState::Empty;
				}
			}
		}
	}
}

void BasicLogic::Show(CellState map[10][10])
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

void BasicLogic::GlobalInit(Ship* ships, CellState map[10][10])
{
	ShipsInit(ships);
	MapInit(ships, map);
	info = " ";
}

