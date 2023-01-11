#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name){
	frag_print();
	std::cout<<"name input constructor!" << std::endl;
	FragTrap::name = name + "_clap_name";
	FragTrap::hit_p = 100;
	FragTrap::energy_p = 100;
	FragTrap::attack_damage = 30;
}

FragTrap::FragTrap(){
	frag_print();
	std::cout<< "Default destructor!" << std::endl;
	FragTrap::hit_p = 100;
	FragTrap::energy_p = 100;
	FragTrap::attack_damage = 30;
}

FragTrap::~FragTrap(){
	frag_print();
	std::cout<< "Default destructor!" << std::endl;
}

void FragTrap::highFivesGuys(void){
	frag_print();
	std::cout<<"HI 5! .. ㅋㅋ..."<<std::endl;
}

FragTrap::FragTrap(FragTrap &fragTrap){
	frag_print();
	std::cout<< "Copy constructor!" << std::endl;
	*this = fragTrap;
}

void FragTrap::frag_print(){
	std::cout<<"[FRAG] ";
}

FragTrap& FragTrap::operator=(const FragTrap &fragTrap){
	frag_print();
	std::cout << "assignment operator!" << std::endl;
	if (this != &fragTrap) {
		this->name = fragTrap.name;
		this->attack_damage = fragTrap.attack_damage;
		this->energy_p = fragTrap.energy_p;
		this->hit_p = fragTrap.hit_p;
	}
	return *this;
}
