#include "Span.hpp"

/*** ------------------------------- CONSTRUCTOR --------------------------------*/
Span::Span()
{
	std::cout << "Span Constructor called" << std::endl;
}
Span::Span(unsigned int _n)
{
	N = _n;
	std::cout << "Span Constructor called" << std::endl;
}
Span::Span(const Span &other )
{
	*this = other;
}

/*** -------------------------------- DESTRUCTOR --------------------------------*/
Span::~Span()
{
	std::cout << "Span Destructor called" << std::endl;
}

/*** --------------------------------- OVERLOAD ---------------------------------*/
Span&   Span::operator=(Span const & other )
{
	N = other.N;
	array = other.array;
	return *this;
}

/*** --------------------------------- METHODS ----------------------------------*/
void Span::addNumber(int n)
{
	if (find(array.begin(), array.end(), n) != array.end())
		throw already_exist();
	if (array.size() + 1 > N)
		throw out_of_range();
	array.insert(n);
}

int current;
static int UniqueNumber () { return current++; }
void Span::iota(int first, int last)
{
	current = first;
	if (array.size() + abs(first - last) > N || first > last)
		throw out_of_range();
	int seq[last- first];
	std::generate_n(seq, last - first + 1, UniqueNumber);
	array.insert(seq, seq + last - first + 1);
}

int Span::shortestSpan()
{
	if (array.size() < 2)
		throw no_Span();
	long n = (((unsigned int )-1) / 2) + 1;
	for (std::set<int>::iterator it = array.begin() ; it != --array.end();)
	{
		int begin = *it;
		int end = *(++it);
		if (end -  begin < n)
			n =  end - begin;
	}
	return n;
}

int Span::longestSpan()
{
	if (array.size() < 2)
		throw no_Span();
	int begin = *array.begin();
	int end = *(--array.end());
	return   end - begin;
}

/*** --------------------------------- ACCESSOR ---------------------------------*/

/*** --------------------------------- ACEPTION ---------------------------------*/

Span::out_of_range::out_of_range() : runtime_error("out_of_range")
{

}
Span::already_exist::already_exist() : runtime_error("already_exist")
{

}
Span::no_Span::no_Span() : runtime_error("no_Span")
{

}