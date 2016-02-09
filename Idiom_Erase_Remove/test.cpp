#include "idiom.h"
#include <gmock/gmock.h>

using namespace ::testing;

namespace {

TEST(The_Remove_all_multiples_of_X_function, removes_all_multiples_of_two_from_a_container)
{
    // Arrange
    std::vector<int> v = {1, 2, 3, 4, 2, 5, 2, 6, 9, 10, 12, 16};

    // Act
    remove_multiples_of(2, v);

    // Assert
    EXPECT_THAT(v.size(), Eq(4u));
    EXPECT_THAT(v, UnorderedElementsAre(1, 3, 5, 9));
}

TEST(The_Remove_all_multiples_of_X_function, removes_all_multiples_of_three_from_a_container)
{
    // Arrange
    std::vector<int> v = {1, 2, 3, 4, 2, 5, 2, 6, 9, 10, 12, 16};

    // Act
    remove_multiples_of(3, v);

    // Assert
    EXPECT_THAT(v.size(), Eq(8u));
    EXPECT_THAT(v, UnorderedElementsAre(1, 2, 4, 2, 5, 2, 10, 16));
}


}
