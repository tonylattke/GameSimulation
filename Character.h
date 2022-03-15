#pragma once

#include "IdentifierContent.h"

#include <iostream>
#include <string>

class Character : public IdentifierContent
{
protected:
	std::string name;
	float life;
	float attack;
public:
	Character(int id, std::string name, float life, float attack);
	void receiveDamage(float damage);
	float getLife() const;
	void makeDamage(Character& enemy);
	std::string getName() const;
};

