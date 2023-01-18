#include "Character.hpp"

Character::Character(): name(""){
	int i = -1;
	while(++i < 4)
		this->inv[i] = NULL;
}

Character::Character(std::string name): name(name){
	int i = -1;
	while(++i < 4)
		this->inv[i] = NULL;
}

Character::~Character(){

}

Character::Character(Character& character){
	this->name = character.name;
	int i = -1;
	while(++i < 4)
	{
		this->inv[i] = NULL;
		this->inv[i] = character.inv[i]->clone();
	}
}

Character& Character::operator=(Character& character){
	if (this == &character)
		return *this;
	this->name = character.name;
	int i = -1;
	while(++i < 4)
	{
		if (this->inv[i] != NULL)
			delete this->inv[i];
		this->inv[i] = NULL;
		this->inv[i] = character.inv[i]->clone();
	}
	return *this;
}

std::string const & Character::getName() const{
	return this->name;
}

void Character::equip(AMateria* m){
	int i = -1;
	while(++i < 4)
	{
		if (this->inv[i] == NULL)
		{
			this->inv[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx){
	if (this->inv[idx] != NULL)
		this->inv[idx] = NULL;
}

void Character::use(int idx, ICharacter& target){
	if (this->inv[idx] != NULL)
	{
		this->inv[idx]->use(target);
		this->inv[idx] = NULL;
	}
	else
		std::cout<<"empty inv"<<std::endl;
}
