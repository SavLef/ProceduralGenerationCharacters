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
	void addSTR(int value);
	void addAGI(int value);
	void addSPR(int value);
	void addINT(int value);
	void addSTM(int value);
	void PrintSheet();

	string getRace();
	string getClass();
public: 
	string Race = "";
	string Class = "";
	string Lore = "";
	vector <string> Inventory;
	int STR=1, AGI=1, SPR=1, INT=1, STM=1;
	int pointstospend = 20;
};

