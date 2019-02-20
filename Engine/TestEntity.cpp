#include "TestEntity.h"

void Redmonkey::RedmonkeySpawn(std::mt19937& rng)
{
	

	if (first_spawned == false)
	{
		rtc.x = (float)spawn_X(rng);
		rtc.y = (float)spawn_Y(rng);

		float holdx = rtc.x;
		float holdy = rtc.y;
	}
	else
	{







	}
	



}

void Redmonkey::RM_Visuals(Graphics & gfx) const
{
	gfx.DrawRectDim(rtc.x,rtc.y,10,10,Colors::Red);
}

void Redmonkey::set_bool(bool statement)
{
	first_spawned = statement;
}

bool Redmonkey::get_bool()
{
	return first_spawned;
}
