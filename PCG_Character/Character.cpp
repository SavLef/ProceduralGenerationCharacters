#include "Character.h"

void Character::setClass(string Classes)
{
	Class = Classes;
}

void Character::setRace(string Races)
{
	Race = Races;
}

void Character::PrintSheet()
{
	cout << "Character Race: " << Race << endl;
	cout << "Character Class: " << Class << endl;
	cout << "------------" << endl;
}

string Character::getRace()
{
	return Race;
}
