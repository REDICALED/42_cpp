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
		Bureaucrat custom_input(name, grade);
		custom_input.decrement_grade(10);
	}

	catch (std::exception & e)
	{
		std::cout<<e.what();
	}
	return 0;
}