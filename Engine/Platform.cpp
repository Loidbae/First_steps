#include "Platform.h"

Platform::Platform()
	:
	PosX(50, 659),
	PosY(50, 459),
	DrawCordX(22, 50),
	DrawCordY(50, 60)
{
}


void Platform::DrawBox(Graphics& gfx) const
{
	for (int in = 0; in < Pos.width; in++)
	{
		for (int i = 0; i < Pos.height; i++)
		{
			gfx.PutPixel(in + Pos.x, i + Pos.y, c);
		}
	}
}

void Platform::CheckSection(Entity & player)
{
	/*        Selfnote....kinda
		 _______________
	 ___|_______I_______|___
	|   | _____________ |   |   My idea here is to surround the object with sections which are indipendent of each other,
	|   ||             ||   |   when a section is activated, by steping in the designated area, the corresponding side-collision
	|   ||             ||   |   gets calculated.
	|   ||             ||   |
	|IV ||             || II|
	|   ||             ||   |
	|   ||             ||   |
	|   ||             ||   |
	|   ||_____________||   |
	|___|_______________|___|
		|______III______|
	*/

	// CCP# / CollisionCheckPoint/x/y/width/height

	const int CCPy = Pos.y - (Pos.height / 3);
	const int CCPh = Pos.height / 3;

	const int CCP1x = Pos.x + Pos.width;
	const int CCP1w = Pos.width / 2;

	const int CCP2y = Pos.y + Pos.height;
	const int CCP2h = Pos.height / 2;

	const int CCP3x = Pos.x - (Pos.width / 2);
	const int CCP3w = Pos.width / 2;

	// I
	if (Col_Check(player, Pos.x, Pos.width, CCPy, CCPh))
	{
		CollisionCheck = true;
	}

	// II
	if (Col_Check(player, CCP1x, CCP1w, Pos.y, Pos.height))
	{
		CollisionCheck1 = true;
	}

	// III
	if (Col_Check(player, Pos.x, Pos.width, CCP2y, CCP2h))
	{
		CollisionCheck2 = true;
	}

	// IV
	if (Col_Check(player, CCP3x, CCP3w, Pos.y, Pos.height))
	{
		CollisionCheck3 = true;
	}
}

void Platform::UpdateBoxCol(Entity& player) const
{
								
	const int BoxRight = Pos.x + Pos.width;
	const int BoxBottom = Pos.y + Pos.height;
	const int EntityRight = player.loc.x + player.loc.width;
	const int EntityBottom = player.loc.y + player.loc.height;

	//Finally the check if the area is active, if it is -> calculate collision accordingly;

	// Top
	if (CollisionCheck)
	{
		if (EntityBottom >= Pos.y && player.loc.x <= BoxRight && EntityRight >= Pos.x)
		{
			player.loc.y = (Pos.y - 1) - player.loc.height;
		}
	}

	// Left Side
	if (CollisionCheck3)
	{
		if (EntityRight >= Pos.x && player.loc.y <= BoxBottom && EntityRight >= Pos.y)
		{
			player.loc.x = (Pos.x - 1) - player.loc.width;
		}
	}

	// Right Side
	if (CollisionCheck1)
	{
		if (player.loc.x <= BoxRight && player.loc.y >= Pos.y && player.loc.y <= BoxBottom)
		{
			player.loc.x = BoxRight + 1;
		}

	}

	//Bottom
	if (CollisionCheck2)
	{
		if (player.loc.y <= BoxBottom && player.loc.x <= BoxRight && EntityRight >= Pos.x)
		{
			player.loc.y = BoxBottom + 1;
		}
	}
}

bool Platform::Col_Check(Entity & player, int objectX, int objectwidth, int objectY, int objectheight) const
{
	// basicly the check if something collides with the player

	const int EntityRight = player.loc.x + player.loc.width;
	const int EntityBottom = player.loc.y + player.loc.height;

	const int PointRight = objectX + objectwidth;
	const int PointBottom = objectY + objectheight;

	return EntityRight >= objectX &&
		player.loc.x <= PointRight &&
		EntityBottom >= objectY &&
		player.loc.y <= PointBottom;
}

void Platform::CheckInBoxVisualtest(Graphics& gfx, Entity& player)
{
	if (CollisionCheck|| CollisionCheck1|| CollisionCheck2|| CollisionCheck3)
	{
		c = Colors::Red;
		CollisionCheck = false;
		CollisionCheck1 = false;
		CollisionCheck2 = false;
		CollisionCheck3 = false;
	}
	else
	{
		c = Colors::Green;
	}

	/*if (player.loc.y < Pos.y - (Pos.height / 3))
	{

	}*/
}