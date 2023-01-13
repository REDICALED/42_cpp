#pragma once

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal{
public:
	Cat();
	~Cat();
	Cat(Cat& cat);
	Cat& operator=(Cat& cat);
	void makeSound() const;
	void cat_print() const;
};