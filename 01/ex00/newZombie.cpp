#include "Zombie.hpp"

Zombie* newZombie(std::string name) {
	Zombie *zb = new Zombie(name);
	return (zb);
}