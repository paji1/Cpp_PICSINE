#include <string>
#include <iostream>
#include <cmath>
class Fixed
{
private:
	static const int frac = 8;
	int num;

public:
	Fixed(/* args */);
	Fixed(const Fixed &);
	Fixed(const int);
	Fixed(const float _fnum);
	friend std::ostream &operator<<(std::ostream& os, const Fixed &other);
	Fixed &operator=(const Fixed &);
	~Fixed();
	float toFloat( void ) const;
	int toInt( void ) const;

};
