#pragma once
#include <iostream>

class ClapTrap{
protected:
	std::string name;
	int hit_p;
	int energy_p;
	int attack_damage;
public:
	ClapTrap();
	virtual ~ClapTrap();
	ClapTrap(const ClapTrap& clapTrap);
	ClapTrap(std::string name);
	ClapTrap(std::string name, int hit_p, int energy_p, int attack_damage);
	ClapTrap& operator=(const ClapTrap &clapTrap);
	virtual void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void show_status(void);
	void clap_print(void);
};

std::ostream& operator<<(std::ostream& out, const ClapTrap& ref);
