#include <iostream>
#include <string>
#include "swim.h"
#define STR(text) #text
#define PRINT_TASK(SRT) \
	std::cout << STR(28.4 Practical Work.Task 1. 100m swim\n\n)

int main()
{
	PRINT_TASK(STR);
	Swimming s;
	s.InputDadeTreck();
	s.swimming();
	s.sort_map();
	std::cin.get();
	return 0;
}
