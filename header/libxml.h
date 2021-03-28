#pragma once

#include <iostream>
#include <fstream>
#include <string>

void parseXML_s(std::ifstream& stream1, std::ofstream& stream2, std::string delimiter);

#ifndef XML_HEADER
#define XML_HEADER

class parseXML
{
public:
	void parseXML_s(std::ifstream& stream1, std::ofstream& stream2, std::string delimiter);

	std::string init_pattern[12] = {
		"<submission_date>[0-9]{4}\\-[0-9]{2}\\-[0-9]{2}T00:00:00</submission_date>",
		"<state>[A-Z]{0,}</state>",
		"<tot_cases>[0-9]{0,}</tot_cases>",
		"<conf_cases>[0-9]{0,}\\.[0-9]{0,}</conf_cases>",
		"<prob_cases>[0-9]{0,}</prob_cases>",
		"<new_case>[0-9]{0,}\\.[0-9]{0,}</new_case>",
		"<pnew_case>[0-9]{0,}</pnew_case>",
		"<tot_death>[0-9]{0,}</tot_death>",
		"<conf_death>[0-9]{0,}\\.[0-9]{0,}</conf_death>",
		"<prob_death>[0-9]{0,}</prob_death>",
		"<new_death>[0-9]{0,}\\.[0-9]{0,}</new_death>",
		"<pnew_death>[0-9]{0,}</pnew_death>",
	};

	std::string secondary_pattern[12] = {
		"[0-9]{4}\\-[0-9]{2}\\-[0-9]{2}",
		">[A-Z]{0,3}<",
		">[0-9]{0,}<",
		"[0-9]{0,}\\.[0-9]{0,}",
		">[0-9]{0,}<",
		"[0-9]{0,}\\.[0-9]{0,}",
		">[0-9]{0,}<",
		">[0-9]{0,}<",
		"[0-9]{0,}\\.[0-9]{0,}",
		">[0-9]{0,}<",
		"[0-9]{0,}\\.[0-9]{0,}",
		">[0-9]{0,}<",
	};
};

#endif

#include "../source/libxml.cpp"
