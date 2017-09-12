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
	void InitBoxes(std::mt19937& rng)
	{
		Pos.x = PosX(rng);
		Pos.y = PosY(rng);
		Dim.x = DrawCordX(rng);
		Dim.y = DrawCordY(rng);
	}
	void DrawBox(Graphics& gfx);
	bool Colliding()const;
	void UpdateBoxCol(Entity& player);

private:
	uniform_int_distribution<int> PosX;
	uniform_int_distribution<int> PosY;
	uniform_int_distribution<int> DrawCordX;
	uniform_int_distribution<int> DrawCordY;
	

	Location Pos,Dim;
	bool IsColliding = false;
	

};
