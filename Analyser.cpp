#include "Analyser.h"

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

