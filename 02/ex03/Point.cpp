#include "Point.hpp"

Fixed Point::get_y() const {
	return (this->y);
}

Fixed Point::get_x() const{
	return (this->x);
}

Point::Point():x(0),y(0){
}

Point::~Point(){
}

Point::Point(float const x1, float const y1):
x(x1),y(y1){
}


Point::Point(Point& point):x(point.x), y(point.y){
}

Point& Point::operator=(Point& point){
	const_cast<Fixed&>(x) = point.x;
	const_cast<Fixed&>(y) = point.y;
	return *this;
}
