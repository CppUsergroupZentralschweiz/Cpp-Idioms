#include "idiom.h"
#include <gmock/gmock.h>

#include <vector>
#include <array>

using namespace ::testing;

namespace {

TEST(The_get_PI_template_Function, returns_3_for_integral_types)
{
    // Assert
    EXPECT_THAT(get_PI<int>(), Eq(3));
    EXPECT_THAT(get_PI<unsigned>(), Eq(3));
    EXPECT_THAT(get_PI<short>(), Eq(3));
    EXPECT_THAT(get_PI<unsigned short>(), Eq(3));
    EXPECT_THAT(get_PI<long>(), Eq(3));
    EXPECT_THAT(get_PI<unsigned long>(), Eq(3));
    EXPECT_THAT(get_PI<long long>(), Eq(3));
    EXPECT_THAT(get_PI<unsigned long long>(), Eq(3));
}

TEST(The_get_PI_template_Function, returns_pi_for_floating_point_types)
{
    const auto pi = 3.1415926536;
    // Assert
    EXPECT_THAT(get_PI<float>(), FloatEq(pi));
    EXPECT_THAT(get_PI<double>(), DoubleEq(pi));
  //  EXPECT_THAT(get_PI<long double>(), Eq(pi));
}

TEST(The_get_PI_template_Function, returns_PI_for_non_numeric_types)
{
    // Assert
    EXPECT_THAT((get_PI<std::array<int, 3>>()), Eq("PI"));
    EXPECT_THAT(get_PI<std::string>(), Eq("PI"));
    EXPECT_THAT(get_PI<std::vector<int>>(), Eq("PI"));
}

}
