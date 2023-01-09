#pragma once
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap{
public:
	ScavTrap(std::string name);
	~ScavTrap();

	void attack(const std::string& target);
	void scav_print();
	void guardGate();
};