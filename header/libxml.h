#pragma once

#include <iostream>
#include <fstream>
#include <string>

#ifndef XML_HEADER
#define XML_HEADER

class parseXML
{
private:
	std::string submission_date;
	std::string state;
	std::string total_cases;
	std::string conf_cases;
	std::string prob_cases;
	std::string new_case;
	std::string pnew_case;
	std::string tot_death;
	std::string conf_death;
	std::string prob_death;
	std::string new_death;
	std::string pnew_death;

public:
	void parseXML_s(std::ifstream& stream1, std::ofstream& stream2, std::string delimiter);
	// std::string* parseXML_s(std::ifstream stream, std::string delimiter);

	void set_submission_date(std::string);
	std::string get_submission_date();

	void set_state(std::string);
	std::string get_state();

	void set_total_cases(std::string);
	std::string get_total_cases();

	void set_conf_cases(std::string);
	std::string get_conf_cases();

	void set_prob_cases(std::string);
	std::string get_prob_cases();

	void set_new_case(std::string);
	std::string get_new_case();

	void set_pnew_case(std::string);
	std::string get_pnew_case();

	void set_tot_death(std::string);
	std::string get_tot_death();

	void set_conf_death(std::string);
	std::string get_conf_death();

	void set_prob_death(std::string);
	std::string get_prob_death();

	void set_new_death(std::string);
	std::string get_new_death();

	void set_pnew_death(std::string);
	std::string get_pnew_death();

	std::string patterns[11] = {
	"<submission_date>[0-9]{4}\\-[0-9]{2}\\-[0-9]{2}T00:00:00</submission_date>",
	"<state>[A-Z]{0,}</state>",
	"<tot_cases>[0-9]{0,}</tot_cases>",
	"<conf_cases>[0-9]{0,}\\.[0-9]{0,}</conf_cases>",
	"<prob_cases>[0-9]{0,}</prob_cases>",
	"<new_case>[0-9]{0,}\\.[0-9]{0,}</new_case>",
	"<pnew_case>[0-9]{0,}</pnew_case>",
	"<tot_death>[0-9]{0,}</tot_death>"
	"<conf_death>[0-9]{0,}\\.[0-9]{0,}</conf_death>",
	"<prob_death>[0-9]{0,}</prob_death>",
	"<new_death>[0-9]{0,}\\.[0-9]{0,}</new_death>",
	"<pnew_death>[0-9]{0,}</pnew_death>"
	};
};

#endif

#include "../source/libxml.cpp"
