#include "graph.cpp"
#include <math.h>

int main(void)
{
	int testArray[100][2][10][50];
    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 10;j++)
        {
            for (int k = 0;k < 2;k++)
            {
                for (int l = 0;l < 100;l++)
                {
                    testArray[l][k][j][i] = i*1000;
                }
            }
        }
	}

	graph(testArray,0, 0, 100);
	return 0;
}
