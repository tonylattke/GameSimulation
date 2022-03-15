#include "Enemy.h"

Enemy::Enemy(int id, std::string name, float life, float attack, float age) :Character(id, name, life, attack)
{
	this->age = age;
}

void Enemy::makeDamage(Character& enemy)
{
	enemy.receiveDamage(attack + (age > 30? 1:0));
}