#pragma once
#include <random>
#include "Coordinates.h"
#include "Graphics.h"

class Redmonkey
{

public:

	Redmonkey()
		:
		rtc(),
		spawn_X(60,740),
		spawn_Y(60,540)
	{

	}


	void RedmonkeySpawn(mt19937& rng);
	void RM_Visuals(Graphics& gfx)const;

	void set_bool(bool statement);
	bool get_bool();

	int Level;
	float Base_Hp;
	float Armor;
	float Attack_Power;
	float Max_Hp;
	float start_x;
	float start_y;
	float velocity;

	int monkeys = 10;
	bool first_spawned;

private:
	Coordinates rtc;
	std::uniform_int_distribution<int> spawn_X;
	std::uniform_int_distribution<int> spawn_Y;

};

