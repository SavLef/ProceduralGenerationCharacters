#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class Character
{
public:
	Character();
	~Character() {};

	void setClass(string Classes);
	void setRace(string Races);
	void addStats(int value, int index);
	void StatCalc(vector <int> statpercents);
	void InitStats(vector <string> statnumber);
	void ReadInventory(vector<string> Neutral_Inventory_Items, vector<float> Neutral_Inventory_Percentage, vector<string> Race_Inventory_Items, vector<float> Race_Inventory_Percentage, vector<string> Class_Inventory_Items, vector<float> Class_Inventory_Percentage);
	void CalculateInventory();
	void ClearSheet();
	void PrintSheet();

	string getRace();
	string getClass();
public: 
	string Race = "";
	string Class = "";
	string Lore = "";
	vector <string> Inventory;

	string s_ST1, s_ST2, s_ST3, s_ST4, s_ST5, s_ST6, s_ST7;
	int ST1 = 1, ST2 = 1, ST3 = 1, ST4 = 1, ST5 = 1, ST6 = 1, ST7 = 1;

	vector <int> stats;
	vector <string> statname;
	vector <int> statpercent;

	int nostats;
	int pointstospend = 20;
};

