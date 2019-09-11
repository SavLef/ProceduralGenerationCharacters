#pragma once
#include <cstdlib>
#include <iostream>
#include <string>
class Character
{

public:
	Character();
	~Character();

	void GenClass();
	void GenStats();
	void randSeed();

private:
	int STR, DEX, CON, INT, WIS, CHA;
	std::string Class;

	

	
};

