#include "Platform.h"

Platform::Platform()
	:
	posX(50, 659),
	posY(50, 459),
	drawCordX(22, 50),
	drawCordY(50, 60)
{

}

void Platform::drawbox(Graphics& gfx) const
{
	for (int In = 0; In < (int)pos.width; In++)
	{
		for (int I = 0; I < (int)pos.height; I++)
		{
			gfx.PutPixel(In + (int)pos.x, I + (int)pos.y, Colors::White);
		}
	}
}

void Platform::checksection(player& player)
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

	// ccP# / collision_checkPoint/x/y/width/height

	const float ccPy = pos.Y - (pos.height / 3);
	const float ccPh = pos.height / 3;

	const float ccP1x = pos.X + pos.width;
	const float ccP1w = pos.width / 2;

	const float ccP2y = pos.Y + pos.height;
	const float ccP2h = pos.height / 2;

	const float ccP3x = pos.X - (pos.width / 2);
	const float ccP3w = pos.width / 2;

	// I
	if (calc_collision(player, pos.X, pos.width, ccPy, ccPh))
	{
		collision_check = true;
	}
	else
	{
		collision_check = false;
	}

	// II
	if (calc_collision(player, ccP1x, ccP1w, pos.Y, pos.height))
	{
		collision_check1 = true;
	}
	else
	{
		collision_check1 = false;
	}

	// III
	if (calc_collision(player, pos.X, pos.width, ccP2y, ccP2h))
	{
		collision_check2 = true;
	}
	else
	{
		collision_check2 = false;
	}

	// IV
	if (calc_collision(player, ccP3x, ccP3w, pos.Y, pos.height))
	{
		collision_check3 = true;
	}
	else
	{
		collision_check3 = false;
	}
}

void Platform::updateboxcol(player& player) const
{

	const float boxRight = pos.X + pos.width;
	const float boxBottom = pos.Y + pos.height;
	const float entityRight = player.coord.x + player._Coord.width;
	const float entityBottom = player.coord.y + player._Coord.height;

	//Finally _checking if the area is active, if it is -> calculate collision accordingly;

	// Top
	if (collision_check)
	{
		if (entityBottom > pos.Y && player.coord.x <= boxRight && entityRight >= pos.X - 1)
		{
			player.coord.y = (pos.Y - 1) - player._Coord.height - 1;

		}
	}

	// Right Side
	if (collision_check1)
	{
		if (player.coord.x <= boxRight && player.coord.y >= pos.Y && player.coord.y <= boxBottom)
		{
			player.coord.x = boxRight + 1;
		}

	}

	// Left Side
	if (collision_check3)
	{
		if (entityRight > pos.X && player.coord.y <= boxBottom && entityRight >= pos.Y)
		{
			player.coord.x = (pos.X - 1) - player._Coord.width;
		}
	}

	

	//Bottom
	if (collision_check2)
	{
		if (player.coord.y <= boxBottom && player.coord.x <= boxRight && entityRight >= pos.X)
		{
			player.coord.y = boxBottom + 1;
		}
	}
}

bool Platform::calc_collision(player& player, float ObjectX, float Objectwidth, float ObjectY, float Objectheight) const
{

	const float entityRight = player.coord.x + player._Coord.width;
	const float entityBottom = player.coord.y + player._Coord.height;

	const float PointRight = ObjectX + Objectwidth;
	const float PointBottom = ObjectY + Objectheight;

	return entityRight >= ObjectX &&
		player.coord.x <= PointRight &&
		entityBottom >= ObjectY &&
		player.coord.y <= PointBottom;
}

void Platform::checkinboxvisualtest(Graphics& gfx, player& player)
{
	if (collision_check || collision_check1 || collision_check2 || collision_check3)
	{
		c = Colors::Green;
	}
	else
	{
		c = Colors::Red;
	}

	// Drawing visuals to _check if the collision areas are on the right place 
	const int intposX = (int)pos.X;
	const int intposY = (int)pos.Y;
	const int intposW = (int)pos.width;
	const int intposH = (int)pos.height;

	const int InboxY = intposY - (intposH / 3);
	const int inboxright = intposX + intposW;
	const int inboxbottom = intposY + intposH;

	const float entityBottom = player.coord.y + player._Coord.height;




		if (player.coord.y <= intposY)
		{
			

			for (int I = 0; I <= intposW; I++)
			{
				gfx.PutPixel(I + intposX, 0 + intposY, c);
				gfx.PutPixel(I + intposX, 0 + InboxY, c);

			}


			for (int I = 0; I < intposH / 3; I++)
			{
				gfx.PutPixel(0 + intposX, I + InboxY, c);
				gfx.PutPixel(0 + inboxright, I + InboxY, c);
			}
		}


		if (entityBottom >= intposY && player.coord.y <= inboxbottom && player.coord.x <= intposX)
		{

			for (int I = 0; I < intposW / 2; I++)
			{
				gfx.PutPixel(I + intposX - (intposW / 2), 0 + intposY, c);
				gfx.PutPixel(I + intposX - (intposW / 2), 0 + inboxbottom, c);

			}

			for (int I = 0; I < intposH; I++)
			{
				gfx.PutPixel(0 + intposX - (intposW / 2), I + intposY, c);
				gfx.PutPixel(0 + intposX, I + intposY, c);

			}
		}


		if (entityBottom >= intposY && player.coord.y <= inboxbottom && player.coord.x >= inboxright)
		{

			for (int I = 0; I < intposW / 2; I++)
			{
				gfx.PutPixel(I + inboxright, 0 + intposY, c);
				gfx.PutPixel(I + inboxright, 0 + intposY + intposH, c);
			}

			for (int I = 0; I < intposH; I++)
			{
				gfx.PutPixel(0 + inboxright, I + intposY, c);
				gfx.PutPixel(0 + inboxright + (intposW / 2), I + intposY, c);
			}
		}

		if (player.coord.y >= intposY + intposH)
		{

			for (int I = 0; I < intposW; I++)
			{
				gfx.PutPixel(I + intposX, 0 + inboxbottom, c);
				gfx.PutPixel(I + intposX, 0 + inboxbottom + (intposH / 2), c);
			}

			for (int I = 0; I < intposH / 2; I++)
			{
				gfx.PutPixel(0 + intposX, I + inboxbottom, c);
				gfx.PutPixel(0 + inboxright, I + inboxbottom, c);
			}
		}
	
}