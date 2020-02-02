#include "Algorithms.h"

void Algorithms::string_ReadFromCSV(vector<string>* DataVector,std::string filename, int rowskip1, int columnskip1, int rowskip2, int columnskip2, bool comma, bool bottom)
{
	ifstream dbfile(filename);
	string value;
	int counter = 0; 

	for (int i = 0; i < columnskip1; i++)
	{
		std::getline(dbfile, value, '\n');
	}


	for (int i = 0; i < rowskip1; i++)
	{
		std::getline(dbfile, value, ','); // read a string until next comma
	}

	while (dbfile.good() && value != "-\n24" && value != "-\n23" && value != "-\n22" && value != "-\n21" && value != "-\n20" && value != "-\n19" && value != "-\n18" && value != "-\n17" && value != "-\n16" && value != "-\n15" && value != "-\n14" && value != "-\n13" && value != "-\n12" && value != "-\n11" && value != "-\n10" && value != "-\n9" && value != "-\n8" && value != "-\n7" && value != "-\n6" && value != "-\n5" && value != "-\n4" && value != "-\n3" && value != "-\n2" && value != "-\n")
	{

		for (int i = 0; i < columnskip2; i++)
		{
			std::getline(dbfile, value, '\n');
		}

		for (int i = 0; i < rowskip2; i++)
		{
			std::getline(dbfile, value, ','); // read a string until next comma
			if (value != "")
			{
				DataVector->push_back(value);
			}
		}

		
		
	}
	dbfile.close();
	
}

void Algorithms::int_ReadFromCSV(vector<int>* DataVector, std::string filename, int rowskip1, int columnskip1, int rowskip2, int columnskip2, bool comma, bool bottom)
{
	ifstream dbfile(filename);
	string value;
	int perce;
	int counter = 0;

	for (int i = 0; i < columnskip1; i++)
	{
		std::getline(dbfile, value, '\n');
	}

	for (int i = 0; i < rowskip1; i++)
	{
		std::getline(dbfile, value, ','); // read a string until next comma
	}

	while (dbfile.good()  &&value != "-\n15")
	{

		for (int i = 0; i < columnskip2; i++)
		{
			std::getline(dbfile, value, '\n');
		}

		for (int i = 0; i < rowskip2; i++)
		{
			std::getline(dbfile, value, ','); // read a string until next comma
		}


		if (value != "-\n24" && value != "-\n23" && value != "-\n22" && value != "-\n21" && value != "-\n20" && value != "-\n19" && value != "-\n18" && value != "-\n17" && value != "-\n16" && value != "" && value != "-\n15" && value != "-\n14" && value != "-\n13" && value != "-\n12" && value != "-\n11" && value != "-\n10" && value != "-\n9" && value != "-\n8" && value != "-\n7" && value != "-\n6" && value != "-\n5" && value != "-\n4" && value != "-\n3" && value != "-\n2" && value != "-\n")
		{
			perce = std::stoi(value);
			DataVector->push_back(perce);
		}
			
		dbfile.close();
	}
	


}

