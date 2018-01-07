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
	for (int in = 0; in < (int)Pos.width; in++)
	{
		for (int i = 0; i < (int)Pos.height; i++)
		{
			gfx.PutPixel(in + (int)Pos.x, i + (int)Pos.y, Colors::White);
		}
	}
}

void Platform::CheckSection(Entity & player)
{
	/*
	     _______________
	 ___|_______I_______|___
	|   | _____________ |   |   My idea here is to surround the object with sections, which are indipendent,
	|   ||             ||   |   when a section is activated, by steping in the designated area,
	|   ||             ||   |   the corresponding side-collision gets calculated.
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

	const float CCPy = Pos.y - (Pos.height / 3);
	const float CCPh = Pos.height / 3;

	const float CCP1x = Pos.x + Pos.width;
	const float CCP1w = Pos.width / 2;

	const float CCP2y = Pos.y + Pos.height;
	const float CCP2h = Pos.height / 2;

	const float CCP3x = Pos.x - (Pos.width / 2);
	const float CCP3w = Pos.width / 2;

	// I
	if (Col_Check(player, Pos.x, Pos.width, CCPy, CCPh))
	{
		CollisionCheck = true;
	}
	else
	{
		CollisionCheck = false;
	}

	// II
	if (Col_Check(player, CCP1x, CCP1w, Pos.y, Pos.height))
	{
		CollisionCheck1 = true;
	}
	else
	{
		CollisionCheck1 = false;
	}

	// III
	if (Col_Check(player, Pos.x, Pos.width, CCP2y, CCP2h))
	{
		CollisionCheck2 = true;
	}
	else
	{
		CollisionCheck2 = false;
	}

	// IV
	if (Col_Check(player, CCP3x, CCP3w, Pos.y, Pos.height))
	{
		CollisionCheck3 = true;
	}
	else
	{
		CollisionCheck3 = false;
	}
}

void Platform::UpdateBoxCol(Entity& player) const
{
								
	const float BoxRight = Pos.x + Pos.width;
	const float BoxBottom = Pos.y + Pos.height;
	const float EntityRight = player.loc.x + player.loc.width;
	const float EntityBottom = player.loc.y + player.loc.height;

	//Finally checking if the area is active, if it is -> calculate collision accordingly;

	// Top
	if (CollisionCheck)
	{
		if (EntityBottom > Pos.y && player.loc.x <= BoxRight && EntityRight >= Pos.x)
		{
			player.loc.y = (Pos.y - 0.5f) - player.loc.height;
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

	// Left Side
	if (CollisionCheck3)
	{
		if (EntityRight >= Pos.x && player.loc.y <= BoxBottom && EntityRight >= Pos.y)
		{
			player.loc.x = (Pos.x - 1) - player.loc.width;
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

bool Platform::Col_Check(Entity & player, float objectX, float objectwidth, float objectY, float objectheight) const
{
	// basicly checking if something collides with the player

	const float EntityRight = player.loc.x + player.loc.width;
	const float EntityBottom = player.loc.y + player.loc.height;

	const float PointRight = objectX + objectwidth;
	const float PointBottom = objectY + objectheight;

	return EntityRight >= objectX &&
		player.loc.x <= PointRight &&
		EntityBottom >= objectY &&
		player.loc.y <= PointBottom;
}

void Platform::CheckInBoxVisualtest(Graphics& gfx, Entity& player)
{
	if (CollisionCheck || CollisionCheck1 || CollisionCheck2 || CollisionCheck3)
	{
		c = Colors::Green;
	}
	else
	{
		c = Colors::Red;
	}

	// Drawing visuals to check if the collision areas are on the right place 
	const int int_PosX = (int)Pos.x;
	const int int_PosY = (int)Pos.y;
	const int int_PosW = (int)Pos.width;
	const int int_PosH = (int)Pos.height;

	const int InBoxY = int_PosY - (int_PosH / 3);
	const int InBoxRight = int_PosX + int_PosW;
	const int InBoxBottom = int_PosY + int_PosH;

	const float EntityBottom = player.loc.y + player.loc.height;




		if (player.loc.y <= int_PosY)
		{
			

			for (int i = 0; i <= int_PosW; i++)
			{
				gfx.PutPixel(i + int_PosX, 0 + int_PosY, c);
				gfx.PutPixel(i + int_PosX, 0 + InBoxY, c);

			}


			for (int i = 0; i < int_PosH / 3; i++)
			{
				gfx.PutPixel(0 + int_PosX, i + InBoxY, c);
				gfx.PutPixel(0 + InBoxRight, i + InBoxY, c);
			}
		}


		if (EntityBottom >= int_PosY && player.loc.y <= InBoxBottom && player.loc.x <= int_PosX)
		{

			for (int i = 0; i < int_PosW / 2; i++)
			{
				gfx.PutPixel(i + int_PosX - (int_PosW / 2), 0 + int_PosY, c);
				gfx.PutPixel(i + int_PosX - (int_PosW / 2), 0 + InBoxBottom, c);

			}

			for (int i = 0; i < int_PosH; i++)
			{
				gfx.PutPixel(0 + int_PosX - (int_PosW / 2), i + int_PosY, c);
				gfx.PutPixel(0 + int_PosX, i + int_PosY, c);

			}
		}


		if (EntityBottom >= int_PosY && player.loc.y <= InBoxBottom && player.loc.x >= InBoxRight)
		{

			for (int i = 0; i < int_PosW / 2; i++)
			{
				gfx.PutPixel(i + InBoxRight, 0 + int_PosY, c);
				gfx.PutPixel(i + InBoxRight, 0 + int_PosY + int_PosH, c);
			}

			for (int i = 0; i < int_PosH; i++)
			{
				gfx.PutPixel(0 + InBoxRight,i + int_PosY, c);
				gfx.PutPixel(0 + InBoxRight + (int_PosW / 2), i + int_PosY, c);
			}
		}

		if (player.loc.y >= int_PosY + int_PosH)
		{

			for (int i = 0; i < int_PosW; i++)
			{
				gfx.PutPixel(i + int_PosX, 0 + InBoxBottom, c);
				gfx.PutPixel(i + int_PosX, 0 + InBoxBottom + (int_PosH / 2), c);
			}

			for (int i = 0; i < int_PosH / 2; i++)
			{
				gfx.PutPixel(0 + int_PosX, i + InBoxBottom, c);
				gfx.PutPixel(0 + InBoxRight, i + InBoxBottom, c);
			}
		}
	
}