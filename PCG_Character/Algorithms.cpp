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

	while (dbfile.good() && value != "END" && value != "end")
	{

		for (int i = 0; i < columnskip2; i++)
		{
			std::getline(dbfile, value, '\n');
		}

		for (int i = 0; i < rowskip2; i++)
		{
			std::getline(dbfile, value, ','); // read a string until next comma
			if (value != "END" && value != "end")
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

	while (dbfile.good() && value != "END" && value != "end")
	{

		for (int i = 0; i < columnskip2; i++)
		{
			std::getline(dbfile, value, '\n');
		}

		for (int i = 0; i < rowskip2; i++)
		{
			std::getline(dbfile, value, ','); // read a string until next comma
		}


		if (value != "END" && value != "end")
		{
			perce = std::stoi(value);
			DataVector->push_back(perce);
		}
			
		dbfile.close();
	}
	


}

