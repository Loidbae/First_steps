#pragma once
#include <random>
#include "Coordinates.h"
#include "Graphics.h"

class Redmonkey
{

public:

	Redmonkey()
		:
		Name(Name),
		rtc(),
		spawn_X(60,740),
		spawn_Y(60,540)
	{

	}

	void InitMon(const std::string& name, float base_hp, float attack_power, float armor, int level, float max_hp)
	{
		Name + name;
		Base_Hp = base_hp;
		Attack_Power = attack_power;
		Armor = armor;
		Level = level;
		Max_Hp = max_hp;
	}

	void RedmonkeySpawn(mt19937& rng);
	void RM_Visuals(Graphics& gfx)const;

	void set_bool(bool statement);
	bool get_bool();


	const std::string& Name;
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

