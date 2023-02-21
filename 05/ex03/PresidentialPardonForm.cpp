#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

PresidentialPardonForm:: ~PresidentialPardonForm(){

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& presidentialPardonForm): AForm(presidentialPardonForm.getName(),presidentialPardonForm.get_ex_Grade(),presidentialPardonForm.get_sign_Grade()), target(presidentialPardonForm.target){

}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm& PresidentialPardonForm){
	std::cout<<"공문서("<<PresidentialPardonForm.getName()<<"), 새 용지에서 작성해주세요."<<std::endl;
	return *this;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm",5,25), target(target){

}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const{
	general_form_check(executor);
	std::cout <<"Name[ "<<target<< " ] has been pardoned by Zaphod Beeblebrox , the President of the Galaxy." << std::endl;
}