#include "HumanB.hpp"
#include <iostream>

void	HumanB::attack() {
	if (weapon == NULL)
		std::cout<<name<<" pushes with bare hands... Do your best to remain calm. "<<name<<"."<<std::endl;
	else
		std::cout<<name<<" attacks with their "<<weapon->getType()<<std::endl;
}

void	HumanB::setWeapon(Weapon& weapon){
	this->weapon = &weapon;
}

HumanB::	HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
}