
# include <iostream>
class learn
{
private:
	int hello;
public:
	int age;
	learn(int a, int b);
	~learn();
};

learn::learn(int a, int b)
{
	age = a;
	hello = b;
}

learn::~learn()
{
}
