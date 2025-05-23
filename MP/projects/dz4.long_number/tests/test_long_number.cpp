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

class FComparisons : public testing::Test {
    public:
        LongNumber
            n_2{"-2"}, n_1{"-1"}, n_1_copy{"-1"},
            
            p_1{"1"}, p_1_copy{"1"}, p_12{"12"};
};

TEST_F(FComparisons, equal) {
    EXPECT_TRUE(p_1 == p_1_copy) << "EXPECT_TRUE: 1 == 1";
    EXPECT_FALSE(n_1 == p_1) << "EXPECT_FALSE: -1 == 1";
    EXPECT_FALSE(p_1 == p_12) << "EXPECT_FALSE: 1 == 12";
    EXPECT_EQ(p_1, p_1_copy) << "EXPECT_EQ: 1 == 1";
    EXPECT_EQ(n_1, n_1_copy) << "EXPECT_EQ: -1 == -1";
}

TEST_F(FComparisons, not_equal) {
    EXPECT_TRUE(n_1 != p_1) << "EXPECT_TRUE: -1 != 1";
    EXPECT_TRUE(p_1 != p_12) << "EXPECT_TRUE: 1 != 12";
    EXPECT_FALSE(p_1 != p_1_copy) << "EXPECT_FALSE: 1 == 1";
    ASSERT_NE(p_1, p_12) << "ASSERT_NE: 1 != 12";
    ASSERT_NE(n_1, p_1) << "ASSERT_NE: -1 != 1";
}

TEST_F(FComparisons, more) {
    EXPECT_TRUE(p_12 > p_1) << "12 > 1";
    EXPECT_TRUE(p_1 > n_1) << "1 > -1";
    EXPECT_TRUE(n_1 > n_2) << "-1 > -2";
    EXPECT_FALSE(p_1_copy > p_1) << "1 > 1";
    EXPECT_FALSE(p_1 > p_12) << "1 > 12";
}

TEST_F(FComparisons, less) {
    EXPECT_TRUE(p_1 < p_12) << "1 < 12";
    EXPECT_TRUE(n_1 < p_1) << "-1 < 1";
    EXPECT_TRUE(n_2 < n_1) << "-2 < -1";
    EXPECT_FALSE(p_1_copy < p_1) << "1 < 1";
    EXPECT_FALSE(p_12 < p_1) << "12 < 1";
}

class FArithmetic : public testing::Test {
    public:
        LongNumber
            n_19602{"-19602"}, n_99{"-99"}, n_87{"-87"}, n_17{"-17"},
            n_16{"-16"}, n_15{"-15"},
            n_7{"-7"}, n_4{"-4"}, n_3{"-3"}, n_2{"-2"}, n_1{"-1"},
        
            p_0{"0"}, p_1{"1"}, p_1_copy{"1"}, p_2{"2"}, p_3{"3"},
            p_4{"4"}, p_6{"6"}, p_12{"12"}, p_16{"16"}, p_17{"17"},
            p_99{"99"}, p_99_copy{"99"},
            p_113{"113"}, p_198{"198"}, p_1188{"1188"}, p_19602{"19602"},
            
            n_100{"-100"}, n_6{"-6"}, p_100{"100"}, p_{"6"};
};

TEST_F(FArithmetic, summ) {
    EXPECT_EQ(p_2, p_1 + p_1_copy) << "1 + 1 = 2";
    EXPECT_EQ(p_0, p_1 + n_1) << "1 + (-1) = 0";
    EXPECT_EQ(p_198, p_99 + p_99_copy) << "99 + 99 = 198";
    EXPECT_EQ(n_87, n_99 + p_12) << "-99 + 12 = -87";
    EXPECT_EQ(n_87, p_12 + n_99) << "12 + (-99) = -87";
}

TEST_F(FArithmetic, substraction) {
    EXPECT_EQ(p_0, p_1 - p_1_copy) << "1 - 1 = 0";
    EXPECT_EQ(p_2, p_1 - n_1) << "1 + (-1) = 2";
    EXPECT_EQ(n_87, p_12 - p_99) << "12 - 99 = -87";
}

TEST_F(FArithmetic, multiply) {
    EXPECT_EQ(p_1, p_1 * p_1_copy) << "1 * 1 = 1";
    EXPECT_EQ(n_1, p_1 * n_1) << "1 * (-1) = -1";
    EXPECT_EQ(p_0, p_0 * p_99) << "0 * 99 = 0";
    EXPECT_EQ(p_1188, p_12 * p_99) << "12 * 99 = 1188";
    EXPECT_EQ(n_19602, p_198 * p_99 * n_1) << "198 * 99 * -1 = -19602";
}

TEST_F(FArithmetic, division) {
    EXPECT_EQ(p_2, p_2 / p_1) << "2 / 1 = 2";
    EXPECT_EQ(p_198, p_19602 / p_99) << "19602 / 99 = 198";
    EXPECT_EQ(p_99, n_19602 / p_198 / n_1) << "-19602 / 198 / -1  = 99";
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
