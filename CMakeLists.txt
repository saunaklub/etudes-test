cmake_minimum_required(VERSION 3.1)

set(TEST etudes_test)

enable_testing()
find_package(GTest REQUIRED)
find_package(etudes REQUIRED)

add_executable(${TEST} src/main.cpp)

target_link_libraries(${TEST}
    GTest::GTest
    GTest::Main
    ${ETUDES_LIBRARIES}
    )

target_include_directories(${TEST}
    PUBLIC ${ETUDES_INCLUDE_DIRS}
    PUBLIC ${GTEST_INCLUDE_DIRS}
    )

add_test(AllTestsInFoo foo)
