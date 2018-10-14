#pragma once

class fraction;

class fraction_utility
{
public:
	static int greatest_common_divider(const fraction& a, const fraction& b);
	static int greatest_common_divider(unsigned int a, unsigned int b);
};
