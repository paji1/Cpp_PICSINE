#include <iostream>
using namespace std;
class T
{
private:
	/* data */
public:
	int t;
	T(int l) ;
	~T();
	T& operator+ (T& other)
	{
		other.t += 5;;
		t = 5;
		return *this;
	}
	friend ostream& operator<<(ostream& os, T& other)
	{
		os << other.t;
		return os;
	} 
};

T::T(int l) : t(l)
{
	cout << "call " << endl;
}

T::~T()
{
}


int main(int argc,  char const *argv[])
{
	T l = T(12);
	T t = T(11);


	cout << t + l << endl;
	cout << "l " <<  l << endl;
	cout << "t " << t << endl;

	return 0;
}
