CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

project(nlohmann_test)

# 保证项目兼容性
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# 应用版本
set(APP_VERSION "1.0")
# 项目版本
project(nlohmann_test VERSION 1.1)

# debug mode
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  add_definitions(-DDEBUG)
endif()

ADD_SUBDIRECTORY(src)
#ADD_SUBDIRECTORY(test)

message(STATUS "CMAKE_PROJECT_VERSION = ${CMAKE_PROJECT_VERSION}")
message(STATUS "output " ${PROJECT_BINARY_DIR})
message(STATUS "source " ${PROJECT_SOURCE_DIR})
message(STATUS "install " ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})
