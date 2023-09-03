#[[
# Author : KeeneChen
# Date   : 2022.08.30-21:20:12
]]

project(01_sequence_list DESCRIPTION "顺序表")

# 设置可执行文件生成位置
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/src_220830/${PROJECT_NAME})

add_executable(dynamic_array dynamic_array_test.c dynamic_array.c)
add_executable(vector vector.c)
