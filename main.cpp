// UAHHackathon.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include "libxml.h"

using std::cout;
using std::endl;
using std::cin;

int main()
{
    std::ifstream stream1("data.xml");
    std::ofstream stream2("data.txt", std::ios::app);
    parseXML xml_obj;

    xml_obj.parseXML_s(stream1, stream2, "<row");

    cout << "Finsihed";

    std::string a;
    cin >> a;

    return 0;
}
