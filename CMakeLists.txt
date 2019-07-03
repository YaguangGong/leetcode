cmake_minimum_required(VERSION 3.6)
project(leetcode)

set(CMAKE_CXX_STANDARD 11)

file(GLOB_RECURSE COMMON_SRC
        themes/utils/*.hpp
        themes/utils/*.cc
        )

add_executable(2 themes/LinkedList/2.cc ${COMMON_SRC})
add_executable(19 themes/LinkedList/19.cc ${COMMON_SRC})
add_executable(21 themes/LinkedList/21.cc ${COMMON_SRC})
add_executable(24 themes/LinkedList/24.cc ${COMMON_SRC})
add_executable(61 themes/LinkedList/61.cc ${COMMON_SRC})
add_executable(82 themes/LinkedList/82.cc ${COMMON_SRC})
add_executable(86 themes/LinkedList/86.cc ${COMMON_SRC})
add_executable(92 themes/LinkedList/92.cc ${COMMON_SRC})
add_executable(138 themes/LinkedList/138.cc ${COMMON_SRC})
add_executable(142 themes/LinkedList/142.cc ${COMMON_SRC})
add_executable(143 themes/LinkedList/143.cc ${COMMON_SRC})
add_executable(94 themes/Tree/94.cc ${COMMON_SRC})

include_directories(.)
