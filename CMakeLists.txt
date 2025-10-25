cmake_minimum_required(VERSION 3.10)
project(lab3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -Werror=maybe-uninitialized")

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.15.0
)
FetchContent_MakeAvailable(googletest)

add_library(${CMAKE_PROJECT_NAME}_lib ./src/figure_array.cpp ./src/figure.cpp ./src/rectangle.cpp ./src/rhomb.cpp ./src/trapezoid.cpp ./src/vector2d.cpp)
add_executable(app main.cpp)
target_link_libraries(app PRIVATE ${CMAKE_PROJECT_NAME}_lib)

enable_testing()
add_executable(tests tests/test_vector2d.cpp tests/test_figure.cpp)
target_link_libraries(tests gtest_main ${CMAKE_PROJECT_NAME}_lib)
add_test(NAME Lab_3_Test COMMAND tests)