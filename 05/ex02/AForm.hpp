#pragma once
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm{
public:
	virtual ~AForm();
	AForm(const AForm& form);

	AForm(std::string name, int re_ex_grade, int re_sign_grade);

	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw();
	};

	class FileOpenFail : public std::exception {
	public:
		const char* what() const throw();
	};

	class NotSigned : public std::exception {
	public:
		const char* what() const throw();
	};

	void general_form_check(Bureaucrat const & executor) const;

	int get_ex_Grade() const;
	int get_sign_Grade() const;
	std::string getName() const;

	void beSigned(Bureaucrat& bureaucrat);

	virtual void execute(Bureaucrat const & executor) const = 0;

private:
	const std::string name;
	bool _signed;
	const int re_ex_grade;
	const int re_sign_grade;
	AForm& operator=(const AForm& form);
	AForm();
};

std::ostream& operator<<(std::ostream& os, const AForm& form);
