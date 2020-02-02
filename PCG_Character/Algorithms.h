#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;



class Algorithms
{
public:
	static void int_ReadFromCSV(vector<int>* DataVector, std::string filename,  int rowskip1 = 0, int columnskip1 = 0, int rowskip2 = 0, int columnskip2 = 0, bool comma = false, bool bottom = false);
	static void string_ReadFromCSV(vector<string>* DataVector,std::string filename,  int rowskip1 = 0, int columnskip1 = 0, int rowskip2 = 0, int columnskip2 = 0, bool comma = false, bool bottom = false);


};