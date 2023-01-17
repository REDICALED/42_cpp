#pragma once

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{
public:
	WrongCat();
	~WrongCat();
	WrongCat(WrongCat& cat);
	WrongCat& operator=(WrongCat& cat);
	void makeSound() const;
	void cat_print() const;
};