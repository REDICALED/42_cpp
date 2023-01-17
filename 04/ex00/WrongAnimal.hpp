#pragma once

#include <iostream>

class WrongAnimal{
protected:
	std::string type;
public:
	WrongAnimal();
	virtual ~WrongAnimal();
	WrongAnimal(WrongAnimal& wrongAnimal);
	WrongAnimal(std::string type);
	std::string getType() const;
	WrongAnimal& operator=(WrongAnimal& wrongAnimal);
	void makeSound() const;
	void	ani_print() const;
};