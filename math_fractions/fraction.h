#pragma once
#include <string>
#include <ostream>

class fraction
{
	enum class number_sign : char { zero = 0, positive = 1, negative = -1 };

public:
	// Constructors
	fraction() : fraction(0, 1) {}
	fraction(int number) : fraction(number, 1) {}
	fraction(int numerator, int denominator);

	fraction(fraction&& f) = default;
	fraction(const fraction& f) = default;
	fraction& operator=(fraction&& f) = default;
	fraction& operator=(const fraction& f) = default;

	// Factory
	static fraction create_fraction(int numerator, int denominator);

	// Getters
	// TODO: inline methods
	unsigned int get_numerator() const;
	unsigned int get_denominator() const;
	number_sign get_sign() const;
	int get_sign_value() const;

	// Relations
	bool operator==(const fraction& f) const;
	bool operator!=(const fraction& f) const;
	bool operator<(const fraction& f) const;
	bool operator>(const fraction& f) const;
	bool operator<=(const fraction& f) const;
	bool operator>=(const fraction& f) const;

	// Arithmetic
	fraction& operator+(const fraction& f);
	fraction& operator-(const fraction& f);
	fraction& operator*(const fraction& f);
	fraction& operator/(const fraction& f);
	fraction& operator+=(const fraction& f);
	fraction& operator-=(const fraction& f);

	fraction& operator+(const int& n);
	fraction& operator-(const int& n);
	fraction& operator*(const int& n);
	fraction& operator/(const int& n);
	fraction& operator+=(const int& n);
	fraction& operator-=(const int& n);

	// Conversions
	operator std::string() const;
	operator std::wstring() const;
	explicit operator double() const;

	// TODO: inline methods
	bool is_positive() const;
	bool is_negative() const;
	bool is_zero() const;
	bool is_common() const;

private:
	fraction(unsigned int numerator, unsigned int denominator, number_sign sign) : numerator(numerator), denominator(denominator), sign(sign) {}

	unsigned int numerator = 1;
	unsigned int denominator = 1;
	number_sign sign = number_sign::positive;

	fraction& reduce();
	fraction& flip_sign();
};

std::ostream& operator<<(std::ostream& stream, const fraction& f);
