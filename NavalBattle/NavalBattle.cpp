
#include "stdafx.h"
#include <conio.h>
#include "GameEngine.h"

GameEngine Engine;

int main()
{
	while (true)
	{
		Engine.MapUpdate();
		Engine.Show();
		Engine.PrintInfo();
		Engine.MakePunch();
		system("cls");
	}
	_getch();
    return 0;
}

