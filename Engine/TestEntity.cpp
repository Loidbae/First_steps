#include "TestEntity.h"
#include <math.h>
#include <cmath>

#define _USE_MATH_DEFINES
#define M_PI      3.14159265358979323846 /* PI */

void Redmonkey::RedmonkeySpawn(std::mt19937& rng)
{
	for (int i = 0; i < monkeys; i++)
	{
		if (i == 0 && first_spawned == false)
		{
			rtc.x = (float)spawn_X(rng);
			rtc.y = (float)spawn_Y(rng);
			first_spawned = true;
		}
		else if (i >= 1 && first_spawned == true)
		{


			int copy_X = rtc.x;
			int copy_Y = rtc.y;

			int xrange = rtc.x + 5;
			int yrange = rtc.y + 5;

			int ttt = pow(xrange - copy_X, 2);
			int tts = pow(yrange - copy_Y, 2);


			int radiant = ttt + tts;
			int maxRange = 2 * M_PI * radiant;
			
			std::uniform_int_distribution<int> con_spawnX(rtc.x + 5, rtc.x + maxRange);
			std::uniform_int_distribution<int> con_spawnY(rtc.y + 1, rtc.y + maxRange);

			rtc.x = (float)con_spawnX(rng);
			rtc.y = (float)con_spawnY(rng);

		}



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
