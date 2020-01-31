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
	MarkovChain();
	~MarkovChain();


public: 
	
	void  CalculateRace(float amount = 1, string Race_1 = "", float percent_1 = 0, string Race_2 = "", float percent_2 = 0, string Race_3 = "", float percent_3 = 0, string Race_4 = "", float percent_4 = 0, string Race_5 = "", float percent_5 = 0, string Race_6 = "", float percent_6 = 0, string Race_7 = "", float percent_7 = 0, string Race_8 = "", float percent_8 = 0, string Race_9 = "", float percent_9 = 0, string Race_10 = "", float percent_10 = 0, string Race_11 = "", float percent_11 = 0, string Race_12 = "", float percent_12 = 0);
	void  RandomRace(float amount =1, string Race_1 = "", string Race_2 = "", string Race_3 = "", string Race_4 = "", string Race_5 = "", string Race_6 = "");
	void SendStats(int statnumber);
	void  ClassStateOne(string Class_1 = "",  string Class_2 = "",  string Class_3 = "",  string Class_4 = "", string Class_5 = "",  string Class_6 = "",  string Class_7 = "",  string Class_8 = "",  string Class_9 = "",  string Class_10 = "",  string Class_11 = "",  string Class_12 = "");
	string  ClassStateOne_Backend();

	string race_selection = "";
	string class_selection[12];
	
	vector <string> Class_State_Name[12];
	vector <float> Class_State_Percent[12];

	vector <int> Class_Percent_Chance;

	Character Arfui;

	vector <Character> Characters;
	vector <int> StatPercent;

};

