#include "fraction.h"
#include <assert.h>
#include <utility>

fraction&& fraction::create_fraction(int numerator, int denominator)
{
	assert(denominator);

	auto sign = numerator * denominator > 0 ? number_sign::positive : numerator == 0 ? number_sign::zero : number_sign::negative;
	numerator = abs(numerator);
	denominator = abs(denominator);

	using std::move;
	return move(fraction(move(numerator), move(denominator), move(sign)));
}