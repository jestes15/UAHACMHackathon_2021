#pragma once
#include <iomanip>
#include <iostream>

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
	double avgNewCase(int start, int stop, int state);
	double avgNewDeath(int state);
	double avgNewDeath(int timeL, int state);
	double avgNewDeath(int start, int stop, int state);
	double avgPNewCase(int state);
	double avgPNewCase(int timeL, int state);
	double avgPNewCase(int start, int stop, int state);
	double avgPNewDeath(int state);
	double avgPNewDeath(int timeL, int state);
	double avgPNewDeath(int start, int stop, int state);
	void sortData();
	int getSize() const;
	void printTable(int t, int a);
	static int timeShift(int ini, int d);
private:
	int DATA_SIZE; 
	int DATA[100][2][10][50];
};
