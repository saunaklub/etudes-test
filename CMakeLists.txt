cmake_minimum_required(VERSION 3.1)

# Download and unpack googletest at configure time
configure_file(${CMAKE_CURRENT_LIST_DIR}/CMakeLists.txt.in
    ${CMAKE_BINARY_DIR}/googletest-download/CMakeLists.txt)

execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
                 ${CMAKE_BINARY_DIR}/googletest-build)

set(TEST etudes_test)

add_executable(${TEST}
    ${CMAKE_CURRENT_LIST_DIR}/src/main.cpp)

set_property(TARGET ${TEST} PROPERTY CXX_STANDARD 14)

target_link_libraries(${TEST}
    ${LIBRARY}
    gtest_main
    )

target_include_directories(${TEST}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/lib
    PUBLIC ${GTEST_INCLUDE_DIRS}
    )

add_test(THIS_TEST ${TEST})
