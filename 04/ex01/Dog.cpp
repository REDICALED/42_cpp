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

void Dog::set_brain(std::string str){
	int i = -1;
	while (this->brain->ideas[++i] != "");
	if (i == 100)
		i = 0;
	this->brain->ideas[i] = str;
}

void Dog::print_brain(int index) const{
	int i = -1;
	if (index == 100) {
		while (this->brain->ideas[++i] != "")
			std::cout<<i<<". "<<this->brain->ideas[i]<<std::endl;
	}
	else if (this->brain->ideas[index] == "")
		std::cout<<"huff huff... (no idea)"<<std::endl;
	else
		std::cout<<index<<". "<<this->brain->ideas[index]<<std::endl;
}