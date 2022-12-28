#pragma once
#include <iostream>

class Zombie{
private:
    std::string name;

public:
	void    	announce();
	Zombie(std::string name);
	~Zombie();
};

Zombie*		newZombie( std::string name );
void		randomChump( std::string name );