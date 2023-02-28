#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <set>
# include <vector>
# include <algorithm>
# include <math.h>
class Span
{
private:
	struct out_of_range : public std::runtime_error
	{
		out_of_range();
	};
	struct already_exist : public std::runtime_error
	{
		already_exist();
	};
	struct no_Span : public std::runtime_error
	{
		no_Span();
	};
	
	unsigned int N;
	std::set<int> array;
public:
	Span();
	Span(unsigned int);
	Span(Span const &);
	~Span();

	Span&	operator=(Span const &);

	void	addNumber(int);
	void	iota(int, int);
	int		shortestSpan();
	int		longestSpan();
};

#endif /* * SPAN_H */