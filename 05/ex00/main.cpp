#include "Bureaucrat.hpp"

int main( void ){
	int grade;
	std::string name;
	std::cout<<"please input your name! :";
	std::cin>>name;
	std::cout<<"please input your grade! :";
	std::cin>>grade;
	try
	{
		Bureaucrat is_valid(name, grade);
		is_valid.decrement_grade(10);
		is_valid.increment_grade(20);
	}
//	catch (Bureaucrat::GradeTooHighException &e)
//	{
//		std::cout<<"zz"<<e.what();
//	}

	catch (std::exception &e)
	{
		std::cout<<e.what();
		return (1);
	}

	Bureaucrat valid_input(name, grade);
	std::cout<<"okay it's a valid input!"<<"\n"<<valid_input<<std::endl;
	return 0;
}