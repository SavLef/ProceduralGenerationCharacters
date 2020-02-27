// PCG_Character.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "MarkovChain.h"
#include "Algorithms.h"

std::ofstream myFile("GENERATED CHARACTERS/Characterlist.csv");





MarkovChain* RaceGenerated;

int choice;
int charamount = 100;
vector <string> Races;
vector <string> Classes;
vector <string> StatName;
vector <int> RacesPercentage;
vector <int> ClassPercentage;

void printSavLefLogo()
{

	std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl;
	std::cout << "@@.                                                                           &@" << std::endl;
	std::cout << "@@.                                                                           &@" << std::endl;
	std::cout << "@@.       *                                                                   &@" << std::endl;
	std::cout << "@@.       ,%                                                                  &@" << std::endl;
	std::cout << "@@.        #&,                                                                &@" << std::endl;
	std::cout << "@@.        ,@@/                                                               &@" << std::endl;
	std::cout << "@@.         &@@%                 .*                                           &@" << std::endl;
	std::cout << "@@.         ,@@@&.               (@#                                          &@" << std::endl;
	std::cout << "@@.          %@@@&*             .&@@&.                                        &@" << std::endl;
	std::cout << "@@.          *@@@@@#            #@@@@&/                                       &@" << std::endl;
	std::cout << "@@.           %@@@@@%.         ,&@@@@@@%                                      &@" << std::endl;
	std::cout << "@@.           *&@@@@@&*        #@@@@@@@@&,                  .,,               &@" << std::endl;
	std::cout << "@@.            &@@@@@@&(      *@@@@@@@@@@@(             .#&@&(#@&(            &@" << std::endl;
	std::cout << "@@.            /@@@@@@@@%     %@@@@@@@@@@@@%.          ,&@@@&/%&@@@&(.        &@" << std::endl;
	std::cout << "@@.             %@@@@@@@@&,  /&@@@@@@@@@@@@@&/        *&@@@@&,     .,/#(.     &@" << std::endl;
	std::cout << "@@.             /@@@@@@@@@@/ %@@@@@@@@@@@@@@@@#      /&@@@@@&.                &@" << std::endl;
	std::cout << "@@.             .&@@@@@@@@@@#,&@@@@@@&/,&@@@@@@&,   (&@@@@@@%                 &@" << std::endl;
	std::cout << "@@.              (@@@@@@@@@@@%,#@@@&*.%&/,%@@@@@&( (@@@@@@@@(                 &@" << std::endl;
	std::cout << "@@.              .&@@@@@@@@@@@&*(%,,&@@@@&/.#@@@&,#@@@@@@@@@/                 &@" << std::endl;
	std::cout << "@@.               (@@@@@&/*%&@@%.,&@@@@@@@@&(.(&,%@@@@@@@@@&,                 &@" << std::endl;
	std::cout << "@@.               .&@@@&*,&%*  .&@@@@@@@@@@@@&( #@@@@@@@@@@&.                 &@" << std::endl;
	std::cout << "@@.                (@@&*,@@@@@@&#*.*#&@@@@@@@@@&#.(@@@@@@@@#                  &@" << std::endl;
	std::cout << "@@.                .&&/*@@@@@@@@@@@@&#*.*%&@@@@@@&#.(&@@@@@(                  &@" << std::endl;
	std::cout << "@@.                 (/*@@@@@@@@@@@@@@@@@@&#,,/%&@@@@%./&@@&*                  &@" << std::endl;
	std::cout << "@@.                  /@@@@@@@@@@@@@@@@@@@@@@@@&(,,(%&@%,*&&,                  &@" << std::endl;
	std::cout << "@@.                 /@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&/.,#&,,                   &@" << std::endl;
	std::cout << "@@.                (@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&#,                    &@" << std::endl;
	std::cout << "@@.               (@@@@@@@@@@@@@@@@@@@@@@@@&&%#/*.                            &@" << std::endl;
	std::cout << "@@.              #@@@@@@@@@@@@@@&&%#/*..                                      &@" << std::endl;
	std::cout << "@@.             #@@@@&&%#(*,.                                                 &@" << std::endl;
	std::cout << "@@.            ,.                                                             &@" << std::endl;
	std::cout << "@@.                                                                           &@" << std::endl;
	std::cout << "@@.                                                                           &@" << std::endl;
	std::cout << "@@.                   SAVLEF'S RPG CHARACTER GENERATOR                        &@" << std::endl;
	std::cout << "@@.                                                                           &@" << std::endl;
	std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl << std::endl;
}

void inptraces()
{
	ifstream dbfile("DATABASES/Database.csv");
	string value;
	int perc;

	std::getline(dbfile, value, '\n');
	std::getline(dbfile, value, ',');

	perc = std::stoi(value);
	RacesPercentage.push_back(perc);

	std::getline(dbfile, value, ',');// read a string until next comma
	Races.push_back(value);
	while (dbfile.good() && value != "END" && value != "end")
	{

		
		std::getline(dbfile, value, '\n');
		std::getline(dbfile, value, ',');// read a string until next comma

		if (value != "") 
		{
			perc = std::stoi(value);
			RacesPercentage.push_back(perc);
		}
		
		std::getline(dbfile, value, ',');// read a string until next comma
		if (value != "")
		{
			Races.push_back(value);
		}
	}

	dbfile.close();
}

void inptclasses()
{
	Algorithms::string_ReadFromCSV(&Classes,"DATABASES/Database.csv",2,0,1,0);
}

void inptstats()
{
	ifstream dbfile("DATABASES/Database_Stats.csv");
	string value;


	std::getline(dbfile, value, '\n');
	std::getline(dbfile, value, ',');


	
	StatName.push_back(value);
	while (dbfile.good() && value != "END" && value != "end")
	{

		std::getline(dbfile, value, '\n');
		std::getline(dbfile, value, ',');// read a string until next comma
		if (value != "" && value != "END" && value!= "end")
		{
		
			StatName.push_back(value);
		}
		
	}

	dbfile.close();
}

void update()
{
		system("CLS");
		std::ofstream myFile("GENERATED CHARACTERS/Characterlist.csv");
		printSavLefLogo();
		std::cout << "Characters created! Choose what to do." << std::endl;
		std::cout << "1. Print all generated characters." << std::endl;
		std::cout << "2. Filter by Race" << std::endl;
		std::cout << "3. Filter by Class" << std::endl;
		std::cout << "-99 . End" << std::endl;
		std::cin >> choice;


		while (choice != 1 && choice != 2 && choice != 3 && choice != -99 || choice == 99 )
		{
			system("CLS");
			printSavLefLogo();
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
			system("CLS");
			printSavLefLogo();
			std::cout << "Characters have been printed into the Characterlist file in the  GENERATED CHARACTERS folder." << std::endl << std::endl;
			std::cout << "To save it, simply SAVE AS the file anywhere on your system." << std::endl << std::endl;
			std::cout << "Press ENTER to wipe it and filter again." << std::endl << std::endl;
			cin.get();
			cin.get();
			break;

		}
		case 2:

		{
			system("CLS");
			printSavLefLogo();
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
				break;
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

			std::cout << "Characters have been printed into the Characterlist file in the  GENERATED CHARACTERS folder." << std::endl << std::endl;
			std::cout << "To save it, simply SAVE AS the file anywhere on your system." << std::endl << std::endl;
			std::cout << "Press ENTER to wipe it and filter again." << std::endl << std::endl;
			cin.get();
			cin.get();
			break;
		}


		case 3:

		{
			system("CLS");
			printSavLefLogo();
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
				break;
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

			std::cout << "Characters have been printed into the Characterlist file in the  GENERATED CHARACTERS folder." << std::endl << std::endl;
			std::cout << "To save it, simply SAVE AS the file anywhere on your system." << std::endl << std::endl;
			std::cout << "Press ENTER to wipe it and filter again." << std::endl << std::endl;
			cin.get();
			cin.get();
			break;



		}
		
		}
}

int main()
{
	inptstats();
	inptraces();
	inptclasses();

	printSavLefLogo();
	std::cout << "Welcome to SavLef's RPG Character Generator!" << std::endl << std::endl;
	std::cout << "How many characters do you want to generate? Up to 1000" << std::endl << std::endl;
	std::cin >> choice;

	while (choice < 1 || choice > 1000) 
	{
		std::cout << "How many characters do you want to generate? Up to 1000" << std::endl;
		std::cin >> choice;
		
	}
	charamount = choice;
	system("CLS");
	RaceGenerated = new MarkovChain;
	RaceGenerated->CalculateLoreSize();
	RaceGenerated->CalculateCharacteristicSize();
	RaceGenerated->StateLore_Neutral();
	RaceGenerated->StateDescription_Neutral();
	RaceGenerated->SendStats(StatName);
	RaceGenerated->ClassStateOne(&Classes);
	RaceGenerated->CalculateRace(&Races,&RacesPercentage,charamount);
	
	
	while (choice != -99)
	{
		update();
	}
	
}


