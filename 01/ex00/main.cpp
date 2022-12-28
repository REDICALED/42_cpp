#include "Zombie.hpp"

int main()
{
	Zombie *first = newZombie("PJ_1");
	first->announce();
	randomChump("chump");
	delete first;
}
