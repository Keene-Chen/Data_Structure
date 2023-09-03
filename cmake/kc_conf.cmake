#[[
# Author : KeeneChen
# Date   : 2022.09.04-15:06:17
# File   : kc_conf.cmake
# Copyright (c) 2019-2023 KeeneChen
]]

#[[
# colorize CMake output code adapted from stackoverflow:
# http://stackoverflow.com/a/19578320 from post authored by
# https://stackoverflow.com/users/2556117/fraser
]]

macro(add_kc_colors)
  if(WIN32)
    # has no effect on WIN32
    set(ColourReset "")
    set(ColourBold "")
    set(Red "")
    set(Green "")
    set(Yellow "")
    set(Blue "")
    set(Magenta "")
    set(Cyan "")
    set(White "")
    set(BoldRed "")
    set(BoldGreen "")
    set(BoldYellow "")
    set(BoldBlue "")
    set(BoldMagenta "")
    set(BoldCyan "")
    set(BoldWhite "")
  else()
    string(ASCII 27 Esc)
    set(ColourReset "${Esc}[m")
    set(ColourBold "${Esc}[1m")
    set(Red "${Esc}[31m")
    set(Green "${Esc}[32m")
    set(Yellow "${Esc}[33m")
    set(Blue "${Esc}[34m")
    set(Magenta "${Esc}[35m")
    set(Cyan "${Esc}[36m")
    set(White "${Esc}[37m")
    set(BoldRed "${Esc}[1;31m")
    set(BoldGreen "${Esc}[1;32m")
    set(BoldYellow "${Esc}[1;33m")
    set(BoldBlue "${Esc}[1;34m")
    set(BoldMagenta "${Esc}[1;35m")
    set(BoldCyan "${Esc}[1;36m")
    set(BoldWhite "${Esc}[1;37m")
  endif()
endmacro()

macro(add_kc_debug)
  # 设置语言标准
  set(CMAKE_C_STANDARD 11)
  set(CMAKE_C_STANDARD_REQUIRED True)
  set(CMAKE_CXX_STANDARD 17)
  set(CMAKE_CXX_STANDARD_REQUIRED True)

  # 设置默认构建类型
  if(NOT CMAKE_BUILD_TYPE)
    if("${CMAKE_BINARY_DIR}" MATCHES "build_.*(D|d)ebug$")
      message(STATUS "${Red}>>> Build Type: Debug  ${ColourReset}")
      set(CMAKE_BUILD_TYPE "Debug")
    elseif("${CMAKE_BINARY_DIR}" MATCHES "build_.*(R|r)elWithDebInfo$")
      message(STATUS "${Green}>>> Build Type: RelWithDebInfo ${ColourReset}")
      set(CMAKE_BUILD_TYPE "RelWithDebInfo")
    elseif("${CMAKE_BINARY_DIR}" MATCHES "build_.*(M|m)inSizeRel$")
      message(STATUS "${Blue}>>> Build Type: MinSizeRel ${ColourReset}")
      set(CMAKE_BUILD_TYPE "MinSizeRel")
    else()
      message(STATUS "${BoldYellow}>>> Build Type: Release ${ColourReset}")
      set(CMAKE_BUILD_TYPE "Release")
    endif()
  endif()

  # CMake 调试信息
  message(
    STATUS "${BoldYellow}>>> CMake Version : ${CMAKE_VERSION} ${ColourReset}")
  message(
    STATUS
      "${BoldYellow}>>> CMake System  : ${CMAKE_SYSTEM_NAME} ${ColourReset}")
  string(TIMESTAMP BUILD_TIMESTAMP "%Y-%m-%d-%H:%M:%S")
  message(
    STATUS "${BoldYellow}>>> Build DateTime: ${BUILD_TIMESTAMP} ${ColourReset}")

  # 导出编译命令配置,供clangd使用
  set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
endmacro()
