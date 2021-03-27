#pragma once
#include <iomanip>

using namespace std;

struct date
{
	int day;
	int month;
	int year;
};

class Analyser
{
public:
	Analyser(int data[][2][10][50], int s);
	double avgNewCase(int state);
	double avgNewCase(int timeL, int state);
	double avgNewCase(date start, date stop, int state);
	double avgNewDeath(int state);
	double avgNewDeath(int timeL, int state);
	double avgNewDeath(date start, date stop, int state);
private:
	int DATA_SIZE; 
	int DATA[100][2][10][50];
};