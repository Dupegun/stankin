#include "stdafx.h"
#include <iostream>
#include "Ship.h"

	Ship::Ship(Location location)
	{
		this->location=location;
		icon=' ';
		SetSize();
		hp=size;
		for(int i=0; i<10; i++)
		{
			for(int j=0; j<10; j++)
			{
				hits[i][j]=false; // летку не трогали
			}
		}
	}

	Ship::Ship()
	{
		icon=' ';
		SetSize();
		hp=size;
		for(int i=0; i<10; i++)
		{
			for(int j=0; j<10; j++)
			{
				hits[i][j]=false; // летку не трогали
			}
		}
	}

	void Ship::SetSize()	
	{
		size=(int)sqrt( pow((location.end.x-location.start.x), 2) + pow((location.end.y-location.start.y), 2) );
	}

	void Ship::DecHP()
	{
		if(hp>0)
		{ hp--; }
		else 
		{ 
			std::cout<<"\n DEAD SHIP \n"; 
			icon='X';
		}
	}

	bool Ship::IsShip(int i, int j)
	{
		if(j<=location.end.x && j>=location.start.x
		  && i<=location.end.y && i>=location.start.y)
		{
			return true;
		}
		return false;
	}

	void Ship::CheckHit(Point HitPoint)
	{
		if (hits[HitPoint.x][HitPoint.y]) 
			{
				std::cout<<"\n This point was already hit!!!!!! \n";
				return;
			}

		hits[HitPoint.x][HitPoint.y]=true;

		if(HitPoint.x<=location.end.x && HitPoint.x>=location.start.x
		  && HitPoint.y<=location.end.y && HitPoint.y>=location.start.y) //”простить через IsShip 
		{
			std::cout<<"\n ship was hit \n";
			DecHP();
		}
	}

	void Ship::SetLocation(Location location)
	{
		this->location=location;
	}

	void Ship::Show(int i, int j)
	{
		if(IsShip(i, j))
		{
			//std::cout<<"DEBUG ship location "<< location.end.x <<' '<< location.start.x <<' '<< location.end.y <<' '<< location.start.y<<' ';
			//std::cout<<"i="<<i<<" j="<<j<<'\n';
			std::cout<<icon;
			//return true;
		}
			//std::cout<<'~'; //no ship
		//return false;
	}