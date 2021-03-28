#include "../header/libxml.h"

void parseXML_s(std::ifstream& stream1, std::ofstream& stream2, std::string delimiter)
{
    std::string data;
    std::getline(stream1, data);
    size_t pos = 0;
    std::string token;

    while ((pos = data.find(delimiter)) != std::string::npos)
    {
        token = data.substr(0, pos) + "\n";

        if (token.compare("<response>\n") == 0)
        {
            data.erase(0, pos + delimiter.length());
            continue;
        }
        if (token.compare(">\n") == 0)
        {
            data.erase(0, pos + delimiter.length());
            continue;
        }

        stream2 << token;
        data.erase(0, pos + delimiter.length());
    }
    stream2 << data;

    return;
}