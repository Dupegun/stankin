#include "stdafx.h"
#include <conio.h>
#include "GameEngine.h"

GameEngine Engine;

int main()
{
	Engine.InstPref();
	while (true)
	{
		Engine.MapUpdate();
		Engine.PrintInfo();
		Engine.Show();
		system("cls");
	}
	_getch();
	return 0;
}
