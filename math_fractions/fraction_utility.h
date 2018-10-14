#pragma once

class fraction;

class fraction_utility
{
public:
	static int greatest_common_divisor(const fraction& a, const fraction& b);
	static int greatest_common_divisor(unsigned int a, unsigned int b);
};
