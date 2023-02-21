#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

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
    try
    {
        Bureaucrat is_valid(name, grade);
        Intern someRandomIntern;
        flag = 1;
        forms[0] = someRandomIntern.makeForm("shrubbery creation", target_name);
        flag = 2;
        forms[1] = someRandomIntern.makeForm("robotomy request", target_name);
        flag = 3;
        forms[2] = someRandomIntern.makeForm("presidential pardon", target_name);
        flag = 4;
        forms[test_grade - 1]->beSigned(is_valid);
        std::cout<<"[ okay sign is fine !]"<<std::endl;
        flag = 5;
        forms[test_grade - 1]->execute(is_valid);
        std::cout<<*forms[test_grade - 1]<<std::endl;
        std::cout<<is_valid<<std::endl;
    }

   catch (std::exception & e)
	{
		std::cout<<e.what();
        if (flag >= 1 && flag <= 3)
        {
            int i = -1;
            while (++i < flag - 1)
                delete(forms[i]);
        }
        else if (flag >= 4)
        {
            int i = -1;
            while (++i < 3)
                delete(forms[i]);
        }
        return 1;
	}
    int i = -1;
    while (++i < 3)
        delete(forms[i]);
    return 0;
}
