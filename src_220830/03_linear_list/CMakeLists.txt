#[[
# Author : KeeneChen
# Date   : 2022.08.31-20:45:27
]]

project(03_linear_list DESCRIPTION "线性表")

# 设置可执行文件生成位置
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/src_220830/${PROJECT_NAME})

# queue
add_executable(link_queue queue/link_queue_test.c queue/link_queue.c)
add_executable(seq_queue queue/seq_queue_test.c queue/seq_queue.c
                         queue/dynamic_array.c)

# stack
add_executable(link_stack stack/link_stack_test.c stack/link_stack.c)
add_executable(seq_stack stack/seq_stack_test.c stack/seq_stack.c)
