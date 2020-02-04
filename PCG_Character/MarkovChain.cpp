#include "MarkovChain.h"
#include <algorithm>    // std::random_shuffle
#include <ctime>


void MarkovChain::SendStats(vector <string> statnumber)
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

void MarkovChain::StateStats()
{
	//CALCULATE STATS

	int perce;
	int counter = 0;

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
}

void MarkovChain::StateClass(vector <string> Race_vector)
{
	int perce;
	int counter = 0;

	for (int j = 0; j < Race_vector.size(); j++)
	{
		if (Arfui.getRace() == Race_vector.at(j))
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
	Arfui.setClass(ClassStateOne_Backend());

}

void MarkovChain::StateRace(vector<string> Race_vector, vector<int> Race_Percentage_Vector)
{
	vector<string> Races;
	//CHECK FOR RACE ASSIGNMENT PERCENTAGE
	for (int j = 0; j < Race_vector.size(); j++)
	{
		for (float i = 0; i < Race_Percentage_Vector.at(j); i += 1)
		{
			Races.push_back(Race_vector.at(j));
		}
	}

	std::srand(std::time(0) + clock());
	std::random_shuffle(Races.begin(), Races.end());

	race_selection = Races.at(0);
	Races.clear();
	Arfui.setRace(race_selection);
}

void MarkovChain::StateInventory(vector<string> Race_vector)
{

	//READ ITEM DATABASE
	float perce;
	int counter = 0;

	//READ FOR RACE
	for (int j = 0; j < Race_vector.size(); j++)
	{
		if (Arfui.getRace() == Race_vector.at(j))
		{
			counter = 0;
			ifstream dbfile("Database_Inventory_Race.csv");
			string value;
			std::getline(dbfile, value, '\n');


			for (int i = 0; i < j; i++)
			{
				std::getline(dbfile, value, ','); // read a string until next comma
				std::getline(dbfile, value, ','); // read a string until next comma
			}
			std::getline(dbfile, value, ','); // read a string until next comma
			while (dbfile.good() && counter < Race_vector.size())
			{
				if (value != "")
				{
					Race_Inventory.push_back(value);
					std::getline(dbfile, value, ','); // read a string until next comma
					if (value != "")
					{
						perce = std::stof(value);
						Race_Inventory_Percentage.push_back(perce);
					}
				}
				std::getline(dbfile, value, '\n');
				for (int t = 0; t < j; t++)
				{
					std::getline(dbfile, value, ','); // read a string until next comma
					std::getline(dbfile, value, ','); // read a string until next comma
				}
				std::getline(dbfile, value, ','); // read a string until next comma
				counter++;

			}
			dbfile.close();
		}
	}
	
	//READ FOR CLASS
	for (int j = 0; j < Class_State_Name.size(); j++)
	{
		if (Arfui.getClass() == Class_State_Name.at(j))
		{
			counter = 0;
			ifstream dbfile("Database_Inventory_Class.csv");
			string value;
			std::getline(dbfile, value, '\n');
			

			for (int i = 0; i < j; i++)
			{
				std::getline(dbfile, value, ','); // read a string until next comma
				std::getline(dbfile, value, ','); // read a string until next comma
			}
			std::getline(dbfile, value, ','); // read a string until next comma
			while (dbfile.good() && counter < Class_State_Name.size())
			{
				if (value != "")
				{
					Class_Inventory.push_back(value);
					std::getline(dbfile, value, ','); // read a string until next comma
					if (value != "")
					{
						perce = std::stof(value);
						Class_Inventory_Percentage.push_back(perce);
					}
				}
				std::getline(dbfile, value, '\n');
				for (int t = 0; t < j; t++)
				{
					std::getline(dbfile, value, ','); // read a string until next comma
					std::getline(dbfile, value, ','); // read a string until next comma
				}
				std::getline(dbfile, value, ','); // read a string until next comma
				counter++;

			}
			dbfile.close();
		}
	}


}

void MarkovChain::StateInventory_Neutral()
{
	//READ FOR NEUTRAL

	int counter = 0;
	float perce = 0;
	ifstream dbfile("Database_Inventory_Neutral.csv");
	string value;
	std::getline(dbfile, value, ',');

	while (dbfile.good() && value != "")
	{
		if (value != "")

		{
			Neutral_Inventory.push_back(value);
			std::getline(dbfile, value, ','); // read a string until next comma
			if (value != "")
			{
				perce = std::stof(value);
				Neutral_Inventory_Percentage.push_back(perce);
			}
		}
		std::getline(dbfile, value, '\n');
		std::getline(dbfile, value, ',');
		counter++;

	}
	dbfile.close();
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
	
	//LOOP BASED ON No. Characters
	for (float i = 0; i < charsize; i += 1)
	{
	
	//CHECK FOR RACEE ASSIGNMENT PERCENTAGE
	StateRace(*Race_vector, *Race_Percentage_Vector);

	//CHECK FOR CLASS ASSIGNMENT PERCENTAGE
	StateClass(*Race_vector);

	//CHECK FOR STAT ASSIGNMENT PERCENTAGE
	StateStats();

	//CALCULATE STATS
	Arfui.StatCalc(StatPercent);
	StatPercent.clear();
	
	//CHECK FOR INTENTORY ASSIGNMENT PERCENTAGE
	StateInventory_Neutral();
	StateInventory(*Race_vector);

	Arfui.ReadInventory(Neutral_Inventory, Neutral_Inventory_Percentage, Race_Inventory, Race_Inventory_Percentage, Class_Inventory, Class_Inventory_Percentage);
	Class_Inventory.clear();
	Race_Inventory.clear();
	Neutral_Inventory.clear();

	//CALCULATE INVENTORY

	//CHECK FOR LORE ASSIGNMENT
	//ASSIGN LORE
	
	//STORE CHARACTER TO VECTOR
	 Characters.push_back(Arfui);
	 system("CLS");

	 //DISPLAY GENERATED NUMBER
	 std::cout << "Characters generated: " << Characters.size() << std::endl;

	 //RESET NEXT CHARACTER
	 Arfui.ClearSheet();

	 
		}
}


