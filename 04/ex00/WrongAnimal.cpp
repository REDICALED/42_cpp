#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("NULL"){
	ani_print();
	std::cout << "default constructor!" << std::endl;
}

WrongAnimal::~WrongAnimal(){
	ani_print();
	std::cout << "Default destructor! " << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal& wrongAnimal){
	ani_print();
	std::cout << "copy constructor!" << std::endl;
	*this = wrongAnimal;
}

WrongAnimal::WrongAnimal(std::string type){
	ani_print();
	std::cout << "type input constructor!" << std::endl;
	this->type = type;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal& wrongAnimal){
	ani_print();
	std::cout << "assignment operator!" << std::endl;
	if (this == &wrongAnimal)
		return *this;
	this->type = wrongAnimal.type;
	return *this;
}

void WrongAnimal::makeSound() const{
	ani_print();
	std::cout<<this->type<<": 안녕하세요. 저는 동물 입니다 ."<<std::endl;
}

std::string WrongAnimal::getType() const{
	ani_print();
	return this->type;
}

void WrongAnimal::ani_print() const{
	std::cout<<"[WRONG_ANIMAL]";
}

