#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <array>

using namespace std;
class MarkovChain
{
public:
	MarkovChain();
	~MarkovChain();


public: 
	
	void  CalculateRace(int amount = 1, string Race_1 = "", int percent_1 = 0, string Race_2 = "", int percent_2 = 0, string Race_3 = "", int percent_3 = 0, string Race_4 = "", int percent_4 = 0, string Race_5 = "", int percent_5 = 0, string Race_6 = "", int percent_6 = 0, string Race_7 = "", int percent_7 = 0, string Race_8 = "", int percent_8 = 0, string Race_9 = "", int percent_9 = 0, string Race_10 = "", int percent_10 = 0, string Race_11 = "", int percent_11 = 0, string Race_12 = "", int percent_12 = 0);
	void  RandomRace(int amount =1, string Race_1 = "", string Race_2 = "", string Race_3 = "", string Race_4 = "", string Race_5 = "", string Race_6 = "");
	void  ClassStateOne(string Class_1 = "", int percent_1 = 0, string Class_2 = "", int percent_2 = 0, string Class_3 = "", int percent_3 = 0, string Class_4 = "", int percent_4 = 0, string Class_5 = "", int percent_5 = 0, string Class_6 = "", int percent_6 = 0, string Class_7 = "", int percent_7 = 0, string Class_8 = "", int percent_8 = 0, string Class_9 = "", int percent_9 = 0, string Class_10 = "", int percent_10 = 0, string Class_11 = "", int percent_11 = 0, string Class_12 = "", int percent_12 = 0);
	void  ClassStateOne_Backend();

	string race_selection = "";
	string class_selection_1 = "";
	
	vector <string> Class_State_1_Name;
	vector <int> Class_State_1_Percent;
};

