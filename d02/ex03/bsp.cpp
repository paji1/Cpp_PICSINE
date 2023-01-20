#include "Point.hpp"

Fixed find_area(Point  a, Point  b, Point  c)
{
	Fixed l =  a.get_x() * (b.get_y() -   c.get_y()) +  // 4 * (3 - 4) 
	b.get_x() * (c.get_y() - a.get_y()) +
	c.get_x() * (a.get_y() -  b.get_y()); // 3 * (4 - 4)
	if (l < 0)
		l = l * -1;
	return (l * Fixed(0.5f));
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed tr1 =  find_area(a, b, point);
	Fixed tr2 =  find_area(c, b, point);
	Fixed tr3 =  find_area(a, c, point);
	// std::cout  << "tr1 " << tr1 << std::endl;
	// std::cout  << "tr2 " << tr2 << std::endl;
	// std::cout  << "tr3 " << tr3 << std::endl;
	// std::cout  << "sum  " << tr3 + tr1 + tr2 << std::endl;
	// std::cout  << "find  " << find_area(a, b, c).toFloat() << std::endl;
	if (find_area(a, b, c) >= (tr1 + tr2 + tr3) && tr1.getRawBits() && tr2.getRawBits() && tr3.getRawBits())
		return true;
	return false;
}