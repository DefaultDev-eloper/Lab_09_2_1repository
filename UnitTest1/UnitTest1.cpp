#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include <sstream>
#include "../macros.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest921
{
    double BranchHigh(double x, double y)
    {
        return MAX(CUBE(x), SQR(x + y));
    }

    double BranchLow(double x, double z)
    {
        return MIN(ABS(x - z), ABS(x + z));
    }

    TEST_CLASS(UnitTest921)
    {
    public:

        TEST_METHOD(Sqr_Number)
        {
            Assert::AreEqual(9.0, (double)SQR(3.0), 1e-12);
        }

        TEST_METHOD(Sqr_Expression)
        {
            Assert::AreEqual(25.0, (double)SQR(2.0 + 3.0), 1e-12);
        }

        TEST_METHOD(Cube_Positive)
        {
            Assert::AreEqual(8.0, (double)CUBE(2.0), 1e-12);
        }

        TEST_METHOD(Cube_Negative)
        {
            Assert::AreEqual(-8.0, (double)CUBE(-2.0), 1e-12);
        }

        TEST_METHOD(Abs_Negative)
        {
            Assert::AreEqual(5.0, (double)ABS(-5.0), 1e-12);
        }

        TEST_METHOD(Abs_Positive)
        {
            Assert::AreEqual(3.0, (double)ABS(3.0), 1e-12);
        }

        TEST_METHOD(Abs_Zero)
        {
            Assert::AreEqual(0.0, (double)ABS(0.0), 1e-12);
        }

        TEST_METHOD(Abs_Expression)
        {
            Assert::AreEqual(2.0, (double)ABS(3.0 - 5.0), 1e-12);
        }

        TEST_METHOD(Max_Positive)
        {
            Assert::AreEqual(7.0, (double)MAX(3.0, 7.0), 1e-12);
        }

        TEST_METHOD(Max_Negative)
        {
            Assert::AreEqual(-1.0, (double)MAX(-1.0, -5.0), 1e-12);
        }

        TEST_METHOD(Min_Positive)
        {
            Assert::AreEqual(3.0, (double)MIN(3.0, 7.0), 1e-12);
        }

        TEST_METHOD(Min_Negative)
        {
            Assert::AreEqual(-5.0, (double)MIN(-1.0, -5.0), 1e-12);
        }

        TEST_METHOD(BranchHigh_SquareBigger)
        {
            Assert::AreEqual(9.0, BranchHigh(2.0, 1.0), 1e-12);
        }

        TEST_METHOD(BranchHigh_CubeBigger)
        {
            Assert::AreEqual(27.0, BranchHigh(3.0, 0.0), 1e-12);
        }

        TEST_METHOD(BranchHigh_NegativeX)
        {
            Assert::AreEqual(4.0, BranchHigh(-2.0, 0.0), 1e-12);
        }

        TEST_METHOD(BranchLow_PositiveX)
        {
            Assert::AreEqual(2.0, BranchLow(3.0, 5.0), 1e-12);
        }

        TEST_METHOD(BranchLow_NegativeX)
        {
            Assert::AreEqual(1.0, BranchLow(-4.0, 5.0), 1e-12);
        }

        TEST_METHOD(BranchLow_XEqualsZ)
        {
            Assert::AreEqual(0.0, BranchLow(5.0, 5.0), 1e-12);
        }

        TEST_METHOD(Printr_OutputsNameAndValue)
        {
            std::ostringstream buf;
            std::streambuf* old = std::cout.rdbuf(buf.rdbuf());
            double w = 2.5;
            PRINTR(w);
            std::cout.rdbuf(old);
            Assert::AreEqual(std::string("w = 2.5\n"), buf.str());
        }
    };
}