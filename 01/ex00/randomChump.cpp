#include "Zombie.hpp"

void Zombie::randomChump(std::string name) {
	Zombie zb;
	zb.name = name;
	zb.announce(zb.name);
}
