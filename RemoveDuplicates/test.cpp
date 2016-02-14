#include "idiom.h"
#include <gmock/gmock.h>

using namespace ::testing;

namespace {

TEST(The_Remove_duplicates_function, removes_all_duplications_from_a_container)
{
    // Arrange
    std::vector<int> v = {1, 1, 2, 3, 4, 2, 5, 2, 5, 2, 6, 9, 10, 10, 12, 16};

    // Act
    sort_and_remove_duplicates(v);

    // Assert
    EXPECT_THAT(v.size(), Eq(10u));
    EXPECT_THAT(v, UnorderedElementsAre(1, 2, 3, 4, 5, 6, 9, 10, 12, 16));
}

}
