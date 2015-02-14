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
TEST(correctness, twoPlusTwo)
{
    BigInteger a(2);
    BigInteger b(2);
    BigInteger c = a + b;
    EXPECT_TRUE(c== 4);

}
TEST(correctness, zero)
{
    BigInteger a;
    BigInteger b = 0;
    EXPECT_TRUE(a== b);

}


TEST(correctness, bigPlus)
{
     BigInteger a = 4;
     BigInteger b = 5;

    EXPECT_TRUE(a + b == BigInteger(9));

}

/*TEST(correctness, constPlus)
{
    const BigInteger a = 4;
    const BigInteger b = 5;

    EXPECT_TRUE(a + b == BigInteger(9));

}*/
/*
TEST(correctness, assignmentOperator)
{
    BigInteger a = 4;
    BigInteger b = 7;
    b = a;

    EXPECT_TRUE(a == b);
}

TEST(correctness, selfAssignment)
{
    BigInteger a = 5;
    a = a;

    EXPECT_TRUE(a == 5);
}
TEST(correctness, assignmentReturnValue)
{
    BigInteger a = 4;
    BigInteger b = 7;
    (a = b) = a;

    EXPECT_TRUE(a == 7);
    EXPECT_TRUE(b == 7);
}
TEST(correctness, compareZeroAndMinusZero)
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

TEST(correctness, addSigned)
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

TEST(correctness, subSigned)
{
    BigInteger a = 5;
    BigInteger b = 20;

    EXPECT_TRUE(a - b == BigInteger(-15));


    a =a- -100;
    EXPECT_TRUE(a == 85);
}
TEST(correctness, plusEq)
{
    BigInteger a = 5;
    a+=15;

    EXPECT_TRUE(a == BigInteger(20));

}
TEST(correctness, minusEq)
{
    BigInteger a = 5;
    a-=15;

    EXPECT_TRUE(a == BigInteger(-10));

}
TEST(correctness, mulEq)
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
TEST(correctness, mul)
{
    BigInteger a = 5;
    BigInteger b = 20;

    EXPECT_TRUE(a * b == BigInteger(100));

}
TEST(correctness, mulSigned)
{
    BigInteger a = 5;
    BigInteger b = -20;

    EXPECT_TRUE(a * b == BigInteger(-100));

}
TEST(correctness, constructor)
{
    BigInteger a = BigInteger("1000");
    BigInteger b = BigInteger(1000);

    EXPECT_TRUE(a == b);

}

TEST(correctness, addLong)
{
    BigInteger a("1000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
    BigInteger b(                                                     "10000000000000000000000000000000");
    BigInteger c("1000000000000000000000000000000000000000000000000000010000000000000000000000000000000");

    EXPECT_TRUE(a + b== c);
}

TEST(correctness, addLongSigned)
{
    BigInteger a("-10000000000000000000000000000000000000000000000000000000000000000");
    BigInteger b( "10000000000000000000000000000000000000000000000000000000000000000");

    EXPECT_EQ(a + b, 0);
}

TEST(correctness, addLongSigned2)
{
    BigInteger a("-100000000000000000000000000000000000000000000000000000000000000000000000000000000000");
    BigInteger b(                                                     "10000000000000000000000000000000");
    BigInteger c( "-99999999999999999999999999999999999999999999999999990000000000000000000000000000000");

    EXPECT_EQ(a + b, c);
}

TEST(correctness, addLongPow2)
{
    BigInteger a( "18446744073709551616");
    BigInteger b( "36893488147419103232");

    EXPECT_EQ(a + a, b);
}
TEST(correctness, addLongPow3)
{
    BigInteger a( "18446744073709551616");
    BigInteger b("-18446744073709551616");
    BigInteger c( "36893488147419103232");

    EXPECT_EQ(b + c, a);
}

TEST(correctness, subLong)
{
    BigInteger a("1000000000000000000000000000000000000000000000000000000000000000000000000000");
    BigInteger b(                                                     "10000000000000000000000");
    BigInteger c( "999999999999999999999999999999999999999999999999999990000000000000000000000");

    EXPECT_EQ(a - b, c);
}

TEST(correctness, mulLong)
{
    BigInteger a("100000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
    BigInteger b(                                                     "1000000000000000000000000000000000");
    BigInteger c("100000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
            "000000000000000000000000000000000");

    EXPECT_EQ(a * b, c);
}

TEST(correctness, mulLongSigned)
{
    BigInteger a("-100000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
    BigInteger b(                                                     "10000000000000000000000000000000000");
    BigInteger c("-100000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
            "0000000000000000000000000000000000");

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
*/