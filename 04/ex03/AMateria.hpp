#pragma once
#include "iostream"

class ICharacter;

class AMateria{
protected:
	std::string type;
public:
	AMateria();
	virtual ~AMateria();
	AMateria(AMateria& aMateria);
	AMateria& operator=(AMateria& aMateria);
	AMateria(std::string const & type);
	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};