#pragma once
#include <iostream>

class Bureaucrat{
public:
	Bureaucrat();
	~Bureaucrat();
	Bureaucrat(Bureaucrat& bureaucrat);
	Bureaucrat& operator=(Bureaucrat& bureaucrat);

	Bureaucrat(std::string name, int grade);
	std::string getName();
	int getGrade();

private:
	const std::string name;
	int grade;

};

