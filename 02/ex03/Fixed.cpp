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
}

Fixed::~Fixed(){
}

Fixed& Fixed::operator=(const Fixed& og){
	this->fixed_point = og.getRawBits();
	return *this;
}

Fixed::Fixed(const Fixed &og)
{
	*this = og;
}

Fixed::Fixed(const int para){
	this->fixed_point = para<<this->frac_bit;
}

Fixed::Fixed(const float para){
	this->fixed_point = roundf(para * (1 << frac_bit));
}

float Fixed::toFloat(void) const{
	return static_cast<float>(this->fixed_point) / (1 << this->frac_bit);
}

int Fixed::toInt(void) const{
	return (this->fixed_point >> this->frac_bit);
}

std::ostream& operator<<(std::ostream& out, const Fixed &ref){
	out << ref.toFloat();
	return (out);
}

Fixed  Fixed::operator*(Fixed const &fix){
	Fixed fixed(this->toFloat() * fix.toFloat());
	return (fixed);
}

Fixed Fixed::operator/(Fixed const &fix){
	Fixed fixed(this->toFloat() / fix.toFloat());
	return (fixed);
}

Fixed Fixed::operator+(Fixed const &fix){
	Fixed fixed(this->toFloat() + fix.toFloat());
	return (fixed);
}

Fixed Fixed::operator-(Fixed const &fix){
	Fixed fixed(this->toFloat() - fix.toFloat());
	return (fixed);
}

bool  Fixed::operator>(Fixed const &fix) const{
	if (this->toFloat() > fix.toFloat())
		return true;
	else
		return false;
}

bool  Fixed::operator<(Fixed const &fix) const{
	if (this->toFloat() < fix.toFloat())
		return true;
	else
		return false;
}

bool  Fixed::operator>=(Fixed const &fix) const{
	if (this->toFloat() >= fix.toFloat())
		return true;
	else
		return false;
}
bool  Fixed::operator<=(Fixed const &fix) const{
	if (this->toFloat() <= fix.toFloat())
		return true;
	else
		return false;
}

bool  Fixed::operator==(Fixed const &fix) const{
	if (this->toFloat() == fix.toFloat())
		return true;
	else
		return false;
}

bool  Fixed::operator!=(Fixed const &fix) const{
	if (this->toFloat() != fix.toFloat())
		return true;
	else
		return false;
}
Fixed  Fixed::operator++(int){
	Fixed dummy(*this);
	this->fixed_point ++;
	return dummy;
}

Fixed  Fixed::operator++(){

	this->fixed_point ++;
	return *this;
}

Fixed  Fixed::operator--(int){
	Fixed dummy(*this);
	this->fixed_point --;
	return dummy;
}

Fixed  Fixed::operator--(){
	this->fixed_point --;
	return *this;
}

Fixed&   Fixed::max(Fixed &a, Fixed &b){
	if (a > b)
		return (a);
	else
		return (b);
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b){
	if (a > b)
		return (a);
	else
		return (b);
}

Fixed&   Fixed::min(Fixed &a, Fixed &b){
	if (a < b)
		return (a);
	else
		return (b);
}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b){
	if (a < b)
		return (a);
	else
		return (b);
}
