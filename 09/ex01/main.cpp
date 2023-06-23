#include "RPN.hpp"

int main(int argc, char **argv ){
	if (argc <= 1)
		std::cout<<"Error: Too few arguments"<<std::endl;
	else if(argc == 2){
		RPN main_rpn(argv);
		main_rpn.check_loop();
	}
	else
		std::cout<<"Error: Too many arguments"<<std::endl;
	return 0;
}