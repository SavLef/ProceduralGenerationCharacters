// PCG_Character.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Character.h"
#include "MarkovChain.h"

Character* Char;
MarkovChain* RaceGenerated;

int choice;

int main()
{
	std::cout << "Press 1 to generate your Character" << std::endl;
	std::cin >> choice;
	while (choice != 1) 
	{
		std::cout << "Press 1 to generate your Character" << std::endl;
		std::cin >> choice;
	}

	if (choice == 1)
	{
		RaceGenerated = new MarkovChain;
		RaceGenerated->RandomRace("human", "elf", "melos", "lol", "haha");
	}

	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
