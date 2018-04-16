#pragma once
#include <vector>

struct Point
{
	int x, y;
};

class Ship
{
public:
	Ship();
	~Ship();
	void SetLocation(int x, int y);
	void SetLocation(int x, int y, int x1, int y1);
	void SetLocation(int x, int y, int x1, int y1, int x2, int y2);
	void SetLocation(int x, int y, int x1, int y1, int x2, int y2, int x3, int y3);

	std::vector<Point>* GetLocation();

	/*Turns the position of the ship on 90 degrees counter-clockwise
	relative to the coordinates origin and take abs()
	*/
	void RotateLocation();


	/*Reflects relative to the middle of the
	axis=0 ---- x-axis
	axis=1 ---- y-axis
	*/
	void MirroringLocation(int axis);


	int GetHP();

	void DecHP();

	bool IsDeck(int x, int y);

	bool IsDead();

private:
	std::vector<Point> location;

	//basic health points
	int Starter_HP;

	//variable health points
	int hp;

	size_t ShipSize;
};