#include <iostream>
// ARRAY FORMAT: [date]	  [date_or_time_bool]   [type_of_data]   [state]

/*
	  EXAMPLE GRAPH

     			Deaths per time 
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
	const int height = total/2.5;

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

	// The board is a 2d array of characters that change depenending on the data given,
	// The if statments set the lined borders of the graph
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
// Mark the spots on the board
	int x;
	int y;

	for(int i = 0; i < total; i++)	
	{	
		y = array[i][0][type][state] / 1000; // divide by 1000 because the graph is in k
		x = 1; //Cannot get X value until array creation is finished and the program can be tested with the real array

		if (board[height - y - 4][x*2-1] >= 48 && board[height - y - 4][x*2-1] <= 57 )
			board[height - y - 4][x*2-1]++;
		else
			board[height - y - 4][x*2-1] = '1';
	}

// Print Board
	std::cout << "\u001b[2J" <<
	"\t\t\t\t\t\t\t\t\t\t\t" << 
	"Average " << topic[type] << " Per 2 Weeks" <<
	'\n';
	for(int i = 0; i < height; i++)
	{
		for(int j = 0; j < length; j++)
		{
			if (board[i][j] == '|')
			{
				if(i < height-4)
				{
					std::cout << ((height-i)-4)*100 << 'k'; // Print the values of the left side
				}
				std::cout<<'\t';
			}
			if(i == height-3 && j > 0 && j <= 60)
			{
				std::cout << j; // Print the values for the week
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

