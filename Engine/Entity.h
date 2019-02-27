#pragma once
#include "TestEntity.h"
#include "Graphics.h"
#include <random>

class entity
{

public:

	void Entitysprites(Graphics& gfx);
	void EntityInits(mt19937& rng);


private:
	Redmonkey monkey;


};