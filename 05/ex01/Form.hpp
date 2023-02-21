#pragma once
#include <iostream>
#include <exception>

class Bureaucrat;

class Form{
public:
	~Form();
	Form(const Form& form);

	Form(std::string name, int re_ex_grade, int re_sign_grade);

	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw();
	};

	bool get_is_signed();
	int get_ex_Grade() const;
	int get_sign_Grade() const;
	std::string getName() const;
	void beSigned(Bureaucrat& bureaucrat);

private:
	const std::string name;
	bool _signed;
	const int re_ex_grade;
	const int re_sign_grade;
	Form& operator=(const Form& form);
	Form();
};

std::ostream& operator<<(std::ostream& os, const Form& form);
