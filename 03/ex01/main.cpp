#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void ){

	ClapTrap *s = new ScavTrap();
	s->attack("who");
	s->show_status();
	ScavTrap ss("a");
	ScavTrap ns = ss;
	ns.show_status();
	ns.guardGate();
	delete s;
	return 0;
}