#include "Analyser.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include <thread>
#include <math.h>



using namespace std;

int main()
{
	string dataTypes[] = { "Garbage" };
	int dataSize = 1;


	for (int i = 0; i < dataSize;i++)
	{
		cout << dataTypes[i] << "\n";
	}

	int garbo[100][2][10][50];
	srand(time(NULL));

	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 10;j++)
		{
			for (int k = 0;k < 2;k++)
			{
				for (int l = 0;l < 100;l++)
				{
					

					garbo[l][k][j][i] = rand()%100 +1;
					if (k==0 && j==4 && i==5)
						cout << garbo[l][k][j][i]<<"\n";
				}
			}
		}
	}

	Analyser anal(garbo, 100);
	cout << anal.avgNewCase(5);



}