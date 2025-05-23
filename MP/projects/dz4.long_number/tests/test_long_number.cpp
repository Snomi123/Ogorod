#include <gtest/gtest.h>
#include "long_number.hpp"
#include <stdexcept>

using namespace biv; 


TEST(LongNumberTest, ConstructorAndEquality) {
    LongNumber num1("12345");
    LongNumber num2("12345");
    LongNumber num3("-67890");

    ASSERT_TRUE(num1 == num2);
    ASSERT_FALSE(num1 == num3);
}

TEST(LongNumberTest, DivisionAndModulo) {
    LongNumber a("1000");
    LongNumber b("3");
    
    LongNumber div = a / b;
    LongNumber mod = a % b;
    
    EXPECT_EQ(div, LongNumber("333"));
    EXPECT_EQ(mod, LongNumber("1"));
}
TEST(LongNumberTest, Addition) {
    LongNumber a("999999999");
    LongNumber b("1");
    LongNumber result = a + b;

    EXPECT_EQ(result, LongNumber("1000000000"));
}

TEST(LongNumberTest, Subtraction) {
    LongNumber a("1000000000");
    LongNumber b("1");
    LongNumber result = a - b;

    EXPECT_EQ(result, LongNumber("999999999"));
}

TEST(LongNumberTest, Multiplication) {
    LongNumber a("123456789");
    LongNumber b("2");
    LongNumber result = a * b;

    EXPECT_EQ(result, LongNumber("246913578"));
}


TEST(LongNumberTest, Modulo) {
    LongNumber a("1000");
    LongNumber b("3");
    LongNumber result = a % b;

    EXPECT_EQ(result, LongNumber("1"));
}

TEST(LongNumberTest, EdgeCases) {
    LongNumber zero;
    LongNumber num("123");
    
    EXPECT_EQ(zero + num, num);
    EXPECT_EQ(num - num, zero);
    EXPECT_TRUE(LongNumber("-123").is_negative());
}

TEST(LongNumberTest, DigitAccess) {
    LongNumber num("987654321");
    
    EXPECT_EQ(num.get_digits_number(), 9);
    EXPECT_EQ(num.get_rank_number(2), 3); 
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}