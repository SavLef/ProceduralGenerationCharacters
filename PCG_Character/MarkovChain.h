#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <array>
#include <ctime>
#include "Character.h"
#include <fstream>

using namespace std;
class MarkovChain
{
public:



public: 
	
	void  CalculateRace(vector<string>* Races, vector<int>*race_percentage, int charsize);
	void SendStats(vector<string> statnumber);
	void  ClassStateOne(vector<string>*classes);
	void StateStats();
	void StateClass(vector <string> race_vector);
	void StateRace(vector <string> race_vector, vector<int> Race_Percentage_Vector);
	void StateInventory();
	void StateInventory_Neutral();
	string  ClassStateOne_Backend();

	string race_selection = "";
	string class_selection[12];
	
	vector <string> Class_State_Name;
	vector <float> Class_State_Percent;

	vector <int> Class_Percent_Chance;

	Character Arfui;

	vector <Character> Characters;
	vector <int> StatPercent;

	vector <string> Neutral_Inventory;
	vector <float> Neutral_Inventory_Percentage;

	vector <string> Class_Inventory;
	vector <float> Class_Inventory_Percentage;

	vector <string> Race_Inventory;
	vector <float> Race_Inventory_Percentage;

};

