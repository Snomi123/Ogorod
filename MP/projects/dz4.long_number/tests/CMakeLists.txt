set(GTEST_ROOT "/opt/homebrew/opt/googletest")

find_package(GTest REQUIRED CONFIG)

add_executable(test_long_number test_long_number.cpp)

target_link_libraries(test_long_number PRIVATE
    long_number
    GTest::gtest
    GTest::gtest_main
)

add_test(NAME long_number_tests COMMAND test_long_number)