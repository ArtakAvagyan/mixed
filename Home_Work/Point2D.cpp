#include "Point2D.h"
#include <iostream>
Point2D& Point2D::operator=(Point2D rhs)
{
	std::swap(*this,rhs);
	return *this;
} 
const Point2D Point2D::operator+(const Point2D& rhs)const
{
	return {this->x+rhs.x,this->y+rhs.y};
}
const Point2D Point2D::operator-(const Point2D& rhs)const
{
	return {this->x-rhs.x,this->y-rhs.y};
}
const Point2D Point2D::operator*(const Point2D& rhs)const
{
	return {this->x*rhs.x,this->y*rhs.y};
}
const Point2D Point2D::operator/(const Point2D& rhs)const
{
	return {this->x/rhs.x,this->y/rhs.y};
}

bool Point2D::operator<(const Point2D& rhs)const
{
	return this->x < rhs.x && this->y < rhs.y;
}
bool Point2D::operator>(const Point2D& rhs)const
{
	return this->x > rhs.x && this->y > rhs.y;
}
bool Point2D::operator==(const Point2D& rhs)const
{
	return this->x == rhs.x && this->y == rhs.y;
}
bool Point2D::operator!=(const Point2D& rhs)const
{
	return this->x != rhs.x && this->y != rhs.y;
}
bool Point2D::operator<=(const Point2D& rhs)const
{
	return this->x <= rhs.x && this->y <= rhs.y;
}bool Point2D::operator>=(const Point2D& rhs)const
{
	return this->x >= rhs.x && this->y >= rhs.y;
}
void Point2D::set_x(size_t _x)
{
	x = _x;
}
void Point2D::set_y(size_t _y)
{
	y = _y;
}
size_t Point2D::get_x()
{
	return x;
}
size_t Point2D::get_y()
{
	return y;
}
std::ostream& operator<<(std::ostream& os , Point2D& lhs)
{
	for(int i = 0; i < lhs.y;++i)os<<std::endl;
	for(int i = 0; i < lhs.x;++i)os<<' ';
	os<< "*" <<std::endl;
	return os;
}
std::istream& operator>>(std::istream& ifs, Point2D& lhs)
{
	ifs >> lhs.x >> lhs.y ;
	return ifs;
}

