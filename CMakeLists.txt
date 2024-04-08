#设置项目名称与版本要求
project(Liner_Algebra)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
aux_source_directory(src SRC_LIST)

include_directories(inc)

#添加可执行文件
add_executable(main ${SRC_LIST})