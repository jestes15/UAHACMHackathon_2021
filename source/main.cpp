// UAHHackathon.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <regex>

#include "../header/libxml.h"
#include "../header/updater.h"
#include "../header/graph.h"
#include "../header/Analyser.h"

using namespace std;
// ################# 
const int getDataSetSize()
{
	return 10;
}
//####################

int main()
{

	bool running = true;
	int a;

	//########################################
	//#####IMPORTANT INITIALIZATIONS HERE#####
	//########################################

	int DATA[10][2][10][50];

	// Manually set Dates
	DATA[0][1][4][5] = 20201105;
	DATA[1][1][4][5] = 20201105;
	DATA[2][1][4][5] = 20201130;
	DATA[3][1][4][5] = 20201129;
	DATA[4][1][4][5] = 20201123;
	DATA[5][1][4][5] = 20201128;
	DATA[6][1][4][5] = 20201110;
	DATA[7][1][4][5] = 20201120;
	DATA[8][1][4][5] = 20201110;
	DATA[9][1][4][5] = 20201111;

	// Manually set the Data
	DATA[0][0][4][5] = 101000;
	DATA[1][0][4][5] = 105000;
	DATA[2][0][4][5] = 208000;
	DATA[3][0][4][5] = 309000;
	DATA[4][0][4][5] = 303000;
	DATA[5][0][4][5] = 505000;
	DATA[6][0][4][5] = 602000;
	DATA[7][0][4][5] = 403000;
	DATA[8][0][4][5] = 507000;
	DATA[9][0][4][5] = 209000;


	const int SIZE = getDataSetSize();
	//int DATA[SIZE][2][10][50];
	Analyser PROCESSOR(SIZE);
	PROCESSOR.sortData(DATA);
	//########################################
	//#####IMPORTANT INITIALIZATIONS HERE#####
	//########################################


	while (running)
	{
		std::cout << "\nPlease enter what you would like to do." << std::endl
			<< "0: Exit the program" << std::endl
			<< "1: Update the data file" << std::endl
			<< "2: print a graph" << std::endl
			<< "3: get averages\n";

		cin >> a;
		if (a == 0)
			running = false;
		else if (a == 1)
		{
			updateData();
			// updateData();
			parseXML xml_obj;

			std::ifstream stream1;
			stream1.open("../data.cdc.gov/data.xml", ios::in);
			std::ofstream stream2;
			stream2.open("../data.cdc.gov/data.txt", std::ios::out);

			xml_obj.parseXML_s(stream1, stream2, "<row");

			std::cout << "Finished" << std::endl;
			stream1.close();
			stream2.close();

			ifstream stream3;
			stream3.open("../data.cdc.gov/data.txt", ios::in);
			ofstream stream5;
			stream5.open("../data.cdc.gov/data2.txt", ios::app);

			int counter = 0;
			while (!stream3.eof() && counter < 5000)
			{
				string data;
				string data_ptr;

				getline(stream3, data);

				data_ptr = *xml_obj.parseXML_s(data);


				for (int i = 0; i < 12; i++)
				{
					char aaa = data_ptr[i];
					cout << aaa;
					stream5 << aaa << "pie ";
				}
				stream5 << "\n";
				if (counter % 1000 == 0)
				{
					cout << counter << "\n";
				}

				counter++;
			}

			std::cout << "Done" << std::endl;
			stream5.close();
		}
		else if (a == 2)
		{
			bool loop = true;
			while (loop)
			{
				int state;
				int sel;
				int sel2;
				int temp;

				cout << "What state would you like to find an graph for? (enter a number from 1-50 representing a state in alphabetical order)\n";
				cin >> state;

				cout << "What data would you like to get the graph of?\n"
					<< "1: total cases\n2: confirmed cases\n3: probable cases\n4: new cases\n5:probable new cases\n6: total deaths\n7: confirmed deaths\n8: probable deaths\n9: new deaths\n10: probable new deaths\n11: Exit\n";
				cin >> sel;
				if (sel == 11)
				{
					loop = false;
				}

				cout << "what's the year preference (2020 or 2021):\n";
				cin >> temp;

				graph(DATA,SIZE, sel-1, state-1, 100, temp);

			}
		}
		else if (a == 3)
		{
			bool loop = true;
			while (loop)
			{
				int state;
				int sel;
				int sel2;
				int temp;
				int temp2;

				cout << "What state would you like to find an average for? (enter a number from 1-50 representing a state in alphabetical order)\n";
				cin >> state;

				cout << "What data would you like to get the average of?\n"
					<< "1: new cases\n2: probable new cases\n3: new deaths\n4: probable new deaths\n5: Exit\n";
				cin >> sel;

				if (sel == 1)
				{
					cout << "What kind of average?\n1: average over the total dataset\n2: average over the last n days\n3: average between a time period";
					cin >> sel2;
					if (sel2 == 1)
					{
						cout << PROCESSOR.avgNewCase(DATA, state) << "\n";
					}
					else if (sel == 2)
					{
						cout << "How many days back?\n";
						cin >> temp;
						cout << PROCESSOR.avgNewCase(DATA, temp, state) << "\n";
					}
					else if (sel == 3)
					{
						cout << "between what days? (enter as one number in year month day ie. 3/28/2021 would be entered as 20212803)\nstart day:\n";
						cin >> temp;
						cout << "end day:\n";
						cin >> temp2;

						cout << PROCESSOR.avgNewCase(DATA, temp, temp2, state) << "\n";
					}
					else
						cout << "Invalid input\n";
				}
				else if (sel == 2)
				{
					cout << "What kind of average?\n1: average over the total dataset\n2: average over the last n days\n3: average between a time period";
					cin >> sel2;
					if (sel2 == 1)
					{
						cout << PROCESSOR.avgPNewCase(DATA, state) << "\n";
					}
					else if (sel == 2)
					{
						cout << "How many days back?\n";
						cin >> temp;
						cout << PROCESSOR.avgPNewCase(DATA, temp, state) << "\n";
					}
					else if (sel == 3)
					{
						cout << "between what days? (enter as one number in year month day ie. 3/28/2021 would be entered as 20212803)\nstart day:\n";
						cin >> temp;
						cout << "end day:\n";
						cin >> temp2;

						cout << PROCESSOR.avgPNewCase(DATA, temp, temp2, state) << "\n";
					}
					else
						cout << "Invalid input\n";
				}
				else if (sel == 3)
				{
					cout << "What kind of average?\n1: average over the total dataset\n2: average over the last n days\n3: average between a time period";
					cin >> sel2;
					if (sel2 == 1)
					{
						cout << PROCESSOR.avgNewDeath(DATA, state) << "\n";
					}
					else if (sel == 2)
					{
						cout << "How many days back?\n";
						cin >> temp;
						cout << PROCESSOR.avgNewDeath(DATA, temp, state) << "\n";
					}
					else if (sel == 3)
					{
						cout << "between what days? (enter as one number in year month day ie. 3/28/2021 would be entered as 20212803)\nstart day:\n";
						cin >> temp;
						cout << "end day:\n";
						cin >> temp2;

						cout << PROCESSOR.avgNewDeath(DATA, temp, temp2, state) << "\n";
					}
					else
						cout << "Invalid input\n";
				}
				else if (sel == 4)
				{
					cout << "What kind of average?\n1: average over the total dataset\n2: average over the last n days\n3: average between a time period";
					cin >> sel2;
					if (sel2 == 1)
					{
						cout << PROCESSOR.avgPNewDeath(DATA, state) << "\n";
					}
					else if (sel == 2)
					{
						cout << "How many days back?\n";
						cin >> temp;
						cout << PROCESSOR.avgPNewDeath(DATA, temp, state) << "\n";
					}
					else if (sel == 3)
					{
						cout << "between what days? (enter as one number in year month day ie. 3/28/2021 would be entered as 20212803)\nstart day:\n";
						cin >> temp;
						cout << "end day:\n";
						cin >> temp2;

						cout << PROCESSOR.avgPNewDeath(DATA, temp, temp2, state) << "\n";
					}
					else
						cout << "Invalid input\n";
				}
				else if (sel == 5)
				{
					loop = false;
				}
			}
		}
		else
			std::cout << "That is not a correct input, please try agian\n";
	}




	return 0;

}
