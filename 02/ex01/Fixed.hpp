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
};

std::ostream& operator<<(std::ostream& out, const Fixed& ref);
