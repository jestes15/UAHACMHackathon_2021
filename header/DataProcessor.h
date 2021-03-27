#pragma once
#include <fstream>
#include <vector>
#include <thread>
#include <chrono>

using namespace std;

class DataProcessor
{
public:
	DataProcessor();
	void initialize(string name);
	void update();
	void stopUpdating();
	void printGarbo();
private:
	string filename;
	bool updating;
	vector<string> bigAssArray;
	
};
