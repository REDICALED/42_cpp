#include "Zombie.hpp"

Zombie *Zombie::newZombie(std::string name) {
	Zombie *zb = new Zombie;
	zb->name = name;
	return (zb);
}