#include "Animal.hpp"
#include "Dog.hpp"


Dog::Dog(): Animal("Dog"){
	dog_print();
	this->brain = new Brain();
	std::cout << "default constructor!" << std::endl;
}

Dog::~Dog(){
	dog_print();
	std::cout << "Default destructor! " << std::endl;
	delete brain;
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
	this->brain = new Brain;
	int i = -1;
	while (++i < 100)
		this->brain->ideas[i] = dog.brain->ideas[i];
	return *this;
}

void Dog::makeSound() const{
	dog_print();
	std::cout<<this->type<<": AWAAAWA!!!AWAA AWAWAAAAA!!"<<std::endl;
}

void Dog::dog_print() const{
	std::cout<<"[DOG]";
}
