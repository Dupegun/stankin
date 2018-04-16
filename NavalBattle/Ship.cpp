#include "stdafx.h"
#include "Ship.h"

Ship::Ship()
{
}

void Ship::SetLocation(int x, int y)
{
	location.reserve(1);

	Point p;
	p.x = x;
	p.y = y;
	location.push_back(p);

	Starter_HP = 1;
	hp = Starter_HP;
	ShipSize = Starter_HP;
}

void Ship::SetLocation(int x, int y, int x1, int y1)
{
	location.reserve(2);

	Point p;
	p.x = x;
	p.y = y;
	location.push_back(p);

	Point p1;
	p1.x = x1;
	p1.y = y1;
	location.push_back(p1);

	Starter_HP = 2;
	hp = Starter_HP;
	ShipSize = Starter_HP;
}

void Ship::SetLocation(int x, int y, int x1, int y1, int x2, int y2)
{
	location.reserve(3);

	Point p;
	p.x = x;
	p.y = y;
	location.push_back(p);

	Point p1;
	p1.x = x1;
	p1.y = y1;
	location.push_back(p1);

	Point p2;
	p2.x = x2;
	p2.y = y2;
	location.push_back(p2);

	Starter_HP = 3;
	hp = Starter_HP;
	ShipSize = Starter_HP;
}

void Ship::SetLocation(int x, int y, int x1, int y1, int x2, int y2, int x3, int y3)
{
	location.reserve(4);

	Point p;
	p.x = x;
	p.y = y;
	location.push_back(p);

	Point p1;
	p1.x = x1;
	p1.y = y1;
	location.push_back(p1);

	Point p2;
	p2.x = x2;
	p2.y = y2;
	location.push_back(p2);

	Point p3;
	p3.x = x3;
	p3.y = y3;
	location.push_back(p3);

	Starter_HP = 4;
	hp = Starter_HP;
	ShipSize = Starter_HP;
}

Ship::~Ship()
{
}

std::vector<Point>* Ship::GetLocation()
{
	return &location;
}

void Ship::RotateLocation()
{
	int RotationMatrix[2][2] = { { 0, -1 },{ 1, 0 } };
	int LocationMatrix[2][4];
	int product[2][4];

	for (int i = 0; i<2; i++)
		for (int j = 0; j<4; j++)
			product[i][j] = 0;

	//int max = location.size();
	int max = ShipSize;

	//init location matrix
	for (size_t j = 0; j < max; j++)
	{
		LocationMatrix[0][j] = location[j].x;
	}

	for (size_t j = 0; j < max; j++)
	{
		LocationMatrix[1][j] = location[j].y;
	}

	for (size_t row = 0; row < 2; row++) {
		for (size_t col = 0; col < max; col++) {
			for (int inner = 0; inner < 2; inner++) {
				product[row][col] += RotationMatrix[row][inner] * LocationMatrix[inner][col];
			}
		}
	}

	//Re-init location
	for (size_t j = 0; j < max; j++)
	{
		location[j].x = abs(product[0][j]);
	}

	for (size_t j = 0; j < max; j++)
	{
		location[j].y = abs(product[1][j]);
	}
}

void Ship::MirroringLocation(int axis)
{
	if (axis == 0)
	{
		for (size_t i = 0; i < location.size(); i++)
		{
			location[i].x = 9 - location[i].x;
		}
	}
	else if (axis == 1)
	{
		for (size_t i = 0; i < location.size(); i++)
		{
			location[i].y = 9 - location[i].y;
		}
	}
}

int Ship::GetHP()
{
	return hp;
}

void Ship::DecHP()
{
	if (hp > 0)
	{
		hp--;
	}
}

bool Ship::IsDeck(int x, int y)
{
	for (size_t i = 0; i < location.size(); i++)
	{
		if (x == location[i].x && y == location[i].y)
		{
			return true;
		}
	}
	return false;
}

bool Ship::IsDead()
{
	if (hp > 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}