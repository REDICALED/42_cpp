#include <iostream>

int main()
{
	std::string A = "HI THIS IS BRAIN";
	std::string *stringPTR = &A;
	std::string &stringREF = A;

	std::cout<<&A<<std::endl;
	std::cout<<stringPTR<<std::endl;
	std::cout<<&stringREF<<std::endl;
	std::cout<<A<<std::endl;
	std::cout<<*stringPTR<<std::endl;
	std::cout<<stringREF<<std::endl;
}
