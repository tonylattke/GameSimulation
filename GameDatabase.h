#pragma once

#include <iostream>
#include <list>
#include <string>
#include<fstream>

class GameDatabase
{
private:
	std::list<std::string> playerNames;

public:
	GameDatabase();
	std::list<std::string> getPlayerNames();
	bool loadPlayerNames(std::string playersFilename);
	std::string getRandomPlayerName();
	std::string get(std::list<std::string> _list, int _i);
};


