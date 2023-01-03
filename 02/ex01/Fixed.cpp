#include "Fixed.hpp"
#include "iostream"

int Fixed::getRawBits( void ) const{
	std::cout<<"getRawBits member function called"<<std::endl;
	return (Fixed::fixed_point);
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
	this->fixed_point = og.getRawBits();
	return *this;
}

Fixed::Fixed(const Fixed &og)
{
	std::cout<<"Copy constructor called"<<std::endl;
	this->fixed_point = og.getRawBits();
}

Fixed::Fixed(const int para){
	std::cout<<"Int constructor called"<<std::endl;
	this->fixed_point = para;
}

Fixed::Fixed(const float para){
	std::cout<<"Float constructor called"<<std::endl;
	this->fixed_point = para;
}

float Fixed::toFloat(void) const{

}

int Fixed::toInt(void) const{

}

std::ostream& operator<<(std::ostream& out, const Fixed &ref){
	out << ref.getRawBits();
	return (out);
}
