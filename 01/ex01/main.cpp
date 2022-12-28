#include "Zombie.hpp"

int main()
{
	int N = 10;
	Zombie *first = zombieHorde(N,"louisville");
	int i = -1;
	while (++i < N)
		first[i].announce();
	delete[] first;
}
