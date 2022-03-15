#pragma once
#include "Character.h"

class Enemy : public Character
{
private:
	float age;

public:
	Enemy(int id, std::string name, float life, float attack, float age);
	void makeDamage(Character& enemy);
};