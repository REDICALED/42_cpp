#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main( void ){
	PresidentialPardonForm a("a");
	Bureaucrat ex("ex",22);
	Intern someRandomIntern;
	AForm* rrf;
	try {
		rrf = someRandomIntern.makeForm("robotomy s", "Bender");
		ex.signAForm(*rrf);
		rrf->execute(ex);
		delete rrf;
	}
	catch(std::exception &e){
		std::cout<<e.what();
	}
	return 0;
}