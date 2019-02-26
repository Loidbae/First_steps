#pragma once
#include "Graphics.h"
#include "Coordinates.h"
#include "Player.h"
#include <random>

class Platform
{
public:
	Platform();
		
	void InitBoxes(mt19937& Rng)
	{
		rtc.x = posX(Rng);
		rtc.y = posY(Rng);
		rtc.w = drawCordX(Rng);
		rtc.h = drawCordY(Rng);
	}

	void drawbox(Graphics& Gfx) const ;
	void checksection(player& player);
	void updateboxcol(player& player) const;
	bool calc_collision(player& player, float ObjectX, float Objectwidth, float ObjectY, float Objectheight) const;
	void checkinboxvisualtest(Graphics& Gfx, player& player);

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
