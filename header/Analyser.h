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
	Analyser(int s);
	double avgNewCase(int DATA[][2][10][50], int state);
	double avgNewCase(int DATA[][2][10][50], int timeL, int state);
	double avgNewCase(int DATA[][2][10][50], int start, int stop, int state);
	double avgNewDeath(int DATA[][2][10][50], int state);
	double avgNewDeath(int DATA[][2][10][50], int timeL, int state);
	double avgNewDeath(int DATA[][2][10][50], int start, int stop, int state);
	double avgPNewCase(int DATA[][2][10][50], int state);
	double avgPNewCase(int DATA[][2][10][50], int timeL, int state);
	double avgPNewCase(int DATA[][2][10][50], int start, int stop, int state);
	double avgPNewDeath(int DATA[][2][10][50], int state);
	double avgPNewDeath(int DATA[][2][10][50], int timeL, int state);
	double avgPNewDeath(int DATA[][2][10][50], int start, int stop, int state);
	void sortData(int DATA[][2][10][50]);
	int getSize() const;
	void printTable(int DATA[][2][10][50], int t, int a);
	static int timeShift(int ini, int d);
private:
	int DATA_SIZE;
};
