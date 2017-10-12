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

	void DrawBox(Graphics& gfx) const ;
	void CheckSection(Entity& player);
	void UpdateBoxCol(Entity& player) const;
	bool Col_Check(Entity& player, int objectX, int objectwidth, int objectY, int objectheight) const;
	void CheckInBoxVisualtest(Graphics& gfx, Entity& player);
	bool GetCollisionCheck();
	bool GetCollisionCheck1();
	bool GetCollisionCheck2();
	bool GetCollisionCheck3();

	Location Pos;
	Color c = Colors::Green;

private:
	uniform_int_distribution<int> PosX;
	uniform_int_distribution<int> PosY;
	uniform_int_distribution<int> DrawCordX;
	uniform_int_distribution<int> DrawCordY;

	bool CollisionCheck;
	bool CollisionCheck1;
	bool CollisionCheck2;
	bool CollisionCheck3;

	
	
	

};
