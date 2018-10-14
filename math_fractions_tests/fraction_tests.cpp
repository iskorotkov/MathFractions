#include "CppUnitTest.h"
#include "../math_fractions/fraction.h"
#include "../math_fractions/fraction.cpp"
#include "../math_fractions/fraction_utility.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

inline std::wstring ToString(const fraction& t)
{
	return t;
}

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

		TEST_METHOD(both_values_negative)
		{
			auto f = fraction::create_fraction(-4, -5);
			Assert::AreEqual<unsigned int>(4, f.get_numerator());
			Assert::AreEqual<unsigned int>(5, f.get_denominator());
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

		TEST_METHOD(both_values_negative)
		{
			auto f = fraction::create_fraction(-4, -5);
			Assert::IsTrue(f.is_positive());
			Assert::IsFalse(f.is_negative());
			Assert::IsFalse(f.is_zero());
		}
	};
}

namespace fraction_properties
{
	TEST_CLASS(common_fractions)
	{
	public:
		TEST_METHOD(uncommon_fraction)
		{
			auto f = fraction::create_fraction(5, 4);
			Assert::IsFalse(f.is_common());
		}

		TEST_METHOD(common_fraction)
		{
			auto f = fraction::create_fraction(4, 5);
			Assert::IsTrue(f.is_common());
		}
	};
}

namespace fraction_conversions
{
	TEST_CLASS(fraction_to_double)
	{
	public:
		TEST_METHOD(negative_fraction)
		{
			auto f = fraction::create_fraction(-5, 4);
			Assert::AreEqual(-5. / 4., double(f));
		}

		TEST_METHOD(positive_fraction)
		{
			auto f = fraction::create_fraction(12, 6);
			Assert::AreEqual(12. / 6., double(f));
		}

		TEST_METHOD(zero_fraction)
		{
			auto f = fraction::create_fraction(0, 11);
			Assert::AreEqual(0., double(f));
		}
	};

	TEST_CLASS(fraction_to_string)
	{
	public:
		TEST_METHOD(positive_fraction)
		{
			auto f = fraction::create_fraction(6, 5);
			Assert::AreEqual<std::string>("6/5", std::string(f));
		}

		TEST_METHOD(negative_fraction)
		{
			auto f = fraction::create_fraction(-6, 7);
			Assert::AreEqual<std::string>("-6/7", std::string(f));
		}

		TEST_METHOD(zero_fraction)
		{
			auto f = fraction::create_fraction(0, 5);
			Assert::AreEqual<std::string>("0", std::string(f));
		}

		TEST_METHOD(positive_reduced_fraction)
		{
			auto f = fraction::create_fraction(4, 12);
			Assert::AreEqual<std::string>("1/3", std::string(f));
		}

		TEST_METHOD(negative_reduced_fraction)
		{
			auto f = fraction::create_fraction(-8, 4);
			Assert::AreEqual<std::string>("-2/1", std::string(f));
		}
	};
}

namespace fraction_comparison
{
	TEST_CLASS(equality)
	{
	public:
		TEST_METHOD(two_positive_equal_fractions)
		{
			auto f = fraction::create_fraction(3, 5);
			auto f2 = fraction::create_fraction(3, 5);
			Assert::IsTrue(f == f2);
			Assert::IsFalse(f != f2);
		}

		TEST_METHOD(two_negative_equal_fractions)
		{
			auto f = fraction::create_fraction(-4, 5);
			auto f2 = fraction::create_fraction(-4, 5);
			Assert::IsTrue(f == f2);
			Assert::IsFalse(f != f2);
		}

		TEST_METHOD(two_positive_unequal_fractions)
		{
			auto f = fraction::create_fraction(9, 18);
			auto f2 = fraction::create_fraction(6, 8);
			Assert::IsFalse(f == f2);
			Assert::IsTrue(f != f2);
		}

		TEST_METHOD(two_negative_unequal_fractions)
		{
			auto f = fraction::create_fraction(-6, 18);
			auto f2 = fraction::create_fraction(6, -12);
			Assert::IsFalse(f == f2);
			Assert::IsTrue(f != f2);
		}

		TEST_METHOD(positive_and_negative_fraction)
		{
			auto f = fraction::create_fraction(-9, 18);
			auto f2 = fraction::create_fraction(4, 8);
			Assert::IsFalse(f == f2);
			Assert::IsTrue(f != f2);
		}

		TEST_METHOD(positive_and_zero_fractions)
		{
			auto f = fraction::create_fraction(0, 18);
			auto f2 = fraction::create_fraction(4, 8);
			Assert::IsFalse(f == f2);
			Assert::IsTrue(f != f2);
		}

		TEST_METHOD(negative_and_zero_fractions)
		{
			auto f = fraction::create_fraction(-9, 18);
			auto f2 = fraction::create_fraction(0, 8);
			Assert::IsFalse(f == f2);
			Assert::IsTrue(f != f2);
		}

		TEST_METHOD(two_zero_fractions)
		{
			auto f = fraction::create_fraction(0, 18);
			auto f2 = fraction::create_fraction(0, 8);
			Assert::IsTrue(f == f2);
			Assert::IsFalse(f != f2);
		}
	};

	TEST_CLASS(comparison)
	{
	public:
		TEST_METHOD(two_positive)
		{
			auto f = fraction::create_fraction(4, 5);
			auto f2 = fraction::create_fraction(3, 6);
			Assert::IsTrue(f > f2);
			Assert::IsFalse(f < f2);
		}

		TEST_METHOD(two_negative)
		{
			auto f = fraction::create_fraction(-4, 5);
			auto f2 = fraction::create_fraction(-3, 2);
			Assert::IsTrue(f > f2);
			Assert::IsFalse(f < f2);
		}

		TEST_METHOD(positive_and_negative)
		{
			auto f = fraction::create_fraction(4, 5);
			auto f2 = fraction::create_fraction(-3, 2);
			Assert::IsTrue(f > f2);
			Assert::IsFalse(f < f2);
		}

		TEST_METHOD(positive_and_zero)
		{
			auto f = fraction::create_fraction(4, 5);
			auto f2 = fraction::create_fraction(0, 2);
			Assert::IsTrue(f > f2);
			Assert::IsFalse(f < f2);
		}

		TEST_METHOD(negative_and_zero)
		{
			auto f = fraction::create_fraction(0, 5);
			auto f2 = fraction::create_fraction(-3, 2);
			Assert::IsTrue(f > f2);
			Assert::IsFalse(f < f2);
		}
	};

	TEST_CLASS(comparison_and_equality)
	{
	public:
		TEST_METHOD(two_positive)
		{
			auto f = fraction::create_fraction(4, 5);
			auto f2 = fraction::create_fraction(3, 6);
			Assert::IsTrue(f >= f2);
			Assert::IsFalse(f <= f2);
		}

		TEST_METHOD(two_negative)
		{
			auto f = fraction::create_fraction(-4, 9);
			auto f2 = fraction::create_fraction(-3, 6);
			Assert::IsTrue(f >= f2);
			Assert::IsFalse(f <= f2);
		}

		TEST_METHOD(two_zero)
		{
			auto f = fraction::create_fraction(0, 5);
			auto f2 = fraction::create_fraction(0, 6);
			Assert::IsTrue(f >= f2);
			Assert::IsTrue(f <= f2);
		}
	};
}

namespace fraction_arithmetic
{
	TEST_CLASS(fraction_addition)
	{
	public:
		TEST_METHOD(two_positive)
		{
			auto f = fraction::create_fraction(3, 4);
			auto f2 = fraction::create_fraction(5, 8);
			auto expected = fraction::create_fraction(11, 8);
			Assert::AreEqual(expected, f + f2);
		}

		TEST_METHOD(two_negative)
		{
			auto f = fraction::create_fraction(-3, 4);
			auto f2 = fraction::create_fraction(-5, 8);
			auto expected = fraction::create_fraction(-11, 8);
			Assert::AreEqual(expected, f + f2);
		}

		TEST_METHOD(positive_and_zero)
		{
			auto f = fraction::create_fraction(3, 4);
			auto f2 = fraction::create_fraction(0, 8);
			auto expected = fraction::create_fraction(3, 4);
			Assert::AreEqual(expected, f + f2);
		}

		TEST_METHOD(negative_and_zero)
		{
			auto f = fraction::create_fraction(-3, 4);
			auto f2 = fraction::create_fraction(0, 8);
			auto expected = fraction::create_fraction(-3, 4);
			Assert::AreEqual(expected, f + f2);
		}

		TEST_METHOD(positive_and_negative)
		{
			auto f = fraction::create_fraction(-3, 4);
			auto f2 = fraction::create_fraction(5, 8);
			auto expected = fraction::create_fraction(-1, 8);
			Assert::AreEqual(expected, f + f2);
		}

		TEST_METHOD(two_zero)
		{
			auto f = fraction::create_fraction(0, 4);
			auto f2 = fraction::create_fraction(0, 8);
			auto expected = fraction::create_fraction(0, 1);
			Assert::AreEqual(expected, f + f2);
		}
	};

	TEST_CLASS(fraction_substraction)
	{
	public:
		TEST_METHOD(two_positive)
		{
			auto f = fraction::create_fraction(3, 4);
			auto f2 = fraction::create_fraction(5, 8);
			auto expected = fraction::create_fraction(1, 8);
			Assert::AreEqual(expected, f - f2);
		}

		TEST_METHOD(two_negative)
		{
			auto f = fraction::create_fraction(-3, 4);
			auto f2 = fraction::create_fraction(-5, 8);
			auto expected = fraction::create_fraction(-1, 8);
			Assert::AreEqual(expected, f - f2);
		}

		TEST_METHOD(positive_and_zero)
		{
			auto f = fraction::create_fraction(3, 4);
			auto f2 = fraction::create_fraction(0, 8);
			auto expected = fraction::create_fraction(3, 4);
			Assert::AreEqual(expected, f - f2);
		}

		TEST_METHOD(negative_and_zero)
		{
			auto f = fraction::create_fraction(-3, 4);
			auto f2 = fraction::create_fraction(0, 8);
			auto expected = fraction::create_fraction(-3, 4);
			Assert::AreEqual(expected, f - f2);
		}

		TEST_METHOD(positive_and_negative)
		{
			auto f = fraction::create_fraction(-3, 4);
			auto f2 = fraction::create_fraction(5, 8);
			auto expected = fraction::create_fraction(-11, 8);
			Assert::AreEqual(expected, f - f2);
		}

		TEST_METHOD(two_zero)
		{
			auto f = fraction::create_fraction(0, 4);
			auto f2 = fraction::create_fraction(0, 8);
			auto expected = fraction::create_fraction(0, 1);
			Assert::AreEqual(expected, f - f2);
		}
	};

	TEST_CLASS(multiplication)
	{
	public:
		TEST_METHOD(two_positive)
		{
			auto f = fraction::create_fraction(3, 4);
			auto f2 = fraction::create_fraction(5, 8);
			auto expected = fraction::create_fraction(15, 32);
			Assert::AreEqual(expected, f * f2);
		}

		TEST_METHOD(two_negative)
		{
			auto f = fraction::create_fraction(-3, 4);
			auto f2 = fraction::create_fraction(-5, 8);
			auto expected = fraction::create_fraction(15, 32);
			Assert::AreEqual(expected, f* f2);
		}

		TEST_METHOD(positive_and_zero)
		{
			auto f = fraction::create_fraction(3, 4);
			auto f2 = fraction::create_fraction(0, 8);
			auto expected = fraction::create_fraction(0, 1);
			Assert::AreEqual(expected, f * f2);
		}

		TEST_METHOD(negative_and_zero)
		{
			auto f = fraction::create_fraction(-3, 4);
			auto f2 = fraction::create_fraction(0, 8);
			auto expected = fraction::create_fraction(0, 1);
			Assert::AreEqual(expected, f * f2);
		}

		TEST_METHOD(positive_and_negative)
		{
			auto f = fraction::create_fraction(-3, 4);
			auto f2 = fraction::create_fraction(5, 8);
			auto expected = fraction::create_fraction(-15, 32);
			Assert::AreEqual(expected, f * f2);
		}

		TEST_METHOD(two_zero)
		{
			auto f = fraction::create_fraction(0, 4);
			auto f2 = fraction::create_fraction(0, 8);
			auto expected = fraction::create_fraction(0, 1);
			Assert::AreEqual(expected, f * f2);
		}
	};

	TEST_CLASS(division)
	{
	public:
		TEST_METHOD(two_positive)
		{
			auto f = fraction::create_fraction(3, 4);
			auto f2 = fraction::create_fraction(5, 8);
			auto expected = fraction::create_fraction(6, 5);
			Assert::AreEqual(expected, f / f2);
		}

		TEST_METHOD(two_negative)
		{
			auto f = fraction::create_fraction(-3, 4);
			auto f2 = fraction::create_fraction(-5, 8);
			auto expected = fraction::create_fraction(6, 5);
			Assert::AreEqual(expected, f / f2);
		}

		TEST_METHOD(positive_and_zero)
		{
			auto f = fraction::create_fraction(3, 4);
			auto f2 = fraction::create_fraction(0, 8);
			Assert::ExpectException<std::exception>([&] {f / f2; });
		}

		TEST_METHOD(negative_and_zero)
		{
			auto f = fraction::create_fraction(-3, 4);
			auto f2 = fraction::create_fraction(0, 8);
			auto expected = fraction::create_fraction(0, 1);
			Assert::ExpectException<std::exception>([&] {f / f2; });
		}

		TEST_METHOD(positive_and_negative)
		{
			auto f = fraction::create_fraction(-3, 4);
			auto f2 = fraction::create_fraction(5, 8);
			auto expected = fraction::create_fraction(-6, 5);
			Assert::AreEqual(expected, f / f2);
		}

		TEST_METHOD(two_zero)
		{
			auto f = fraction::create_fraction(0, 4);
			auto f2 = fraction::create_fraction(0, 8);
			Assert::ExpectException<std::exception>([&] {f / f2; });
		}
	};
}

namespace fraction_and_numbers_arithmetic
{
	TEST_CLASS(addition)
	{
	public:
		TEST_METHOD(add_positive)
		{
			auto f = fraction::create_fraction(4, 5);
			auto expected = fraction::create_fraction(19, 5);
			Assert::AreEqual(expected, f + 3);
		}

		TEST_METHOD(add_negative)
		{
			auto f = fraction::create_fraction(4, 5);
			auto expected = fraction::create_fraction(-11, 5);
			Assert::AreEqual(expected, f + (-3));
		}

		TEST_METHOD(add_zero)
		{
			auto f = fraction::create_fraction(4, 5);
			Assert::AreEqual(f, f + 0);
		}
	};

	TEST_CLASS(substraction)
	{
	public:
		TEST_METHOD(substract_positive)
		{
			auto f = fraction::create_fraction(4, 5);
			auto expected = fraction::create_fraction(-11, 5);
			Assert::AreEqual(expected, f - 3);
		}

		TEST_METHOD(substract_negative)
		{
			auto f = fraction::create_fraction(4, 5);
			auto expected = fraction::create_fraction(19, 5);
			Assert::AreEqual(expected, f - (-3));
		}

		TEST_METHOD(substract_zero)
		{
			auto f = fraction::create_fraction(4, 5);
			Assert::AreEqual(f, f - 0);
		}
	};

	TEST_CLASS(multiplication)
	{
	public:
		TEST_METHOD(positive)
		{
			auto f = fraction::create_fraction(4, 5);
			auto expected = fraction::create_fraction(12, 5);
			Assert::AreEqual(expected, f * 3);
		}

		TEST_METHOD(negative)
		{
			auto f = fraction::create_fraction(4, 5);
			auto expected = fraction::create_fraction(-12, 5);
			Assert::AreEqual(expected, f * (-3));
		}

		TEST_METHOD(zero)
		{
			auto f = fraction::create_fraction(4, 5);
			auto expected = fraction::create_fraction(0, 1);
			Assert::AreEqual(expected, f * 0);
		}
	};

	TEST_CLASS(division)
	{
	public:
		TEST_METHOD(positive)
		{
			auto f = fraction::create_fraction(4, 5);
			auto expected = fraction::create_fraction(4, 15);
			Assert::AreEqual(expected, f / 3);
		}

		TEST_METHOD(negative)
		{
			auto f = fraction::create_fraction(4, 5);
			auto expected = fraction::create_fraction(-4, 15);
			Assert::AreEqual(expected, f / (-3));
		}

		TEST_METHOD(zero)
		{
			auto f = fraction::create_fraction(4, 5);
			Assert::ExpectException<std::exception>([&] { f / 0; });
		}
	};
}