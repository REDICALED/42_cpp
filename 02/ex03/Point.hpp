#include "Fixed.hpp"

class Point{
private:
	Fixed const x;
	Fixed const y;
public:
	Point();
	~Point();
	Point(float x, float y);
	Point(Point& point);
	Point& operator=(Point& point);
	Fixed get_y() const;
	Fixed get_x() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);
Fixed bsp_util( Point const &a, Point const &b, Point const &c);