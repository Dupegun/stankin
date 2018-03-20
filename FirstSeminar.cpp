#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <cmath>
#include "Ship.h"
using namespace std;

Ship ship[10]; //(0-3) - 1 deck, (4-6) - 2 deck, (7-8) - 3 deck, (9) - 4 deck

void init(Ship* ships)
{
	ship[0].SetLocation(Location(0,0,0,0));
	ship[1].SetLocation(Location(0,9,0,9));
	ship[2].SetLocation(Location(9,0,9,0));
	ship[3].SetLocation(Location(9,9,9,9));

	ship[4].SetLocation(Location(0,3,0,4));
	ship[5].SetLocation(Location(2,3,2,4));
	ship[6].SetLocation(Location(5,1,5,2));

	ship[7].SetLocation(Location(2,9,4,9));
	ship[8].SetLocation(Location(9,4,9,7));

	//ship[9].SetLocation()
}

void MakeHit()
{
	cout<<"Please input location (x,y): ";
	int x0;
	int y0;
	cin>>x0>>y0;
	Point HitPoint;
	HitPoint.x=x0;
	HitPoint.y=y0;
	for(int k=0; k<8; k++)
	{
		ship[k].CheckHit(HitPoint);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	init(ship);
	char escape=' ';
	while(escape!='`')
	{
		for(int i=0; i<10; i++)
		{
			for(int j=0; j<10; j++)
			{
				for(int k=0; k<8; k++)
					{
						ship[k].Show(i, j);
					}
				cout<<' ';
			}
			cout<<'\n';
		}
		MakeHit();
	}
	_getch();
	return 0;
}

