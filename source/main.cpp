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
	parseXML xml_obj;

    std::ifstream stream1("../data.cdc.goc/data.xml");
    std::ofstream stream2("../data.cdc.goc/data.txt", std::ios::out);

    xml_obj.parseXML_s(stream1, stream2, "<row");

    std::cout << "Finished" << std::endl;
	stream1.close();
	stream2.close();
	
	std::ifstream stream3("../data.cdc.goc/data.txt");
	std::ofstream stream5("../data.cdc.goc/data2.txt", std::ios::out);
	int L = 0;
	while (!stream3.eof())
	{
		std::string data;
		std::string* data_ptr;
		std::getline(stream3, data);

		data_ptr = xml_obj.parseXML_s(data);
		for (int i = 0; i < 12; i++) {
			stream5 << data_ptr[i] << " ";
		}
		stream5 << "\n";
	}

	std::cout << "Done" << std::endl;
    std::string a;
    std::cin >> a;

    return 0;
}
