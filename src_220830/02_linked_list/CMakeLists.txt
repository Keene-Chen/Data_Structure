#[[
# Author : KeeneChen
# Date   : 2022.08.31-19:15:07
]]

project(02_linked_list DESCRIPTION "链表")

# 设置可执行文件生成位置
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/src_220830/${PROJECT_NAME})

add_executable(list list_test.c list.c)
