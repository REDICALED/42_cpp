#pragma once
#include "ICharacter.hpp"

class Character : public ICharacter{
private:
	std::string name;
	AMateria *inv[4];
public:
	Character();
	~Character();
	Character(Character& character);
	Character(std::string name);
	Character& operator=(Character& character);

	virtual std::string const & getName() const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);
};
