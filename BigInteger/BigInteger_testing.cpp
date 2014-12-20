#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <vector>
#include <utility>
#include <gtest/gtest.h>

#include "BigInteger.h"
#include "gtest/gtest.h"

TEST(correctness, zeros)
{
    BigInteger a(0);
    BigInteger b = BigInteger(10)*a;

    EXPECT_TRUE(a == b);

}
TEST(correctness, two_plus_two)
{
    EXPECT_EQ(BigInteger(2) + BigInteger(2), BigInteger(4));

}
TEST(correctness, zero)
{
    BigInteger a;
    BigInteger b = 0;
    EXPECT_EQ(a, b);

}
TEST(correctness, assignment_operator)
{
    BigInteger a = 4;
    BigInteger b = 7;
    b = a;

    EXPECT_TRUE(a == b);
}
TEST(correctness, self_assignment)
{
    BigInteger a = 5;
    a = a;

    EXPECT_TRUE(a == 5);
}
TEST(correctness, assignment_return_value)
{
    BigInteger a = 4;
    BigInteger b = 7;
    (a = b) = a;

    EXPECT_TRUE(a == 7);
    EXPECT_TRUE(b == 7);
}
TEST(correctness, compare_zero_and_minus_zero)
{
    BigInteger a(0);
    BigInteger b = BigInteger(-1)*a;

    EXPECT_TRUE(a == b);
}

TEST(correctness, add)
{
    BigInteger a = 123;
    BigInteger b = 456;

    EXPECT_TRUE(a + b == BigInteger(123+456));

}

TEST(correctness, add_signed)
{
    BigInteger a = 5;
    BigInteger b = -20;

    EXPECT_TRUE(a + b == BigInteger(-15));

}

TEST(correctness, sub)
{
    BigInteger a = 20;
    BigInteger b = 5;

    EXPECT_TRUE(a - b == BigInteger(15));

}

TEST(correctness, sub_signed)
{
    BigInteger a = 5;
    BigInteger b = 20;

    EXPECT_TRUE(a - b == BigInteger(-15));


    a =a- -100;
    EXPECT_TRUE(a == 85);
}
TEST(correctness, plus_eq)
{
    BigInteger a = 5;
    a+=15;

    EXPECT_TRUE(a == BigInteger(20));

}
TEST(correctness, minus_eq)
{
    BigInteger a = 5;
    a-=15;

    EXPECT_TRUE(a == BigInteger(-10));

}
TEST(correctness, mul_eq)
{
    BigInteger a = 5;
    a*=15;

    EXPECT_TRUE(a == BigInteger(75));

}



TEST(correctness, eq)
{
    BigInteger a = 7;
    BigInteger b = 4;
    a = a -8;
    a=a+1;
    b =b-5;
    b = b + 1;
    EXPECT_TRUE(a == b);
    a = BigInteger(0);
    a = BigInteger(-0);
    EXPECT_TRUE(a == b);
}
TEST(correctness, mul1)
{
    BigInteger a = 71;
    BigInteger b = 4;

    EXPECT_TRUE(a * b == BigInteger(284));

}
TEST(correctness, mul2)
{
    BigInteger a = 5;
    BigInteger b = 20;

    EXPECT_TRUE(a * b == BigInteger(100));

}
TEST(correctness, mul_signed)
{
    BigInteger a = BigInteger("1000");
    BigInteger b = BigInteger(1000);

    EXPECT_TRUE(a == b);

}

TEST(correctness, add_long)
{
    BigInteger a("1000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
    BigInteger b(                                                     "10000000000000000000000000000000");
    BigInteger c("1000000000000000000000000000000000000000000000000000010000000000000000000000000000000");

    EXPECT_EQ(a + b, c);
}

TEST(correctness, add_long_signed)
{
    BigInteger a("-10000000000000000000000000000000000000000000000000000000000000000");
    BigInteger b( "10000000000000000000000000000000000000000000000000000000000000000");

    EXPECT_EQ(a + b, 0);
}

TEST(correctness, add_long_signed2)
{
    BigInteger a("-100000000000000000000000000000000000000000000000000000000000000000000000000000000000");
    BigInteger b(                                                     "10000000000000000000000000000000");
    BigInteger c( "-99999999999999999999999999999999999999999999999999990000000000000000000000000000000");

    EXPECT_EQ(a + b, c);
}

TEST(correctness, add_long_pow2)
{
    BigInteger a( "18446744073709551616");
    BigInteger b( "36893488147419103232");

    EXPECT_EQ(a + a, b);
}
TEST(correctness, add_long_pow3)
{
    BigInteger a( "18446744073709551616");
    BigInteger b("-18446744073709551616");
    BigInteger c( "36893488147419103232");

    EXPECT_EQ(b + c, a);
}

TEST(correctness, sub_long)
{
    BigInteger a("1000000000000000000000000000000000000000000000000000000000000000000000000000");
    BigInteger b(                                                     "10000000000000000000000");
    BigInteger c( "999999999999999999999999999999999999999999999999999990000000000000000000000");

    EXPECT_EQ(a - b, c);
}

TEST(correctness, mul_long)
{
    BigInteger a("100000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
    BigInteger b(                                                     "1000000000000000000000000000000000");
    BigInteger c("100000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
            "000000000000000000000000000000000");

    EXPECT_EQ(a * b, c);
}

TEST(correctness, mul_long_signed)
{
    BigInteger a("-100000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
    BigInteger b(                                                     "10000000000000000000000000000000000");
    BigInteger c("-100000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
            "0000000000000000000000000000000000f");

    EXPECT_EQ(a * b, c);
}

TEST(correctness, mul_long_signed2)
{
    BigInteger a("-100000000000000000000000000");
    BigInteger b("-100000000000000000000000000");
    BigInteger c("100000000000000000000000000"
            "00000000000000000000000000");

    EXPECT_EQ(a * b, c);
}
