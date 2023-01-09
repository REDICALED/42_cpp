#pragma once
#include "ClapTrap.hpp"

class FragTrap: public ClapTrap{
public:
	FragTrap(std::string name);
	~FragTrap();
	void highFivesGuys(void);
	void frag_print();
};