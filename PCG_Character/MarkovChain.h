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
	void SendStats(int statnumber);
	void  ClassStateOne(vector<string>*classes);
	string  ClassStateOne_Backend();

	string race_selection = "";
	string class_selection[12];
	
	vector <string> Class_State_Name;
	vector <float> Class_State_Percent;

	vector <int> Class_Percent_Chance;

	Character Arfui;

	vector <Character> Characters;
	vector <int> StatPercent;

};

