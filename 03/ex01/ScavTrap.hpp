#pragma once
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap{
public:
	ScavTrap(std::string name);
	virtual ~ScavTrap();
	ScavTrap();
	ScavTrap& operator=(const ScavTrap &scavTrap);
	void attack(const std::string& target);
	void scav_print();
	virtual void guardGate();
};
