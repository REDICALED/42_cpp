#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("Wrong_Cat"){
	cat_print();
	std::cout << "default constructor!" << std::endl;
}

WrongCat::~WrongCat() {
	cat_print();
	std::cout << "Default destructor! " << std::endl;
}

WrongCat::WrongCat(WrongCat& cat){
	cat_print();
	std::cout << "copy constructor!" << std::endl;
	*this = cat;
}

WrongCat& WrongCat::operator=(WrongCat& cat){
	cat_print();
	std::cout << "assignment operator!" << std::endl;
	if (this == &cat)
		return *this;
	this->type = cat.type;
	return *this;
}

void WrongCat::makeSound() const{
	cat_print();
	std::cout<<this->type<<": MEOW ."<<std::endl;
}

void WrongCat::cat_print() const{
	std::cout<<"[CAT]";
}