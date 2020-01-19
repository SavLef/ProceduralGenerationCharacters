#include "MarkovChain.h"
#include <algorithm>    // std::random_shuffle
#include <ctime>



MarkovChain::MarkovChain()
{

}

void MarkovChain::RandomRace(float amount, string Race_1, string Race_2, string Race_3, string Race_4, string Race_5, string Race_6)
{

	vector<string> Races;
	
	for (float i = 0; i < amount; i+= 0.1f)
	{
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
	}
	
}

void MarkovChain::ClassStateOne(string Class_1, float percent_1, string Class_2, float percent_2, string Class_3, float percent_3, string Class_4, float percent_4, string Class_5, float percent_5, string Class_6, float percent_6, string Class_7, float percent_7, string Class_8, float percent_8, string Class_9, float percent_9, string Class_10, float percent_10, string Class_11, float percent_11, string Class_12, float percent_12)
{
	Class_State_Name[0].push_back(Class_1);
	Class_State_Percent[0].push_back(percent_1);
	Class_State_Name[0].push_back(Class_2);
	Class_State_Percent[0].push_back(percent_2);
	Class_State_Name[0].push_back(Class_3);
	Class_State_Percent[0].push_back(percent_3);
	Class_State_Name[0].push_back(Class_4);
	Class_State_Percent[0].push_back(percent_4);
	Class_State_Name[0].push_back(Class_5);
	Class_State_Percent[0].push_back(percent_5);
	Class_State_Name[0].push_back(Class_6);
	Class_State_Percent[0].push_back(percent_6);
	Class_State_Name[0].push_back(Class_7);
	Class_State_Percent[0].push_back(percent_7);
	Class_State_Name[0].push_back(Class_8);
	Class_State_Percent[0].push_back(percent_8);
	Class_State_Name[0].push_back(Class_9);
	Class_State_Percent[0].push_back(percent_9);
	Class_State_Name[0].push_back(Class_10);
	Class_State_Percent[0].push_back(percent_10);
	
}

string MarkovChain::ClassStateOne_Backend()
{
	vector <string> Classes;

	for (float i = 0; i < Class_State_Percent[0].at(0); i+= 0.1f)
		{
			Classes.push_back(Class_State_Name[0].at(0));
		}
		for (float i = 0; i < Class_State_Percent[0].at(1); i+= 0.1f)
		{
			Classes.push_back(Class_State_Name[0].at(1));
		}

		for (float i = 0; i < Class_State_Percent[0].at(2); i+= 0.1f)
		{
			Classes.push_back(Class_State_Name[0].at(2));
		}

		for (float i = 0; i < Class_State_Percent[0].at(3); i+= 0.1f)
		{
			Classes.push_back(Class_State_Name[0].at(3));
		}
		for (float i = 0; i < Class_State_Percent[0].at(4); i+= 0.1f)
		{
			Classes.push_back(Class_State_Name[0].at(4));
		}
		for (float i = 0; i < Class_State_Percent[0].at(5); i+= 0.1f)
		{
			Classes.push_back(Class_State_Name[0].at(5));
		}
		for (float i = 0; i < Class_State_Percent[0].at(6); i+= 0.1f)
		{
			Classes.push_back(Class_State_Name[0].at(6));
		}
		for (float i = 0; i < Class_State_Percent[0].at(7); i+= 0.1f)
		{
			Classes.push_back(Class_State_Name[0].at(7));
		}
		for (float i = 0; i < Class_State_Percent[0].at(8); i+= 0.1f)
		{
			Classes.push_back(Class_State_Name[0].at(8));
		}
		for (float i = 0; i < Class_State_Percent[0].at(9); i+= 0.1f)
		{
			Classes.push_back(Class_State_Name[0].at(9));
		}


		std::random_shuffle(Classes.begin(), Classes.end());
		return Classes.at(0);
	
	Classes.empty();
}





void MarkovChain::CalculateRace(float amount, string Race_1,float percent_1, string Race_2, float percent_2, string Race_3, float percent_3, string Race_4, float percent_4, string Race_5, float percent_5, string Race_6, float percent_6, string Race_7, float percent_7, string Race_8, float percent_8, string Race_9, float percent_9, string Race_10, float percent_10, string Race_11, float percent_11, string Race_12, float percent_12)
{
	
	vector<string> Races;
	for (float i = 0; i < amount; i+= 1)
		{
	for (float i = 0; i < percent_1; i+= 0.1f)
	{
		Races.push_back(Race_1);
	}

	for (float i = 0; i < percent_2; i+= 0.1f)
	{
		Races.push_back(Race_2);
	}

	for (float i = 0; i < percent_3; i+= 0.1f)
	{
		Races.push_back(Race_3);
	}

	for (float i = 0; i < percent_4; i+= 0.1f)
	{
		Races.push_back(Race_4);
	}
	for (float i = 0; i < percent_5; i+= 0.1f)
	{
		Races.push_back(Race_5);
	}

	for (float i = 0; i < percent_6; i+= 0.1f)
	{
		Races.push_back(Race_6);
	}

	for (float i = 0; i < percent_7; i+= 0.1f)
	{
		Races.push_back(Race_7);
	}
	for (float i = 0; i < percent_8; i+= 0.1f)
	{
		Races.push_back(Race_8);
	}
	for (float i = 0; i < percent_9; i+= 0.1f)
	{
		Races.push_back(Race_9);
	}
	for (float i = 0; i < percent_10; i+= 0.1f)
	{
		Races.push_back(Race_10);
	}
	for (float i = 0; i < percent_11; i+= 0.1f)
	{
		Races.push_back(Race_11);
	}
	for (float i = 0; i < percent_12; i+= 0.1f)
	{
		Races.push_back(Race_12);
	}
	std::srand(std::time(0) + clock());
	std::random_shuffle(Races.begin(), Races.end());
	race_selection = Races.at(0);
	Races.clear();

	
	Arfui.setRace(race_selection);

	//CHECK FOR CLASS ASSIGNMENT
	 if (Arfui.getRace() == Race_1)
	 {
		 Arfui.setClass(ClassStateOne_Backend());
	 }

	 //CHECK FOR STAT DISTRIBUTION
	 if (Arfui.getClass() == Class_State_Name[0].at(0))
	 {
		 std::srand(std::time(0) + clock());
		 Arfui.addSTR(rand() % 10 + 1);
		 std::srand(std::time(0));
		 Arfui.addSTM(rand() % 10 + 1);
		 std::srand(std::time(0) + clock());
		 Arfui.addINT(rand() % 18 + 1);
		 std::srand(std::time(0));
		 Arfui.addSPR(rand() % 15 + 1);
	 }

	// Arfui.PrintSheet();
	 Characters.push_back(Arfui);
	 system("CLS");
	 std::cout << "Characters generated: " << Characters.size() << std::endl;
	 Arfui.ClearSheet();

	 
		}
}


