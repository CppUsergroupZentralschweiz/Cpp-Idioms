#include "idiom.h"
#include <gmock/gmock.h>

using namespace ::testing;

namespace {

TEST(Shrink_to_fit, reduces_capacity_to_size)
{
    // Arrange
    std::vector<int> v = {1, 2, 3,};
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);

    // Act
    shrink_to_fit(v);

    // Assert
    EXPECT_THAT(v.capacity(), Eq(v.size()));
}

}
