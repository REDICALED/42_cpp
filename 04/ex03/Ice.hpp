#pragma once
#include "AMateria.hpp"

class Ice : public AMateria{
public:
	Ice();
	~Ice();
	Ice(Ice& ice);
	Ice& operator=(Ice& ice);
	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);
	void ice_print();
};