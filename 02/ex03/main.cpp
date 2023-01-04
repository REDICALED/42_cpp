#include "Point.hpp"

const int Fixed::frac_bit = 8;

#include <iostream>

int main( void ) {
	Point	a(5, 5);
	Point	b(2, 9);
	Point	c(0, 5);
	Point	p(3, 5);
	Point	p2(4, 7);

	std::cout << "Point a.x = " << a.get_x() << " a.y = " << a.get_y() << std::endl;
	std::cout << "Point b.x = " << b.get_x() << " b.y = " << b.get_y() << std::endl;
	std::cout << "Point c.x = " << c.get_x() << " c.y = " << c.get_y() << std::endl;
	std::cout << "Point p.x = " << p.get_x() << " p.y = " << p.get_y() << std::endl;
	std::cout << "Point p2.x = " << p2.get_x() << " p2.y = " << p2.get_y() << std::endl;
	if (bsp(a, b, c, p))
		std::cout << "p is in the triangle" << std::endl;
	else
		std::cout << "p is out of the triangle" << std::endl;
	if (bsp(a, b, c, p2))
		std::cout << "p2 is in the triangle" << std::endl;
	else
		std::cout << "p2 is out of the triangle" << std::endl;
	return 0;
}