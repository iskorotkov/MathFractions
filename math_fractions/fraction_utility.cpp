#include "fraction_utility.h"
#include "fraction.h"

int fraction_utility::greatest_common_divisor(const fraction& a, const fraction& b)
{
	return greatest_common_divisor(a.get_numerator(), b.get_denominator());
}

int fraction_utility::greatest_common_divisor(unsigned int a, unsigned int b)
{
	while (a && b)
	{
		if (a > b)
		{
			a %= b;
		}
		else
		{
			b %= a;
		}
	};
	return a + b;
}