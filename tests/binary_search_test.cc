#include "binarySearch.h"
#include "gtest/gtest.h"
#include <vector>

TEST(binarySearch, OutOfRange)
{
    std::vector<int> array{ 0, 1, 2, 3, 4, 5, 6 };
    EXPECT_EQ(array.end(), lnfAlg::find(array.begin(), array.end(), -1));
    EXPECT_EQ(array.end(), lnfAlg::find(array.begin(), array.end(), 7));
}

TEST(binarySearch, Middle)
{
    std::vector<int> array{ 0, 1, 2};
    EXPECT_EQ((array.begin() + 1), lnfAlg::find(array.begin(), array.end(), 1));
}

TEST(binarySearch, FirstLast)
{
    std::vector<int> array{0, 1, 2, 3, 4, 5, 6};
    EXPECT_EQ(array.begin(), lnfAlg::find(array.begin(), array.end(), 0));
    EXPECT_EQ(array.end() - 1, lnfAlg::find(array.begin(), array.end(), 6));
}
