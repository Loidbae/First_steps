#include "Player.h"

void Player::draw(Graphics& gfX) const
{
	// simple rec draw function

	for (int I = 0; I < (int)rtc.h; I++)
	{
		for (int In = 0; In < (int)rtc.w; In++)
		{
			gfX.PutPixel(I+(int)rtc.x,In+(int)rtc.y,255,255,255);
		}
	}
}

void Player::move(Keyboard & kbd)
{

	if (kbd.KeyIsPressed('A'))
	{
		rtc.x-= rtc.v;
	}
	
	if (kbd.KeyIsPressed('D'))
	{
		rtc.x+= rtc.v;
	}

	if (kbd.KeyIsPressed('S'))
	{
		rtc.y += rtc.v;
	}

	if (kbd.KeyIsPressed('W'))
	{
		rtc.y-= rtc.v;
	}
}

void Player::wndborder() 
{
	const float right = rtc.x + rtc.w;
	if (rtc.x <= 4)
	{
		rtc.x = 4;
	}
	else if (right >= Graphics::ScreenWidth)
	{
		rtc.x = (Graphics::ScreenWidth - 4) - rtc.w;
	}

	const float bottom = rtc.y + rtc.h;
	if (rtc.y <= 4)
	{
		rtc.y = 4;
	}
	else if (bottom >= Graphics::ScreenHeight)
	{
		rtc.y = (Graphics::ScreenHeight - 4) - rtc.h;
	}
}