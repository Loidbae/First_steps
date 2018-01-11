#pragma once
#include "Graphics.h"
#include "Locations.h"
#include "Player.h"
#include <random>

class Platform
{
public:
	Platform();
		
	void InitBoxes(mt19937& Rng)
	{
		_Pos.X = _PosX(Rng);
		_Pos.Y = _PosY(Rng);
		_Pos.Width = _DrawCordX(Rng);
		_Pos.Height = _DrawCordY(Rng);
	}

	void drawbox(Graphics& Gfx) const ;
	void checksection(Player& Player);
	void updateboxcol(Player& Player) const;
	bool calc_collision(Player& Player, float ObjectX, float Objectwidth, float ObjectY, float Objectheight) const;
	void checkinboxvisualtest(Graphics& Gfx, Player& Player);

	Coordinates _Pos;
	Color c = Colors::Green;

private:
	uniform_real_distribution<float> _PosX;
	uniform_real_distribution<float> _PosY;
	uniform_real_distribution<float> _DrawCordX;
	uniform_real_distribution<float> _DrawCordY;

	bool CollisionCheck;
	bool CollisionCheck1;
	bool CollisionCheck2;
	bool CollisionCheck3;

};
