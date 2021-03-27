#include "Analyser.h"
#include <string>
#include <iostream>

using namespace std;

Analyser::Analyser(int data[][2][10][50], int s)
{
	DATA_SIZE = s;

	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 10;j++)
		{
			for (int k = 0;k < 2;k++)
			{
				for (int l = 0;l < s;l++)
				{
					DATA[l][k][j][i] = data[l][k][j][i];
				}
			}
		}
	}

	sortData();
}


double Analyser::avgNewCase(int state)
{
	int total = 0;
	for (int i = 0; i < DATA_SIZE; i++)
	{
		total += DATA[i][0][4][state];
	}

	return ((double)total/(double)DATA_SIZE);
}

double Analyser::avgNewCase(int timeL, int state)
{

	int total = 0;
	bool found = false;
	for (int i = 0; i <DATA_SIZE; i++)
	{
		if (DATA[i][1][4][state] = timeShift(DATA[DATA_SIZE - 1][1][4][state],timeL))
		total += DATA[i][0][4][state];
	}

	return ((double)total / (double)DATA_SIZE);
}

double Analyser::avgNewCase(date start, date stop, int state)
{
	return 0.0;
}

double Analyser::avgNewDeath(int state)
{
	return 0.0;
}

double Analyser::avgNewDeath(int timeL, int state)
{
	return 0.0;
}

double Analyser::avgNewDeath(date start, date stop, int state)
{
	return 0.0;
}

void Analyser::sortData()
{
	for (int i = 0; i < 50;i++)
	{
		for (int j = 0; j < 10;j++)
		{
			for (int k = 0; k < DATA_SIZE-1;k++)
			{
				for (int l= 0;l< DATA_SIZE - k - 1;l++)
				{
					if (DATA[l][1][j][i] > DATA[l + 1][1][j][i])
					{
						int tempDate1, tempData1;
						int tempDate2, tempData2;

						tempDate1 = DATA[l][1][j][i];
						tempData1 = DATA[l][0][j][i];
						tempDate2 = DATA[l + 1][1][j][i];
						tempData2 = DATA[l + 1][0][j][i];

						DATA[l][1][j][i] = tempDate2;
						DATA[l][0][j][i] = tempData2;

						DATA[l + 1][1][j][i] = tempDate1;
						DATA[l + 1][0][j][i] = tempData1;

					}
				}
			}
		}
	}
}

void Analyser::printTable(int t, int a)
{
	for (int i = 0; i < DATA_SIZE;i++)
	{
		cout << DATA[i][1][t][a] << "\t" << DATA[i][0][t][a] << "\n";
	}
}

int Analyser::getSize() const
{
    return DATA_SIZE;
}

int Analyser::timeShift(int ini,int d)
{
	int iY, iM, iD;
	string f;
	f = to_string(ini);

	iY = stoi(f.substr(0, 4), NULL, 10);
	iM = stoi(f.substr(3, 2), NULL, 10);
	iD = stoi(f.substr(5, 4), NULL, 10);

		if (iD - d < 1 && (iM == 1 || iM == 2 || iM == 4 || iM == 6 || iM == 8 || iM == 9 || iM == 11))
		{
			if (iM - 1 < 1)
			{
				iY -= 1;
				iM = 12;
			}
			else
			{
				iM--;
			}

			iD = 31;

			d -= iD;

			return (timeShift(iY * 10000 + iM * 100 + iD, d));
		}
		else if (iD - d < 1 && (iM == 5 || iM == 7 || iM == 10 || iM == 12))
		{
			iM--;
			iD = 30;
			d -= iD;

			return (timeShift(iY * 10000 + iM * 100 + iD, d));
		}
		else if (iD - d < 1 && iM == 3)
		{
			if (iY % 4 == 0)
			{
				iD = 29;
			}
			else
			{
				iD = 28;
			}

			iM--;
			d -= iD;

			return (timeShift(iY * 10000 + iM * 100 + iD, d));
		}
		else
		{
			return iY * 10000 + iM * 100 + (iD - d);
		}

}