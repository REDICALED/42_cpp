#pragma once
#include <iostream>

class Contact
{
private:
	std::string info[5];
public:
	const std::string get_info(const int index) const;
	void set_info(const std::string add, int index);
	enum info_vals {
		NUMBER,
		FIRST_NAME,
		LAST_NAME,
		NICKNAME,
		DARKEST_SECRET
	};
	const std::string convert(int val);
};
