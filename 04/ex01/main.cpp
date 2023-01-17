#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main( void ){

	int size = 10;
	Animal* ani[size];
	Dog dogo;
	int i = -1;
	while (++i <size)
	{
		if (i < size / 2)
			ani[i] = new Dog;
		else
			ani[i] = new Cat;
	}
	std::cout<<"--------------------"<<std::endl;


	ani[0]->makeSound();
	ani[5]->makeSound();


	std::cout<<"--------------------"<<std::endl;

	dogo.set_brain("oh hi. my name is john.");
	dogo.set_brain("Have you heard about dog theoretical physics?");
	dogo.set_brain("Now I'm going to show you a new world away from human-centered classical physics.");
	dogo.print_brain(100);

	std::cout<<"--------------------"<<std::endl;
	i = -1;
	while (++i < size)
		delete ani[i];
	return 0;
}