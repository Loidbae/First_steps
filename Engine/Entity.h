#pragma once

#include "Graphics.h"
#include "Coordinates.h"

class Entity
{


public:
	Entity();
	void Reg_Entity()const;
	void EntityName();
	void EntityHealth();
	void EntityAttackPower();
	void EntityDefence();
	void EntityGfx()const;
	void EntityMovement()const;

private:
	Coordinates with;
	
	void Entity_HP_F();
	void Entity_AP_F();
	void Entity_DEF_F();


};