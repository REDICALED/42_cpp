#pragma once

#include "Contact.hpp"

class PhoneBook
{
	Contact Conts[8];
	int 	index;
	int 	add_count;
public:
	static int flag;
	PhoneBook();
	~PhoneBook();
	void	add_print(const char *mes, std::string *number);
	void	add_print(const int cont_index);
	void	add();
	int 	page_print(std::string str, int str_index, int input_int);
	int 	page_print(int input_int, int str_index);
	void	search();
};
