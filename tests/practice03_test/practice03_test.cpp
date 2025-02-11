// used chatgpt to help make the test methods
#include "pch.h"
#include "CppUnitTest.h"
#include "practice03.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace practice03tests
{
    TEST_CLASS(practice03test)
    {
    public:
        TEST_METHOD(SumRangeTest)
        {
            Assert::AreEqual(15, MathUtils::sumRange(1, 5));
            Assert::AreEqual(0, MathUtils::sumRange(0, 0));
            Assert::AreEqual(0, MathUtils::sumRange(-3, 3));
        }

        TEST_METHOD(ContainsNegativeTest)
        {
            std::vector<int> allPositive = { 1, 2, 3 };
            std::vector<int> hasNegative = { 1, -2, 3 };
            std::vector<int> emptyList = {};

            Assert::IsFalse(MathUtils::containsNegative(allPositive));
            Assert::IsTrue(MathUtils::containsNegative(hasNegative));
            Assert::IsFalse(MathUtils::containsNegative(emptyList));
        }

        TEST_METHOD(FindMaxTest)
        {
            std::vector<int> values = { 3, 1, 5, 7 };
            std::vector<int> allSame = { 4, 4, 4 };
            std::vector<int> emptyList = {};

            Assert::AreEqual(7, MathUtils::findMax(values));
            Assert::AreEqual(4, MathUtils::findMax(allSame));
            Assert::AreEqual(INT_MIN, MathUtils::findMax(emptyList));
        }
    };
}

