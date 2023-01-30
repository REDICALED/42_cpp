#pragma once
#include "AForm.hpp"

class ShrubberyCreationForm: public AForm{
public:
	virtual ~ShrubberyCreationForm();
	ShrubberyCreationForm(ShrubberyCreationForm& shrubberyCreationForm);
	ShrubberyCreationForm(std::string target);

	virtual void execute(Bureaucrat const & executor) const;

private:
	std::string target;
	ShrubberyCreationForm();
	ShrubberyCreationForm& operator=(ShrubberyCreationForm& shrubberyCreationForm);

};