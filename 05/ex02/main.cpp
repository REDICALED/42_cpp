#include "Bureaucrat.hpp"
#include "Form.hpp"

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

	}
	catch (std::exception & e)
	{
		std::cout<<e.what();
		return (1);
	}
	Bureaucrat valid_input(name, grade);
	std::cout<<"okay it's valid input!"<<"\n"<<valid_input<<std::endl;
	Form orm("form", 100, 100);
	valid_input.signForm(orm);
	Bureaucrat valid_input2("two", 100);
	valid_input2.signForm(orm);
	std::cout<<orm;
	return 0;
}