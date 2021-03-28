// UAHHackathon.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <regex>

#include "../header/libxml.h"
#include "../header/updater.h"
#include "../header/graph.h"

using std::cout;
using std::endl;
using std::cin;

int main()
{
    // updateData();
    std::ifstream stream1("data.xml");
    std::ofstream stream2("data.txt", std::ios::out);
    parseXML xml_obj;

    xml_obj.parseXML_s(stream1, stream2, "<row");

    cout << "Finished";
	stream1.close();
	stream2.close();

	std::ifstream stream3("data.txt");

	std::string data;
	std::getline(stream3, data);

	std::string var[12]{ "" };

	for (int i = 0; i < 11; i++)
	{
		std::regex rx(xml_obj.patterns[i]);
		std::smatch sm;
		std::regex_search(data, sm, rx);
		std::cout << sm[0] << std::endl;
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


    return 0;
}
