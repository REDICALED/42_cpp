#include "Zombie.hpp"

void Zombie::announce() {
	std::cout<<this->name<<": BraiiiiiiinnnzzzZ..."<<std::endl;
}

Zombie::~Zombie() {
	std::cout<<this->name<<"  Grrrrr..."<<std::endl;
}

void	Zombie::set_zombie_name(std::string name){
	this->name = name;
}