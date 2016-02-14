#include "complex_number.h"
#include <gmock/gmock.h>

#include <vector>

using namespace ::testing;

namespace {

TEST(Complex_Numbers, can_be_ordered)
{
    // Arrange
    const auto number1 = complex{2.2, 1.0};
    const auto number2 = complex{2.3, 1.0};

    const auto number3 = complex{2.3, 1.0};
    const auto number4 = complex{2.3, -1.0};

    // Assert
    EXPECT_TRUE(number1 < number2);
    EXPECT_TRUE(number3 > number4);
}

TEST(Complex_Numbers, can_be_compared)
{
    // Arrange
    const auto number1 = complex{2.2, 1.0};
    const auto number2 = complex{2.3, 1.0};

    const auto number3 = complex{2.3, 1.0};
    const auto number4 = complex{2.3, 1.0};

    // Assert
    EXPECT_TRUE(number1 != number2);
    EXPECT_TRUE(number3 == number4);
}

TEST(Complex_Numbers, can_be_added)
{
    // Arrange
    const auto number1 = complex{2.2, 1.0};
    const auto number2 = complex{2.3, 1.0};

    const auto number3 = number1 + number2;

    // Assert
    EXPECT_THAT(number3, Eq(complex{4.5, 2.0}));
}

TEST(Complex_Numbers, can_be_incremented)
{
    // Arrange
    auto number1 = complex{2.2, 1.0};

    // Assert
    EXPECT_THAT(++number1, Eq(complex{3.2, 1.0}));
}

TEST(Complex_Numbers, can_be_decremented)
{
    // Arrange
    auto number1 = complex{2.2, 1.0};

    // Assert
    EXPECT_THAT(--number1, Eq(complex{1.2, 1.0}));
}

TEST(Complex_Numbers, can_be_subtracted)
{
    // Arrange
    const auto number1 = complex{1.1, 1.0};
    const auto number2 = complex{3.3, 2.1};

    const auto number3 = number2 - number1;

    // Assert
    EXPECT_THAT(number3, Eq(complex{2.2, 1.1}));
}

}
