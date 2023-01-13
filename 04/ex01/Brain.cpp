#include "Brain.hpp"

Brain::Brain(){

}

Brain::~Brain(){

}

Brain::Brain(Brain& brain){
	brain_print();
	std::cout << "copy constructor!" << std::endl;
	*this = brain;
}

Brain& Brain::operator=(Brain& brain){
	brain_print();
	std::cout << "assignment operator!" << std::endl;
	if (this == &brain)
		return *this;
	int i = -1;
	while (++i < 100)
		this->ideas[i] = brain.ideas[i];
	return *this;
}

void Brain::brain_print() const{
	std::cout<<"[BRAIN]";
}