// PCG_Character.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <stdlib.h>
#include "MarkovChain.h"


MarkovChain* RaceGenerated;

int choice;
int charamount = 100;
vector <string> Races;

void inptraces()
{
	Races.push_back("Human");
	Races.push_back("Night Elf");
	Races.push_back("Draenai");
	Races.push_back("Worgen");
	Races.push_back("Dwarf");
	Races.push_back("Gnome");
	Races.push_back("Orc");
	Races.push_back("Troll");
	Races.push_back("Blood Elf");
	Races.push_back("Tauren");
	Races.push_back("Goblin");
	Races.push_back("Undead");
}

void update()
{
	while (choice != -99)
	{
		system("CLS");
		std::cout << "Characters created! Choose what to do." << std::endl;
		std::cout << "1. Print all generated characters." << std::endl;
		std::cout << "2. Filter by Race" << std::endl;
		std::cout << "3. Filter by Class" << std::endl;
		std::cout << "-99 . End" << std::endl;
		std::cin >> choice;


		while (choice != 1 && choice != 2 && choice != 3 && choice !=-1 || choice == 99 )
		{
			
			std::cout << "Characters created! Choose what to do." << std::endl;
			std::cout << "1. Print all generated characters." << std::endl;
			std::cout << "2. Filter by Race" << std::endl;
			std::cout << "3. Filter by Class" << std::endl;
			std::cout << "-99 . End" << std::endl;
			std::cin >> choice;

		}

		switch (choice)
		{
		case 1:
		{
			for (int i = 0; i < charamount; i++)

			{
				RaceGenerated->Characters.at(i).PrintSheet();
			}
			choice = 99;
			std::cout << "Press Enter to continue..." << std::endl;
			cin.get();
			cin.get();
			break;

		}
		case 2:

		{
			system("CLS");
			for (int i = 0; i < Races.size(); i++)
			{
				std::cout << i + 1 << ":  " << Races.at(i) << std::endl;
			}
			std::cout << "99 : Back" << std::endl;
			std::cin >> choice;
			choice -= 1;

			if (choice > Races.size() || choice < 0)
			{
				choice = 99;
			}

			for (int j = 0; j < Races.size(); j++)
			{
				if (choice == j)
				{
					for (int i = 0; i < charamount; i++)

					{
						if (RaceGenerated->Characters.at(i).getRace() == Races.at(choice))
						{
							RaceGenerated->Characters.at(i).PrintSheet();
						}
					}
				}
			}

			std::cout << "Press Enter to continue..." << std::endl;
			cin.get();
			cin.get();
			break;
		}

		case -1:
			break;
		
		}
	}

}

int main()
{
	inptraces();
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
		RaceGenerated->CalculateRace(charamount, Races.at(0), 15, Races.at(1),12, Races.at(2), 6, Races.at(3), 5, Races.at(4), 4, Races.at(5), 4, Races.at(6), 8, Races.at(7), 6, Races.at(8), 15, Races.at(9), 7, Races.at(10), 3, Races.at(11), 7);
		
	}


	while (choice != -99)
	{
		update();
	}
	
}


void inptclasses() {};