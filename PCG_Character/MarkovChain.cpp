#include "MarkovChain.h"
#include <algorithm>    // std::random_shuffle
#include <ctime>

MarkovChain::MarkovChain()
{

}

void MarkovChain::RandomRace(int amount, string Race_1, string Race_2, string Race_3, string Race_4, string Race_5, string Race_6)
{

	vector<string> Races;
	
	for (int i = 0; i < amount; i++)
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

		/*class_selection = Races.at(0);

		cout << class_selection << endl;
		cout << "=============" << endl;*/
	}
	
}

void MarkovChain::ClassStateOne(string Class_1, int percent_1, string Class_2, int percent_2, string Class_3, int percent_3, string Class_4, int percent_4, string Class_5, int percent_5, string Class_6, int percent_6, string Class_7, int percent_7, string Class_8, int percent_8, string Class_9, int percent_9, string Class_10, int percent_10, string Class_11, int percent_11, string Class_12, int percent_12)
{
	Class_State_1_Name.push_back(Class_1);
	Class_State_1_Percent.push_back(percent_1);
	Class_State_1_Name.push_back(Class_2);
	Class_State_1_Percent.push_back(percent_2);
	Class_State_1_Name.push_back(Class_3);
	Class_State_1_Percent.push_back(percent_3);
	Class_State_1_Name.push_back(Class_4);
	Class_State_1_Percent.push_back(percent_4);
	Class_State_1_Name.push_back(Class_5);
	Class_State_1_Percent.push_back(percent_5);
	Class_State_1_Name.push_back(Class_6);
	Class_State_1_Percent.push_back(percent_6);
	Class_State_1_Name.push_back(Class_7);
	Class_State_1_Percent.push_back(percent_7);
	Class_State_1_Name.push_back(Class_8);
	Class_State_1_Percent.push_back(percent_8);
	Class_State_1_Name.push_back(Class_9);
	Class_State_1_Percent.push_back(percent_9);
	Class_State_1_Name.push_back(Class_10);
	Class_State_1_Percent.push_back(percent_10);
	
}

void MarkovChain::ClassStateOne_Backend()
{
	vector <string> Classes;
	if (race_selection == "Human")
	{
		for (int i = 0; i < Class_State_1_Percent.at(0); i++)
		{
			Classes.push_back(Class_State_1_Name.at(0));
		}
		for (int i = 0; i < Class_State_1_Percent.at(1); i++)
		{
			Classes.push_back(Class_State_1_Name.at(1));
		}

		for (int i = 0; i < Class_State_1_Percent.at(2); i++)
		{
			Classes.push_back(Class_State_1_Name.at(2));
		}

		for (int i = 0; i < Class_State_1_Percent.at(3); i++)
		{
			Classes.push_back(Class_State_1_Name.at(3));
		}
		for (int i = 0; i < Class_State_1_Percent.at(4); i++)
		{
			Classes.push_back(Class_State_1_Name.at(4));
		}
		for (int i = 0; i < Class_State_1_Percent.at(5); i++)
		{
			Classes.push_back(Class_State_1_Name.at(5));
		}
		for (int i = 0; i < Class_State_1_Percent.at(6); i++)
		{
			Classes.push_back(Class_State_1_Name.at(6));
		}
		for (int i = 0; i < Class_State_1_Percent.at(7); i++)
		{
			Classes.push_back(Class_State_1_Name.at(7));
		}
		for (int i = 0; i < Class_State_1_Percent.at(8); i++)
		{
			Classes.push_back(Class_State_1_Name.at(8));
		}
		for (int i = 0; i < Class_State_1_Percent.at(9); i++)
		{
			Classes.push_back(Class_State_1_Name.at(9));
		}


		std::random_shuffle(Classes.begin(), Classes.end());

		class_selection_1 = Classes.at(0);
		std::cout << class_selection_1 << endl;
	}
	Classes.empty();
}




void MarkovChain::CalculateRace(int amount, string Race_1,int percent_1, string Race_2, int percent_2, string Race_3, int percent_3, string Race_4, int percent_4, string Race_5, int percent_5, string Race_6, int percent_6, string Race_7, int percent_7, string Race_8, int percent_8, string Race_9, int percent_9, string Race_10, int percent_10, string Race_11, int percent_11, string Race_12, int percent_12)
{
	vector<string> Races;
	for (int i = 0; i < amount; i++)
		{
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

	for (int i = 0; i < percent_7; i++)
	{
		Races.push_back(Race_7);
	}
	for (int i = 0; i < percent_8; i++)
	{
		Races.push_back(Race_8);
	}
	for (int i = 0; i < percent_9; i++)
	{
		Races.push_back(Race_9);
	}
	for (int i = 0; i < percent_10; i++)
	{
		Races.push_back(Race_10);
	}
	for (int i = 0; i < percent_11; i++)
	{
		Races.push_back(Race_11);
	}
	for (int i = 0; i < percent_12; i++)
	{
		Races.push_back(Race_12);
	}
	std::srand(std::time(0));
	std::random_shuffle(Races.begin(), Races.end());
	 race_selection = Races.at(0);
	 cout << race_selection << endl;

	 if (race_selection == Race_1)
	 {
		 ClassStateOne_Backend();
	 }

	 cout << "------------" << endl;
		}
}


