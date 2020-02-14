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
	void StateInventory(vector<string> Race_vector);
	void StateInventory_Neutral();
	void StateLore_Neutral();
	void CalculateLore();
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

	vector <string> Lore_Origin; vector <float> Lore_Origin_Percentage;
	vector <string> Lore_ConnectorWord; vector <float> Lore_ConnectorWord_Percentage;
	vector <string> Lore_CITY; vector <float> Lore_CITY_Percentage;
	vector <string> Lore_ConnectorWordSecond; vector <float> Lore_ConnectorWordSecond_Percentage;
	vector <string> Lore_Characteristic; vector<float> Lore_Characteristic_Percentage;
	vector <string> Lore_Occupation; vector <float> Lore_Occupation_Percentage;
	vector <string> Lore_ConnectorWordThird; vector <float> Lore_ConnectorWordThird_Percentage;
	vector <string> Lore_Ambition; vector <float> Lore_Ambition_Percentage;
	vector <string> Lore_Ambition_2; vector <float> Lore_Ambition_2_Percentage;
	vector <string> Lore_Ambition3; vector <float> Lore_Ambition3_Percentage;


};

