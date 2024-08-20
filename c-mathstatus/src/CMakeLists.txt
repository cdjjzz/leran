cmake_minimum_required(VERSION 3.23)
#从当前源文件src 遍历子目录
file(GLOB child_dir RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/*)
foreach(dir ${child_dir})
        # IS_DIRECTORY 判断是否是目录，将目录下所有的源文件 添加到变量集合 LIB_SRC
        if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${dir})
            aux_source_directory(./${dir} LIB_SRC)
        endif()
endforeach()
#将Statu.c 打包lib
aux_source_directory(. LIB_SRC)
# 将所用源文件打包成lib ，父级引用就可以使用lib中的函数
add_library(LIB ${LIB_SRC})

