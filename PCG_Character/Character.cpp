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

void Character::InitStats(int statnumber)
{
	
	stats.resize(statnumber);
	nostats = statnumber;

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
	myFile << Race << "," << Class << ",";
	for (int i = 0; i < stats.size(); i++)
	{
		myFile << "," << stats.at(i) ;
	}
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
