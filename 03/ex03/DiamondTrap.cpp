#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name) {
	DiamondTrap::name = name;
}

void DiamondTrap::whoAmI(){
	std::cout<<"ClapTrap's name: "<<ClapTrap::name<<std::endl;
	std::cout<<"DiamondTrap's name: "<<name<<std::endl;
}
