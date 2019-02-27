#include "Entity.h"

void entity::Entitysprites(Graphics& gfx)
{
	monkey.RM_Visuals(gfx);
}

void entity::EntityInits(mt19937 & rng)
{
	monkey.RedmonkeySpawn(rng);
}
