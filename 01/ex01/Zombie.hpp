#pragma once
#include <iostream>

class Zombie{
private:
    std::string name;

public:
	void    	announce();
	void		set_zombie_name(std::string name);
	~Zombie();
};

Zombie* zombieHorde( int N, std::string name );