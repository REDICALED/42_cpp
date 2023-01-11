#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name) {
	DiamondTrap::name = name;
	DiamondTrap::hit_p = FragTrap::hit_p;
	DiamondTrap::attack_damage = FragTrap::attack_damage;
}

void DiamondTrap::whoAmI(){
	std::cout<<"ClapTrap's name: "<<ClapTrap::name<<std::endl;
	std::cout<<"DiamondTrap's name: "<<name<<std::endl;
	std::cout<<"Hit_p:"<<this->hit_p<<std::endl;
	std::cout<<"Energy_p:"<<this->energy_p<<std::endl;
	std::cout<<"attact_damage:"<<this->attack_damage<<std::endl;

}

DiamondTrap::DiamondTrap(): ClapTrap("_clap_name"), FragTrap(""), ScavTrap(""){
	dia_print();
	std::cout<< "Default constructor!" << std::endl;
}

DiamondTrap::~DiamondTrap(){
	dia_print();
	std::cout<< "Default destructor!" << std::endl;
}

void DiamondTrap::dia_print(){
	std::cout<<"[DIAMOND]";
}

DiamondTrap::DiamondTrap(DiamondTrap &diamondTrap){
	*this = diamondTrap;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &diamondTrap){
	frag_print();
	std::cout << "assignment operator!" << std::endl;
	if (this != &diamondTrap) {
		ClapTrap::name = diamondTrap.name + "_clap_name";
		this->name = diamondTrap.name;
		this->attack_damage = diamondTrap.attack_damage;
		this->energy_p = diamondTrap.energy_p;
		this->hit_p = diamondTrap.hit_p;
	}
	return *this;
}
