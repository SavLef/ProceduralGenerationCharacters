#pragma once
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>    // std::random_shuffle

class Character
{

public:
	Character();
	~Character();

	void GenClass();
	void GenStats();
	void randSeed();
	void GenRace();

private:
	int STR, DEX, CON, INT, WIS, CHA;
	std::string Class, Race, Name;
	std::vector<int> class_weights;

	

	
};

