#include <gtest/gtest.h>

#include "umap.h"

TEST(UMap, Basic)
{
    UnorderedMapT m{};
    std::string k = "hello";
    m.insert(k, "world");
    EXPECT_EQ(m.get(k), "world");

    m.insert(k, "ABC");
    EXPECT_EQ(m.get(k), "ABC");

    m.remove(k);
    EXPECT_THROW(m.get(k), std::out_of_range);

    EXPECT_NO_THROW(m.remove(k));
}

TEST(UMap, InvalidArgs)
{
    UnorderedMapT m{};
    EXPECT_THROW(m.insert("", "world"), std::invalid_argument);
}