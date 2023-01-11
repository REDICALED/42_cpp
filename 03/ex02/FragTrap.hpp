#pragma once
#include "ClapTrap.hpp"

class FragTrap: public ClapTrap{
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(FragTrap &fragTrap);
	FragTrap& operator=(const FragTrap &fragTrap);
	virtual ~FragTrap();
	void highFivesGuys(void);
	void frag_print();
};