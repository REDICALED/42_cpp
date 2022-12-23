#pragma once
#include <iostream>

class Zombie{
private:
    std::string name;

public:
	void    	announce(std::string name);
	Zombie*		newZombie( std::string name );
	void		randomChump( std::string name );
	std::string get_zomname();
	void		set_zomname(std::string name);
	~Zombie();
};