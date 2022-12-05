cmake_minimum_required(VERSION 3.23)
project(leran C)

message (">>> top PROJECT_NAME: ${PROJECT_NAME}")
message (">>> top PROJECT_SOURCE_DIR: ${PROJECT_SOURCE_DIR}")
message (">>> top <PROJECT_NAME>_SOURCE_DIR: ${${TOP_PROJECT_NAME}_SOURCE_DIR}")
message (">>> top PROJECT_BINARY_DIR: ${PROJECT_BINARY_DIR}")
message (">>> top <PROJECT_NAME>_BINARY_DIR: ${${TOP_PROJECT_NAME}_BINARY_DIR}")
message (">>> top CMAKE_PROJECT_NAME: ${CMAKE_PROJECT_NAME}")

set(CMAKE_C_STANDARD 17)

aux_source_directory (structureL structureL)
add_executable(leran main.c ${structureL})
target_link_libraries(leran E:/c-source/leran/cmake-build-debug-mingw/libleran.dll)