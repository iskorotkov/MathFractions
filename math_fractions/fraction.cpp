#include "fraction.h"
#include <assert.h>
#include <utility>
#include <string>
#include "fraction_utility.h"

fraction&& fraction::create_fraction(int numerator, int denominator)
{
	assert(denominator);

	auto sign = numerator * denominator > 0 ? number_sign::positive : numerator == 0 ? number_sign::zero : number_sign::negative;
	numerator = abs(numerator);
	denominator = abs(denominator);

	using std::move;
	return move(fraction(move(numerator), move(denominator), move(sign)));
}

unsigned int fraction::get_numerator() const
{
	return numerator;
}

unsigned int fraction::get_denominator() const
{
	return denominator;
}

fraction::number_sign fraction::get_sign() const
{
	return sign;
}

bool fraction::is_positive() const
{
	return sign == number_sign::positive;
}

bool fraction::is_negative() const
{
	return sign == number_sign::negative;
}

bool fraction::is_zero() const
{
	return sign == number_sign::zero;
}

bool fraction::is_common() const
{
	return numerator < denominator;
}

// std::string fraction::to_string() const
// {
// 	if (sign == number_sign::zero)
// 	{
// 		return std::string("0");
// 	}
// 	else if (sign == number_sign::negative)
// 	{
// 		return ("-" + numerator + '/' + denominator);
// 	}
// 	else
// 	{
// 		return "" + numerator + '/' + denominator;
// 	}
// }

void fraction::reduce()
{
	auto gcd = fraction_utility::greatest_common_divider(numerator, denominator);
	numerator /= gcd;
	denominator /= gcd;
}