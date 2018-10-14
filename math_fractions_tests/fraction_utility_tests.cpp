#include "CppUnitTest.h"
#include "../math_fractions/fraction.h"
#include "../math_fractions/fraction_utility.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace greatest_common_divisor
{
	TEST_CLASS(numbers)
	{
	public:
		TEST_METHOD(test_1)
		{
			Assert::AreEqual(1, fraction_utility::greatest_common_divisor(3, 7));
		}

		TEST_METHOD(test_2)
		{
			Assert::AreEqual(2, fraction_utility::greatest_common_divisor(2, 8));
		}

		TEST_METHOD(test_16)
		{
			Assert::AreEqual(16, fraction_utility::greatest_common_divisor(128, 144));
		}
	};

	TEST_CLASS(fractions)
	{
	public:
		TEST_METHOD(two_positive)
		{
			auto f = fraction::create_fraction(3, 4);
			auto f2 = fraction::create_fraction(3, 8);
			Assert::AreEqual(4, fraction_utility::greatest_common_divisor(f, f2));
		}

		TEST_METHOD(positive_and_negative)
		{
			auto f = fraction::create_fraction(3, 10);
			auto f2 = fraction::create_fraction(-4, 5);
			Assert::AreEqual(5, fraction_utility::greatest_common_divisor(f, f2));
		}

		TEST_METHOD(positive_and_zero)
		{
			auto f = fraction::create_fraction(3, 7);
			auto f2 = fraction::create_fraction(0, 1);
			Assert::AreEqual(1, fraction_utility::greatest_common_divisor(f, f2));
		}
	};
}