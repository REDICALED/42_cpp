#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main( void ){
	FragTrap fr;
	fr.highFivesGuys();
	fr.takeDamage(1);
	fr.attack("oh");
	fr.beRepaired(1);
	fr.show_status();
	return 0;
}