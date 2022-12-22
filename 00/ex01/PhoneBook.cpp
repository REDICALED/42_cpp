#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	index = 0;
	add_count = 0;
}
	
int	PhoneBook::add_print(const char *mes, std::string *number)
{
	std::cout<<mes<<std::endl;
	std::getline(std::cin, *number);
	if (std::cin.eof())
		exit(1);
	return 0;
}


int	PhoneBook::add_print(const int cont_index)
{
	std::string input_tmp;
	std::cout<<this->Conts[this->index].convert(cont_index)<<" 입력해주세용"<<std::endl;
	std::getline(std::cin,input_tmp);
	if (std::cin.eof())
		exit(1);
	this->Conts[this->index].set_info(input_tmp, cont_index);
	return 0;
}

	int	PhoneBook::add()
	{
		int i = -1;
		if (index == 8)
			index = 0;
		while (++i < 5)
			this->add_print(i);
		index ++;
		add_count ++;
		return 0;
	}
	
	int PhoneBook::gap_print(std::string str, int str_index, int input_int)
	{
		if (str_index == 0)
		{
			std::cout<<"|"<<std::setw(10)<<input_int + 1;
			return (1);
		}
		if (str_index > 3)
		{
			std::cout<<"|"<<std::endl;
			return (0);
		}
		std::cout<<"|";
		if (str.size() >= 10)
			std::cout<<std::setw(9)<<str.substr(0,9)<<".";
		else
			std::cout<<std::setw(10)<<str;
		return (1);
	}

	int PhoneBook::gap_print(int input_int, int str_index)
	{
		if (str_index > 4)
			return (0);
		std::cout<<input_int<<" page: "<<this->Conts[input_int - 1].convert(str_index)<<" is "<<this->Conts[input_int - 1].get_info(str_index)<<std::endl;
		return (1);
	}
	
	void PhoneBook::search() {
		std::string input;
		int add_result = add_count > 8 ? 8 : add_count;
		for (int j = 0; j < add_result ; j++)
			for (int i = 0; gap_print(this->Conts[j].get_info(i), i, j); i++);
		while (1) {
			if (add_count == 0)
			{
				std::cout << "no one here ... (ADD SOMEONE!)" << std::endl;
				break ;
			}
			else
				std::cout<<"몇 번 페이지를 열어볼까요우"<<std::endl;
			std::getline(std::cin, input);
			if (input.length() > 1 || std::cin.fail() || input[0] <= '0' ||  input[0] > add_result + '0') {
				std::cout << "wrong input.. (current phonebook size: "<<add_count << ")"<<std::endl;
			}
			else
			{
				for (int i = 0; gap_print(input[0] - '0', i); i++);
				break;
			}
		}
	};
