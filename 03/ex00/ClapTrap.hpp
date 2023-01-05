#pragma once
#include <iostream>

class ClapTrap{
private:
	std::string name;
	int hit_p;
	int energy_p;
	int attack_damage;
public:
	ClapTrap();
	~ClapTrap();
	ClapTrap(const ClapTrap& clapTrap);
	ClapTrap(std::string name);
	ClapTrap& operator=(const ClapTrap &clapTrap);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void show_status(void);
};

std::ostream& operator<<(std::ostream& out, const ClapTrap& ref);
