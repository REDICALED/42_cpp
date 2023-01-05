#include "ClapTrap.hpp"

int main( void ){

	ClapTrap de_fault;
	ClapTrap named("CLAP");
	ClapTrap na2(named);
	ClapTrap na3;
	na3 = na2;

	for(int i = 0; i < 10; i++)
		de_fault.attack("pi_de_fault");
	de_fault.show_status();

	return 0;
}