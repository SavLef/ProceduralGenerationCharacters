#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <array>

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
	void ReadPassives(vector<string> Passives, vector<float> Passives_Percentage);
	void CalculateInventory();
	void ClearSheet();
	void PrintSheet();
	void importLore(vector <string> Lore);
	void importPersonality(vector <string> Lore);
	void importDescription(vector <string> Lore);
	void ProcessLore();

	string getRace();
	string getClass();
public: 
	string Race = "";
	string Class = "";
	string Lore = "";
	vector <string> Inventory;
	vector <string> Real_Inventory;
	vector <float> Inventory_Percentage;

	string s_ST1, s_ST2, s_ST3, s_ST4, s_ST5, s_ST6, s_ST7;
	int ST1 = 1, ST2 = 1, ST3 = 1, ST4 = 1, ST5 = 1, ST6 = 1, ST7 = 1;

	vector <int> stats;
	vector <string> statname;
	vector <int> statpercent;
	vector <string> lore;
	vector <string> personality;
	vector <string> description;
	vector <string> passiveslist;
	vector <string> Real_Passives;

	int inventoryslots = 0;
	int emptyslots = 0;
	int nostats;
	int pointstospend = 20;
	int level = 1;
	const int basehp = 5;

	int HP;
};

