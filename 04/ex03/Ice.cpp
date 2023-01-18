#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice():AMateria("ice"){
}

Ice::~Ice(){

}

Ice::Ice(Ice& ice){
	this->type = ice.type;
}

Ice& Ice::operator=(Ice& ice){
	if (this == &ice)
		return *this;
	this->type = ice.type;
	return *this;
}

AMateria* Ice::clone() const{
	Ice *ret = new Ice;
	ret->type = this->type;
	return ret;
}

void Ice::use(ICharacter& target){
	std::cout<<"* shoots an ice bolt at "<<target.getName()<<" *"<<std::endl;
}

void Ice::ice_print(){
	std::cout<<"ICE"<<std::endl;
}