// UAHHackathon.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::endl;
using std::cin;

void
parseXML(std::ifstream & stream1, std::ofstream & stream2)
{
    std::string data;
    std::getline(stream1, data);

    std::string delimiter = "<row";
    size_t pos = 0;
    std::string token;

    while ((pos = data.find(delimiter)) != std::string::npos)
    {
        token = data.substr(0, pos) + "\n";
        stream2 << token;
        data.erase(0, pos + delimiter.length());
    }
    stream2 << token;

    return;
}

int main()
{
    std::ifstream stream1("data.xml");
    std::ofstream stream2("data.txt", std::ios::app);

    parseXML(stream1, stream2);

    cout << "Finsihed";

    std::string a;
    cin >> a;

    return 0;
}
