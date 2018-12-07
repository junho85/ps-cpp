cmake_minimum_required(VERSION 3.12)
project(ps_cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(ps_cpp main.cpp)
add_executable(pre_coloring 2017_kakao_blind/pre_coloring.cpp)
add_executable(pre_pedestrian_heaven 2017_kakao_blind/pre_pedestrian_heaven.cpp)

add_subdirectory(googletest)
add_subdirectory(leetcode)

