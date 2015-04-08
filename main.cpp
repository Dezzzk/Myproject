#include <iostream>
#include "Myset.h"

int main()
{
	
	Myset<int> set;

	try
	{
		for (int i = 0; i < 10000; ++i)
			set.add(i);

		std::cout << set.size() << std::endl;
	}
	catch (const char * message)
	{
		std::cout << message << std::endl;
	}

	std::cout << set.contains(723) << std::endl;
	set.remove(723);
	std::cout << set.contains(723) << std::endl;

	Myset<int> set1(set);
	std::cout << set1.size() << std::endl;

	Myset<int> set2 = set1;
	std::cout << set2.size() << std::endl;

	Myset<int> set3;
	set3 = set2;
	set3 = set2;
	std::cout << set3.size() << std::endl;

	return 0;
}