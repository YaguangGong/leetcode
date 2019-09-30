cmake_minimum_required(VERSION 3.6)
project(leetcode)

set(CMAKE_CXX_STANDARD 11)

file(GLOB_RECURSE COMMON_SRC
        themes/utils/*.hpp
        themes/utils/*.cc
        )

add_executable(3 themes/String/3.cc ${COMMON_SRC})
add_executable(5 themes/String/5.cc ${COMMON_SRC})
add_executable(28 themes/String/28.cc ${COMMON_SRC})
add_executable(30 themes/String/30.cc ${COMMON_SRC})
add_executable(43 themes/String/43.cc ${COMMON_SRC})
add_executable(44 themes/String/44.cc ${COMMON_SRC})
add_executable(76 themes/String/76.cc ${COMMON_SRC})
add_executable(2 themes/LinkedList/2.cc ${COMMON_SRC})
add_executable(19 themes/LinkedList/19.cc ${COMMON_SRC})
add_executable(21 themes/LinkedList/21.cc ${COMMON_SRC})
add_executable(24 themes/LinkedList/24.cc ${COMMON_SRC})
add_executable(61 themes/LinkedList/61.cc ${COMMON_SRC})
add_executable(82 themes/LinkedList/82.cc ${COMMON_SRC})
add_executable(86 themes/LinkedList/86.cc ${COMMON_SRC})
add_executable(92 themes/LinkedList/92.cc ${COMMON_SRC})
add_executable(138 themes/LinkedList/138.cc ${COMMON_SRC} themes/String/3.cc themes/String/5.cc test.cc)
add_executable(142 themes/LinkedList/142.cc ${COMMON_SRC})
add_executable(143 themes/LinkedList/143.cc ${COMMON_SRC})
add_executable(94 themes/Tree/94.cc ${COMMON_SRC})
add_executable(95 themes/Tree/95.cc ${COMMON_SRC})
add_executable(105 themes/DFS/105.cc ${COMMON_SRC})
add_executable(114 themes/DFS/114.cc ${COMMON_SRC})
add_executable(124 themes/DFS/124.cc ${COMMON_SRC})
add_executable(test test.cc ${COMMON_SRC})

include_directories(.)
