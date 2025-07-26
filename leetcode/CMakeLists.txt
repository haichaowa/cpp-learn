# 包含头文件目录
include_directories(
        /usr/include
        ${PROJECT_SOURCE_DIR}/include
)

# 定义公共依赖库
set(LEETCODE_DEPS fmt::fmt GTest::GTest GTest::Main)

# 自动遍历 hot100/ 下的所有 .cpp 文件并生成对应的可执行文件
file(GLOB HOT100_SOURCES "hot100/*.cpp")

foreach(SRC ${HOT100_SOURCES})
    # 提取文件名（不带扩展名）作为目标名
    get_filename_component(TARGET_NAME ${SRC} NAME_WE)

    # 为每个 .cpp 文件创建可执行文件
    add_executable(${TARGET_NAME} ${SRC})

    # 链接公共依赖
    target_link_libraries(${TARGET_NAME} PRIVATE ${LEETCODE_DEPS})
endforeach()