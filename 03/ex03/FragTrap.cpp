#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name): ClapTrap(name, 100, 100, 30){
	frag_print();
	std::cout<<"name input constructor!" << std::endl;
}

FragTrap::~FragTrap(){
	frag_print();
	std::cout<< "Default destructor!" << std::endl;
}

void FragTrap::highFivesGuys(void){
	frag_print();
	std::cout<<"HI 5! ..."<<std::endl;
}

void FragTrap::frag_print(){
	std::cout<<"[FRAG] ";
}