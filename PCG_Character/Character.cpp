#include "Character.h"

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

void Character::PrintSheet()
{
	cout << "Character Race: " << Race << endl;
	cout << "Character Class: " << Class << endl;
	cout << "Strength: " << STR << endl;
	cout << "Stamina: " << STM << endl;
	cout << "Intellect: " << INT << endl;
	cout << "Spirit: " << SPR << endl;
	cout << "Agility: " << AGI << endl;
	cout << "------------" << endl;
}

string Character::getRace()
{
	return Race;
}

string Character::getClass()
{
	return Class;
}
