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
	loc.y++;

	bool strafe = false;
	
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

	//if (kbd.KeyIsPressed(VK_SPACE))
	//{
	//	loc.y-=2;
	//	if (kbd.KeyIsPressed('A')/*&&kbd.KeyIsPressed(VK_SPACE)*/)
	//	{
	//		loc.y-=2;
	//		loc.x--;
	//	}
	//	else if (kbd.KeyIsPressed('D'))
	//	{
	//		loc.y-=2;
	//		loc.x++;
	//	}
	//}

	/*if (kbd.KeyIsPressed('W'))
	{
	loc.y--;
	}*/

	/*if (kbd.KeyIsPressed('S'))
	{
		loc.y++;
	}*/
}

void Entity::WNDBorder() 

{
	const int right = loc.x + width;
	if (loc.x < 0)
	{
		loc.x = 0;
	}
	else if (right >= Graphics::ScreenWidth)
	{
		loc.x = (Graphics::ScreenWidth - 1) - width;
	}

	const int bottom = loc.y + height;
	if (loc.y < 0)
	{
		loc.y = 0;
	}
	else if (bottom >= Graphics::ScreenHeight)
	{
		loc.y = (Graphics::ScreenHeight - 1) - height;
	}
}

bool Entity::Testoroni()
{
	return false;
}

void Entity::Test(Keyboard& kbd)
{
	if (kbd.KeyIsPressed(VK_SPACE))
	{
		loc.y -= 2;
		if (kbd.KeyIsPressed('A')/*&&kbd.KeyIsPressed(VK_SPACE)*/)
		{
			loc.y -= 2;
			loc.x--;
		}
		else if (kbd.KeyIsPressed('D'))
		{
			loc.y -= 2;
			loc.x++;
		}
	}
}
