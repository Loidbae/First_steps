#include "Player.h"

void Player::draw(Graphics& GfX) const
{
	// simple rec draw function

	for (int I = 0; I < (int)_Coord.Height; I++)
	{
		for (int In = 0; In < (int)_Coord.Width; In++)
		{
			GfX.PutPixel(I+(int)_Coord.X,In+(int)_Coord.Y,255,255,255);
		}
	}
}

void Player::move(Keyboard & Kbd)
{

	if (Kbd.KeyIsPressed('A'))
	{
		_Coord.X-= _Coord.Sp;
	}
	
	if (Kbd.KeyIsPressed('D'))
	{
		_Coord.X+= _Coord.Sp;
	}

	if (Kbd.KeyIsPressed('S'))
	{
		_Coord.Y += _Coord.Sp;
	}

	if (Kbd.KeyIsPressed('W'))
	{
		_Coord.Y-= _Coord.Sp;
	}
}

void Player::wndborder() 
{
	const float right = _Coord.X + _Coord.Width;
	if (_Coord.X <= 4)
	{
		_Coord.X = 4;
	}
	else if (right >= Graphics::ScreenWidth)
	{
		_Coord.X = (Graphics::ScreenWidth - 4) - _Coord.Width;
	}

	const float bottom = _Coord.Y + _Coord.Height;
	if (_Coord.Y <= 4)
	{
		_Coord.Y = 4;
	}
	else if (bottom >= Graphics::ScreenHeight)
	{
		_Coord.Y = (Graphics::ScreenHeight - 4) - _Coord.Height;
	}
}