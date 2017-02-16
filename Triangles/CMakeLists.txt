cmake_minimum_required(VERSION 3.6)
project(Triangles)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

set(SOURCE_FILES
        Point.cpp
        Point.hpp
        Edge.cpp
        Edge.hpp
        Triangle.cpp
        Triangle.hpp
        Utils.cpp
        Utils.hpp)
add_executable(Triangles main.cpp ${SOURCE_FILES})

set(TEST_FILES Testing/PointTester.cpp
        Testing/PointTester.hpp
        Testing/EdgeTester.cpp
        Testing/EdgeTester.hpp
        Testing/TriangleTester.cpp
        Testing/TriangleTester.hpp
        Testing/UtilsTester.cpp
        Testing/UtilsTester.hpp)
add_executable(Test Testing/testMain.cpp ${TEST_FILES} ${SOURCE_FILES})
