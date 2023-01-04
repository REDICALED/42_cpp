#include "Fixed.hpp"
#include "iostream"

int Fixed::getRawBits( void ) const{
	return (this->fixed_point);
}

void Fixed::setRawBits( int const raw ){
	fixed_point = raw;
}

Fixed::Fixed()
:fixed_point(0)
{
	std::cout<<"Default constructor called"<<std::endl;
}

Fixed::~Fixed(){
	std::cout<<"Destructor called"<<std::endl;
}

Fixed& Fixed::operator=(const Fixed& og){
	if (&og != this)
		this->fixed_point = og.getRawBits();
	std::cout<<"Copy assignment operator called"<<std::endl;
	return *this;
}

Fixed::Fixed(const Fixed &og)
{
	std::cout<<"Copy constructor called"<<std::endl;
	*this = og;
}

Fixed::Fixed(const int para){
	std::cout<<"Int constructor called"<<std::endl;
	this->fixed_point = para<<this->frac_bit;
}

Fixed::Fixed(const float para){
	std::cout<<"Float constructor called"<<std::endl;
	this->fixed_point = roundf(para * (1 << frac_bit));
}

float Fixed::toFloat(void) const{
	float return_value = this->fixed_point;
	return return_value / (1 << this->frac_bit);
}

int Fixed::toInt(void) const{
	return (this->fixed_point >> this->frac_bit);
}

std::ostream& operator<<(std::ostream& out, const Fixed &ref){
	out << ref.toFloat();
	return (out);
}
