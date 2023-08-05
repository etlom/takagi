# cmake 最低版本需求
cmake_minimum_required(VERSION 3.16)

# 工程名称
project(takagi)

include_directories(include)
# 设置
#set(CMAKE_CXX_STANDARD 11)

# 编译源码生成目标
add_executable(takagi src/main.c)