#pragma once

#include <iostream>
#include <exception>

#define Low_Grade 150
#define High_Grade 1

class AForm;

class Bureaucrat{
public:
	Bureaucrat();
	~Bureaucrat();
	Bureaucrat(Bureaucrat& bureaucrat);
	Bureaucrat& operator=(const Bureaucrat& bureaucrat);

	Bureaucrat(std::string name, int grade);
	const std::string getName() const;
	int getGrade() const;

	class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw();
	};
	void executeForm(AForm const & form);
	void increment_grade(int input);
	void decrement_grade(int input);
	void signAForm(AForm &form);
private:
	const std::string name;
	int grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

