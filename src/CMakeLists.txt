# 源代码目录的CMakeLists.txt

# 收集所有源文件
file(GLOB_RECURSE SOURCES *.cpp)

# 创建库
add_library(omini_slam SHARED ${SOURCES})

# 链接依赖库
target_link_libraries(omini_slam
    ${OpenCV_LIBS}
    ${PCL_LIBRARIES}
)

# 安装规则
install(TARGETS omini_slam
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
)