#pragma once
#include "Graphics.h"
#include "Keyboard.h"
#include "Locations.h"
#include <chrono>

class Player
{
public:
	Player()
	{
		_Coord.X = 40; // Starting point
		_Coord.Y = 40; //---------------
		_Coord.Width = 10; // Player size
		_Coord.Height = 10; //-----------
		_Coord.Sp = 2.05f; // Player Speed 
	}

	void draw(Graphics& Gfx)const;
	void move(Keyboard& Kbd);
	void wndborder();


	Coordinates _Coord;
};