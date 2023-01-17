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
	virtual void makeSound() const;
	void cat_print() const;
	void set_brain(std::string str);
	void print_brain(int index) const;
};