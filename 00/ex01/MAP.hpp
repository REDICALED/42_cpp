#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <iomanip>
#include <limits>

class Contact
{
	public:
	std::string number;
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string darkest_secret;
};

class PhoneBook
{
	Contact Conts[8];
	int 	index;
	int 	add_count;
	public:
	static int flag;
	PhoneBook() {
		index = 0;
		add_count = 0;
	}
	
	int	add_print(const char *mes,std::string *number)
	{
		std::cout<<mes<<std::endl;
		std::cin>>*number;
		if (std::cin.eof())
			exit(1);
		return 0;
	}
	
	int	add()
	{
		if (index == 8)
			index = 0;
		add_print("number 입력하세여", &PhoneBook::Conts[index].number);
		add_print("first_name 입력하세여", &PhoneBook::Conts[index].first_name);
		add_print("last_name 입력하세여", &PhoneBook::Conts[index].last_name);
		add_print("nickname 입력하세여", &PhoneBook::Conts[index].nickname);
		add_print("darkest_secret 입력하세여", &PhoneBook::Conts[index].darkest_secret);
		index ++;
		add_count ++;
		return 0;
	}
	
	void	gap_print(std::string str)
	{
		std::cout<<"|";
		if (str.size() >= 10)
		{
			std::cout<<std::setw(9);
			std::cout<<str.substr(0,9)<<".";
		}
		else
			std::cout<<std::setw(10)<<str;
	}
	void	search() {
		int input;
		while (1) {
			if (add_count == 0)
			{
				std::cout << "no one here ... (ADD SOMEONE!)" << std::endl;
				break ;
			}
			std::cin >> input;
			if (std::cin.fail() || input > add_count || input <= 0) {
				std::cout << "wrong input.. (current phonebook size: "<<add_count << ")"<<std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else
			{
				std::cout<<"|"<<std::setw(10)<<input;
				gap_print(Conts[input - 1].first_name);
				gap_print(Conts[input - 1].last_name);
				gap_print(Conts[input - 1].nickname);
				std::cout<<"|"<<std::endl;
				break;
			}
		}
	}
};

#endif