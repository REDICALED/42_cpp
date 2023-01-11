#pragma once
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap{
private:
	std::string name;
public:
	DiamondTrap(std::string name);
	DiamondTrap();
	virtual ~DiamondTrap();
	DiamondTrap(DiamondTrap &diamondTrap);
	DiamondTrap& operator=(const DiamondTrap &diamondTrap);
	void whoAmI();
	void dia_print();

};
