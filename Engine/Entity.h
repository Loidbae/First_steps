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
		loc.sp = 1.75f;
	}

	void Draw(Graphics& gfx)const;
	void Move(Keyboard& kbd);
	void WNDBorder();


	Location loc;
};