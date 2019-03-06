#声明要求的Cmake的最低版本
cmake_minimum_required(VERSION 2.8)

#声明一个cmake工程
project(UseEIGEN3)

#添加一个可执行程序
add_executable(UseEIGEN3 eigenMatrix.cpp)

#添加头文件
include_directories("/usr/include/eigen3")


