#include "sort.h"
#include <gmock/gmock.h>

#include <vector>

using namespace ::testing;

namespace {

TEST(Sort, ascending)
{
    // Arrange
    std::vector<int> v = {1, 2, 5, 3, 4, 2, 3, 5, 2, 6};

    // act
    sort_ascending(v);

    // Assert
    EXPECT_THAT(v, ElementsAre(1, 2, 2, 2, 3, 3, 4, 5, 5, 6));
}

TEST(Sort, descending)
{
    // Arrange
    std::vector<int> v = {1, 2, 5, 3, 4, 2, 3, 5, 2, 6};

    // act
    sort_descending(v);

    // Assert
    EXPECT_THAT(v, ElementsAre(6, 5, 5, 4, 3, 3, 2, 2, 2, 1));
}

}
