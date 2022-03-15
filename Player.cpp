#include "Player.h"

Player::Player(int id, std::string name, float life, float attack, float magic) :Character(id, name, life, attack)
{
	this->magic = magic;
	this->score = 0;
}

int Player::getScore() const
{
	return score;
}

void Player::meleeAtack(Character& enemy)
{
	enemy.receiveDamage(attack);
}

void Player::magicAttack(Character& enemy)
{
	enemy.receiveDamage(attack);
}
void Player::addScore(int points)
{
	score += points;
}