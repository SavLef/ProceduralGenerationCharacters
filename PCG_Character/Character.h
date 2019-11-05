#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Character
{
public:
	Character() {};
	~Character() {};

	void setClass(string Classes);
	void setRace(string Races);
	void PrintSheet();

	string getRace();

public: 
	string Race;
	string Class;
	string Lore;
	vector <string> Inventory;
	int STR=0, AGI=0, SPR=0, INT=0, STM=0;
};

