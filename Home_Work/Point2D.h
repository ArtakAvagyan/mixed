#ifndef POINT2D_H
#define POINT2D_H
#include <iostream>

class Point2D
{
public:
	Point2D(){}
	Point2D(int x_,int y_):x{x_},y{y_}{}
	Point2D(const Point2D& rhs):x{rhs.x},y{rhs.y}{}
	Point2D(const Point2D&& rhs):x(std::move(rhs.x)),y{std::move(rhs.y)}{}
public:
	Point2D& operator=(Point2D);
	const Point2D operator+(const Point2D&)const;
	const Point2D operator-(const Point2D&)const;
	const Point2D operator*(const Point2D&)const;
	const Point2D operator/(const Point2D&)const;
	bool operator<(const Point2D&)const;
	bool operator>(const Point2D&)const;
	bool operator==(const Point2D&)const;
	bool operator!=(const Point2D&)const;
	bool operator<=(const Point2D&)const;
	bool operator>=(const Point2D&)const;
public:
	void set_x(size_t _x);
	void set_y(size_t _y);
	size_t get_x();
	size_t get_y();
public:
	friend std::ostream& operator<<(std::ostream& , Point2D& lhs);
	friend std::istream& operator>>(std::istream& , Point2D& lhs);
private:
	int x;
	int y;
};
#endif //POINT2D_H
