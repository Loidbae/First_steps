#pragma once
#include "Graphics.h"
#include "Locations.h"
#include "Entity.h"
#include <random>

class Platform
{
public:
	Platform();
		
	void InitBoxes(mt19937& rng)
	{
		Pos.x = PosX(rng);
		Pos.y = PosY(rng);
		Pos.width = DrawCordX(rng);
		Pos.height = DrawCordY(rng);
	}

	void DrawBox(Graphics& gfx) const ;
	void CheckSection(Entity& player);
	void UpdateBoxCol(Entity& player) const;
	bool Col_Check(Entity& player, float objectX, float objectwidth, float objectY, float objectheight) const;
	void CheckInBoxVisualtest(Graphics& gfx, Entity& player);

	Location Pos;
	Color c = Colors::Green;

private:
	uniform_real_distribution<float> PosX;
	uniform_real_distribution<float> PosY;
	uniform_real_distribution<float> DrawCordX;
	uniform_real_distribution<float> DrawCordY;

	bool CollisionCheck;
	bool CollisionCheck1;
	bool CollisionCheck2;
	bool CollisionCheck3;

};
