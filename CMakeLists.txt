cmake_minimum_required(VERSION 3.10)
project(weakPasswdDetector)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)

# 添加可执行文件
add_executable(weakPasswdDetector main.cpp)

# 添加头文件目录
target_include_directories(weakPasswdDetector PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# 添加源文件
set(SOURCE_FILES
        src/asset_discovery.cpp
        src/weak_password.cpp
        src/mysql_weak_password.cpp
        src/tomcat_weak_password.cpp
        src/report_generator.cpp
        src/utils.cpp
)

# 添加到可执行文件
target_sources(weakPasswdDetector PRIVATE ${SOURCE_FILES})