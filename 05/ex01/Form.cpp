#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): name(""), _signed(0), re_ex_grade(150), re_sign_grade(150){

}

Form::~Form(){

}

Form::Form(Form& form): name(form.name),_signed(form._signed), re_ex_grade(form.re_ex_grade), re_sign_grade(form.re_sign_grade) {

}

Form& Form::operator=(Form& form){
	std::cout<<"공문서("<<form.name<<"), 새 용지에서 작성해주세요."<<std::endl;
	return *this;
}

Form::Form(std::string name, int re_ex_grade, int re_sign_grade): name(name), _signed(0), re_ex_grade(re_ex_grade), re_sign_grade(re_sign_grade){
	if (this->get_sign_Grade() < High_Grade || this->get_ex_Grade() < High_Grade)
		throw Form::GradeTooHighException();
	else if (this->get_sign_Grade() > Low_Grade|| this->get_ex_Grade() > Low_Grade)
		throw Form::GradeTooLowException();
}

std::string Form::getName() const{
	return this->name;
}

 int Form::get_sign_Grade() const{
	return re_sign_grade;
}

int Form::get_ex_Grade() const{
	return re_ex_grade;
}

bool Form::get_is_signed(){
	return _signed;
}

const char *Form::GradeTooHighException::what() const throw() {
	return "Form Grade too high!\n";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Form Grade too low!\n";
}

void Form::beSigned(Bureaucrat& bureaucrat){
	if (bureaucrat.getGrade() > this->get_sign_Grade())
		throw GradeTooLowException();
	else
	{
		if (_signed == 1)
			std::cout<<"This form is already signed... but It's okay."<<std::endl;
		else
			this->_signed = 1;
	}
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
	os <<"Form Name: ["<< form.getName() <<"], required to sign grade: "<<form.get_sign_Grade()<<" and" \
	<<" required to execute grade: "<<form.get_ex_Grade()<<std::endl;
	return os;
}
