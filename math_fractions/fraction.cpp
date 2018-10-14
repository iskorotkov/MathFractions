#include "fraction.h"
#include <assert.h>
#include <utility>
#include <string>
#include <ostream>
#include <sstream>
#include <exception>
#include "fraction_utility.h"

fraction fraction::create_fraction(int numerator, int denominator)
{
	if (denominator == 0)
	{
		// TODO: create class for exception
		throw std::exception("Division by zero");
	}

	auto sign = numerator * denominator > 0 ? number_sign::positive : numerator == 0 ? number_sign::zero : number_sign::negative;
	return fraction(abs(numerator), abs(denominator), sign)
		.reduce();
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

bool fraction::operator<(const fraction& f) const
{
	// TODO: use more precise method (w/o doubles)
	return double(*this) < double(f);
}

bool fraction::operator>(const fraction& f) const
{
	// TODO: use more precise method (w/o doubles)
	return double(*this) > double(f);
}

bool fraction::operator>=(const fraction& f) const
{
	return *this == f || *this > f;
}

bool fraction::operator<=(const fraction& f) const
{
	return *this == f || *this < f;
}

bool fraction::operator!=(const fraction& f) const
{
	return !(*this == f);
}

bool fraction::operator==(const fraction& f) const
{
	return sign == f.sign
		&& numerator == f.numerator
		&& denominator == f.denominator;
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

fraction::operator double() const
{
	return double(sign) * numerator / denominator;
}

fraction& fraction::reduce()
{
	auto gcd = fraction_utility::greatest_common_divider(numerator, denominator);
	numerator /= gcd;
	denominator /= gcd;
	return *this;
}

fraction::operator std::string() const
{
	if (sign == number_sign::zero)
	{
		return { "0" };
	}
	else
	{
		std::ostringstream out_string;
		if (sign == number_sign::negative)
		{
			out_string << '-';
		}
		out_string << numerator << '/' << denominator;
		return out_string.str();
	}
}

std::ostream& operator<<(std::ostream& stream, const fraction& f)
{
	return stream << std::string(f);
}