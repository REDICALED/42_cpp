#include "Zombie.hpp"

void Zombie::announce(std::string name) {
	std::cout<<name<<": BraiiiiiiinnnzzzZ..."<<std::endl;
}

std::string Zombie::get_zomname(){
	return (this->name);
}

void	Zombie::set_zomname(std::string name){
	this->name = name;
}

Zombie::~Zombie() {
	std::cout<<this->name<<"  Grrrrr..."<<std::endl;
}