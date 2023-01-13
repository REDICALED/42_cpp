#pragma once
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal{
private:
	Brain* brain;
public:
	Dog();
	virtual ~Dog();
	Dog(Dog& dog);
	Dog& operator=(Dog& dog);
	void makeSound() const;
	void dog_print() const;
};