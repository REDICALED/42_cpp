#include "Animal.hpp"
#include "Dog.hpp"




Dog::Dog(): Animal("Dog"){
	dog_print();
	std::cout << "default constructor!" << std::endl;
}

Dog::~Dog(){
	dog_print();
	std::cout << "Default destructor! " << std::endl;
}

Dog::Dog(Dog& dog){
	dog_print();
	std::cout << "copy constructor!" << std::endl;
	*this = dog;
}

Dog& Dog::operator=(Dog& dog){
	dog_print();
	std::cout << "assignment operator!" << std::endl;
	if (this == &dog)
		return *this;
	this->type = dog.type;
	return *this;
}

void Dog::makeSound() const{
	dog_print();
	std::cout<<this->type<<": AWAAAWA!!!AWAA AWAWAAAAA!!"<<std::endl;
}

void Dog::dog_print() const{
	std::cout<<"[DOG]";
}
