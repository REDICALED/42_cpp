#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <time.h>
#include <iostream>
#include <cstdlib>

RobotomyRequestForm:: ~RobotomyRequestForm(){

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& robotomyRequestForm): AForm(robotomyRequestForm.getName(),robotomyRequestForm.get_ex_Grade(),robotomyRequestForm.get_sign_Grade()), target(robotomyRequestForm.target){

}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm& robotomyRequestForm){
	std::cout<<"공문서("<<robotomyRequestForm.getName()<<"), 새 용지에서 작성해주세요."<<std::endl;
	return *this;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm",45,72), target(target){

}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const{
	general_form_check(executor);
	std::cout<<"DRILL. DRILL. "<<std::endl;
	srand((unsigned int)time(NULL));
	int num = rand();
	if (num % 2 == 1)
		std::cout<<"Target[ "<<target<<" ]"<<"has been robotomized."<<std::endl;
	else
		std::cout<<"Target[ "<<target<<" ]"<<"robotomizing fail ...."<<std::endl;
}