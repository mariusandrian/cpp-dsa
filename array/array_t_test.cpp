#include <gtest/gtest.h>

#include "array_t.h"

TEST(ArrayT, AccessFns)
{
    ArrayT<int, 5> a{1, 2, 3, 4, 5};
    EXPECT_EQ(a.at(0), 1);
    EXPECT_EQ(a.at(4), 5);

    EXPECT_THROW(a.at(6), std::out_of_range);

    EXPECT_EQ(a.size(), 5);

    EXPECT_EQ(a.front(), 1);
    EXPECT_EQ(a.back(), 5);

    EXPECT_EQ(a[0], 1);
}

TEST(ArrayT, Iterators)
{
    ArrayT<int, 5> a{1, 2, 3, 4, 5};
    EXPECT_EQ(*a.begin(), 1);
    EXPECT_EQ(*(a.end() - 1), 5);

    std::vector<int> actual{};
    for (auto it = a.begin(); it != a.end(); it++)
    {
        actual.push_back(*it);
    }

    std::vector<int> expect{1, 2, 3, 4, 5};
    EXPECT_EQ(expect, actual);
}

TEST(ArrayT, OperationFns)
{
    ArrayT<int, 5> a{};
    a.fill(1);
    EXPECT_EQ(a.at(0), 1);
    EXPECT_EQ(a.at(4), 1);
}