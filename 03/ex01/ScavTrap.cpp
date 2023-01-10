#include "ScavTrap.hpp"

void ScavTrap::scav_print() {
	std::cout<<"[SCAV] ";
}

ScavTrap::ScavTrap(std::string name):ClapTrap(name, 100, 50, 20) {
	scav_print();
	std::cout << "name input constructor!" << std::endl;
}

ScavTrap::~ScavTrap(){
	scav_print();
	std::cout<< "Default destructor!" << std::endl;
}

ScavTrap::ScavTrap():ClapTrap("", 100, 50, 20) {
	scav_print();
	std::cout<< "Default constructor!" << std::endl;
}

void ScavTrap::attack(const std::string& target){
	scav_print();
	if (hit_p == 0)
	{
		std::cout << name << " is knockdown... [ X . X ] ...." << std::endl;
		return ;
	}
	if (energy_p == 0)
	{
		std::cout << name << "has no energy ..!" << std::endl;
		return ;
	}
	energy_p--;
	std::cout<< "ScavTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
}
void ScavTrap::guardGate(){
	scav_print();
	std::cout<<"Gate Keeper Mode ON ...."<<std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &scavTrap){
	scav_print();
	std::cout << "assignment operator!" << std::endl;
	this->name = scavTrap.name;
	this->attack_damage = scavTrap.attack_damage;
	this->energy_p = scavTrap.energy_p;
	this->hit_p = scavTrap.hit_p;
	return *this;
}