// PCG_Character.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <stdlib.h>
#include "MarkovChain.h"


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
		system("CLS");
		RaceGenerated = new MarkovChain;
		RaceGenerated->ClassStateOne("Paladin", 20, "Warrior", 12, "Mage", 12, "Priest", 11, "Warlock", 12, "Death Knight", 10, "Rogue", 10, "Hunter", 8, "Monk", 4);
		RaceGenerated->CalculateRace(5,"Human", 15,"Night Elf",12, "Draenai", 6, "Worgen", 5, "Dwarf", 4, "Gnome", 4, "Orc", 8, "Troll", 6, "Blood Elf", 15, "Tauren", 7, "Goblin", 3, "Undead", 7);
		
	}

	
}

