#include "MarkovChain.h"
#include <algorithm>    // std::random_shuffle
#include <ctime>

MarkovChain::MarkovChain()
{

}

void MarkovChain::RandomRace(string Race_1, string Race_2, string Race_3, string Race_4, string Race_5, string Race_6)
{

	vector<string> Races;
	
	if (Race_1 != "")
	{
		Races.push_back(Race_1);
	}

	if (Race_2 != "")
	{
		Races.push_back(Race_2);
	}

	if (Race_3 != "")
	{
		Races.push_back(Race_3);
	}

	if (Race_4 != "")
	{
		Races.push_back(Race_4);
	}

	if (Race_5 != "")
	{
		Races.push_back(Race_5);
	}


	if (Race_6 != "")
	{
		Races.push_back(Race_6);
	}

	std::srand(std::time(0));
	std::random_shuffle(Races.begin(), Races.end());

	class_selection = Races.at(0);

	cout << class_selection;
}

void MarkovChain::CalculateRace(string Race_1,int percent_1, string Race_2, int percent_2, string Race_3, int percent_3, string Race_4, int percent_4, string Race_5, int percent_5, string Race_6, int percent_6)
{
	vector<string> Races;

	for (int i = 0; i < percent_1; i++)
	{
		Races.push_back(Race_1);
	}

	for (int i = 0; i < percent_2; i++)
	{
		Races.push_back(Race_2);
	}

	for (int i = 0; i < percent_3; i++)
	{
		Races.push_back(Race_3);
	}

	for (int i = 0; i < percent_4; i++)
	{
		Races.push_back(Race_4);
	}
	for (int i = 0; i < percent_5; i++)
	{
		Races.push_back(Race_5);
	}

	for (int i = 0; i < percent_6; i++)
	{
		Races.push_back(Race_6);
	}

	std::srand(std::time(0));
	std::random_shuffle(Races.begin(), Races.end());

	 class_selection = Races.at(0);

	 cout << class_selection;
}


