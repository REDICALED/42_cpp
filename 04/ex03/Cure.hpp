#pragma once
#include "AMateria.hpp"

class Cure : public AMateria{
public:
	Cure();
	~Cure();
	Cure(Cure& cure);
	Cure& operator=(Cure& cure);
	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);
	void cure_print();
};