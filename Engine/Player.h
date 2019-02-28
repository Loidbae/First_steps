#pragma once
#include "Graphics.h"
#include "Keyboard.h"
#include "Coordinates.h"
#include <chrono>

class Player
{
public:
	Player()
	{
		rtc.x = 40; // Starting point
		rtc.y = 40; //---------------
		rtc.w = 10; // player size
		rtc.h = 10; //-----------
		rtc.v = 2.05f; // player Speed 
	}

	void draw(Graphics& gfx)const;
	void move(Keyboard& kbd);
	void wndborder();


	Coordinates rtc; // real-time-coordinates
};