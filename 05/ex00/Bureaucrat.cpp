#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name(""), grade(Low_Grade){

};

Bureaucrat::~Bureaucrat(){

};

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat):name(bureaucrat.name), grade(bureaucrat.grade){
};

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& bureaucrat){
	if (this == &bureaucrat)
		return *this;
	this->grade = bureaucrat.grade;
	return *this;
};

Bureaucrat::Bureaucrat(std::string name, int grade): name(name), grade(grade){
	if (this->grade < High_Grade)
		throw GradeTooHighException();
	else if (this->grade > Low_Grade)
		throw GradeTooLowException();
};

const std::string Bureaucrat::getName() const{
	return this->name;
};

int Bureaucrat::getGrade() const{
	return this->grade;
};

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high!\n";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low!\n";
}

void Bureaucrat::increment_grade(int input) {
	this->grade -= input;
	if (this->grade < High_Grade)
		throw GradeTooHighException();
}

void Bureaucrat::decrement_grade(int input) {
	this->grade += input;
	if (this->grade > Low_Grade)
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.getName() <<", bureaucrat grade "<<bureaucrat.getGrade()<<".";
	return os;
}