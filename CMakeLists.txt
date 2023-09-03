#[[
# Author : KeeneChen
# Date   : 2022.09.04-15:06:17
]]

cmake_minimum_required(VERSION 3.10...3.20)

project(
  Data_Structure
  VERSION 1.0.1
  DESCRIPTION "Data_Structure"
  HOMEPAGE_URL ""
  LANGUAGES C CXX)

# 包括 kc_config.cmake 模块,调用其中定义的宏
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(kc_config)
add_kc_colors()
add_kc_debug()

# 开启测试
enable_testing()

# 添加子目录
add_subdirectory(src_220830)
add_subdirectory(src_230830)
