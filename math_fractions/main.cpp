#include <iostream>
#include "fraction.h"

int main()
{
	int n;
	fraction sum;
	std::cin >> n;
	for (auto i = 0; i < n; ++i)
	{
		sum += fraction(1, i + 1);
	}
	std::cout << sum;
}