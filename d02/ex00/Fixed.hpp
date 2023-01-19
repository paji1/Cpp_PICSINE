#include <string>
#include <iostream>
class Fixed
{
private:
	int num;
	static const int frac = 8;

public:
	Fixed(/* args */);
	Fixed(const Fixed &);
	Fixed &operator=(const Fixed &);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

