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
	if (this != &dog) {
		this->type = dog.type;
		this->brain = new Brain;
		int i = -1;
		while (++i < 100)
			this->brain->ideas[i] = dog.brain->ideas[i];
//		this->brain = dog.brain; /얕은 복사 케이스!
	}
}

Dog& Dog::operator=(Dog& dog){
	dog_print();
	std::cout << "assignment operator!" << std::endl;
	if (this == &dog)
		return *this;
	this->type = dog.type;
	delete brain;
	brain = NULL;
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
	{
		i = 0;
		std::cout<<"용량 부족으로 기억이 소멸됩니다... ㅠㅠ"<<std::endl;
	}
	this->brain->ideas[i] = str;
}

void Dog::print_brain(int index) const{
	int i = -1;
	if (index >= 1) {
		while (this->brain->ideas[++i] != "" && i < index)
			std::cout<<i + 1<<". "<<this->brain->ideas[i]<<std::endl;
	}
	else
		std::cout<<"huff huff... (no idea)"<<std::endl;
}