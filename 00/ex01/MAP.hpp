#ifndef MAP_H
#define MAP_H

#include <iostream>

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
		unsigned long i = 0;
		std::cout<<"|";
		if (str.length() > 10)
		{
			while (i < 9)
			{
				std::cout<<str[i];
				i++;
			}
			std::cout<<".";
		}
		else
		{
			while (i < 10 - str.length())
			{
				std::cout<<" ";
				i++;
			}
			std::cout<<str;
		}
	}
	void	search()
	{
		int i = 0;
		while (i < add_count && i < 8)
		{
			std::cout<<"|         "<<i;
			gap_print(Conts[i].first_name);
			gap_print(Conts[i].last_name);
			gap_print(Conts[i].nickname);
			std::cout<<"|"<<std::endl;
			i++;
		}
	}
};


#endif