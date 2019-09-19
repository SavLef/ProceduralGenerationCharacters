#include "Character.h"
#include <ctime>

//CLASSES: WARRIOR | MAGE | ROGUE 
//RACES : HUMAN | ORC | ELF 
//WEIGHTINGS : HUMAN .WARRIOR x2 MAGEx3 ROGUEx1
//			   ORC   .WARRIOR x3 MAGEx1 ROGUEx2
//			   ELF   .WARRIOR x1 MAGEx2 ROGUEx3

Character::Character()
{
}

Character::~Character()
{
}

void Character::GenRace()
{
	int randomrace = (rand()%4);

	switch (randomrace)
	{
		case 0:Race = "HUMAN";
			for (int i = 0; i < (3); i++)
			{
				class_weights.push_back (2);
			}
			for (int i = 0; i < (2); i++)
			{
				class_weights.push_back (1);
			}
			class_weights.push_back (3);
			break;
			

		case 1:Race = "ORC";
			for (int i = 0; i < (3); i++)
			{
				class_weights.push_back (1);
			}
			for (int i = 0; i < (2); i++)
			{
				class_weights.push_back (3);
			}
			class_weights.push_back(2);
			break;


		case 2:Race = "ELF";
			for (int i = 0; i < (3); i++)
			{
				class_weights.push_back (3);
			}
			for (int i = 0; i < (2); i++)
			{
				class_weights.push_back(2);
			}
			class_weights.push_back (1);
			break;

	default:
		break;
	}


	std::cout << Race << std::endl;
}

void Character::GenClass()
{
	int class_indicator = (rand() % 6);
	
	std::random_shuffle(class_weights.begin(), class_weights.end());

	int class_selection = class_weights.at(class_indicator);

	switch (class_selection) {
	case 1: Class = "WARRIOR";
		break;
	case 2: Class = "MAGE";
		break;
	case 3: Class = "ROGUE";
		break;
	default:break;
	}
	std::cout << Class << std::endl;
}

void Character::GenStats()
{
	randSeed();

	for (int i = 0; i < (rand() % rand()); i++)
	{
		GenRace();
		GenClass();

		STR = (rand() % 11);
		std::cout << "STR: " << STR << std::endl;

		DEX = (rand() % 11);
		std::cout << "DEX: " << DEX << std::endl;

		CON = (rand() % 11);
		std::cout << "CON: " << CON << std::endl;

		INT = (rand() % 11);
		std::cout << "INT: " << INT << std::endl;

		WIS = (rand() % 11);
		std::cout << "WIS: " << WIS << std::endl;

		CHA = (rand() % 11);
		std::cout << "CHA: " << CHA << std::endl;
		std::cout << "=============== " << std::endl;
	}
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
