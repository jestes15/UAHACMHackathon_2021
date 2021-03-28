#include <string>
#include <iostream>
// ARRAY FORMAT: [date]	  [date_or_time_bool]   [type_of_data]   [state]

/*
	  EXAMPLE GRAPH

     			Deaths per time 
1100k|
1000k|                          7  
900k |
800k |                  6 1
700k |            6
600k |            5       2
500k |                        1
400k |
300k |                3
200k |        1
100k |
	 --------------------------------------
	  1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
*/ 

inline int findyear(int date)
{
	while(date >= 10000)
		date = date/10;	
	return date;
}

inline int findmonth(int tempDate)
{
	int date = tempDate;
		
	while(date >= 1000000)
		date = date/10;	
	date = date%100;
	
	return date;
}

inline int findday(int date)
{
	return date%100;
}

inline int timeShift(int ini,int d)
{
    int iY, iM, iD;
    std::string f;
    f = std::to_string(ini);

    iY = findyear(ini);
    iM = findmonth(ini);
    iD = findday(ini);

        if (iD - d < 1 && (iM == 1 || iM == 2 || iM == 4 || iM == 6 || iM == 8 || iM == 9 || iM == 11))
        {
            d -= iD;
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


            return (timeShift(iY * 10000 + iM * 100 + iD, d));
        }
        else if (iD - d < 1 && (iM == 5 || iM == 7 || iM == 10 || iM == 12))
        {
            iM--;
            d -= iD;
            iD = 30;

            return (timeShift(iY * 10000 + iM * 100 + iD, d));
        }
        else if (iD - d < 1 && iM == 3)
        {
            d -= iD;
            if (iY % 4 == 0)
            {
                iD = 29;
            }
            else
            {
                iD = 28;
            }

            iM--;

            return (timeShift(iY * 10000 + iM * 100 + iD, d));
        }
        else if (d == 0)
        {
            return ini;
        }
        else
        {
            return iY * 10000 + iM * 100 + (iD - d);
        }

}

inline int daysInYear(int date)
{
    int iY, iM, iD;
    std::string f;
    f = std::to_string(date);

    iY = findyear(date);
    iM = findmonth(date);
    iD = findday(date);

    if (iM == 1)
    {
        return iD;
    }
    else
    {
        return daysInYear(timeShift(date, iD)) + iD;
    }

}

inline int graph(int array[][2][10][50], int array_length, int type, int state, int total, int yearPref)
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
	int year;
	int month;
	int day;
	
	int mtd = 0; //Months to Days variable

	for(int i = 0; i < array_length; i++)	
	{	
		year = findyear(array[i][1][type][state]);
		month = findmonth(array[i][1][type][state]);
		day = findday(array[i][1][type][state]); // take first two digits of the date (the day)

		y = array[i][0][type][state] / 100000; // divide the data by 100000 because the graph is in 100k
		x = daysInYear(array[i][1][type][state]) / 7;

		//debug info
		std::cout << "y: " << height - y - 4 << '\t';
		std::cout << "x: " << x*2-1 << '\n';
		std::cout << "year: " << year << '\n';
		std::cout << "month: " << month << '\n';
		std::cout << "day: " << day << '\n';
		std::cout << "days in year: " << daysInYear(array[i][1][type][state]) << '\n';

		// The subtractions in the x and y values are to adjust for the borders of the graph
			if (board[height - y - 4][x*2-1] >= 48 && board[height - y - 4][x*2-1] <= 57 )
				board[height - y - 4][x*2-1]++;
			else
			{
				if(year == 2020)	
					board[height - y - 4][x-1] = '1';
			}
	}

// Print Board
	std::cout << //"\u001b[2J" <<
	"\t\t\t\t\t\t\t\t\t" << 
	"Average " << topic[type] << " Per Week in " << yearPref << '\n';
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

