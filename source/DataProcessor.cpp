#include "DataProcessor.h"
#include <iostream>


using namespace std;

DataProcessor::DataProcessor()
{
	updating = true;
}

void DataProcessor::initialize(string name)
{
	filename = name;
}

void DataProcessor::update()
{
	char* temp;
	ifstream inFile;
	inFile.open(filename, ios::in);

		while (! inFile.eof())
		{
			temp = new char;
			inFile >>temp;
			bigAssArray.push_back(temp);

			cout << "also here";
		}
}

void DataProcessor::stopUpdating()
{
	updating = false;
}

void DataProcessor:: printGarbo()
{
	cout << "efwefw\n";
	for (auto x : bigAssArray)
	{
		cout << x << "\n";
	}
}
