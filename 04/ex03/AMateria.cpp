#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(): type("a"){
}

AMateria::~AMateria(){

}

AMateria::AMateria(AMateria& aMateria){
	this->type = aMateria.type;
}

AMateria& AMateria::operator=(AMateria& aMateria){
	if (this == &aMateria)
		return *this;
	this->type = aMateria.type;
	return *this;
}

AMateria::AMateria(std::string const & type){
	this->type = type;
}

std::string const & AMateria::getType() const{
	return this->type;
}

void AMateria::use(ICharacter& target){
	std::cout<<target.getName()<<std::endl;
}
