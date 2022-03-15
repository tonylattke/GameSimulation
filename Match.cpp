#include "Match.h"
#include <ctime>

Match::Match(int id, int numberOfEnemies, GameDatabase database) : IdentifierContent(id)
{
	double randomValue = (double)rand() / (double)RAND_MAX;
	Player* player = new Player(id, database.getRandomPlayerName(), randomValue * 100, 2, 3);
	this->player = player;

	for (int i = 0; i < numberOfEnemies; i++)
	{
		randomValue = (double)rand() / (double)RAND_MAX;

		Enemy enemy(i, database.getRandomPlayerName(), randomValue * 3, 1, randomValue * 3);
		enemies.push_back(enemy);
	}

	round = 0;
}

void Match::playRound()
{
	// Player attack
	for (Enemy enemy : enemies)
	{
		if (enemy.getLife() <= 0)
			continue;

		double randomValue = (double)rand() / (double)RAND_MAX;
		int scoreBonus = 1;
		if (randomValue > 0.66)
		{
			player->magicAttack(enemy);
			scoreBonus++;
		}
		else
			player->meleeAtack(enemy);

		if (enemy.getLife() <= 0)
			scoreBonus++;

		player->addScore(10 * scoreBonus);
	}

	// Enemies attack
	for (Enemy enemy : enemies)
	{
		if (enemy.getLife() <= 0)
			continue;

		double randomValue = (double)rand() / (double)RAND_MAX;
		if (randomValue < 0.75)
			continue;

		enemy.makeDamage(*this->player);

		if (player->getLife() <= 0)
			break;
	}
}

void Match::simulate()
{
	while (player->getLife() > 0)
	{
		if (!isEnemyAlive())
		{
			std::cout << "All the enemies are dead!" << std::endl;
			break;
		}

		playRound();

		round++;
	}
}

void Match::printMatchStats()
{
	std::cout << "Match " << getId() << " - Score: " << player->getScore()
		<< " Rounds: " << round << " Enemies: " << enemies.size() << std::endl;
}

bool Match::isEnemyAlive()
{
	for (Enemy enemy : enemies)
		if (enemy.getLife() > 0)
			return true;

	return false;
}

void Match::enemiesStatus()
{
	for (Enemy enemy : enemies)
		std::cout << enemy.getName() << " " << enemy.getLife() << std::endl;
}