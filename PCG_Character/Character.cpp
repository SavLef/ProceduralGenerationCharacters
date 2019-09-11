#include "Character.h"
#include <ctime>

Character::Character()
{
}

Character::~Character()
{
}

void Character::GenClass()
{
	randSeed();

	
}

void Character::GenStats()
{
	randSeed();

	STR = (rand() % 11) ;
	std::cout << "STR: " << STR << std::endl;

	DEX = (rand() % 11);
	std::cout << "DEX: " << DEX << std::endl;

	CON = (rand() % 11);
	std::cout << "CON: " << CON <<  std::endl;

	INT = (rand() % 11);
	std::cout << "INT: " << INT << std::endl;

	WIS = (rand() % 11);
	std::cout << "WIS: " << WIS << std::endl;

	CHA = (rand() % 11);
	std::cout << "CHA: " << CHA << std::endl;
}

void Character::randSeed()
{
	//Source http://www.math.uaa.alaska.edu/~afkjm/csce211/fall2018/handouts/RandomFunctions.pdf
	//Return computer time passed in seconds
	srand(time(NULL));

	int seed = rand();
	int seedtime = rand();

	srand(seed);

	//Randomizing it beyond just the PC time
	srand((rand() * rand()) / seedtime);

	for (int i = 0; i < (rand() % rand()); i++)
	{
		seed = rand();
		srand(seed);
		//std::cout << seed << std::endl;
	}
}
