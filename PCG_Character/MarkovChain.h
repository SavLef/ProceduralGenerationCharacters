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
	void StateDescription_Neutral();
	void CalculateLore();
	void CalculateDescription();
	void CalculateLoreSize();
	void CalculateCharacteristicSize();

	void CalculatePersonalitySize();
	void CalculatePersonality();
	void StatePersonality_Neutral();

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



	/*vector <string> Lore[30]; vector <float> Lore_Percentage[30];
	vector <string> Desc[30]; vector <float> Desc_Percentage[30];
*/

	vector <string>* Lore; vector <float>* Lore_Percentage;
	vector <string>* Desc; vector <float>* Desc_Percentage;
	vector <string>* Personality; vector <float>* Personality_Percentage;

	int lore_column_size;
	int characteristic_column_size;
	int personality_column_size;



};

