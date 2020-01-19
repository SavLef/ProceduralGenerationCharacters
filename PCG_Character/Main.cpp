// PCG_Character.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "MarkovChain.h"

std::ofstream myFile("Characterlist.csv");





MarkovChain* RaceGenerated;

int choice;
int charamount = 100;
vector <string> Races;
vector <string> Classes;
vector <int> RacesPercentage;



void inptraces()
{
	ifstream dbfile("Database.csv");
	string value;
	int perc;

	std::getline(dbfile, value, '\n');
	std::getline(dbfile, value, ',');

	perc = std::stoi(value);
	RacesPercentage.push_back(perc);

	std::getline(dbfile, value, ',');// read a string until next comma
	Races.push_back(value);
	while (dbfile.good())
	{

		
		std::getline(dbfile, value, '\n');
		std::getline(dbfile, value, ',');// read a string until next comma

		if (value != "")
		{
			perc = std::stoi(value);
			RacesPercentage.push_back(perc);
		}
		std::getline(dbfile, value, ',');// read a string until next comma
		Races.push_back(value);
	}

	
}

void inptclasses()
{
	ifstream dbfile("Database.csv");
	string value;
	std::getline(dbfile, value, ','); // read a string until next comma
	std::getline(dbfile, value, ','); // read a string until next comma
	while (dbfile.good())
	{
		std::getline(dbfile, value, ','); // read a string until next comma
		Classes.push_back(value);
	}
	
}

void update()
{
		/*std::ofstream myFile;
		myFile.open("Characterlist.csv", std::ofstream::out | std::ofstream::app);*/
		std::ofstream myFile("Characterlist.csv");
		myFile << "Race" << "," << "Class" << "," << "STR" << "," << "STM" << "," << "INT" << "," << "SPR" << "," << "AGI" << std::endl;

		system("CLS");
		std::cout << "Characters created! Choose what to do." << std::endl;
		std::cout << "1. Print all generated characters." << std::endl;
		std::cout << "2. Filter by Race" << std::endl;
		std::cout << "3. Filter by Class" << std::endl;
		std::cout << "-99 . End" << std::endl;
		std::cin >> choice;


		while (choice != 1 && choice != 2 && choice != 3 && choice != -99 || choice == 99 )
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


		case 3:

		{
			system("CLS");
			for (int i = 0; i < Classes.size(); i++)
			{
				std::cout << i + 1 << ":  " << Classes.at(i) << std::endl;
			}
			std::cout << "99 : Back" << std::endl;
			std::cin >> choice;
			choice -= 1;

			if (choice > Classes.size() || choice < 0)
			{
				choice = 99;
			}

			for (int j = 0; j < Classes.size(); j++)
			{
				if (choice == j)
				{
					for (int i = 0; i < charamount; i++)

					{
						if (RaceGenerated->Characters.at(i).getClass() == Classes.at(choice))
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

		}
}

int main()
{
	
	

	inptraces();
	inptclasses();
	std::cout << "How many characters do you want to generate? 1-10000" << std::endl;
	std::cin >> choice;
	while (choice < 1 || choice > 1000) 
	{
		std::cout << "How many characters do you want to generate? 1-10000" << std::endl;
		std::cin >> choice;
		
	}
	charamount = choice;
	system("CLS");
	RaceGenerated = new MarkovChain;
	RaceGenerated->ClassStateOne(Classes.at(0), 20, Classes.at(1), 12, Classes.at(2), 12, Classes.at(3), 11, Classes.at(4), 12, Classes.at(5), 10, Classes.at(6), 10, Classes.at(7), 8, Classes.at(8), 4);
	RaceGenerated->CalculateRace(charamount, Races.at(0), RacesPercentage.at(0), Races.at(1), RacesPercentage.at(1), Races.at(2), RacesPercentage.at(2), Races.at(3), RacesPercentage.at(3), Races.at(4), RacesPercentage.at(4), Races.at(5), RacesPercentage.at(5), Races.at(6), RacesPercentage.at(6), Races.at(7), RacesPercentage.at(7), Races.at(8), RacesPercentage.at(8), Races.at(9), RacesPercentage.at(9), Races.at(10), RacesPercentage.at(10), Races.at(11), RacesPercentage.at(11));
		
	

	while (choice != -99)
	{
		update();
		
	}
	
}


