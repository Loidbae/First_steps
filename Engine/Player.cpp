#include "Player.h"

void Entity::Draw(Graphics & gfx) 
{

	for (int in = 0; in < width; in++)
	{
		for (int i = 0; i < height; i++)
		{
			gfx.PutPixel(in+x,i+y,255,255,255);
		}
	}
}

void Entity::Move(Keyboard & kbd)
{
	if (kbd.KeyIsPressed('W'))
	{

	}
	if (kbd.KeyIsPressed('A'))
	{

	}
	if (kbd.KeyIsPressed('S'))
	{

	}
	if (kbd.KeyIsPressed('D'))
	{

	}

}
