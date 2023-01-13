#pragma once

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal{
public:
	Dog();
	~Dog();
	Dog(Dog& dog);
	Dog& operator=(Dog& dog);
	void makeSound() const;
	void dog_print() const;
};