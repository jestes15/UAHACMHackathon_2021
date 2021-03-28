// UAHHackathon.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <regex>

#include "../header/libxml.h"
#include "../header/updater.h"
#include "../header/graph.h"

using namespace std;

int main()
{
    // updateData();
	parseXML xml_obj;

    std::ifstream stream1;
	stream1.open("../data.cdc.gov/data.xml",ios::in);
    std::ofstream stream2;
	stream2.open("../data.cdc.gov/data.txt", std::ios::out);

    xml_obj.parseXML_s(stream1, stream2, "<row");

    std::cout << "Finished" << std::endl;
	stream1.close();
	stream2.close();
	
	ifstream stream3;
	stream3.open("../data.cdc.gov/data.txt",ios::in);
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
			cout<< aaa;
			stream5 << aaa<< "pie ";
		}
		stream5 << "\n";
		if (counter%1000 ==0)
		{
			cout<<counter<<"\n";
		}

		counter++;
	}

	bool running = true;
    	int a;

	while (running)
	{
		std::cout << "\nPlease enter what you would like to do." << std::endl
    	<< "0: Exit the program" << std::endl
    	<< "1: Update the data file" << std::endl
    	<< "2: print a graph (WIP)" << std::endl;
    	cin >> a;
		if(a == 0)
			running = false;
		else if(a == 1)
			updateData();
/*		else if(a == 2)
			graph();
*/
		else
			std::cout << "That is not a correct input, please try agian\n";
	}


	std::cout << "Done" << std::endl;
	stream5.close();

    return 0;

}
