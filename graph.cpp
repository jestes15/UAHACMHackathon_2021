#include <ncurses.h>
#include <iostream>
// ARRAY FORMAT: [date]	  [date_or_time_bool]   [type_of_data]   [state]

/*
	  EXAMPLE GRAPH

     			Deaths per week
1100k|
1000k|                           9
900k |
800k |                  6 1
700k |
600k |            5
500k |                        1
400k |
300k |                3
200k |        1
100k |
	 --------------------------------------
	  1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
*/ 

int graph(int array[][2][10][50], int type, int state, int total)
{
// constants
	const int length = total*1.8;
	const int height = total/3;

	const char* topic[10] = 
	{
		"Total Covid Cases",
		"Confirmed Covid Cases",
		"Probable Covid Cases",
		"New Covid Cases",
		"Probable New Covid Cases",
		"Total Covid Deaths",
		"Total Confirmed Covid Deaths",
		"Total Probable Covid Deaths",
		"Total New Deaths",
		"Probable New Deaths"
	};

// Set Board
	char board[height][length];
	for(int i = 0; i < height; i++)
	{
		for(int j = 0; j < length; j++)
		{
			if(i == height-4)
				board[i][j] = '-';
			else if(j == 0)
				board[i][j] = '|';
			else
				board[i][j] = ' ';
				
		}
	}


// Print Board
	std::cout << "\u001b[2J";
	std::cout << "\t\t\t\t\t\t\t\t\t\t\t";
	std::cout << "Average " << topic[type] << " Per Week";
	std::cout << '\n';
	for(int i = 0; i < height; i++)
	{
		for(int j = 0; j < length; j++)
		{
			if (board[i][j] == '|')
			{
				if(i < height-4)
				{
					std::cout << ((height-i)-4)*100 << 'k';
				}
				std::cout<<'\t';
			}
			if(i == height-3 && j > 0 && j <= 60)
			{
				std::cout << j;//array[i][1][type][state];
			}
			std::cout << board[i][j];	
		}
		std::cout << '\n';
	}






/*PRINTS THE ENTIRE ARRAY (FOR DEBUGGING)
	for (int i = 0; i < total; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 10; k++)
			{
				for (int l = 0; l < 50; l++)
				{
					std::cout << array[i][j][k][l];
				}
				std::cout << "\n";
			}
			std::cout << "\n\n";
		}
		std::cout << "\n\n\n";
	}	
*/
	return 0;	
}

