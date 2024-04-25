#include "doubly_linked_list.hpp"
#include <gtest/gtest.h>

using namespace GGolub;

TEST(DoublyLinkedListTest, DefaultConstructor) {
    DoublyLinkedList<int> list;
    EXPECT_EQ(list.size(), 0);
}

TEST(DoublyLinkedListTest, PushBackAndSize) {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    EXPECT_EQ(list.size(), 3);
}

TEST(DoublyLinkedListTest, HasItem) {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    EXPECT_TRUE(list.has_item(2));
    EXPECT_FALSE(list.has_item(4));
}

TEST(DoublyLinkedListTest, RemoveFirst) {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    EXPECT_TRUE(list.remove_first(2));
    EXPECT_EQ(list.size(), 2);
    EXPECT_FALSE(list.has_item(2));
}

TEST(DoublyLinkedListTest, Print) {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    testing::internal::CaptureStdout();
    list.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "1 2 3");
}
