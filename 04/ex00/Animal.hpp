#pragma once

#include <iostream>

class Animal{
protected:
	std::string type;
public:
	Animal();
	virtual ~Animal();
	Animal(Animal& animal);
	Animal(std::string type);
	std::string getType() const;
	Animal& operator=(Animal& animal);
	virtual void makeSound() const;
	void	ani_print() const;
};