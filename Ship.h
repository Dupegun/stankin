#include <cmath>

struct Point
{
	int x,y;
};

struct Location
{
public:
	Location() {}
	Location(int x0,int y0,int x1,int y1)
	{
		start.x=x0;
		start.y=y0;
		end.x=x1;
		end.y=y1;
	}
	Point start;
	Point end;
};

class Ship
{
private:
	int size;
	int hp;
	char icon;
	Location location;
	bool hits[10][10];
public:
	Ship();
	Ship(Location location);

	void SetSize();

	void DecHP();

	void CheckHit(Point HitPoint);

	void SetLocation(Location location);

	void Show(int i, int j);

	bool IsShip(int i, int j);
};