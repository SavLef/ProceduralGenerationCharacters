#include "MarkovChain.h"
#include <algorithm>    // std::random_shuffle
#include <ctime>


void MarkovChain::SendStats(int statnumber)
{
	Arfui.InitStats(statnumber);
}

void MarkovChain::ClassStateOne( vector<string>* Classes)
{

	for (int i = 0; i < Classes->size(); i++)
	{
		Class_State_Name.push_back(Classes->at(i));
	}
	
}

string MarkovChain::ClassStateOne_Backend()
{
	vector <string> Classes;


		for (int j = 0; j < Class_State_Name.size(); j++)
		{
			for (float i = 0; i < Class_State_Percent.at(j); i += 1)
			{
				Classes.push_back(Class_State_Name.at(j));
			}
		}

		Class_State_Percent.clear();
		std::random_shuffle(Classes.begin(), Classes.end());
		return Classes.at(0);

		
		Classes.clear();
}

void MarkovChain::CalculateRace(vector<string>* Race_vector, vector <int>* Race_Percentage_Vector, int charsize)
{
	int perce;
	int counter = 0 ;
	vector<string> Races;

	for (float i = 0; i < charsize; i += 1)
	{
		//CHECK FOR RACE ASSIGNMENT PERCENTAGE
		for (int j = 0; j < Race_vector->size(); j++)
		{
			for (float i = 0; i < Race_Percentage_Vector->at(j); i += 1)
			{
				Races.push_back(Race_vector->at(j));
			}
		}

	std::srand(std::time(0) + clock());
	std::random_shuffle(Races.begin(), Races.end());

	race_selection = Races.at(0);
	Races.clear();
	Arfui.setRace(race_selection);

	//CHECK FOR CLASS ASSIGNMENT PERCENTAGE

for (int j = 0; j < Race_vector->size(); j++)
		{
		if (Arfui.getRace() == Race_vector->at(j))
			{
			ifstream dbfile("Database.csv");
			string value;
			int counter = 0;

			for (int i = 0; i < j; i++)
			{
				std::getline(dbfile, value, '\n');
			}
			std::getline(dbfile, value, '\n');
			std::getline(dbfile, value, ','); // read a string until next comma
			std::getline(dbfile, value, ',');
			std::getline(dbfile, value, ',');

			
			while (dbfile.good() && counter < Class_State_Name.size() && value != "-")
			{

				if (value != "-\n-" && value != "-" && value != "-\n24" && value != "-\n23" && value != "-\n22" && value != "-\n21" && value != "-\n20" && value != "-\n19" && value != "-\n18" && value != "-\n17" && value != "-\n16" && value != "" && value != "-\n15" && value != "-\n14" && value != "-\n13" && value != "-\n12" && value != "-\n11" && value != "-\n10" && value != "-\n9" && value != "-\n8" && value != "-\n7" && value != "-\n6" && value != "-\n5" && value != "-\n4" && value != "-\n3" && value != "-\n2" && value != "-\n")
				{
					perce = std::stoi(value);
					Class_State_Percent.push_back(perce);
				}
				std::getline(dbfile, value, ',');// read a string until next comma
				counter++;
			}
			dbfile.close();
			}

		}

	//CALCULATE THE CLASS
	Arfui.setClass(ClassStateOne_Backend());

	//CALCULATE STATS
	for (int j = 0; j < Class_State_Name.size(); j++)
	{
		if (Arfui.getClass() == Class_State_Name.at(j))
		{
			counter = 0;
			ifstream dbfile("Database_Stats.csv");
			string value;
			std::getline(dbfile, value, '\n');
			std::getline(dbfile, value, ','); // read a string until next comma
			std::getline(dbfile, value, ','); // read a string until next comma

			for (int i = 0; i < j; i++)
			{
				std::getline(dbfile, value, ','); // read a string until next comma
			}

			while (dbfile.good() && counter < Class_State_Name.size())
			{


				if (value != "")
				{
					perce = std::stoi(value);
					StatPercent.push_back(perce);
				}
				std::getline(dbfile, value, '\n');
				std::getline(dbfile, value, ','); // read a string until next comma
				std::getline(dbfile, value, ','); // read a string until next comma
				for (int t = 0; t < j; t++)
				{
					std::getline(dbfile, value, ','); // read a string until next comma
				}
				counter++;

			}
			dbfile.close();
		}
	}

	Arfui.StatCalc(StatPercent);

	StatPercent.clear();
	
	//CHECK FOR INTENTORY

	//CHECK FOR LORE
	

	// Arfui.PrintSheet();

	 Characters.push_back(Arfui);
	 system("CLS");
	 std::cout << "Characters generated: " << Characters.size() << std::endl;
	 Arfui.ClearSheet();

	 
		}
}


