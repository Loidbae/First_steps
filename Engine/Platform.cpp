#include "Platform.h"

Platform::Platform()
	:
	PosX(50, 600),
	PosY(50, 500),
	DrawCordX(10, 50),
	DrawCordY(10, 70)
{

}

void Platform::DrawBox(Graphics& gfx)
{

	for (int in = 0; in < Dim.x; in++)
	{
		for (int i = 0; i < Dim.y; i++)
		{
			gfx.PutPixel(in+Pos.x, i+Pos.y, 255,255,255);
		}
	}
}

bool Platform::Colliding() const
{
	return IsColliding;
}

//void Platform::Respawn(std::mt19937& rng,Entity & player)
//{
//	
//
//	Location newPos;
//	
//	newPos.x = Distx(rng);
//	newPos.x = Distx(rng);
//
//	Pos = newPos;
//
//}

void Platform::UpdateBoxCol(Entity& player)
{

	const int BoxRight = Pos.x + Dim.x;
	const int BoxBottom = Pos.y + Dim.y;
	const int EntityRight = player.loc.x + player.width;
	const int EntityBottom = player.loc.y + player.height;

	if (BoxRight >= player.loc.x &&
		Pos.x <= EntityRight &&
		BoxBottom >= player.loc.y &&
		Pos.y <= EntityBottom)
	{
		player.loc.y -= 1;
	}
}













