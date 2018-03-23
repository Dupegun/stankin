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
}

Ship::~Ship()
{
}

std::vector<Point>* Ship::GetLocation()
{
	return &location;
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
		if(x==location[i].x && y==location[i].y)
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
