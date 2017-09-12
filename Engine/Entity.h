#pragma once
#include "Graphics.h"
#include "Keyboard.h"
#include "Locations.h"

class Entity
{
public:
	Entity(const Location& delta_loc)
	{
		loc = delta_loc;
	}

	void Draw(Graphics& gfx)const;
	void Move(Keyboard& kbd);
	void WNDBorder();
	void Test(Keyboard& kbd);
	bool Testoroni();

	Location loc;
	static constexpr int width = 10;
	static constexpr int height = 10;
};