#include "../header/libxml.h"

void parseXML::parseXML_s(std::ifstream& stream1, std::ofstream& stream2, std::string delimiter)
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

std::string* parseXML::parseXML_s(std::string data)
{
    std::string var[12];
    std::string arr[12];
    std::string arr_v2[12];

    for (int i = 0; i < 12; i++)
    {

        std::regex rx(init_pattern[i]);
        std::smatch sm;
        std::regex_search(data, sm, rx);
        var[i] = sm[0];

        std::regex rx2(secondary_pattern[i]);
        std::smatch sm2;
        std::regex_search(var[i], sm2, rx2);
        arr[i] = sm2[0];

        int len = arr[i].length();

        if (arr[i].substr(0, 1) == ">") {
            arr_v2[i] = arr[i].erase(0, 1);
            arr_v2[i] = arr[i].erase(len - 2, len);
        }
        else
        {
            arr_v2[i] = arr[i];
        }
    }

    return arr_v2;
}

void parseXML::set_submission_date(std::string data)
{
    submission_date = data;
}
std::string parseXML::get_submission_date()
{
    return submission_date;
}

void parseXML::set_state(std::string data)
{
    state = data;
}
std::string parseXML::get_state()
{
    return state;
}

void parseXML::set_total_cases(std::string data)
{
    total_cases = data;
}
std::string parseXML::get_total_cases()
{
    return total_cases;
}

void parseXML::set_conf_cases(std::string data)
{
    conf_cases = data;
}
std::string parseXML::get_conf_cases()
{
    return conf_cases;
}

void parseXML::set_prob_cases(std::string data)
{
    prob_cases = data;
}
std::string parseXML::get_prob_cases()
{
    return prob_cases;
}

void parseXML::set_new_case(std::string data)
{
    new_case = data;
}
std::string parseXML::get_new_case()
{
    return new_case;
}

void parseXML::set_pnew_case(std::string data)
{
    pnew_case = data;
}
std::string parseXML::get_pnew_case()
{
    return pnew_case;
}

void parseXML::set_tot_death(std::string data)
{
    tot_death = data;
}
std::string parseXML::get_tot_death()
{
    return tot_death;
}

void parseXML::set_conf_death(std::string data)
{
    conf_death = data;
}
std::string parseXML::get_conf_death()
{
    return conf_death;
}

void parseXML::set_prob_death(std::string data)
{
    prob_death = data;
}
std::string parseXML::get_prob_death()
{
    return prob_death;
}

void parseXML::set_new_death(std::string data)
{
    new_death = data;
}
std::string parseXML::get_new_death()
{
    return new_death;
}

void parseXML::set_pnew_death(std::string data)
{
    pnew_death = data;
}
std::string parseXML::get_pnew_death()
{
    return pnew_death;
}