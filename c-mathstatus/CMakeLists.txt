# cmake 最低版本
cmake_minimum_required(VERSION 3.23)
#项目名称
project(c_mathstatus)
#支持中文目录
set(LC_ALL,"")
#设置c语言使用标准
set(CMAKE_C_STANDARD 99)
#设置可执行文件输出目录 EXECUTABLE_OUTPUT_PATH  CMAKE_CURRENT_SOURCE_DIR cmake的内部环境变量
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)
#设置头文件目录
include_directories(./include)

aux_source_directory(. DIR_SRC)
#设置源文件目录-一级目录
add_subdirectory(src)
#执行文件
add_executable(${PROJECT_NAME} ${DIR_SRC})
# 添加链接库

target_link_libraries(${PROJECT_NAME} LIB)

