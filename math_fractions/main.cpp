#include <iostream>
#include "fraction.h"

int main()
{
	int n;
	fraction sum = fraction::create_fraction(0, 1);
	std::cin >> n;
	for (auto i = 0; i < n; ++i)
	{
		sum += fraction::create_fraction(1, i + 1);
	}
	std::cout << sum;
}