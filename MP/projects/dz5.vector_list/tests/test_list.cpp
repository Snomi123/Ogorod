#include <gtest/gtest.h>
#include "doubly_linked_list.hpp"

using biv::DoublyLinkedList;

TEST(ListTest, PushBack) {
    DoublyLinkedList<int> list;
    list.push_back(42);
    EXPECT_EQ(list.get_size(), 1);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
