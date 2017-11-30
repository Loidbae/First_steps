#pragma once
#include "Graphics.h"
#include "Keyboard.h"
#include "Locations.h"
#include <chrono>

class Entity
{
public:
	Entity()
	{
		loc.x = 400;
		loc.y = 300;
		loc.width = 10;
		loc.height = 10;
	}

	void Draw(Graphics& gfx)const;
	void Move(Keyboard& kbd);
	void WNDBorder();
	void Test(Keyboard& kbd); // see cpp file


	Location loc;
};