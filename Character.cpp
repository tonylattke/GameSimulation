#include "Character.h"

Character::Character(int id, std::string name, float life, float attack) :IdentifierContent(id)
{
	this->name = name;
	this->life = life;
	this->attack = attack;
}

void  Character::receiveDamage(float damage)
{
	life -= damage;
}

float Character::getLife() const
{
	return life;
}

void Character::makeDamage(Character& enemy)
{
	enemy.receiveDamage(attack);
}

std::string Character::getName() const
{
	return name;
}
