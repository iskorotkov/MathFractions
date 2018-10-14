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

int fraction::get_sign_value() const
{
	return sign == number_sign::positive ? 1 :
		sign == number_sign::negative ? -1 : 0;
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

fraction& fraction::operator+(const fraction& f)
{
	if (f.is_zero())
	{
		return *this;
	}

	auto gcd = fraction_utility::greatest_common_divisor(*this, f);
	auto multiplier_for_this = f.get_denominator() / gcd;
	auto multiplier_for_other = get_denominator() / gcd;

	int numerator_value = get_sign_value()*get_numerator()*multiplier_for_this + f.get_sign_value()*f.get_numerator()*multiplier_for_other;

	sign = numerator_value > 0 ? number_sign::positive :
		numerator_value < 0 ? number_sign::negative :
		number_sign::zero;
	numerator = abs(numerator_value);
	denominator = denominator * multiplier_for_this;

	return this->reduce();
}

fraction& fraction::operator+(const int& n)
{
	return *this + create_fraction(n, 1);
}

fraction& fraction::operator-(const fraction& f)
{
	auto negative_f = f;
	negative_f.sign = f.is_positive() ? number_sign::negative :
		f.is_negative() ? number_sign::positive : number_sign::zero;
	return *this + negative_f;
}

fraction& fraction::operator-(const int& n)
{
	return *this + (-n);
}

fraction& fraction::operator*(const fraction& f)
{
	numerator *= f.get_numerator();
	denominator *= f.get_denominator();
	auto sign_mul = get_sign_value()*f.get_sign_value();
	// TODO: extract method
	sign = sign_mul > 0 ? number_sign::positive :
		sign_mul < 0 ? number_sign::negative :
		number_sign::zero;
	return this->reduce();
}

fraction& fraction::operator*(const int& n)
{
	return *this * create_fraction(n, 1);
}

fraction& fraction::operator/(const fraction& f)
{
	auto reversed_f = f;
	reversed_f.numerator = f.get_denominator();
	reversed_f.denominator = f.get_numerator();
	return *this * reversed_f;
}

fraction& fraction::operator/(const int& n)
{
	if (n == 0)
	{
		// TODO: create exception class
		throw std::exception("Division by zero");
	}
	return *this / create_fraction(1, n);
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
	auto gcd = fraction_utility::greatest_common_divisor(numerator, denominator);
	numerator /= gcd;
	denominator /= gcd;
	return *this;
}

fraction& fraction::flip_sign()
{
	if (sign == number_sign::positive)
	{
		sign = number_sign::negative;
	}
	else if (sign == number_sign::negative)
	{
		sign = number_sign::positive;
	}
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

fraction::operator std::wstring() const
{
	// TODO: remove duplicated code (fraction::operator string())
	if (sign == number_sign::zero)
	{
		return std::wstring(L"0");
	}
	else
	{
		std::wostringstream out_string;
		if (sign == number_sign::negative)
		{
			out_string << L'-';
		}
		out_string << numerator << L'/' << denominator;
		return out_string.str();
	}
}

std::ostream& operator<<(std::ostream& stream, const fraction& f)
{
	return stream << std::string(f);
}