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
	PhoneBook() {
		index = 0;
		add_count = 0;
	}
	
	void	add()
	{
		std::string number;
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string darkest_secret;
		
		std::cout<<"number 입력해주세용"<<std::endl;
		std::cin>>number;
		std::cout<<"first_name 입력해주세용"<<std::endl;
		std::cin>>first_name;
		std::cout<<"last_name 입력해주세용"<<std::endl;
		std::cin>>last_name;
		std::cout<<"nickname 입력해주세용"<<std::endl;
		std::cin>>nickname;
		std::cout<<"darkest_secret 입력해주세용"<<std::endl;
		std::cin>>darkest_secret;
		if (!number.empty() && !first_name.empty() && !last_name.empty() && !nickname.empty() && !darkest_secret.empty())
		{
			if (index == 8)
				index = 0;
			Conts[index].number = number;
			Conts[index].first_name = first_name;
			Conts[index].last_name = last_name;
			Conts[index].nickname = nickname;
			Conts[index].darkest_secret = darkest_secret;
			index ++;
			add_count ++;
		}
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