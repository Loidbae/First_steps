#include "Entity.h"

void Entity::Draw(Graphics & gfx) const
{
	// simple rec draw function

	for (int i = 0; i < (int)loc.width; i++)
	{
		for (int in = 0; in < (int)loc.height; in++)
		{
			gfx.PutPixel(i+(int)loc.x,in+(int)loc.y,255,255,255);
		}
	}
}

void Entity::Move(Keyboard & kbd) 
{
	

	


	if (kbd.KeyIsPressed('A'))
	{
		loc.x-= loc.sp;
	}
	
	if (kbd.KeyIsPressed('D'))
	{
		loc.x+= loc.sp;
	}

	// "Gravity"
	//loc.y++;

	if (kbd.KeyIsPressed('S'))// for testing purposes
	{
		loc.y += loc.sp;
	}

	if (kbd.KeyIsPressed('W')) // for testing purposes
	{
		loc.y-= loc.sp;
	}
}

void Entity::WNDBorder() 
{
	const float right = loc.x + loc.width;
	if (loc.x <= 4)
	{
		loc.x = 4;
	}
	else if (right >= Graphics::ScreenWidth)
	{
		loc.x = (Graphics::ScreenWidth - 4) - loc.width;
	}

	const float bottom = loc.y + loc.height;
	if (loc.y <= 4)
	{
		loc.y = 4;
	}
	else if (bottom >= Graphics::ScreenHeight)
	{
		loc.y = (Graphics::ScreenHeight - 4) - loc.height;
	}
}