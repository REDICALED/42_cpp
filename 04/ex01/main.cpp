#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main( void ){

//	int size = 4;
//	Animal* ani[size];
//	int i = -1;
//	while (++i <size)
//	{
//		if (i < size / 2)
//			ani[i] = new Dog;
//		else
//			ani[i] = new Cat;
//	}
//	i = -1;
//	while (++i < size)
//		delete ani[i];
	Animal *c = new Cat;
	Animal *s = new Cat;
	*s = *c;
	Cat c1;
	Cat c2;
	c1 = c2;
	delete s;
	delete c;
	return 0;
}