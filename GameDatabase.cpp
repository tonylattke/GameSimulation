#include "GameDatabase.h"

GameDatabase::GameDatabase()
{
	std::cout << "Database created" << std::endl;
}

std::list<std::string> GameDatabase::getPlayerNames()
{
	return playerNames;
}

bool GameDatabase::loadPlayerNames(std::string playersFilename)
{
	std::ifstream myFile(playersFilename);
	if (!myFile.is_open())
		return false;

	// Read data, line by line
	std::string line;
	while (std::getline(myFile, line))
	{
		std::string name(line);
		playerNames.push_back(name);
	}

	myFile.close();

	return true;
}

std::string GameDatabase::getRandomPlayerName()
{
	if (playerNames.empty())
		return "";

	int randomIndex = rand() % playerNames.size();

	return get(playerNames, randomIndex);

}

std::string GameDatabase::get(std::list<std::string> _list, int _i)
{
	std::list<std::string>::iterator nameIterator = _list.begin();
	for (int i = 0; i < _i; i++)
		++nameIterator;

	return *nameIterator;
}