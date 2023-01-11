#pragma once
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap{
public:
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& scavTrap);
	virtual ~ScavTrap();
	ScavTrap();
	ScavTrap& operator=(const ScavTrap &scavTrap);
	virtual void attack(const std::string& target);
	void scav_print();
	void guardGate();
};
