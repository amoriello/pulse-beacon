#include <iostream>
#include "run/factorial.hpp"

int	main()
{
	std::cout << factorial<12>::value << std::endl;

	std::cout << "Yeah" << std::endl;
}