#pragma once
#include "Graphics.h"
#include "Keyboard.h"
#include "Locations.h"
#include "Platforms.h"

using namespace std;

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


	Location loc;
	static constexpr int width = 10;
	static constexpr int height = 10;
};