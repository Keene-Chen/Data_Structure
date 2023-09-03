#[[
# Author : KeeneChen
# Date   : 2022.09.03-14:36:37
]]

project(04_binary_tree DESCRIPTION "二叉树")

# 设置可执行文件生成位置
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/src_220830/${PROJECT_NAME})

# 添加可执行文件
add_executable(binary_tree_recursion binary_tree_recursion.c)
add_executable(binary_tree_non_recursion seq_stack.c
                                         binary_tree_non_recursion.c)
add_executable(leaf_node_num leaf_node_num.c)
