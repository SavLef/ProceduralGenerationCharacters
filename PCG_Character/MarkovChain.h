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
	
	void  CalculateRace(string Race_1 = "", int percent_1 = 0, string Race_2 = "", int percent_2 = 0, string Race_3 = "", int percent_3 = 0, string Race_4 = "", int percent_4 = 0, string Race_5 = "", int percent_5 = 0, string Race_6 = "", int percent_6 = 0);
	void  RandomRace(string Race_1 = "", string Race_2 = "", string Race_3 = "", string Race_4 = "", string Race_5 = "", string Race_6 = "");

	string class_selection = "";
};

