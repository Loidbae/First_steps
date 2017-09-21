#pragma once
#include "Graphics.h"
#include "Locations.h"
#include "Entity.h"
#include <random>

using namespace std;
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

	void DrawBox(Graphics& gfx);
	void UpdateBoxCol(Entity& player);
	void CheckInBox(Entity& player); // BOOOL
	void CheckInBoxVisualtest(Graphics& gfx);

private:
	uniform_int_distribution<int> PosX;
	uniform_int_distribution<int> PosY;
	uniform_int_distribution<int> DrawCordX;
	uniform_int_distribution<int> DrawCordY;

	bool CollisionCheck = false;
	bool CollisionCheck1 = false;
	bool CollisionCheck2 = false;
	bool CollisionCheck3 = false;

	Color c= Colors::Green;
	Location Pos;
	

};
