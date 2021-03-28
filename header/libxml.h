#pragma once

#include <iostream>
#include <fstream>
#include <string>

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
};

#include "../source/libxml.cpp"
