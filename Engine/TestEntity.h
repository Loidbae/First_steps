#pragma once
#include <random>
#include "Coordinates.h"

class TestEntity
{
public:

	TestEntity();

	void Init(mt19937& rng)
	{
		rtc.x = OriginX(rng);
		rtc.y = OriginY(rng);
	}

	void InitCon(mt19937& rng)
	{
		rtc.x = conX(rng);
		rtc.y = conY(rng);
	}

	void spawn();

private:
	Coordinates rtc;

	std::uniform_real_distribution<float>OriginX;
	std::uniform_real_distribution<float>OriginY;

	std::uniform_real_distribution<float>conX;
	std::uniform_real_distribution<float>conY;


};
