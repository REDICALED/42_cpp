#include "Animal.hpp"

Animal::Animal(): type("NULL"){
	ani_print();
	std::cout << "default constructor!" << std::endl;
}

Animal::~Animal(){
	ani_print();
	std::cout << "Default destructor! " << std::endl;
}

Animal::Animal(Animal& animal){
	ani_print();
	std::cout << "copy constructor!" << std::endl;
	*this = animal;
}

Animal::Animal(std::string type){
	ani_print();
	std::cout << "type input constructor!" << std::endl;
	this->type = type;
}

Animal& Animal::operator=(Animal& animal){
	ani_print();
	std::cout << "assignment operator!" << std::endl;
	if (this == &animal)
		return *this;
	this->type = animal.type;
	return *this;
}

std::string Animal::getType() const{
	ani_print();
	return this->type;
}

void Animal::ani_print() const{
	std::cout<<"[ANIMAL]";
}

