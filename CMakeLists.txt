cmake_minimum_required(VERSION 3.0.0)
project(leetcode-problem-solving VERSION 0.1.0)

include(CTest)
enable_testing()

# 生成可执行文件命令，第一个参数是生成可执行文件的名称，后面的参数是源文件代码
add_executable(leetcode-problem-solving 1.两数之和.cpp main.cpp)

# 指定生成可执行文件的输出目录
set(EXECUTABLE_OUTPUT_PATH "../out")

# 调试模式
set(CMAKE_BUILD_TYPE Debug)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
