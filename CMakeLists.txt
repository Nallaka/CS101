cmake_minimum_required(VERSION 3.17)
project(cs101)

set(CMAKE_CXX_STANDARD 14)

add_executable(cs101
        "labs/l2-classes/triple.cpp" labs/l2-classes/main.cpp "projects/p1-csv stats/p1.cpp")
