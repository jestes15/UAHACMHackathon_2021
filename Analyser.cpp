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

