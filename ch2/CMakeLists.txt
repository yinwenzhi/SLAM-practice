#声明要求的cmake的最低版本
cmake_minimum_required( VERSION 2.8 )

#声明一个cmake工程
project(HelloSLAM)

#添加一个可执行程序
#语法：add_executable(程序名 源代码文件）
add_executable(helloSLAM helloSLAM.cpp)

add_library( hello libHelloSLAM.cpp)
add_library( hello_shared SHARED libHelloSLAM.cpp)

#添加一个可执行程序的生成命令
add_executable( useHello useHello.cpp)
#链接到我们使用的库上
target_link_libraries( useHello hello_shared )

