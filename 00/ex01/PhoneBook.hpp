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
	int		add_print(const char *mes, std::string *number);
	int		add_print(const int cont_index);
	int		add();
	int 	gap_print(std::string str, int str_index, int input_int);
	int 	gap_print(int input_int, int str_index);
	void	search();
};
