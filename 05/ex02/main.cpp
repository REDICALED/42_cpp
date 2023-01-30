#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main( void ){
	PresidentialPardonForm a("a");
	Bureaucrat ex("ex",22);
	try {
		ex.signAForm(a);
		ex.executeForm(a);
	}
	catch(std::exception &e){
		std::cout<<e.what();
	}
	return 0;
}