#pragma once
#include <iostream>
#include <list>

#include "IdentifierContent.h"
#include "Enemy.h"
#include "Player.h"
#include "GameDatabase.h"

class Match : public IdentifierContent
{
private:
	int round;
	std::list<Enemy> enemies;
	Player* player;

	void playRound();

public:
	Match(int id, int numberOfEnemies, GameDatabase database);
	void simulate();
	void printMatchStats();
	bool isEnemyAlive();
	void enemiesStatus();
};

