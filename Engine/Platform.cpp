#include "Platform.h"

Platform::Platform()
	:
	_PosX(50, 659),
	_PosY(50, 459),
	_DrawCordX(22, 50),
	_DrawCordY(50, 60)
{

}

void Platform::drawbox(Graphics& Gfx) const
{
	for (int In = 0; In < (int)_Pos.Width; In++)
	{
		for (int I = 0; I < (int)_Pos.Height; I++)
		{
			Gfx.PutPixel(In + (int)_Pos.X, I + (int)_Pos.Y, Colors::White);
		}
	}
}

void Platform::checksection(Player& Player)
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

	const float CCPy = _Pos.Y - (_Pos.Height / 3);
	const float CCPh = _Pos.Height / 3;

	const float CCP1x = _Pos.X + _Pos.Width;
	const float CCP1w = _Pos.Width / 2;

	const float CCP2y = _Pos.Y + _Pos.Height;
	const float CCP2h = _Pos.Height / 2;

	const float CCP3x = _Pos.X - (_Pos.Width / 2);
	const float CCP3w = _Pos.Width / 2;

	// I
	if (calc_collision(Player, _Pos.X, _Pos.Width, CCPy, CCPh))
	{
		CollisionCheck = true;
	}
	else
	{
		CollisionCheck = false;
	}

	// II
	if (calc_collision(Player, CCP1x, CCP1w, _Pos.Y, _Pos.Height))
	{
		CollisionCheck1 = true;
	}
	else
	{
		CollisionCheck1 = false;
	}

	// III
	if (calc_collision(Player, _Pos.X, _Pos.Width, CCP2y, CCP2h))
	{
		CollisionCheck2 = true;
	}
	else
	{
		CollisionCheck2 = false;
	}

	// IV
	if (calc_collision(Player, CCP3x, CCP3w, _Pos.Y, _Pos.Height))
	{
		CollisionCheck3 = true;
	}
	else
	{
		CollisionCheck3 = false;
	}
}

void Platform::updateboxcol(Player& Player) const
{

	const float BoxRight = _Pos.X + _Pos.Width;
	const float BoxBottom = _Pos.Y + _Pos.Height;
	const float EntityRight = Player._Coord.X + Player._Coord.Width;
	const float EntityBottom = Player._Coord.Y + Player._Coord.Height;

	//Finally checking if the area is active, if it is -> calculate collision accordingly;

	// Top
	if (CollisionCheck)
	{
		if (EntityBottom > _Pos.Y && Player._Coord.X <= BoxRight && EntityRight >= _Pos.X - 1)
		{
			Player._Coord.Y = (_Pos.Y - 1) - Player._Coord.Height - 1;

		}
	}

	// Right Side
	if (CollisionCheck1)
	{
		if (Player._Coord.X <= BoxRight && Player._Coord.Y >= _Pos.Y && Player._Coord.Y <= BoxBottom)
		{
			Player._Coord.X = BoxRight + 1;
		}

	}

	// Left Side
	if (CollisionCheck3)
	{
		if (EntityRight > _Pos.X && Player._Coord.Y <= BoxBottom && EntityRight >= _Pos.Y)
		{
			Player._Coord.X = (_Pos.X - 1) - Player._Coord.Width;
		}
	}

	

	//Bottom
	if (CollisionCheck2)
	{
		if (Player._Coord.Y <= BoxBottom && Player._Coord.X <= BoxRight && EntityRight >= _Pos.X)
		{
			Player._Coord.Y = BoxBottom + 1;
		}
	}
}

bool Platform::calc_collision(Player& Player, float ObjectX, float Objectwidth, float ObjectY, float Objectheight) const
{

	const float EntityRight = Player._Coord.X + Player._Coord.Width;
	const float EntityBottom = Player._Coord.Y + Player._Coord.Height;

	const float PointRight = ObjectX + Objectwidth;
	const float PointBottom = ObjectY + Objectheight;

	return EntityRight >= ObjectX &&
		Player._Coord.X <= PointRight &&
		EntityBottom >= ObjectY &&
		Player._Coord.Y <= PointBottom;
}

void Platform::checkinboxvisualtest(Graphics& Gfx, Player& Player)
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
	const int Int_PosX = (int)_Pos.X;
	const int Int_PosY = (int)_Pos.Y;
	const int Int_PosW = (int)_Pos.Width;
	const int Int_PosH = (int)_Pos.Height;

	const int InBoxY = Int_PosY - (Int_PosH / 3);
	const int InBoxRight = Int_PosX + Int_PosW;
	const int InBoxBottom = Int_PosY + Int_PosH;

	const float EntityBottom = Player._Coord.Y + Player._Coord.Height;




		if (Player._Coord.Y <= Int_PosY)
		{
			

			for (int I = 0; I <= Int_PosW; I++)
			{
				Gfx.PutPixel(I + Int_PosX, 0 + Int_PosY, c);
				Gfx.PutPixel(I + Int_PosX, 0 + InBoxY, c);

			}


			for (int I = 0; I < Int_PosH / 3; I++)
			{
				Gfx.PutPixel(0 + Int_PosX, I + InBoxY, c);
				Gfx.PutPixel(0 + InBoxRight, I + InBoxY, c);
			}
		}


		if (EntityBottom >= Int_PosY && Player._Coord.Y <= InBoxBottom && Player._Coord.X <= Int_PosX)
		{

			for (int I = 0; I < Int_PosW / 2; I++)
			{
				Gfx.PutPixel(I + Int_PosX - (Int_PosW / 2), 0 + Int_PosY, c);
				Gfx.PutPixel(I + Int_PosX - (Int_PosW / 2), 0 + InBoxBottom, c);

			}

			for (int I = 0; I < Int_PosH; I++)
			{
				Gfx.PutPixel(0 + Int_PosX - (Int_PosW / 2), I + Int_PosY, c);
				Gfx.PutPixel(0 + Int_PosX, I + Int_PosY, c);

			}
		}


		if (EntityBottom >= Int_PosY && Player._Coord.Y <= InBoxBottom && Player._Coord.X >= InBoxRight)
		{

			for (int I = 0; I < Int_PosW / 2; I++)
			{
				Gfx.PutPixel(I + InBoxRight, 0 + Int_PosY, c);
				Gfx.PutPixel(I + InBoxRight, 0 + Int_PosY + Int_PosH, c);
			}

			for (int I = 0; I < Int_PosH; I++)
			{
				Gfx.PutPixel(0 + InBoxRight, I + Int_PosY, c);
				Gfx.PutPixel(0 + InBoxRight + (Int_PosW / 2), I + Int_PosY, c);
			}
		}

		if (Player._Coord.Y >= Int_PosY + Int_PosH)
		{

			for (int I = 0; I < Int_PosW; I++)
			{
				Gfx.PutPixel(I + Int_PosX, 0 + InBoxBottom, c);
				Gfx.PutPixel(I + Int_PosX, 0 + InBoxBottom + (Int_PosH / 2), c);
			}

			for (int I = 0; I < Int_PosH / 2; I++)
			{
				Gfx.PutPixel(0 + Int_PosX, I + InBoxBottom, c);
				Gfx.PutPixel(0 + InBoxRight, I + InBoxBottom, c);
			}
		}
	
}