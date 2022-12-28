#pragma once
#include "Weapon.hpp"

class HumanB{
public:
	void	attack();
	void	setWeapon(Weapon& weapon);
	HumanB(std::string name);
private:
	Weapon 		*weapon;
	std::string name;
};
