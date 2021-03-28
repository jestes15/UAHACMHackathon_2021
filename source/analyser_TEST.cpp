#include "../header/Analyser.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include <thread>
#include <math.h>



using namespace std;

int main()
{
	const int size = 100;
	string dataTypes[] = { "Garbage" };
	int dataSize = 1;


	for (int i = 0; i < dataSize;i++)
	{
		cout << dataTypes[i] << "\n";
	}

	int garbo[size][2][10][50];
	srand(time(NULL));

	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 10;j++)
		{
			for (int k = 0;k < 2;k++)
			{
				for (int l = 0;l < size;l++)
				{
					
					if (k == 1)
					{
						garbo[l][k][j][i] = (rand() %12+1)*100+(rand()%31+1)+20200000;
					}
					else
					{
						garbo[l][k][j][i] = rand() % 100 + 1;
					}
					if (k==0 && j==4 && i==5)
						cout << garbo[l][k][j][i]<<"\n";
				}
			}
		}
	}

	Analyser anal(size);
	anal.sortData(garbo);

	for (int i = 4; i < 5;i++)
	{
		for (int j = 0;j < 50;j++)
		{
			anal.printTable(garbo,i, j);
			//cout << anal.avgNewCase(garbo,20201130,20201215,j);
			cout << "\n" << i << " " << j << "\n";
		}
	}

	return 1;

}
