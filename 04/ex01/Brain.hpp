#pragma once

#include <iostream>

class Brain{
public:
	Brain();
	~Brain();
	Brain(Brain& brain);
	Brain& operator=(Brain& brain);
	std::string ideas[100];
	void brain_print() const;
};