#pragma once
#include "Graphics.h"
#include "Coordinates.h"
#include "Player.h"
#include <random>

class Platform
{
public:
	Platform();
		
	void InitBoxes(mt19937& rng)
	{
		rtc.x = posX(rng);
		rtc.y = posY(rng);
		rtc.w = drawCordX(rng);
		rtc.h = drawCordY(rng);
	}

	void drawbox(Graphics& Gfx) const ;
	void checksection(Player& player);
	void updateboxcol(Player& player) const;
	bool calc_collision(Player& player, float ObjectX, float Objectwidth, float ObjectY, float Objectheight) const;
	void checkinboxvisualtest(Graphics& Gfx, Player& player);

	Coordinates rtc;
	Color c = Colors::Green;

private:
	uniform_real_distribution<float> posX;
	uniform_real_distribution<float> posY;
	uniform_real_distribution<float> drawCordX;
	uniform_real_distribution<float> drawCordY;

	bool collision_check;
	bool collision_check1;
	bool collision_check2;
	bool collision_check3;

};
