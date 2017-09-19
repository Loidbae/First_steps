#include "Platform.h"

Platform::Platform()
	:
	PosX(50, 659),
	PosY(50, 459),
	DrawCordX(22, 50),
	DrawCordY(50, 60)
{

}

void Platform::DrawBox(Graphics& gfx)
{
	for (int in = 0; in < Pos.width; in++)
	{
		for (int i = 0; i < Pos.height; i++)
		{
			gfx.PutPixel(in+Pos.x, i+Pos.y,c);
		}
	}
}

void Platform::UpdateBoxCol(Entity& player)
{
																															    //            #Collision detection#            //
	const int BoxRight = Pos.x + Pos.width;																						// Almost done, but will be redone eventually. //
	const int BoxBottom = Pos.y + Pos.height;
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













