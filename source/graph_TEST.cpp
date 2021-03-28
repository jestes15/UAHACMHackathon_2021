#include "../header/graph.h"

int main(void)
{
	
	int testArray[10][2][10][50];

// Manually set Dates
    testArray[0][1][4][5] = 20201105;
    testArray[1][1][4][5] = 20201105;
    testArray[2][1][4][5] = 20201130;
    testArray[3][1][4][5] = 20201129;
    testArray[4][1][4][5] = 20201123;
    testArray[5][1][4][5] = 20201128;
    testArray[6][1][4][5] = 20201110;
    testArray[7][1][4][5] = 20201120;
    testArray[8][1][4][5] = 20201110;
    testArray[9][1][4][5] = 20201111;

// Manually set the Data
    testArray[0][0][4][5] = 101000;
    testArray[1][0][4][5] = 105000;
    testArray[2][0][4][5] = 208000;
    testArray[3][0][4][5] = 309000;
    testArray[4][0][4][5] = 303000;
    testArray[5][0][4][5] = 505000;
    testArray[6][0][4][5] = 602000;
    testArray[7][0][4][5] = 403000;
    testArray[8][0][4][5] = 507000;
    testArray[9][0][4][5] = 209000;

	graph(testArray,10, 4, 5, 100, 2020);


/*    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 10;j++)
        {
            for (int k = 0;k < 2;k++)
            {
                for (int l = 0;l < 100;l++)
                {
                    testArray[l][k][j][i] = (i-j+l-k) * 1000;
                }
            }
        }
	}	*/

	return 0;
}
