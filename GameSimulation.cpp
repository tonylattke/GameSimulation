// GameSimulation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "GameDatabase.h"
#include "Utils.h"
#include "Match.h"

int main()
{
	// Initialize database
    GameDatabase database;
	if (!database.loadPlayerNames("data/names.txt"))
	{
		std::cout << "Database cannot be loaded" << std::endl;
		exit(EXIT_FAILURE);
	}
	std::cout << "Database loaded" << std::endl;

	// Setup matches
	int numberOfMatchs = 10;
	int minNumberOfEnemies = 5;
	int maxNumberOfEnemies = 15;
	srand(time(0));

	// Run matches
	for (int i = 0; i < numberOfMatchs; i++)
	{
		// Create a match
		double randomValue = (double)rand() / (double)RAND_MAX;
		int numberOfEnemies = randomValue * maxNumberOfEnemies;
		numberOfEnemies = clamp(numberOfEnemies, minNumberOfEnemies, maxNumberOfEnemies);
		Match match(i, numberOfEnemies, database);

		// Simulate match
		match.simulate();

		// Show results
		match.printMatchStats();
	}
}