#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
:name(""), hit_p(10),energy_p(10), attack_damage(0) {
	std::cout << "default constructor!" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
:name(name),hit_p(10), energy_p(10), attack_damage(0) {
	std::cout << "name input constructor!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &clapTrap){
	std::cout << "assignment operator!" << std::endl;
	this->name = clapTrap.name;
	this->attack_damage = clapTrap.attack_damage;
	this->energy_p = clapTrap.energy_p;
	this->hit_p = clapTrap.hit_p;
	return *this;
}

ClapTrap::ClapTrap(const ClapTrap& clapTrap) {
	std::cout << "Copy constructor!" << std::endl;
	*this = clapTrap;
}

ClapTrap::~ClapTrap() {
	std::cout << "Default destructor! " << std::endl;
}

void ClapTrap::attack(const std::string& target){
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
	std::cout << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
	if (hit_p == 0)
	{
		std::cout << name << "'s already dead...! STOP..." << std::endl;
		return ;
	}
	std::cout << name << " takeDamage " << amount << ", HP: " << hit_p << " -> ";
	hit_p -= amount;
	if (hit_p < 0)
		hit_p = 0;
	std::cout << hit_p << std::endl;
	if (hit_p == 0)
		std::cout << name << "'s over." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
	if (hit_p == 0)
	{
		std::cout << name << "'s already dead... It's meaningless..." << std::endl;
		return ;
	}
	if (energy_p == 0)
	{
		std::cout << name << "has no energy! can't be-Repaired-." << std::endl;
		return ;
	}
	energy_p--;
	std::cout << name << " beRepaired " << amount << ", HP: " << hit_p << " -> ";
	hit_p += amount;
	std::cout << hit_p << std::endl;
}

void ClapTrap::show_status(void){
	std::cout<<"|NAME:"<<this->name<<" |HP:"<<this->hit_p<<" |ENERGY:"<<this->energy_p<<" |attack_damage:"<<this->attack_damage<<"|"<<std::endl;



}