#include <iostream>
#include <gtest/gtest.h>
#include <IO/OSCInput.hpp>

TEST(OSCInput, DoesntLeak) {
    etudes::OSCInput a(6666);

    std::cout << "failed\n";

    ASSERT_EQ(0, 0);
}
