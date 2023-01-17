#include "Animal.hpp"
#include "Cat.hpp"


Cat::Cat(): Animal("Cat"){
	cat_print();
	this->brain = new Brain();
	std::cout << "default constructor!" << std::endl;
}

Cat::~Cat() {
	cat_print();
	std::cout << "Default destructor! " << std::endl;
	delete brain;
}

Cat::Cat(Cat& cat) {
	cat_print();
	std::cout << "copy constructor!" << std::endl;
	if (this != &cat) {
		this->type = cat.type;
		this->brain = new Brain;
		int i = -1;
		while (++i < 100)
			this->brain->ideas[i] = cat.brain->ideas[i];
//		this->brain = cat.brain; /얕은 복사 케이스!
	}
}

Cat& Cat::operator=(Cat& cat){
	cat_print();
	std::cout << "assignment operator!" << std::endl;
	if (this == &cat)
		return *this;
	this->type = cat.type;
	delete brain;
	brain = NULL;
	this->brain = new Brain;
	int i = -1;
	while (++i < 100)
		this->brain->ideas[i] = cat.brain->ideas[i];
	return *this;
}

void Cat::makeSound() const{
	cat_print();
	std::cout<<this->type<<": MEOW ."<<std::endl;
}

void Cat::cat_print() const{
	std::cout<<"[CAT]";
}

void Cat::set_brain(std::string str){
	int i = -1;
	while (this->brain->ideas[++i] != "");
	if (i == 100)
	{
		i = 0;
		std::cout<<"용량 부족으로 기억이 소멸됩니다... ㅠㅠ"<<std::endl;
	}
	this->brain->ideas[i] = str;
}

void Cat::print_brain(int index) const{
	int i = -1;
	if (index >= 1) {
		while (this->brain->ideas[++i] != "" && i < index)
			std::cout<<i + 1<<". "<<this->brain->ideas[i]<<std::endl;
	}
	else
		std::cout<<"MEOW ? (no idea)"<<std::endl;
}