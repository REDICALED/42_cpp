#include "Weapon.hpp"

void	Weapon::setType(std::string type) {
	this->type = type;
}

const std::string& Weapon::getType() {
	std::string &tmp_type = this->type;
	return (tmp_type);
}

Weapon::Weapon(std::string type) {
	this->type = type;
}