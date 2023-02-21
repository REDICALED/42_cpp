#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): name(""), _signed(0), re_ex_grade(150), re_sign_grade(150){

}

AForm::~AForm(){

}

AForm::AForm(const AForm& form): name(form.name),_signed(form._signed), re_ex_grade(form.re_ex_grade), re_sign_grade(form.re_sign_grade) {

}

AForm& AForm::operator=(const AForm& form){
	std::cout<<"공문서("<<form.name<<"), 새 용지에서 작성해주세요."<<std::endl;
	return *this;
}

AForm::AForm(std::string name, int re_ex_grade, int re_sign_grade): name(name), _signed(0), re_ex_grade(re_ex_grade), re_sign_grade(re_sign_grade){
	if (this->get_sign_Grade() < High_Grade || this->get_ex_Grade() < High_Grade)
		throw AForm::GradeTooHighException();
	else if (this->get_sign_Grade() > Low_Grade|| this->get_ex_Grade() > Low_Grade)
		throw AForm::GradeTooLowException();
}

std::string AForm::getName() const{
	return this->name;
}

 int AForm::get_sign_Grade() const{
	return re_sign_grade;
}

int AForm::get_ex_Grade() const{
	return re_ex_grade;
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "AForm Grade too high!\n";
}

const char *AForm::FileOpenFail::what() const throw() {
	return "Shrubbery file open fail!\n";
}


const char *AForm::GradeTooLowException::what() const throw() {
	return "AForm Grade too low!\n";
}

const char *AForm::NotSigned::what() const throw() {
	return "AForm Not Signed!\n";
}

void AForm::beSigned(Bureaucrat& bureaucrat){
	if (bureaucrat.getGrade() > this->get_sign_Grade())
		throw GradeTooLowException();
	else
	{
		if (_signed == 1)
			std::cout<<"This AForm is already signed... but It's okay."<<std::endl;
		else
			this->_signed = 1;
	}
}

void  AForm::general_form_check(Bureaucrat const & executor) const{
	if (this->_signed == 0)
		throw NotSigned();
	if (this->get_ex_Grade() < executor.getGrade())
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
	os <<"AForm Name: ["<< form.getName() <<"], required to sign grade: "<<form.get_sign_Grade()<<" and" \
	<<" required to execute grade: "<<form.get_ex_Grade();
	return os;
}
