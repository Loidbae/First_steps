#include "Entity.h"

void Entity::Draw(Graphics & gfx) const
{
	for (int i = 0; i < width; i++)
	{
		for (int in = 0; in < height; in++)
		{
			gfx.PutPixel(i+loc.x,in+loc.y,255,255,255);
		}
	}
}

void Entity::Move(Keyboard & kbd) 
{
	// "Gravity"
	//loc.y++;

	bool strafe = false;
	if (kbd.KeyIsPressed('W')) // for testing purposes
	{
		loc.y--;
	}

	if (kbd.KeyIsPressed('A'))
	{
		loc.x--;
		strafe = true;
	}
	if (kbd.KeyIsPressed('D'))
	{
		loc.x++;
		strafe = true;
	}

}

void Entity::WNDBorder() 
{
	const int right = loc.x + width;
	if (loc.x <= 4)
	{
		loc.x = 4;
	}
	else if (right >= Graphics::ScreenWidth)
	{
		loc.x = (Graphics::ScreenWidth - 1) - width;
	}

	const int bottom = loc.y + height;
	if (loc.y <= 4)
	{
		loc.y = 4;
	}
	else if (bottom >= Graphics::ScreenHeight)
	{
		loc.y = (Graphics::ScreenHeight - 1) - height;
	}
}


void Entity::Test(Keyboard& kbd)
{
	if (kbd.KeyIsPressed(VK_SPACE))
	{
		loc.y --;

		if (kbd.KeyIsPressed('A'))
		{
			loc.y --;
			loc.x--;
		}
		else if (kbd.KeyIsPressed('D'))
		{
			loc.y --;
			loc.x++;
		}
	}
}
