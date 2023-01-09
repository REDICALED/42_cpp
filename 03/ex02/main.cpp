#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void ){

	FragTrap de_fault("zz");
	de_fault.show_status();
	de_fault.attack("a");
	de_fault.beRepaired(10);
	de_fault.show_status();
	return 0;
}