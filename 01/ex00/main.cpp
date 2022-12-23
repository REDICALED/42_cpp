#include "Zombie.hpp"

int main()
{
	Zombie suk_ju;
	suk_ju.set_zomname("suk_ju");
	Zombie *first = suk_ju.newZombie("new1");

	suk_ju.randomChump("new2");

	first->announce(first->get_zomname());
	delete first;
}
