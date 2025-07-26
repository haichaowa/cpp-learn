cmake_minimum_required(VERSION 3.0.0)

set(CMAKE_CXX_STANDARD 11)

include_directories(
        /usr/include  # 远程第三方库的安装路径
        ${PROJECT_SOURCE_DIR}/include
)

# 包含第三方库
find_package(fmt REQUIRED)
find_package(GTest REQUIRED)

# 添加 leetcode 子目录
add_subdirectory(leetcode)