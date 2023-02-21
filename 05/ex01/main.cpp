#include "Bureaucrat.hpp"
#include "Form.hpp"

int main( void ){
	int grade;
	std::string name;
	int test_form_grade;
	std::cout<<"please input your name! :";
	std::cin>>name;
	std::cout<<"please input your grade! :";
	std::cin>>grade;
	std::cout<<"please input the form grade of want to sign. (ex_grade is 150) :";
	std::cin>>test_form_grade;
	int flag = 0;
	try
	{
		Bureaucrat is_valid(name, grade);
		Form test_form("test",150,test_form_grade);
		test_form.beSigned(is_valid);
		flag = 2;
	}
	catch (std::exception & e)
	{
		std::cout<<e.what();
		std::cout << "[sign failed ...]\n" <<std::endl;
		return 1;
	}
	Bureaucrat is_valid(name, grade);
	Form test_form("input_test_FORM",150,test_form_grade);
	std::cout << "[okay it's valid input!]\n" << is_valid << std::endl;
	is_valid.signForm(test_form);
	return 0;
}