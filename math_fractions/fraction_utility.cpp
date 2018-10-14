#include "fraction_utility.h"
#include "fraction.h"

int fraction_utility::greatest_common_divider(const fraction& a, const fraction& b)
{
	return greatest_common_divider(a.get_numerator(), b.get_denominator());
}

int fraction_utility::greatest_common_divider(unsigned int a, unsigned int b)
{
	auto reduce = [](auto bigger, auto smaller, auto multiplier)
	{
		bigger -= smaller * multiplier;
	};
	while (a != b)
	{
		if (a > b)
		{
			reduce(a, b, a / b);
		}
		else
		{
			reduce(b, a, b / a);
		}
	};
	return a;
}