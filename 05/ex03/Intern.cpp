#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(){

}

Intern::~Intern(){

}

Intern::Intern(Intern& intern){
	*this = intern;
}

Intern& Intern::operator=(Intern& intern){
	(void)intern;
	return *this;
}

AForm* Intern::make_robo_form(std::string target_form){
	AForm *form = new RobotomyRequestForm(target_form);
	return form;
}

AForm* Intern::make_sh_form(std::string target_form){
	AForm *form = new ShrubberyCreationForm(target_form);
	return form;
}

AForm* Intern::make_par_form(std::string target_form){
	AForm *form = new PresidentialPardonForm(target_form);
	return form;
}

AForm* Intern::makeForm(std::string form_name, std::string target_form){
	AForm* (Intern::*f[3])(std::string) = {&Intern::make_robo_form, &Intern::make_sh_form, &Intern::make_par_form};
	std::string Forms[3] = { "robotomy request", "shrubbery creation", "presidential pardon"};
	int i = -1;
	while (form_name != Forms[++i] && i < 3);
	if (i == 3)
		throw NotExistForm();
	AForm* form = (this->*(f[i]))(target_form);
	std::cout << "Intern creates " << form->getName() << std::endl;
	return form;
}

const char* Intern::NotExistForm::what() const throw(){
	return "no form such of that name !\n";
}