#设置项目名称与版本要求
cmake_minimum_required(VERSION 3.10)
project(Liner_Algebra)

#设置c99标准
set(CMAKE_C_STANDARD 99) # 设置C语言标准为C99
set(CMAKE_C_STANDARD_REQUIRED True)

include_directories(src inc)


#添加可执行文件
add_executable(Executable src/main.c src/algebra.c)

