#include <iostream>

class Fixed{
private:
	int	fixed_point;
	static const int frac_bit;
public:
	Fixed();
	Fixed(const Fixed& og);
	Fixed& operator=(const Fixed& og);
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );

	Fixed(const int para);
	Fixed(const float para);
	float toFloat(void) const;
	int toInt(void) const;

	Fixed  operator*(Fixed const &fix);
	Fixed  operator/(Fixed const &fix);
	Fixed  operator+(Fixed const &fix);
	Fixed  operator-(Fixed const &fix);
	bool  operator>(Fixed const &fix) const;
	bool  operator<(Fixed const &fix) const;
	bool  operator>=(Fixed const &fix) const;
	bool  operator<=(Fixed const &fix) const;
	bool  operator==(Fixed const &fix) const;
	bool  operator!=(Fixed const &fix) const;
	Fixed  operator++(int);
	Fixed  operator++();
	Fixed  operator--(int);
	Fixed  operator--();

	static Fixed&   max(Fixed &a, Fixed &b);
	static Fixed const &max(Fixed const &a, Fixed const &b);
	static Fixed&   min(Fixed &a, Fixed &b);
	static Fixed const &min(Fixed const &a, Fixed const &b);
};

std::ostream& operator<<(std::ostream& out, const Fixed& ref);
