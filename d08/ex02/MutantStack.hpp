#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <stack>
# include <deque>

template <class T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack() : std::stack<T>() {}
	MutantStack(int n) : std::stack<T>()
	{
		std::stack<T>::push(n);
	}
	~MutantStack() {}

	MutantStack &operator=(MutantStack const &other)
	{
		std::stack<T>::operator=(other);
		return *this;
	}
	class iterator
	{
	private:
		T *ptr;	
	public:
		iterator() : ptr(NULL) {}
		iterator(T* _ptr) : ptr(_ptr) {}
		iterator(iterator const &other)
		{
			ptr =other.ptr;
		}
		iterator &operator=(iterator const &other)
		{
			this->ptr = other.ptr;
			return *this;
		}
		iterator &operator++()
		{
			ptr++;
			return  *this;
		}
		iterator operator++(int)
		{
			iterator tmp = *this;
			ptr++;
			return tmp;
		}
		iterator &operator--()
		{
			ptr--;
			return *this;
		}
		iterator operator--(int)
		{
			iterator tmp = *this;
			ptr--;
			return tmp;
		}
		bool operator<(iterator &other)
		{
			return (this->ptr < other.ptr);
		}
		bool operator<=(iterator &other)
		{
			return (this->ptr <= other.ptr);
		}
		bool operator>(iterator &other)
		{
			return (this->ptr > other.ptr);
		}
		bool operator>=(iterator &other)
		{
			return (this->ptr >= other.ptr);
		}
		bool operator==(iterator &other)
		{
			return (this->ptr == other.ptr);
		}
		T& operator*()
		{
			return *ptr;
		}
		T& operator[](int n)
		{
			return ptr[n];
		}
		~iterator() { ptr = NULL;}
	};
	iterator	begin(void)
	{
		return iterator(&this->top() - this->size() + 1);
	}
	iterator	end(void)
	{
		return iterator(&this->top() + 1);
	}
};

#endif /* * MUTANTSTACK_H */