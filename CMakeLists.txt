cmake_minimum_required(VERSION 3.23)
project(TIL)

set(CMAKE_CXX_STANDARD 14)


include_directories(C_C++/ROS-Cpp)


add_executable(TIL
        C_C++/ROS-Cpp/main.cpp)
