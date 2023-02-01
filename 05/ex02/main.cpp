#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main( void ){
	int grade;
	std::string name;
	int test_grade;
	std::string target_name;
	std::cout<<"please input your name! :";
	std::cin>>name;
	std::cout<<"please input your grade! :";
	std::cin>>grade;
	std::cout<<"what kind of form do you want? [1. ShrubberyCreation |2. RobotomyRequest |3. PresidentialPardon] :";
	std::cin>>test_grade;
	std::cout<<"please input form's target_name! :";
	std::cin>>target_name;
	int flag = 0;
	AForm* forms[3];
	forms[0] = new ShrubberyCreationForm(target_name);
	forms[1] = new RobotomyRequestForm(target_name);
	forms[2] = new PresidentialPardonForm(target_name);
	try
	{
		Bureaucrat is_valid(name, grade);
		forms[test_grade - 1]->beSigned(is_valid);
		std::cout<<"[ okay sign is fine !]"<<std::endl;
		flag = 3;

		forms[test_grade - 1]->execute(is_valid);

		flag = 2;

	}

	catch (std::exception & e)
	{
		std::cout<<e.what();
		if (flag != 3)
			flag = 1;
	}
	if (flag == 1) {
		std::cout << "[sign failed ...]" <<std::endl;
	}
	else if (flag == 2)
	{
		std::cout << "[ sign and execute all Fine!! ]" <<std::endl;
	}
	else if (flag == 3)
	{
		std::cout << "[execute failed ...]" <<std::endl;
	}
	int i = -1;
	while (++i < 3)
		delete(forms[i]);
	return 0;
}