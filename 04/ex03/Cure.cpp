#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure():AMateria("cure"){
}

Cure::~Cure(){

}

Cure::Cure(Cure& cure){
	this->type = cure.type;
}

Cure& Cure::operator=(Cure& cure){
	if (this == &cure)
		return *this;
	this->type = cure.type;
	return *this;
}

AMateria* Cure::clone() const{
	Cure *ret = new Cure;
	ret->type = this->type;
	return ret;
}

void Cure::use(ICharacter& target){
	std::cout<<"* heals "<<target.getName()<<"’s wounds *"<<std::endl;
}

void Cure::cure_print(){
	std::cout<<"Cure"<<std::endl;
}