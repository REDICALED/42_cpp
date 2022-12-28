#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ){
	Zombie* zb_horde = new Zombie[N];
	int i = -1;
	while (++i < N) {
		char num = '0' + i;
		zb_horde[i].set_zombie_name(name + "-" + num);
	}
		return (zb_horde);
}