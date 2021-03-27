// UAHHackathon.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::endl;
using std::cin;

int main()
{
    std::ifstream stream1("data.xml");
    std::ofstream stream2("data.txt", std::ios::app);
    std::string data;

    std::getline(stream1, data);

    std::string delimiter = "<";
    std::string a;
    size_t pos = 0;
    std::string token;

    while ((pos = data.find(delimiter[0])) != std::string::npos)
    {
        token = data.substr(0, pos) + "\n";
        stream2 << token ;
        std::cout << token << std::endl;
        data.erase(0, pos + delimiter.length());
    }

    std::cout << data << std::endl;

    cin >> a;

    return 0;
}
