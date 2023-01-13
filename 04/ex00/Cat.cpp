#include "Animal.hpp"
#include "Cat.hpp"


Cat::Cat(): Animal("Cat"){
	cat_print();
	std::cout << "default constructor!" << std::endl;
}

Cat::~Cat() {
	cat_print();
	std::cout << "Default destructor! " << std::endl;
}

Cat::Cat(Cat& cat){
	cat_print();
	std::cout << "copy constructor!" << std::endl;
	*this = cat;
}

Cat& Cat::operator=(Cat& cat){
	cat_print();
	std::cout << "assignment operator!" << std::endl;
	if (this == &cat)
		return *this;
	this->type = cat.type;
	return *this;
}

void Cat::makeSound() const{
	cat_print();
	std::cout<<this->type<<": MEOW ."<<std::endl;
}

void Cat::cat_print() const{
	std::cout<<"[CAT]";
}