cmake_minimum_required(VERSION 3.6)
project(leetcode)

set(CMAKE_CXX_STANDARD 11)

file(GLOB_RECURSE COMMON_SRC
        leetcode/utils/*.hpp
        leetcode/utils/*.cc
        )

add_executable(2 leetcode/LinkedList/2.cc ${COMMON_SRC})
add_executable(19 leetcode/LinkedList/19.cc ${COMMON_SRC})
add_executable(21 leetcode/LinkedList/21.cc ${COMMON_SRC})
add_executable(24 leetcode/LinkedList/24.cc ${COMMON_SRC})
add_executable(61 leetcode/LinkedList/61.cc ${COMMON_SRC})
add_executable(82 leetcode/LinkedList/82.cc ${COMMON_SRC})
add_executable(86 leetcode/LinkedList/86.cc ${COMMON_SRC})
add_executable(92 leetcode/LinkedList/92.cc ${COMMON_SRC})
add_executable(138 leetcode/LinkedList/138.cc ${COMMON_SRC})
add_executable(142 leetcode/LinkedList/142.cc ${COMMON_SRC})
add_executable(143 leetcode/LinkedList/143.cc ${COMMON_SRC})
add_executable(94 leetcode/Tree/94.cc ${COMMON_SRC})

include_directories(.)
