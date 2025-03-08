#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "/Users/igormajorov/Desktop/Ogorod/MP/projects/dz2.sort/src/sort.hpp"

TEST(ArrayIsEqual, AnyElementCounts) {
    std::vector<int> actual;
    actual.push_back(1);
    actual.push_back(8);
    actual.push_back(2);
    actual.push_back(5);
    actual.push_back(3);
    actual.push_back(11);
    mik::bubble_sort(actual);
    std::vector<int> expected;
    actual.push_back(1);
    actual.push_back(4);
    actual.push_back(3);
    actual.push_back(5);
    actual.push_back(8);
    actual.push_back(11);
   

    ASSERT_EQ(expected.size(), actual.size())

        << "Разные размеры ожидаемого и отсортированного массивов" ;
    for (int i = 0; i < actual.size(); i++) {
        ASSERT_EQ (expected [i], actual[i])
            <<"Массив ожидаемый и отсортировнный отличаются в элементе с индекс"
            << i;
    }
}

int main (int argc, char **argv) {
     :: testing::InitGoogleTest (&argc, argv);
     return RUN_ALL_TESTS ();
}
