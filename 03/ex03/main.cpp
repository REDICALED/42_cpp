#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

int main( void ){
//	ClapTrap *dia = new FragTrap;
//	dia->show_status();
//	dia = new ScavTrap;
//	dia->show_status();
//	dia = new DiamondTrap;
//	dia->show_status();
//
//	dia->attack("what");
//	dia->show_status();
//	dia->takeDamage(10);
//	dia->show_status();
//	dia->beRepaired(10);
//	dia->show_status();

	DiamondTrap diamondTrap("a");
	diamondTrap.whoAmI();
	diamondTrap.highFivesGuys();
	diamondTrap.guardGate();

	DiamondTrap diamondTrap1("a2");
	diamondTrap = diamondTrap1;
	diamondTrap.whoAmI();

	return 0;
}