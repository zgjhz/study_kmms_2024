#include "doubly_linked_list.hpp"
#include <gtest/gtest.h>

using namespace GGolub;

TEST(DoublyLinkedListTest, zero_size) {
    DoublyLinkedList<int> list;
    EXPECT_EQ(list.size(), 0);
}
