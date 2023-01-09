#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void ){

	ScavTrap de_fault("zz");
	de_fault.show_status();
	de_fault.attack("a");
	de_fault.beRepaired(10);
	de_fault.show_status();
	de_fault.guardGate();
	return 0;
}