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
	
	for (int i = 0; i < statpercent.size(); i++)
	{
		addStats(statpercent.at(i), i);
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
	Inventory.insert(Inventory.end(), Neutral_Inventory_Items.begin(), Neutral_Inventory_Items.end());
	Inventory.insert(Inventory.end(), Race_Inventory_Items.begin(), Race_Inventory_Items.end());
	Inventory.insert(Inventory.end(), Class_Inventory_Items.begin(), Class_Inventory_Items.end());
}

void Character::ClearSheet()
{
	Race = "";
	Class = "";
	Lore = "";
	Inventory.clear();
	stats.clear();
	stats.resize(nostats);
	pointstospend = 50;
}

void Character::PrintSheet()
{

	std::ofstream myFile;
	myFile.open("Characterlist.csv", std::ofstream::out | std::ofstream::app);

	//CAPTIONS
	myFile << "Race" << "," << "Class" << ",";
	for (int i = 0; i < statname.size(); i++)
	{
		myFile << "," << statname.at(i);
	}
	myFile << "," << "INVENTORY" << ",";
	myFile << std::endl;

	//ACTUAL VALUES
	myFile << Race << "," << Class << ",";
	for (int i = 0; i < stats.size(); i++)
	{
		myFile << "," << stats.at(i);
	}
	myFile << std::endl;
	for (int i = 0; i < Inventory.size(); i++)
	{
		for (int j = 0; j < stats.size()+3; j++)
		{
			myFile << ",";
		}
		myFile << Inventory.at(i);
		myFile << std::endl;
		
	}

	myFile << std::endl;
	myFile << std::endl;

	myFile.close();
}

string Character::getRace()
{
	return Race;
}

string Character::getClass()
{
	return Class;
}
