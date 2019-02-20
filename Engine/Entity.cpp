#include "Entity.h"

float Entity::Health_Scaling(float unit_baseHP, int unit_level)
{

	return 0.0f;
}

float Entity::Armor_Scaling(float unit_armor, int unit_level)
{
	return 0.0f;
}

float Entity::Attack_Power()
{
	return 0.0f;
}

void Entity::Special_Executions(std::mt19937& rng)
{
	Monkey[].RedmonkeySpawn(rng);
}

void Entity::EntitySprites(Graphics& gfx) const
{
	Monkey[].RM_Visuals(gfx);
}

void Entity::EntityMovement() const
{
}
