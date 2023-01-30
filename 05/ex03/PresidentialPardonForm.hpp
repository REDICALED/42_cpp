#pragma once
#include "AForm.hpp"

class PresidentialPardonForm: public AForm{
public:
	virtual ~PresidentialPardonForm();
	PresidentialPardonForm(PresidentialPardonForm& presidentialPardonForm);
	PresidentialPardonForm(std::string target);

	virtual void execute(Bureaucrat const & executor) const;

private:
	std::string target;
	PresidentialPardonForm();
	PresidentialPardonForm& operator=(PresidentialPardonForm& presidentialPardonForm);
};