#pragma once
#include "Weapon.hpp"

class HumanA{
public:
	void	attack();
	HumanA(std::string name, Weapon& weapon);
private:
	Weapon& weapon;
	std::string name;
};
