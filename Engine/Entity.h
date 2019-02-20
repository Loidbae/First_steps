#pragma once

#include "Graphics.h"
#include "Coordinates.h"
#include "TestEntity.h"
#include <random>

class Entity
{


public:
	Entity()
		:
		Monkey()
	{
	}

	

	void Special_Executions(std::mt19937& rng);


	float Health_Scaling(float unit_baseHP, int unit_level);
	float Armor_Scaling(float unit_armor, int unit_level);
	float Attack_Power();

	

	void EntitySprites(Graphics& gfx)const;
	void EntityMovement()const;

	
private:
	static constexpr int aSize = 10; 
	Redmonkey Monkey[aSize];
};