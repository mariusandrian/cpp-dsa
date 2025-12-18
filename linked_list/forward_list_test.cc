#include <gtest/gtest.h>
#include <list>

#include "forward_list.h"

TEST(ForwardList, Basic)
{
    ForwardListT f{};
    f.push_back("hello");
    EXPECT_EQ(f.front(), "hello");
    EXPECT_EQ(f.back(), "hello");

    f.push_back("there");
    EXPECT_EQ(f.front(), "hello");
    EXPECT_EQ(f.back(), "there");

    auto bi = f.begin();
    auto ei = f.end();
    EXPECT_NE(bi, ei);
};