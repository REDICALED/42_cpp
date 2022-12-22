#include "Contact.hpp"
const std::string Contact::get_info(const int index) const{
	return (this->info[index]);
}

void Contact::set_info(const std::string add, int index) {
	this->info[index] = add;
}

const std::string Contact::convert(int val)
{
	if (val == this->NUMBER)
		return ("number");
	else if (val == this->FIRST_NAME)
		return ("first_name");
	else if (val == this->LAST_NAME)
		return ("last_name");
	else if (val == this->NICKNAME)
		return ("nickname");
	else if (val == this->DARKEST_SECRET)
		return ("darkest_secret");
	return ("invalid");
}