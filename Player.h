#pragma once

#include <string>
#include <iostream>
#include "Character.h"

class Player : public Character
{
private:
	int score;
	float magic;
public:
	Player(int id, std::string name, float life, float attack, float magic);
	int getScore() const;
	void meleeAtack(Character& enemy);
	void magicAttack(Character& enemy);
	void addScore(int points);
};

