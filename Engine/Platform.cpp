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
	for (int In = 0; In < (int)rtc.w; In++)
	{
		for (int I = 0; I < (int)rtc.h; I++)
		{
			gfx.PutPixel(In + (int)rtc.x, I + (int)rtc.y, Colors::White);
		}
	}
}

void Platform::checksection(player& player)
{
	/*
	     _______________
	 ___|_______I_______|___
	|   | _____________ |   |   My idea here is to surround the object with sections,
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

	const float ccPy = rtc.y - (rtc.h / 3);
	const float ccPh = rtc.h / 3;

	const float ccP1x = rtc.x + rtc.w;
	const float ccP1w = rtc.w / 2;

	const float ccP2y = rtc.y + rtc.h;
	const float ccP2h = rtc.h / 2;

	const float ccP3x = rtc.x - (rtc.w / 2);
	const float ccP3w = rtc.w / 2;

	// I
	if (calc_collision(player, rtc.x, rtc.w, ccPy, ccPh))
	{
		collision_check = true;
	}
	else
	{
		collision_check = false;
	}

	// II
	if (calc_collision(player, ccP1x, ccP1w, rtc.y, rtc.h))
	{
		collision_check1 = true;
	}
	else
	{
		collision_check1 = false;
	}

	// III
	if (calc_collision(player, rtc.x, rtc.w, ccP2y, ccP2h))
	{
		collision_check2 = true;
	}
	else
	{
		collision_check2 = false;
	}

	// IV
	if (calc_collision(player, ccP3x, ccP3w, rtc.y, rtc.h))
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

	const float boxRight = rtc.x + rtc.w;
	const float boxBottom = rtc.y + rtc.h;
	const float entityRight = player.rtc.x + player.rtc.w;
	const float entityBottom = player.rtc.y + player.rtc.h;

	//Finally _checking if the area is active, if it is -> calculate collision accordingly;

	// Top
	if (collision_check)
	{
		if (entityBottom > rtc.y && player.rtc.x <= boxRight && entityRight >= rtc.x - 1)
		{
			player.rtc.y = (rtc.y - 1) - player.rtc.h - 1;

		}
	}

	// Right Side
	if (collision_check1)
	{
		if (player.rtc.x <= boxRight && player.rtc.y >= rtc.y && player.rtc.y <= boxBottom)
		{
			player.rtc.x = boxRight + 1;
		}

	}

	// Left Side
	if (collision_check3)
	{
		if (entityRight > rtc.x && player.rtc.y <= boxBottom && entityRight >= rtc.y)
		{
			player.rtc.x = (rtc.x - 1) - player.rtc.w;
		}
	}

	

	//Bottom
	if (collision_check2)
	{
		if (player.rtc.y <= boxBottom && player.rtc.x <= boxRight && entityRight >= rtc.x)
		{
			player.rtc.y = boxBottom + 1;
		}
	}
}

bool Platform::calc_collision(player& player, float ObjectX, float Objectwidth, float ObjectY, float Objectheight) const
{

	const float entityRight = player.rtc.x + player.rtc.w;
	const float entityBottom = player.rtc.y + player.rtc.h;

	const float PointRight = ObjectX + Objectwidth;
	const float PointBottom = ObjectY + Objectheight;

	return entityRight >= ObjectX &&
		player.rtc.x <= PointRight &&
		entityBottom >= ObjectY &&
		player.rtc.y <= PointBottom;
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
	const int intposX = (int)rtc.x;
	const int intposY = (int)rtc.y;
	const int intposW = (int)rtc.w;
	const int intposH = (int)rtc.h;

	const int InboxY = intposY - (intposH / 3);
	const int inboxright = intposX + intposW;
	const int inboxbottom = intposY + intposH;

	const float entityBottom = player.rtc.y + player.rtc.h;




		if (player.rtc.y <= intposY)
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


		if (entityBottom >= intposY && player.rtc.y <= inboxbottom && player.rtc.x <= intposX)
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


		if (entityBottom >= intposY && player.rtc.y <= inboxbottom && player.rtc.x >= inboxright)
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

		if (player.rtc.y >= intposY + intposH)
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