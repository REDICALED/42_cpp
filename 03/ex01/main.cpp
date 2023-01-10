#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void ){

	ClapTrap *s = new ScavTrap();
	s->attack("who");
	delete s;
	return 0;
}