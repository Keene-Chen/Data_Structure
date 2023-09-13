#[[
# Author : Keenechen
# Date   : 2023.08.24-18:11:36
]]

project(src_230830)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${PROJECT_NAME})

link_libraries(-lmimalloc)

# 01_dynamic_array
aux_source_directory(./01_dynamic_array dynamic_array_source)
add_executable(01_dynamic_array ${dynamic_array_source})

# 02_linked_list
set(dir ./02_linked_list)
set(subdir
    01_single_linked_list
    02_single_circular_linked_list
    # 03_double_linked_list
    04_double_circular_linked_list
    05_head_linked_list
    06_nohead_linked_list
    07_double_circular_lib1
    08_double_circular_lib2
    09_double_circular_lib3
    10_double_circular_lib4
    11_kernel_doubly_linked_list
    12_single_merge)

foreach(index ${subdir})
  aux_source_directory(${dir}/${index} ${index}_source)
  add_executable(${index} ${${index}_source})
endforeach()

# 03_stack
aux_source_directory(./03_stack/01_array_based seq_stack_source)
aux_source_directory(./03_stack/02_list_based list_stack_source)
add_executable(12_seq_stack ${seq_stack_source})
add_executable(13_list_stack ${list_stack_source})

# 04_queue
aux_source_directory(04_queue/01_array_based seq_queue_source)
aux_source_directory(04_queue/02_list_based list_queue_source)
add_executable(14_seq_queue ${seq_queue_source})
add_executable(15_list_queue ${list_queue_source})

# 05_btree todo 二叉树搜索树 红黑树 最全二叉树 完全二叉树
aux_source_directory(./05_btree/01_btree_recursion btree_source)
add_executable(16_btree_recursion ${btree_source})
aux_source_directory(./05_btree/02_level_travel level_travel_source)
add_executable(17_level_travel ${level_travel_source})
aux_source_directory(./05_btree/03_binary_search_tree btree_search_source)
add_executable(18_btree_search ${btree_search_source})
