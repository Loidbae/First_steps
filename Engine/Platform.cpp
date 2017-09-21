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
								
	const int BoxRight = Pos.x + Pos.width;
	const int BoxBottom = Pos.y + Pos.height;
	const int EntityRight = player.loc.x + player.loc.width;
	const int EntityBottom = player.loc.y + player.loc.height;

	//Finally the check if area is selected, then calculating collision accordingly;

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

void Platform::CheckInBox(Entity & player)
{
	/*        Selfnote....kinda
	         _______________
	     ___|_______I_______|___
	    |   | _____________ |   |   My idea here is to sourround the object with sections which are indipendent of each other,
	    |   ||             ||   |   when a section is getting activated, by steping in the designated area, the corresponding side-collision
	    |   ||             ||   |   gets calculated.
	    |   ||             ||   |   
		|IV ||             || II|
		|   ||             ||   |	//Edit1: Success.
		|   ||             ||   | 
		|   ||             ||   |
		|   ||_____________||   |
		|___|_______________|___|
	        |______III______|
	*/

	// CCP# / CollisionCheckPoint##### /x/y/width/height
	
	const int CCPx = Pos.x;
	const int CCPy = Pos.y - (Pos.height / 3);
	const int CCPw = Pos.width;
	const int CCPh = Pos.height / 3;

	const int CCP1x = Pos.x + Pos.width;
	const int CCP1y = Pos.y;
	const int CCP1w = Pos.width / 2;
	const int CCP1h = Pos.height;

	const int CCP2x = Pos.x;
	const int CCP2y = Pos.y + Pos.height;
	const int CCP2w = Pos.width;
	const int CCP2h = Pos.height / 2;

	const int CCP3x = Pos.x - (Pos.width / 2);
	const int CCP3y = Pos.y;
	const int CCP3w = Pos.width / 2;
	const int CCP3h = Pos.height;

	const int PointRight = CCPx + CCPw;
	const int PointBottom = CCPy + CCPh;
	const int EntityRight = player.loc.x + player.loc.width;
	const int EntityBottom = player.loc.y + player.loc.height;

	const int PointRight1 = CCP1x + CCP1w;
	const int PointBottom1 = CCP1y + CCP1h;
	const int EntityRight1 = player.loc.x + player.loc.width;
	const int EntityBottom1 = player.loc.y + player.loc.height;

	const int PointRight2 = CCP2x + CCP2w;
	const int PointBottom2 = CCP2y + CCP2h;
	const int EntityRight2 = player.loc.x + player.loc.width;
	const int EntityBottom2 = player.loc.y + player.loc.height;

	const int PointRight3 = CCP3x + CCP3w;
	const int PointBottom3 = CCP3y + CCP3h;
	const int EntityRight3 = player.loc.x + player.loc.width;
	const int EntityBottom3 = player.loc.y + player.loc.height;
	
	//I
	if (EntityRight >= CCPx &&
	player.loc.x <= PointRight &&
	EntityBottom >= CCPy &&
	player.loc.y <= PointBottom)
	{
	CollisionCheck = true;
	c = Colors::Red;
	}

	//II
	if (EntityRight >= CCP1x &&
		player.loc.x <= PointRight1 &&
		EntityBottom >= CCP1y &&
		player.loc.y <= PointBottom1)
	{
		CollisionCheck1 = true;
	}

	//III
	if (EntityRight >= CCP2x &&
		player.loc.x <= PointRight2 &&
		EntityBottom >= CCP2y &&
		player.loc.y <= PointBottom2)
	{
		CollisionCheck2 = true;
	}

	//IV
	if (EntityRight >= CCP3x &&
		player.loc.x <= PointRight3 &&
		EntityBottom >= CCP3y &&
		player.loc.y <= PointBottom3)
	{
		CollisionCheck3 = true;
	}
}

void Platform::CheckInBoxVisualtest(Graphics& gfx)
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
}
