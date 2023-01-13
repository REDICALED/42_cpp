#pragma once
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal{
private:
	Brain* brain;
public:
	Cat();
	virtual ~Cat();
	Cat(Cat& cat);
	Cat& operator=(Cat& cat);
	void makeSound() const;
	void cat_print() const;
};