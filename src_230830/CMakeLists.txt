#[[
# Author : Keenechen
# Date   : 2023.08.24-18:11:36
]]

project(src_230830)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${PROJECT_NAME})

aux_source_directory(./01_dynamic_array dynamic_array_source)
add_executable(01_dynamic_array ${dynamic_array_source})

set(dir ./02_linked_list)
set(subdir
    01_single_linked_list
    02_single_circular_linked_list
    # 03_double_linked_list
    04_double_circular_linked_list
    05_head_linked_list
    06_nohead_linked_list
    07_double_circular_lib1)

foreach(index ${subdir})
  aux_source_directory(${dir}/${index} ${index}_source)
  add_executable(${index} ${${index}_source})
endforeach()
