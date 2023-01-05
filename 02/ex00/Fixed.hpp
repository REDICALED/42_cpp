#pragma once

class Fixed{
private:
	int	fixed_point;
	static const int frac_bit;
public:
	Fixed();
	Fixed(const Fixed& og);
	Fixed& operator=(const Fixed &og);
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};