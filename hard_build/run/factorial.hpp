#ifndef FACTORIAL_HPP_
# define FACTORIAL_HPP_

template <int val>
struct factorial
{
	enum  { value = val * factorial<val - 1>::value };
};


template <>
struct factorial<0>
{
	enum { value = 1 };
};

#endif /* !FACTORIAL_HPP_ */