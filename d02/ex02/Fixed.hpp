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
	Fixed &operator=(const Fixed &);
	bool operator<(const Fixed &);
	bool operator>(const Fixed &);
	bool operator>=(const Fixed &);
	bool operator<=(const Fixed &);
	bool operator==(const Fixed &);
	bool operator!=(const Fixed &);
	Fixed operator+(const Fixed &);
	Fixed operator++();
	Fixed operator++(int);
	Fixed operator--();
	Fixed operator--(int);
	Fixed operator*(const Fixed &);
	Fixed operator-(const Fixed &);
	static Fixed& min(Fixed &, Fixed&);
	static const Fixed& min(const Fixed &, const Fixed&);
	static Fixed& max(Fixed &, Fixed&);
	static const Fixed& max(const Fixed &, const Fixed&);
	int getRawBits( void ) const;
	~Fixed();
	float toFloat(void) const;
	int toInt(void) const;
};
std::ostream &operator<<(std::ostream &os, const Fixed &other);

