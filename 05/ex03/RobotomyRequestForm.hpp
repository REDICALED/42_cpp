#pragma once
#include "AForm.hpp"

class RobotomyRequestForm: public AForm{
public:
	virtual ~RobotomyRequestForm();
	RobotomyRequestForm(RobotomyRequestForm& robotomyRequestForm);
	RobotomyRequestForm(std::string target);

	virtual void execute(Bureaucrat const & executor) const;

private:
	std::string target;
	RobotomyRequestForm();
	RobotomyRequestForm& operator=(RobotomyRequestForm& robotomyRequestForm);
};