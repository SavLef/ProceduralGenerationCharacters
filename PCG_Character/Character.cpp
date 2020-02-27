#include "Character.h"
#include <fstream>

Character::Character()
{

}

void Character::setClass(string Classes)
{
	Class = Classes;
}

void Character::setRace(string Races)
{
	Race = Races;
}

void Character::addStats(int value, int index)
{
	int newvalue;

	newvalue = rand() % (value+1) + 1;

	if (pointstospend > newvalue)
	{
		stats.at(index) += newvalue;
		pointstospend -= newvalue;
	}

	else if (pointstospend > 0 && pointstospend < newvalue)
	{
		stats.at(index) += pointstospend;
		pointstospend -= pointstospend;
	}

}



void Character::StatCalc(vector <int> statpercents)
{
	statpercent = statpercents;
	vector <string> selection;
	string answer;

	while (pointstospend > 0)
	{


		for (int j = 0; j < statname.size(); j++)
		{
			for (float i = 0; i < statpercent.at(j); i += 1)
			{
				selection.push_back(statname.at(j));
			}
		}


		std::random_shuffle(selection.begin(), selection.end());

		answer = selection.at(0);

		for (int z = 0; z < stats.size(); z++)
		{
			if (statname.at(z) == answer)
			{

				if (pointstospend > 0 && stats.at(z) <20)
				{

					if (stats.at(z) > 16 && pointstospend > 2)
					{
						stats.at(z) += 1;
						pointstospend -= 3;
					}

					else if (stats.at(z) > 12 && pointstospend >1)
					{
						stats.at(z) += 1;
						pointstospend -= 2;
					}

					else 
					{
						stats.at(z) += 1;
						pointstospend -= 1;
					}
				}

			}
		}
		selection.clear();

	}
}

void Character::InitStats(vector<string> statnumber)
{
	
	stats.resize(statnumber.size());
	nostats = statnumber.size();

	statname = statnumber;

}

void Character::ReadInventory(vector<string> Neutral_Inventory_Items, vector<float> Neutral_Inventory_Percentage, vector<string> Race_Inventory_Items, vector<float> Race_Inventory_Percentage, vector<string> Class_Inventory_Items, vector<float> Class_Inventory_Percentage)
{
	//calculate inventory slots
	std::srand(std::time(0) + clock());

	inventoryslots = rand() % 10 + 5;
	emptyslots = inventoryslots;

	Inventory_Percentage.clear();
	Inventory.clear();

	Inventory.insert(Inventory.end(), Neutral_Inventory_Items.begin(), Neutral_Inventory_Items.end());
	Inventory.insert(Inventory.end(), Race_Inventory_Items.begin(), Race_Inventory_Items.end());
	Inventory.insert(Inventory.end(), Class_Inventory_Items.begin(), Class_Inventory_Items.end());

	Inventory_Percentage.insert(Inventory_Percentage.end(), Neutral_Inventory_Percentage.begin(), Neutral_Inventory_Percentage.end());
	Inventory_Percentage.insert(Inventory_Percentage.end(), Race_Inventory_Percentage.begin(), Race_Inventory_Percentage.end());
	Inventory_Percentage.insert(Inventory_Percentage.end(), Class_Inventory_Percentage.begin(), Class_Inventory_Percentage.end());

	for (int i = 0; i < Inventory.size(); i++)
	{
		if (emptyslots > 0)
		{
			vector <int> temprolls;
			int tempselection;
			//Fill with positive data
			for (int j = 0; j < Inventory_Percentage.at(i); j++)
			{
				temprolls.push_back(1);
			}
			//Fill with negative data
			while (temprolls.size() < 100)
			{
				temprolls.push_back(0);
			}

			std::random_shuffle(temprolls.begin(), temprolls.end());
			tempselection = temprolls.at(0);

			switch (tempselection)
			{
			case 0:
				break;
			case 1:
				Real_Inventory.push_back(Inventory.at(i));
				emptyslots--;
				break;
			default:
				break;
			}

			temprolls.clear();

		}
	}
}

void Character::ClearSheet()
{
	Race = "";
	Class = "";
	Lore = "";
	Inventory.clear();
	Real_Inventory.clear();
	Inventory_Percentage.clear();
	lore.clear();
	description.clear();
	lore.resize(0);
	stats.clear();
	statpercent.clear();
	stats.resize(nostats);
	for (int i = 0; i < stats.size(); i++)
	{
		stats.at(i) = 4;
	}


	
	int newvalue = rand() % (20) + 1;
	level = newvalue;

	//points to spend relative to level
	pointstospend = level * 2.5;
}

void Character::PrintSheet()
{

	std::ofstream myFile;
	myFile.open("GENERATED CHARACTERS/Characterlist.csv", std::ofstream::out | std::ofstream::app);

	//CAPTIONS

	myFile << "Race" << "," << "Class" << ",";
	for (int i = 0; i < statname.size(); i++)
	{
		myFile << "," << statname.at(i);
	}
	myFile << "," << "," << "INVENTORY" << ",";
	myFile << std::endl;

	//ACTUAL VALUES
	myFile << Race << "," << Class << ",";
	for (int i = 0; i < stats.size(); i++)
	{
		myFile << "," << stats.at(i);
	}
	myFile << "," << "," << inventoryslots - emptyslots << " out of " << inventoryslots;

	//Print level
	myFile << std::endl;
	myFile << "Level" << "," << level;

	myFile << std::endl;


	for (int i = 0; i < Real_Inventory.size(); i++)
	{
		for (int j = 0; j < stats.size() + 4; j++)
		{
			myFile << ",";
		}
		myFile << Real_Inventory.at(i);
		myFile << std::endl;

	}

	//PRINT LORE
	for (int i = 0; i < lore.size(); i++)
	{
		myFile << " " << lore.at(i);
	}
	myFile << std::endl;
	//PRINT LORE
	for (int i = 0; i < description.size(); i++)
	{
		myFile << " " << description.at(i);
	}
	myFile << std::endl;
	myFile << std::endl;
	myFile << "___________________________________________________________________________________________________________________________________________________________________________________________";
	myFile << std::endl;
	myFile.close();
}

void Character::importLore(vector<string> Lore)
{
	lore = Lore;
}

void Character::importDescription(vector<string> Desc)
{
	description = Desc;
}

void Character::ProcessLore()
{
	for (int i = 0; i < lore.size(); i++)
	{
		if (lore.at(i) == "CLASS")
		{
			lore.at(i) = getClass();
		}

		else if (lore.at(i) == "RACE")
		{
			lore.at(i) = getRace();
		}

		if (description.at(i) == "EMPTY")
		{
			description.at(i) = "";
		}


	}
	
}

string Character::getRace()
{
	return Race;
}

string Character::getClass()
{
	return Class;
}
