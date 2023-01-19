#include "Fixed.hpp"
class Point
{
private:
	Fixed x;
	Fixed y;
	/* data */
public:
	Point(/* args */);
	Point(float _x, float _y);
	Point(const Point &);
	Point &operator=(const Point &);
	Fixed get_x();
	Fixed get_y();
	~Point();
};
bool bsp( Point const a, Point const b, Point const c, Point const point);