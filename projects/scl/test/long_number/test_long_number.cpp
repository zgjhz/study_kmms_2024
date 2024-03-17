#include <gtest/gtest.h>

#include "long_number.hpp"

TEST(get_digits_number, check_positive) {
	GGolub::LongNumber x("12345");
	EXPECT_EQ(5, x.get_digits_number())
		<< "Неправильно подсчитано количество разрядов в числе " << x;
}

TEST(get_digits_number, check_negative) {
	GGolub::LongNumber x("-1");
	EXPECT_EQ(1, x.get_digits_number())
		<< "Неправильно подсчитано количество разрядов в числе " << x;
}

class EqualityFixture : public testing::Test {
	public:
    GGolub::LongNumber one_v1 = GGolub::LongNumber("1");
    GGolub::LongNumber one_v2 = GGolub::LongNumber("1");
    GGolub::LongNumber seven = GGolub::LongNumber("7");
    GGolub::LongNumber eleven = GGolub::LongNumber("11");
    GGolub::LongNumber twelve = GGolub::LongNumber("12");
    GGolub::LongNumber negative_one = GGolub::LongNumber("-1");
    GGolub::LongNumber hundred = GGolub::LongNumber("1000");
    GGolub::LongNumber num_1 = GGolub::LongNumber("143043646467550005435000");
    GGolub::LongNumber num_2 = GGolub::LongNumber("143043646467550005435000000");
    GGolub::LongNumber num_3 = GGolub::LongNumber("143043646467267836806260550005435000");
};

TEST_F(EqualityFixture, equal) {
	ASSERT_TRUE(one_v1 == one_v2) << "Проверка " << one_v1 << " == " << one_v2;
}

TEST_F(EqualityFixture, not_equal) {
	ASSERT_FALSE(one_v1 == twelve) << "Проверка " << one_v1 << " == " << twelve;
}

TEST_F(EqualityFixture, not_equal_negative_var) {
	ASSERT_FALSE(one_v1 == negative_one) 
		<< "Проверка " << one_v1 << " == " << negative_one;
}

TEST_F(EqualityFixture, less) {
    EXPECT_LT(one_v1 , twelve) << "Проверка " << one_v1 << " < " << twelve;
}

TEST_F(EqualityFixture, great) {
    EXPECT_GT(twelve, one_v1) << "Проверка " << twelve << " > " << one_v1;
}

TEST_F(EqualityFixture, sum) {
    GGolub::LongNumber result = one_v1 + eleven;
    EXPECT_EQ(result , twelve) << "Проверка " << one_v1 << " + " << eleven << " = " << twelve;
}

TEST_F(EqualityFixture, diff) {
    GGolub::LongNumber result = twelve - one_v1;
    EXPECT_EQ(result , eleven) << "Проверка " << twelve << " - " << eleven << " = " << eleven;
}

TEST_F(EqualityFixture, multiplie) {
    GGolub::LongNumber result = hundred * num_1;
    EXPECT_EQ(result , num_2) << "Проверка " << hundred << " * " << num_1 << " = " << num_2;
}

TEST_F(EqualityFixture, module) {
    GGolub::LongNumber result = num_3 % eleven;
    EXPECT_EQ(result , seven) << "Проверка " << num_3 << " - " << eleven << " = " << seven;
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
