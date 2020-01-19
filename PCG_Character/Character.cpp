#include "Character.h"
#include <fstream>

void Character::setClass(string Classes)
{
	Class = Classes;
}

void Character::setRace(string Races)
{
	Race = Races;
}

void Character::addSTR(int value)
{
	if (pointstospend > value)
	{
		STR += value;
		pointstospend -= value;
	}

	else if (pointstospend > 0 && pointstospend < value)
	{
		STR += pointstospend;
		pointstospend -= pointstospend;
	}
}

void Character::addAGI(int value)
{
	if (pointstospend > value)
	{
		AGI += value;
		pointstospend -= value;
	}

	else if (pointstospend > 0 && pointstospend < value)
	{
		AGI += pointstospend;
		pointstospend -= pointstospend;
	}
}

void Character::addSPR(int value)
{
	if (pointstospend > value)
	{
		SPR += value;
		pointstospend -= value;
	}

	else if (pointstospend > 0 && pointstospend < value)
	{
		SPR += pointstospend;
		pointstospend -= pointstospend;
	}
}

void Character::addINT(int value)
{
	if (pointstospend > value)
	{
		INT += value;
		pointstospend -= value;
	}

	else if (pointstospend > 0 && pointstospend < value)
	{
		INT += pointstospend;
		pointstospend -= pointstospend;
	}
}

void Character::addSTM(int value)
{
	if (pointstospend >= value)
	{
		STM += value;
		pointstospend -= value;
	}

	else if (pointstospend > 0 && pointstospend < value)
	{
		STM += pointstospend;
		pointstospend -= pointstospend;
	}
}

void Character::ClearSheet()
{
	Race = "";
	Class = "";
	Lore = "";
	Inventory.clear();
	STR = 1; 
	AGI = 1; 
	SPR = 1; 
	INT = 1;
	STM = 1;
	pointstospend = 20;
}

void Character::PrintSheet()
{

	std::ofstream myFile;
	myFile.open("Characterlist.csv", std::ofstream::out | std::ofstream::app);
	myFile << Race << "," << Class << "," << STR << "," << STM << "," << INT << "," << SPR << "," << AGI << std::endl;
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
