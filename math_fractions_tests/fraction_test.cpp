#include "CppUnitTest.h"
#include "../math_fractions/fraction.h"
#include "../math_fractions/fraction.cpp"
#include "../math_fractions/fraction_utility.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace creating_fractions
{
	TEST_CLASS(assigning_numerator_and_denumerator)
	{
	public:

		TEST_METHOD(create_positive_fraction)
		{
			auto f = fraction::create_fraction(5, 4);
			Assert::AreEqual<unsigned int>(5, f.get_numerator());
			Assert::AreEqual<unsigned int>(4, f.get_denominator());
		}

		TEST_METHOD(create_negative_fraction)
		{
			auto f = fraction::create_fraction(-5, 4);
			Assert::AreEqual<unsigned int>(5, f.get_numerator());
			Assert::AreEqual<unsigned int>(4, f.get_denominator());
		}

		TEST_METHOD(create_zero_fraction)
		{
			auto f = fraction::create_fraction(0, 1);
			Assert::AreEqual<unsigned int>(0, f.get_numerator());
			Assert::AreEqual<unsigned int>(1, f.get_denominator());
		}

		TEST_METHOD(create_fraction_with_zero_denominator)
		{
			Assert::ExpectException<std::exception>([] {fraction::create_fraction(5, 0); });
		}
	};

	TEST_CLASS(reducing_fractions)
	{
	public:
		TEST_METHOD(create_for_reducing)
		{
			auto f = fraction::create_fraction(8, 2);
			Assert::AreEqual<unsigned int>(4, f.get_numerator());
			Assert::AreEqual<unsigned int>(1, f.get_denominator());
		}

		TEST_METHOD(create_negative_for_reducing)
		{
			auto f = fraction::create_fraction(-10, 4);
			Assert::AreEqual<unsigned int>(5, f.get_numerator());
			Assert::AreEqual<unsigned int>(2, f.get_denominator());
		}

		TEST_METHOD(create_zero_for_reducing)
		{
			auto f = fraction::create_fraction(0, 8);
			Assert::AreEqual<unsigned int>(0, f.get_numerator());
			Assert::AreEqual<unsigned int>(1, f.get_denominator());
		}
	};

	TEST_CLASS(fraction_signs)
	{
	public:
		TEST_METHOD(check_positive_sign)
		{
			auto f = fraction::create_fraction(10, 4);
			Assert::IsTrue(f.is_positive());
			Assert::IsFalse(f.is_negative());
			Assert::IsFalse(f.is_zero());
		}

		TEST_METHOD(check_negative_sign)
		{
			auto f = fraction::create_fraction(-10, 4);
			Assert::IsFalse(f.is_positive());
			Assert::IsTrue(f.is_negative());
			Assert::IsFalse(f.is_zero());
		}

		TEST_METHOD(check_zero_sign)
		{
			auto f = fraction::create_fraction(0, 4);
			Assert::IsFalse(f.is_positive());
			Assert::IsFalse(f.is_negative());
			Assert::IsTrue(f.is_zero());
		}
	};
}