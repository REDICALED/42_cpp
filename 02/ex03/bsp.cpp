#include "Point.hpp"

Fixed bsp_util( Point const &a, Point const &b, Point const &c){
	Fixed left = (a.get_x() * b.get_y() + b.get_x() * c.get_y() + c.get_x() * a.get_y());
	Fixed right = (a.get_x() * c.get_y() + b.get_x() * a.get_y() + c.get_x() * b.get_y());
	Fixed total;
	if (left > right)
		total = (left - right);
	else
		total = (right - left);
	return (total);
}

bool bsp( Point const a, Point const b, Point const c, Point const point){
	Fixed large = bsp_util(a,b,c);
	Fixed one = bsp_util(a,b,point);
	Fixed two = bsp_util(point, b, c);
	Fixed three = bsp_util(a,c,point);


	std::cout<<(one)<<std::endl;
	std::cout<<(two)<<std::endl;
	std::cout<<(three)<<std::endl;


	std::cout<<(large)<<std::endl;

	if (large == (one + two + three) && one != 0 && two != 0 && three != 0)
		return true;
	else
		return false;
}