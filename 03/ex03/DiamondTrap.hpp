#pragma once
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap{
private:
	std::string name;
public:
	DiamondTrap(std::string name);
	void whoAmI();
};