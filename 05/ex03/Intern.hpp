#pragma once

#include <iostream>
#include <exception>


class AForm;

class Intern{
public:
	Intern();
	~Intern();
	Intern(Intern& intern);
	Intern& operator=(Intern& intern);
	AForm* makeForm(std::string form_name, std::string target_form);
	AForm* make_robo_form(std::string target_form);
	AForm* make_sh_form(std::string target_form);
	AForm* make_par_form(std::string target_form);
private:
class not_exist_form: public std::exception{
public:
	const char* what() const throw();
	};
};